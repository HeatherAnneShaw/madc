////////////////////////////////////////////////////////////////////////////////
// THE SCOTCH-WARE LICENSE (Revision 0):
// <aaronryool@gmail.com> wrote this file. As long as you retain this notice you
// can do whatever you want with this stuff. If we meet some day, and you think
// this stuff is worth it, you can buy me a shot of scotch in return
////////////////////////////////////////////////////////////////////////////////

#include <ast/ast.h>
#include <errors/errors.h>


TruthNode::TruthNode (bool v) {
	debug("Truth constructor");
	this->vtype = TRUTH;
	this->value = v;
}

std::string TruthNode::to_string (void) {
	debug("Truth to_string");
	if (this->value)
		return "truth(true)";
	else
		return "truth(false)";
}
std::string TruthNode::type_str (void) {
	debug("Truth type_str");
	return "truth";
}



ValueNode* TruthNode::oper (Operation op, ValueNode* right) {
	if (right != NULL && right->vtype == TRUTH) { // this is a binary operation with like types
		switch (op) {
			case ADD:
				return new TruthNode (this->value + static_cast<TruthNode*>(right)->value);
			case SUB:
				return new TruthNode (this->value - static_cast<TruthNode*>(right)->value);
			case MUL:
				// error: ‘*’ in boolean context, suggest ‘&&’ instead
				return new TruthNode (this->value && static_cast<TruthNode*>(right)->value);
			case DIV:
				return new TruthNode (this->value / static_cast<TruthNode*>(right)->value);
			case MOD:
				return new TruthNode (this->value % static_cast<TruthNode*>(right)->value);
			case BAND:
				return new TruthNode (this->value & static_cast<TruthNode*>(right)->value);
			case BOR:
				return new TruthNode (this->value | static_cast<TruthNode*>(right)->value);
			case BXOR:
				return new TruthNode (this->value ^ static_cast<TruthNode*>(right)->value);
			case LAND:
				return new TruthNode (this->value && static_cast<TruthNode*>(right)->value);
			case LOR:
				return new TruthNode (this->value || static_cast<TruthNode*>(right)->value);
			case LEQ:
				return new TruthNode (this->value == static_cast<TruthNode*>(right)->value);
			case LNEQ:
				return new TruthNode (this->value != static_cast<TruthNode*>(right)->value);
			case LTEQ:
				return new TruthNode (this->value <= static_cast<TruthNode*>(right)->value);
			case GTEQ:
				return new TruthNode (this->value >= static_cast<TruthNode*>(right)->value);
			case LT:
				return new TruthNode (this->value < static_cast<TruthNode*>(right)->value);
			case GT:
				return new TruthNode (this->value > static_cast<TruthNode*>(right)->value);
			default:
				runtime_error("Operation " + ast_operation_to_string(op) + " not supported by type: " + this->type_str(), this);
				return NULL;
		}
	}
	else if (right == NULL) { // this is a unary operation
		switch (op) {
			case SUB:
				return new TruthNode (- this->value);
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

