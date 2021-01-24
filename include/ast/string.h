////////////////////////////////////////////////////////////////////////////////
// THE SCOTCH-WARE LICENSE (Revision 0):
// <aaronryool@gmail.com> wrote this file. As long as you retain this notice you
// can do whatever you want with this stuff. If we meet some day, and you think
// this stuff is worth it, you can buy me a shot of scotch in return
////////////////////////////////////////////////////////////////////////////////

#ifndef __ast_string_h__
#define __ast_string_h__ 1

#include <ast/value.h>


class StringNode: public ValueNode {
  public:
  	std::string* value;
  	StringNode (std::string v);
  	~StringNode (void);
	  std::string to_string (void);
		std::string type_str (void);
		ValueNode* oper (Operation op, ValueNode* right);
};


#endif
