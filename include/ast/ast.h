////////////////////////////////////////////////////////////////////////////////
// THE SCOTCH-WARE LICENSE (Revision 0):
// <aaronryool@gmail.com> wrote this file. As long as you retain this notice you
// can do whatever you want with this stuff. If we meet some day, and you think
// this stuff is worth it, you can buy me a shot of scotch in return
////////////////////////////////////////////////////////////////////////////////

#ifndef __ast_h__
#define __ast_h__ 1

#include <map>
#include <list>
#include <config.h>

enum NodeType {
	nodeType_root,
	nodeType_value,
	nodeType_statement,
	nodeType_assignment,
	nodeType_symbol_reference,
	nodeType_math_operation,
	nodeType_math_eq_operation,
	nodeType_builtin,
	nodeType_function_call,
	nodeType_function_return,
	nodeType_if_statement,
	nodeType_loop_statement,
	nodeType_for_statement,
};

enum RootType {
	rootType_root,
	rootType_function,
	rootType_loop,
	rootType_if,
};

class AstNode {
	public:
		NodeType type; 		// set by the node constructors
		int linenumber;		// used for error messages
		int colnumber;		// ...
		virtual AstNode* walk();
	protected:
		AstNode();
		virtual ~AstNode();
};



class StatementNode: public AstNode {
	public:
		AstNode* left;	// this is where the instruction branch is
		StatementNode* right;	// this is where the next statement is
		
		StatementNode();
		~StatementNode();
		
		AstNode* walk();
};

#include <ast/value.h>

class RootNode: public AstNode {
	public:
		RootType root_type;				// defined by the creator of the node
		StatementNode* state_start;		// the begining of the statement list
		StatementNode* state_end;		// the end of our statement list
		std::map<std::string, ValueNode*>* symbol_table; // scope level variables
		std::list<ValueNode*>* value_table;	// values created stored for garbage collection
		
		RootNode();
		~RootNode();
		
		AstNode* walk();
		RootNode* attach_statement(AstNode* next);
};


#include <ast/branch.h>
#include <ast/function.h>
#include <builtins/builtins.h>
#include <math/math.h>
#include <ast/symbol.h>

extern RootNode* tree_root;
extern RootNode* current_scope;




#endif





