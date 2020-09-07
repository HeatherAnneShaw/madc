////////////////////////////////////////////////////////////////////////////////
// THE SCOTCH-WARE LICENSE (Revision 0):
// <aaronryool@gmail.com> wrote this file. As long as you retain this notice you
// can do whatever you want with this stuff. If we meet some day, and you think
// this stuff is worth it, you can buy me a shot of scotch in return
////////////////////////////////////////////////////////////////////////////////

#include <vector>

#include <ast/ast.h>
#include <errors/errors.h>


ListNode::ListNode (std::vector<AstNode*> v) {
	debug("List constructor");
	this->vtype = LIST;
	this->value = new std::vector<AstNode*>(v);
}

ListNode::~ListNode (void) {
	debug("List destructor");
	delete this->value;
}

std::string ListNode::to_string (void) {
	debug("List to_string");
	std::string items;
	ValueNode* v;
	for (auto i : *this->value) {
		if (i->type != nodeType_value)
			v = dynamic_cast<ValueNode*>(i->walk());
		else
			v = dynamic_cast<ValueNode*>(i);
		
		if (v == NULL)
			runtime_error("problem in list item", this);
		
		if (v->vtype == STRING)
			items += "\"" + v->to_string() + "\"" + ", ";
		else
			items += v->to_string() + ", ";
	}
	if (items.length()) {
		items.pop_back();
		items.pop_back();
	}
	return "list(["+items+"])";
}
std::string ListNode::type_str (void) {
	debug("List type_str");
	return "list";
}

bool is_equal(ValueNode* left, ValueNode* right) {
	debug("entering is_equal");
	// assumes that both types are the same
	bool ret;
	TruthNode* test = static_cast<TruthNode*>(left->oper(LEQ, right));
	ret = test->value;
	delete test;
	return ret;
}

ValueNode* ListNode::oper (Operation op, ValueNode* right) {
	debug("list operation: " + ast_operation_to_string(op));
	if (right != NULL && right->vtype == LIST) { // this is a binary operation with like types
		std::vector<AstNode*> swap(*this->value);
		std::vector<AstNode*>* left_list = this->value;
		std::vector<AstNode*>* right_list = static_cast<ListNode*>(right)->value;
		switch (op) {
			case ADD:
				swap.insert(swap.end(), right_list->begin(), right_list->end());
				return new ListNode (swap);
			case LEQ:
				if (left_list->size() != right_list->size())
					return new TruthNode (false);
				for (size_t i = 0; i < left_list->size(); i++) {
					ValueNode* lval = static_cast<ValueNode*>(left_list->at(i));
					ValueNode* rval = static_cast<ValueNode*>(right_list->at(i));
					if (lval->vtype != rval->vtype)
						return new TruthNode (false);
					if (! is_equal(lval, rval))
						return new TruthNode (false);
				}
				return new TruthNode (true);
			case LNEQ:
				if (left_list->size() == right_list->size())
					return new TruthNode (false);
				for (size_t i = 0; i < left_list->size(); i++) {
					ValueNode* lval = static_cast<ValueNode*>(left_list->at(i));
					ValueNode* rval = static_cast<ValueNode*>(right_list->at(i));
					if (lval->vtype == rval->vtype)
						return new TruthNode (false);
					if (is_equal(lval, rval))
						return new TruthNode (false);
				}
				return new TruthNode (true);
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
			default:
				runtime_error("Syntax error " + this->type_str(), this);
				return NULL;
		}
	}
	runtime_error("Syntax error " + this->type_str(), this);
	return NULL;
}

