////////////////////////////////////////////////////////////////////////////////
// THE SCOTCH-WARE LICENSE (Revision 0):
// <aaronryool@gmail.com> wrote this file. As long as you retain this notice you
// can do whatever you want with this stuff. If we meet some day, and you think
// this stuff is worth it, you can buy me a shot of scotch in return
////////////////////////////////////////////////////////////////////////////////

#include <ast/ast.h>
#include <errors/errors.h>


FunctionNode::FunctionNode (std::string name, std::list<std::tuple<std::string, Type>> arguments,
			Type return_type, AstNode* function_branch) {
	debug("Mapping function -> " + name);
	this->type = nodeType_value;
	this->vtype = FUNCTION;
	this->name = new std::string(name);
  this->arguments = new std::list<std::tuple<std::string, Type>>(arguments);
  this->return_type = return_type;
  this->function_branch = function_branch;
  this->recursion = 0;

  AstNode* ass = new AssignmentNode(FUNCTION, name, this);

  current_scope->attach_statement (ass);
  if (function_branch->type == nodeType_root)
  	((RootNode*) function_branch)->root_type = rootType_function;
}


std::string FunctionNode::to_string (void) {
	debug("function to_string");
	std::string items;
	for (auto a : *this->arguments) {
			items += ast_type_to_string(std::get<1>(a))+" "+std::get<0>(a) + ", ";
	}
	if (items.length() == 0)
		items = "none";
	else {
		items.pop_back();
		items.pop_back();
	}
	return "function(" + *this->name + " "+items+" : "+ast_type_to_string(return_type)+")";
}
std::string FunctionNode::type_str (void) {
	debug("function type_str");
	return "function";
}


FunctionCallNode::FunctionCallNode (std::string name, std::vector<AstNode*> arguments) {
	debug("function call constructor");
	this->type = nodeType_function_call;
	this->name = new std::string(name);
	if (arguments.front())
  	this->arguments = new std::vector<AstNode*>(arguments);
  else
		this->arguments = new std::vector<AstNode*>;
}



int create_function_symbols(FunctionNode* function, std::vector<AstNode*>* args, std::map<std::string, ValueNode*>* newsym) {
	debug("entering create function symbols");
	for (auto pair : *newsym) {
		debug("{"+pair.first+": "+std::to_string(reinterpret_cast<std::uintptr_t>(pair.second))+"}\n");
	}
	
	if (function->recursion == 0) {
		*newsym = *current_scope->symbol_table;
		function->recursion += 1;
	}
	else {
		function->recursion += 1;
	}
	
	
	if (args->size() < function->arguments->size()) {
		runtime_error("not enough arguments", (AstNode*) function);
		return -1;
	}
	if (args->size() > function->arguments->size()) {
		runtime_error("too many arguments", (AstNode*) function);
		return -1;
	}
	
	auto b = args->begin();
	for (auto a : *function->arguments) {
		ValueNode* arg;
		arg = (ValueNode*) (*b)->walk();
		if (arg == NULL || arg->type != nodeType_value) {
			runtime_error("bad argument", (AstNode*) function);
			return -1;
		}
		if (std::get<1>(a) != arg->vtype) {
			runtime_error("wrong argument type", (AstNode*) function);
			return -1;
		}
		if (function->recursion == 1)
			newsym->insert({std::get<0>(a), arg});
		else
			newsym->at(std::get<0>(a)) = arg;
		
		std::advance(b, 1);
	}
	return 0;
}


AstNode* ast_function_call_handler_lambda (FunctionCallNode* node, FunctionNode* function) {
	debug("entering lambda expression");
	if (function->function_branch == NULL) {
			runtime_error("bad lambda expression", (AstNode*) node);
			return NULL;
		}
		std::map<std::string, ValueNode*> oldsym = *current_scope->symbol_table;
		std::map<std::string, ValueNode*> newsym;
		if (create_function_symbols(function, node->arguments, &newsym) == -1) {
			runtime_error("problem with arguments", (AstNode*) node);
			return NULL;
		}
		
		*current_scope->symbol_table = newsym;
		ValueNode* returns = (ValueNode*) function->function_branch->walk();
		*current_scope->symbol_table = oldsym;
		
		if (returns == NULL) {
			runtime_error("problem executing function", (AstNode*) node);
			return NULL;
		}
		if (returns->vtype != function->return_type) {
			runtime_error("Wrong return type", (AstNode*) node);
			runtime_error("see definition", (AstNode*) function);
			
			return NULL;
		}
		return (AstNode*) returns;
}

AstNode* ast_function_call_handler_scoped (FunctionCallNode* node, FunctionNode* function) {
	debug("executing function: " + *function->name);
	std::map<std::string, ValueNode*>* function_symbols;
	function_symbols = ((RootNode*)function->function_branch)->symbol_table;
	
	if (create_function_symbols(function, node->arguments, function_symbols) == -1) {
		runtime_error("problem with arguments", (AstNode*) node);
		return NULL;
	}

	RootNode* old_scope = current_scope;
	current_scope = (RootNode*) function->function_branch;
	ValueNode* returns = (ValueNode*) function->function_branch->walk();
	
	if (returns == NULL) {
		runtime_error("branch problem in return", (AstNode*) node);
		return NULL;
	}
	
	if (function->return_type == NONE) {
		returns = new NoneNode;
	}
	
	if (returns->vtype != function->return_type && function->return_type != NONE) {
		runtime_error("Wrong return type", (AstNode*) node);
		runtime_error("see definition", (AstNode*) function);
		return NULL;
	}
	else {
		current_scope = old_scope;
		returns = duplicate_value(returns);
		if (function->recursion == 1)
			free_value_walk(((RootNode*) function->function_branch)->value_table);
		function->recursion -= 1;
		debug("return type matches: " + *function->name);
		return (AstNode*) returns;
	}
}

AstNode* FunctionCallNode::walk (void) {
	debug("entering ast_function_call_handler");
	FunctionNode* function;
	
	if (current_scope->symbol_table->count(*this->name) != 0) {
		function = (FunctionNode*) current_scope->symbol_table->at(*this->name);
		
		if (function->function_branch->type != nodeType_root) {
			return ast_function_call_handler_lambda (this, function);
		}
		else
			return ast_function_call_handler_scoped(this, function);
	}
	else {
		runtime_error("function undefined", this);
		return NULL;
	}
	return NULL;
}


FunctionReturnNode::FunctionReturnNode (AstNode* expression) {
	debug("function return constructor");
	this->type = nodeType_function_return;
  this->expression = expression;
}

AstNode* FunctionReturnNode::walk (void) {
	debug("entering ast_function_return_handler");
	if (current_scope == tree_root) {
		ValueNode* returns = (ValueNode*) this->expression->walk();
		if (returns->type != nodeType_value)
			runtime_error("attempt to return a non value from __main__", this);
		if (returns->type != nodeType_value)
			runtime_error("attempt to return a non int from __main__", this);
		exit(((IntNode*) returns)->value);
	}
	else {
		return this->expression->walk();
	}
}







