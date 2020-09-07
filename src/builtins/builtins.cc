////////////////////////////////////////////////////////////////////////////////
// THE SCOTCH-WARE LICENSE (Revision 0):
// <aaronryool@gmail.com> wrote this file. As long as you retain this notice you
// can do whatever you want with this stuff. If we meet some day, and you think
// this stuff is worth it, you can buy me a shot of scotch in return
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>

#include <ast/ast.h>
#include <errors/errors.h>


BuiltinNode::BuiltinNode (Builtin op, AstNode* arguments) {
	debug("Adding builtin node");
	this->type = nodeType_builtin;
  this->op = op;
  this->arguments = arguments;
}

AstNode* builtin_print_handler(BuiltinNode* node) {
	debug("PRINT called");
	if (node->arguments) {
		ValueNode* value;
		value = (ValueNode*) node->arguments->walk();
		
		if (value != NULL && value->type == nodeType_value) {
			std::cout << value->to_string() << std::endl;
			return value;
		}
		else {
			runtime_error("encountered bad branch", node);
			return NULL;
		}
	}
	else std::cout << std::endl;
	return NULL;
}

AstNode* BuiltinNode::walk() {
	debug("entering builtin handler");
	ValueNode* value;
	switch (this->op) {
		case PRINT:
			return builtin_print_handler(this);
		case TYPE:
			debug("TYPE called");
			value = (ValueNode*) this->arguments->walk();
			if (value == NULL) {
				runtime_error("problem in type() ", this);
				return NULL;
			}
			else
				return new StringNode(value->type_str());
			
			return NULL;
		default:
			fatal_error("Unknown builtin called");
			return NULL;
	}
}


