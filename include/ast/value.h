////////////////////////////////////////////////////////////////////////////////
// THE SCOTCH-WARE LICENSE (Revision 0):
// <aaronryool@gmail.com> wrote this file. As long as you retain this notice you
// can do whatever you want with this stuff. If we meet some day, and you think
// this stuff is worth it, you can buy me a shot of scotch in return
////////////////////////////////////////////////////////////////////////////////

#ifndef __ast_value_h__
#define __ast_value_h__ 1


#include <ast/ast.h>

enum Operation {
	LAND, LOR, LEQ, LNEQ, LTEQ, GTEQ, LT, GT,
	
	BAND, BOR, BXOR, BNOT,
	
	ADD, SUB, MUL, DIV, MOD, POW,
	SUBSUB, ADDADD,
	
	ADDEQ, SUBEQ, POWEQ, MULEQ, DIVEQ, MODEQ,
	BANDEQ, BOREQ, BXOREQ,
};

std::string ast_operation_to_string(Operation op);

enum Type {
	NONE, TRUTH, INT, FLOAT, STRING, FUNCTION, LIST,
};


std::string ast_type_to_string(Type type);

// type nodes are based on this node type
class ValueNode: public AstNode {
	public:
	  int vtype;
	  ValueNode (void);
	  virtual ~ValueNode (void);
	  virtual ValueNode* walk (void);
	  virtual std::string to_string (void) { return NULL; }
	  virtual std::string type_str (void) { return NULL; }
	  virtual ValueNode* oper (Operation op, ValueNode* right);
};

class NoneNode: public ValueNode {
	public:
		NoneNode (void);
		std::string to_string (void);
		std::string type_str (void);
};



#include <ast/string.h>
#include <ast/list.h>
#include <ast/float.h>
#include <ast/int.h>
#include <ast/truth.h>

void free_value_walk (std::list<ValueNode*>* values);
ValueNode* duplicate_value(ValueNode* node);



#endif
