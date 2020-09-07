////////////////////////////////////////////////////////////////////////////////
// THE SCOTCH-WARE LICENSE (Revision 0):
// <aaronryool@gmail.com> wrote this file. As long as you retain this notice you
// can do whatever you want with this stuff. If we meet some day, and you think
// this stuff is worth it, you can buy me a shot of scotch in return
////////////////////////////////////////////////////////////////////////////////

#ifndef __ast_symbol_h___
#define __ast_symbol_h___ 1

#include <ast/ast.h>

class SymbolReference: public AstNode {
	public:
		std::string* name;
		
		SymbolReference (std::string name);
		~SymbolReference (void);
		AstNode* walk(void);
};

class AssignmentNode: public AstNode {
	public:
		std::string* name;
		AstNode* resolve_tree;
		
		AssignmentNode (std::string name, AstNode* resolve_tree);
		~AssignmentNode (void);
		AstNode* walk(void);
};




#endif

