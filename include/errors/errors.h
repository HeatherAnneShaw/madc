////////////////////////////////////////////////////////////////////////////////
// THE SCOTCH-WARE LICENSE (Revision 0):
// <aaronryool@gmail.com> wrote this file. As long as you retain this notice you
// can do whatever you want with this stuff. If we meet some day, and you think
// this stuff is worth it, you can buy me a shot of scotch in return
////////////////////////////////////////////////////////////////////////////////

#ifndef __errors_h__
#define __errors_h__ 1

#include <ast/ast.h>

void fatal_error(std::string msg);
void parse_error(std::string msg);
void runtime_error(std::string msg, AstNode* node);

extern bool error_flag;
extern int line_number;
extern int col_number;



#if __debug__ == true
	#define debug(x) __debug((x), __FILE__, __LINE__)
	void __debug(std::string msg, std::string file, int line);
#else
	#define debug(x) 
#endif






#endif
