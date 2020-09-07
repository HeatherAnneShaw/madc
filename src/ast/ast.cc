////////////////////////////////////////////////////////////////////////////////
// THE SCOTCH-WARE LICENSE (Revision 0):
// <aaronryool@gmail.com> wrote this file. As long as you retain this notice you
// can do whatever you want with this stuff. If we meet some day, and you think
// this stuff is worth it, you can buy me a shot of scotch in return
////////////////////////////////////////////////////////////////////////////////

#include <ast/ast.h>
#include <errors/errors.h>
#include <iostream>

bool interactive=false;
RootNode* tree_root = NULL;
RootNode* current_scope = NULL;


AstNode::AstNode() {
	debug("Constructor for AstNode called");
	this->linenumber = line_number;
  this->colnumber = col_number;
}
AstNode::~AstNode() {
	debug("destructor for AstNode called");
}

AstNode* AstNode::walk() {
	fatal_error("Walk called from generic node type");
	return NULL;
}


RootNode::RootNode() {
	debug("Constructor for RootNode called");
  this->type = nodeType_root;
  this->root_type = rootType_root;
  this->state_start = NULL;
  this->state_end = NULL;
  
  this->symbol_table = new std::map<std::string, ValueNode*>;
  this->value_table = new std::list<ValueNode*>({});
  
  if (current_scope == NULL)
  	current_scope = this;
  if (tree_root == NULL)
  	tree_root = this;
}
RootNode::~RootNode() {
	debug("Destructor for RootNode called");
	delete this->symbol_table;
  delete this->value_table;
  StatementNode* e = this->state_start;
  StatementNode* n;
  while (e != NULL) {
  	n = e->right;
  	delete e;
  	e = n;
  }
}

AstNode* RootNode::walk() {
	debug("root walk called");
	if (root_type == rootType_root) {
		current_scope = this;
		return state_start->walk();
	}
	else if (current_scope != NULL && root_type != rootType_function) {
		debug("entering a loop or branch root");
		*symbol_table = *current_scope->symbol_table;
		return state_start->walk();
	}
	else if (root_type == rootType_function) {
		debug("entering a function root");
		return state_start->walk();
	}
	else {
		fatal_error("We have reached an invalid root type");
		return NULL;
	}
}


RootNode* RootNode::attach_statement(AstNode* next) {
	debug("Adding statement to root");
	if (! state_start)
	{
		StatementNode* state = new StatementNode;
		state->type = nodeType_statement;
		state->left = next;
		state->right = NULL;
		this->state_start = state;
		this->state_end = state;
	}
	else {
		StatementNode* end = this->state_end;
		StatementNode* state = new StatementNode;
		state->type = nodeType_statement;
		state->left = next;
		state->right = NULL;
		
		end->right = state;
		this->state_end = state;
	}
	return this;
}

AstNode* StatementNode::walk() {
	debug("statement walk called");
	if (error_flag) {
		exit(EXIT_FAILURE);
	}
	
	AstNode* ret;
	ret = left->walk();		// follow instructions
	if (right != NULL)
		return right->walk();	// go to next statement
	
	return ret;
}














