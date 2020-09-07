////////////////////////////////////////////////////////////////////////////////
// THE SCOTCH-WARE LICENSE (Revision 0):
// <aaronryool@gmail.com> wrote this file. As long as you retain this notice you
// can do whatever you want with this stuff. If we meet some day, and you think
// this stuff is worth it, you can buy me a shot of scotch in return
////////////////////////////////////////////////////////////////////////////////

#ifndef __math_h__
#define __math_h__ 1

#include <ast/ast.h>


class MathNode: public AstNode {
	public:
		AstNode* left;
		AstNode* right;
		Operation op;
		
		MathNode (Operation op, AstNode* left, AstNode* right);
		ValueNode* walk (void);
};




#endif

