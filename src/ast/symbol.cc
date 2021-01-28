////////////////////////////////////////////////////////////////////////////////
// THE SCOTCH-WARE LICENSE (Revision 0):
// <aaronryool@gmail.com> wrote this file. As long as you retain this notice you
// can do whatever you want with this stuff. If we meet some day, and you think
// this stuff is worth it, you can buy me a shot of scotch in return
////////////////////////////////////////////////////////////////////////////////

#include <ast/ast.h>
#include <errors/errors.h>


AssignmentNode::AssignmentNode (Type vtype, std::string name, AstNode* resolve_tree) {
	debug("assignment constructor");
  this->vtype = vtype;
  this->name = new std::string(name);
  this->resolve_tree = resolve_tree;
}

AssignmentNode::~AssignmentNode (void) {
	debug("assignment constructor");
  delete this->name;
}


AstNode* AssignmentNode::walk (void) {
	debug("assignment walk");
	ValueNode* value;
	value = (ValueNode*) this->resolve_tree->walk();
	if (value == NULL) {
		runtime_error("couldn't assign", this);
		return NULL;
	}
	
	if (value->vtype != this->vtype) {
		runtime_error("Wrong type", this);
		return NULL;
	}
	
	if (current_scope->symbol_table->count(*this->name) == 0)
		current_scope->symbol_table->insert({*this->name, value});
	else
		current_scope->symbol_table->at(*this->name) = value;
	return value;
}


SymbolReference::SymbolReference (std::string name) {
	debug("symbol reference constructor");
	this->name = new std::string(name);
}

SymbolReference::~SymbolReference (void) {
	debug("symbol reference destructor");
	delete this->name;
}

AstNode* SymbolReference::walk (void) {
	if (current_scope->symbol_table->count(*this->name) != 0) {
		return current_scope->symbol_table->at(*this->name);
	}
	runtime_error("symbol referenced before assignment", this);
	return NULL;
}







