////////////////////////////////////////////////////////////////////////////////
// THE SCOTCH-WARE LICENSE (Revision 0):
// <aaronryool@gmail.com> wrote this file. As long as you retain this notice you
// can do whatever you want with this stuff. If we meet some day, and you think
// this stuff is worth it, you can buy me a shot of scotch in return
////////////////////////////////////////////////////////////////////////////////


#include <cmath>

#include <ast/ast.h>
#include <errors/errors.h>


FloatNode::FloatNode (double v) {
	debug("Float constructor");
	this->vtype = FLOAT;
	this->value = v;
}

std::string FloatNode::to_string (void) {
	debug("Float to_string");
	return std::to_string(this->value);
}
std::string FloatNode::type_str (void) {
	debug("Float type_str");
	return "float";
}

ValueNode* FloatNode::oper (Operation op, ValueNode* right) {
	if (right != NULL && right->vtype == FLOAT) { // this is a binary operation with like types
		switch (op) {
			case ADD:
				return new FloatNode (this->value + static_cast<FloatNode*>(right)->value);
			case SUB:
				return new FloatNode (this->value - static_cast<FloatNode*>(right)->value);
			case MUL:
				return new FloatNode (this->value * static_cast<FloatNode*>(right)->value);
			case DIV:
				return new FloatNode (this->value / static_cast<FloatNode*>(right)->value);
			case MOD:
				return new FloatNode (fmod(this->value, static_cast<FloatNode*>(right)->value));
			case POW:
				return new FloatNode (pow(this->value, static_cast<FloatNode*>(right)->value));
			case LAND:
				return new TruthNode (this->value && static_cast<FloatNode*>(right)->value);
			case LOR:
				return new TruthNode (this->value || static_cast<FloatNode*>(right)->value);
			case LEQ:
				return new TruthNode (this->value == static_cast<FloatNode*>(right)->value);
			case LNEQ:
				return new TruthNode (this->value != static_cast<FloatNode*>(right)->value);
			case LTEQ:
				return new TruthNode (this->value <= static_cast<FloatNode*>(right)->value);
			case GTEQ:
				return new TruthNode (this->value >= static_cast<FloatNode*>(right)->value);
			case LT:
				return new TruthNode (this->value < static_cast<FloatNode*>(right)->value);
			case GT:
				return new TruthNode (this->value > static_cast<FloatNode*>(right)->value);
			default:
				runtime_error("Operation " + ast_operation_to_string(op) + " not supported by type: " + this->type_str(), this);
				return NULL;
		}
	}
	else if (right == NULL) { // this is a unary operation
		switch (op) {
			case SUB:
				return new FloatNode (- this->value);
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

