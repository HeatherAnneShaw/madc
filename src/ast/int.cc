////////////////////////////////////////////////////////////////////////////////
// THE SCOTCH-WARE LICENSE (Revision 0):
// <aaronryool@gmail.com> wrote this file. As long as you retain this notice you
// can do whatever you want with this stuff. If we meet some day, and you think
// this stuff is worth it, you can buy me a shot of scotch in return
////////////////////////////////////////////////////////////////////////////////

#include <cmath>

#include <ast/ast.h>
#include <errors/errors.h>


IntNode::IntNode (int v) {
	debug("Int constructor");
	this->vtype = INT;
	this->value = v;
}

std::string IntNode::to_string (void) {
	debug("Int to_string");
	return std::to_string(this->value);
}
std::string IntNode::type_str (void) {
	debug("Int type_str");
	return "int";
}

ValueNode* IntNode::oper (Operation op, ValueNode* right) {
	if (right != NULL && right->vtype == INT) { // this is a binary operation with like types
		switch (op) {
			case ADD:
				return new IntNode (this->value + static_cast<IntNode*>(right)->value);
			case SUB:
				return new IntNode (this->value - static_cast<IntNode*>(right)->value);
			case MUL:
				return new IntNode (this->value * static_cast<IntNode*>(right)->value);
			case DIV:
				if (static_cast<IntNode*>(right)->value != 0)
					return new IntNode (this->value / static_cast<IntNode*>(right)->value);
				else {
					runtime_error("Cannot divide by zero", this);
					return NULL;
				}
			case MOD:
				return new IntNode (this->value % static_cast<IntNode*>(right)->value);
			case POW:
				return new IntNode (pow(this->value, static_cast<IntNode*>(right)->value));
			case BAND:
				return new IntNode (this->value & static_cast<IntNode*>(right)->value);
			case BOR:
				return new IntNode (this->value | static_cast<IntNode*>(right)->value);
			case BXOR:
				return new IntNode (this->value ^ static_cast<IntNode*>(right)->value);
			case LAND:
				return new TruthNode (this->value && static_cast<IntNode*>(right)->value);
			case LOR:
				return new TruthNode (this->value || static_cast<IntNode*>(right)->value);
			case LEQ:
				return new TruthNode (this->value == static_cast<IntNode*>(right)->value);
			case LNEQ:
				return new TruthNode (this->value != static_cast<IntNode*>(right)->value);
			case LTEQ:
				return new TruthNode (this->value <= static_cast<IntNode*>(right)->value);
			case GTEQ:
				return new TruthNode (this->value >= static_cast<IntNode*>(right)->value);
			case LT:
				return new TruthNode (this->value < static_cast<IntNode*>(right)->value);
			case GT:
				return new TruthNode (this->value > static_cast<IntNode*>(right)->value);
			default:
				runtime_error("Operation " + ast_operation_to_string(op) + " not supported by type: " + this->type_str(), this);
				return NULL;
		}
	}
	else if (right == NULL) { // this is a unary operation
		switch (op) {
			case SUB:
				return new IntNode (- this->value);
			case BNOT:
				return new TruthNode (! this->value);
			default:
				runtime_error("Operation " + ast_operation_to_string(op) + " not supported by type: " + this->type_str(), this);
				return NULL;
		}
	}
	else
		runtime_error("Mixed types not supported by " + this->type_str() + " operations", this);
	return NULL;
}

