////////////////////////////////////////////////////////////////////////////////
// THE SCOTCH-WARE LICENSE (Revision 0):
// <aaronryool@gmail.com> wrote this file. As long as you retain this notice you
// can do whatever you want with this stuff. If we meet some day, and you think
// this stuff is worth it, you can buy me a shot of scotch in return
////////////////////////////////////////////////////////////////////////////////

#ifndef __ast_function_h__
#define __ast_function_h__ 1

#include <ast/ast.h>

class FunctionCallNode: public AstNode {
	public:
		std::string* name;
		std::vector<AstNode*>* arguments;
		
		FunctionCallNode (std::string name, std::vector<AstNode*> arguments);
		AstNode* walk (void);
};

class FunctionReturnNode: public AstNode {
	public:
		AstNode* expression;
		
		FunctionReturnNode (AstNode* expression);
		AstNode* walk (void);
};


class FunctionNode: public ValueNode {
	public:
		std::string* name;
		std::list<std::tuple<std::string, Type>>* arguments;
		Type return_type;
		AstNode* function_branch;
		int recursion;
		
		FunctionNode (std::string name, std::list<std::tuple<std::string, Type>> arguments,
			Type return_type, AstNode* function_branch);
		std::string to_string (void);
		std::string type_str (void);
};



#endif


