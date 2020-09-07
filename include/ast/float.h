////////////////////////////////////////////////////////////////////////////////
// THE SCOTCH-WARE LICENSE (Revision 0):
// <aaronryool@gmail.com> wrote this file. As long as you retain this notice you
// can do whatever you want with this stuff. If we meet some day, and you think
// this stuff is worth it, you can buy me a shot of scotch in return
////////////////////////////////////////////////////////////////////////////////

#ifndef __ast_float_h__
#define __ast_float_h__ 1


#include <ast/value.h>


class FloatNode: public ValueNode {
	public:
	  double value;
	  FloatNode (double v);
	  std::string to_string (void);
		std::string type_str (void);
		ValueNode* oper (Operation op, ValueNode* right);
};





#endif
