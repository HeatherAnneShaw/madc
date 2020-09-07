////////////////////////////////////////////////////////////////////////////////
// THE SCOTCH-WARE LICENSE (Revision 0):
// <aaronryool@gmail.com> wrote this file. As long as you retain this notice you
// can do whatever you want with this stuff. If we meet some day, and you think
// this stuff is worth it, you can buy me a shot of scotch in return
////////////////////////////////////////////////////////////////////////////////


#include <ast/ast.h>
#include <errors/errors.h>


MathNode::MathNode (Operation op, AstNode* left, AstNode* right) {
	debug("Adding math node");
  this->type = nodeType_math_operation;
  this->left = left;
  this->right = right;
  this->op = op;
}



ValueNode* MathNode::walk (void) {
	debug("entering math handler");
	ValueNode* left_ret;
	ValueNode* right_ret;
	
	if (this->right != NULL) right_ret = dynamic_cast<ValueNode*>(this->right->walk());
	else {
		runtime_error("Improper right operand", this);
		return NULL;
	}
	
	if (this->left == NULL && right_ret->type == nodeType_value) {
		return right_ret->oper(this->op, NULL);
	}
	else {
		// this is a binary operation, left gets precedence
		if (this->left != NULL) left_ret = dynamic_cast<ValueNode*>(this->left->walk());
		else {
			runtime_error("Improper left operand to binary operation", this);
			return NULL;
		}
		if (left_ret == NULL || right_ret == NULL) {
			runtime_error("problem in math from operand branch", this);
			return NULL;
		}
		return left_ret->oper(this->op, right_ret);
	}
	
	return NULL;
}



