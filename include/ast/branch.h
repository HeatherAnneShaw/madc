////////////////////////////////////////////////////////////////////////////////
// THE SCOTCH-WARE LICENSE (Revision 0):
// <aaronryool@gmail.com> wrote this file. As long as you retain this notice you
// can do whatever you want with this stuff. If we meet some day, and you think
// this stuff is worth it, you can buy me a shot of scotch in return
////////////////////////////////////////////////////////////////////////////////

#ifndef __ast_branch_h__
#define __ast_branch_h__ 1

#include <ast/ast.h>

class IfNode: public AstNode {
	public:
		AstNode* condition;
		AstNode* if_branch;
		AstNode* else_branch;
		
		IfNode (AstNode* condition, AstNode* if_branch, AstNode* else_branch);
		AstNode* walk(void);
};

class LoopNode: public AstNode {
	public:
		AstNode* condition;
		RootNode* loop_branch;
		
		LoopNode (AstNode* condition, RootNode* loop_branch);
		AstNode* walk(void);
};

class ForNode: public AstNode {
	public:
		AstNode* initial;
		AstNode* condition;
		AstNode* count;
		RootNode* loop_branch;
		
		ForNode (AstNode* initial, AstNode* condition, AstNode* count, RootNode* loop_branch);
		AstNode* walk(void);
};


#endif

