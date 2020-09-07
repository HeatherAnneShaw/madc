////////////////////////////////////////////////////////////////////////////////
// THE SCOTCH-WARE LICENSE (Revision 0):
// <aaronryool@gmail.com> wrote this file. As long as you retain this notice you
// can do whatever you want with this stuff. If we meet some day, and you think
// this stuff is worth it, you can buy me a shot of scotch in return
////////////////////////////////////////////////////////////////////////////////

#include <string>

#include <ast/ast.h>
#include <errors/errors.h>


StringNode::StringNode (std::string v) {
	debug("String constructor");
	this->vtype = STRING;
	this->value = new std::string(v);
}

StringNode::~StringNode (void) {
	debug("String destructor");
	delete this->value;
}

std::string StringNode::to_string (void) {
	debug("String to_string");
	return *this->value;
}
std::string StringNode::type_str (void) {
	debug("String type_str");
	return "string";
}

ValueNode* StringNode::oper (Operation op, ValueNode* right) {
	if (right != NULL && right->vtype == STRING) { // this is a binary operation with like types
		std::string swap;
		std::vector<AstNode*> swap_list;
		std::string right_str;
		size_t npos = std::string::npos;
		switch (op) {
			case ADD:
				return new StringNode (*static_cast<StringNode*>(this)->value + *static_cast<StringNode*>(right)->value);
			case SUB:
				swap = *static_cast<StringNode*>(this)->value;
				right_str = *static_cast<StringNode*>(right)->value;
				while ((npos  = swap.find(right_str)) != std::string::npos)
					swap.erase(npos, right_str.length());
				return new StringNode (swap);
			case DIV:
				swap = *static_cast<StringNode*>(this)->value;
				right_str = *static_cast<StringNode*>(right)->value;
				while ((npos  = swap.find(right_str)) != std::string::npos) {
					swap_list.push_back(new StringNode(swap.substr(0, npos)));
					swap.erase(0, right_str.length() + npos);
				}
				swap_list.push_back(new StringNode(swap));
				return new ListNode (swap_list);
			case LEQ:
				return new TruthNode (*static_cast<StringNode*>(this)->value == *static_cast<StringNode*>(right)->value);
			case LNEQ:
				return new TruthNode (*static_cast<StringNode*>(this)->value != *static_cast<StringNode*>(right)->value);
			default:
				runtime_error("Operation " + ast_operation_to_string(op) + " not supported by type: " + this->type_str(), this);
				return NULL;
		}
	}
	else if (right == NULL) { // this is a unary operation
		runtime_error("Unary operation " + ast_operation_to_string(op) + " not supported by type: " + this->type_str(), this);
		return NULL;
	}
	else {
		std::string swap;
		switch (op) {
			case MUL:
				if (right != NULL && right->vtype == INT) {
					for (int i = static_cast<IntNode*>(right)->value; i > 0; i--)
						swap += *static_cast<StringNode*>(this)->value;
					return new StringNode (swap);
				}
				break;
			default:
				runtime_error("Syntax error " + this->type_str(), this);
				return NULL;
		}
	}
	runtime_error("Syntax error " + this->type_str(), this);
	return NULL;
}

