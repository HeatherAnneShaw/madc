////////////////////////////////////////////////////////////////////////////////
// THE SCOTCH-WARE LICENSE (Revision 0):
// <aaronryool@gmail.com> wrote this file. As long as you retain this notice you
// can do whatever you want with this stuff. If we meet some day, and you think
// this stuff is worth it, you can buy me a shot of scotch in return
////////////////////////////////////////////////////////////////////////////////

#include <ast/ast.h>
#include <errors/errors.h>

IfNode::IfNode (AstNode* condition, AstNode* if_branch, AstNode* else_branch) {
	debug("if node constructor");
	this->type = nodeType_if_statement;
	this->condition = condition;
	this->if_branch = if_branch;
	this->else_branch = else_branch;
	if (if_branch->type == nodeType_root)
		((RootNode*) if_branch)->root_type = rootType_if;
	if (else_branch->type == nodeType_root)
		((RootNode*) else_branch)->root_type = rootType_if;
}

ForNode::ForNode (AstNode* initial, AstNode* condition, AstNode* count, RootNode* loop_branch) {
	this->type = nodeType_for_statement;
	this->initial = initial;
	this->condition = condition;
	this->count = count;
	this->loop_branch = loop_branch;
	if (loop_branch->type == nodeType_root)
		((RootNode*) loop_branch)->root_type = rootType_loop;
}

LoopNode::LoopNode (AstNode* condition, RootNode* loop_branch) {
	debug("loop node constructor");
	this->type = nodeType_loop_statement;
	this->condition = condition;
	this->loop_branch = loop_branch;
	if (loop_branch->type == nodeType_root)
		((RootNode*) loop_branch)->root_type = rootType_loop;
}


AstNode* IfNode::walk (void) {
	TruthNode* condition_ret	= (TruthNode*) this->condition->walk();
	debug("resolving if condition");
	if (condition_ret == NULL) {
		runtime_error("Couldn't resolve conditional in if statement", this);
		return NULL;
	}
	if (condition_ret->value) {
		debug("entering if branch");
		return this->if_branch->walk();
	}
	else if (this->else_branch != NULL) {
		debug("entering else branch");
		return this->else_branch->walk();
	}
	return NULL;
}

AstNode* LoopNode::walk (void) {
	this->loop_branch->symbol_table = current_scope->symbol_table;
	while (true) {
		TruthNode* condition_ret	= (TruthNode*) this->condition->walk();
		debug("resolving loop condition");
		if (condition_ret == NULL) {
			runtime_error("Couldn't resolve conditional in loop statement", this);
			return NULL;
		}
		if (condition_ret->value) {
			debug("entering loop branch");
			if (this->loop_branch->walk() == NULL) {
				runtime_error("problem in loop", this);
				return NULL;
			}
			if (this->loop_branch->type == nodeType_root)
				free_value_walk(this->loop_branch->value_table);
		}
		else
			break;
	}
	return NULL;
}


AstNode* ForNode::walk (void) {
	this->loop_branch->symbol_table = current_scope->symbol_table;
	if (this->initial->walk() == NULL) {
		runtime_error("problem in initial", this);
		return NULL;
	}
	while (true) {
		TruthNode* condition_ret = (TruthNode*) this->condition->walk();
		debug("resolving loop condition");
		if (condition_ret == NULL) {
			runtime_error("Couldn't resolve conditional in loop statement", this);
			return NULL;
		}
		if (condition_ret->value) {
			debug("entering loop branch");
			this->loop_branch->walk();
			if (this->loop_branch->type == nodeType_root)
				free_value_walk(this->loop_branch->value_table);
			if (this->count->walk() == NULL) {
				runtime_error("problem in counter resolution", this);
				return NULL;
			}
		}
		else
			break;
	}
	return NULL;
}








