////////////////////////////////////////////////////////////////////////////////
// THE SCOTCH-WARE LICENSE (Revision 0):
// <aaronryool@gmail.com> wrote this file. As long as you retain this notice you
// can do whatever you want with this stuff. If we meet some day, and you think
// this stuff is worth it, you can buy me a shot of scotch in return
////////////////////////////////////////////////////////////////////////////////

#ifndef __builtins_h__
#define __builtins_h__ 1

#include <ast/ast.h>

enum Builtin {
	PRINT, TYPE, EXIT
};

class BuiltinNode: public AstNode {
	public:
		Builtin op;
		AstNode* arguments;
		
		BuiltinNode (Builtin op, AstNode* arguments);
		AstNode* walk();
};



#endif

