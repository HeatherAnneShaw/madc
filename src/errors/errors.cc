////////////////////////////////////////////////////////////////////////////////
// THE SCOTCH-WARE LICENSE (Revision 0):
// <aaronryool@gmail.com> wrote this file. As long as you retain this notice you
// can do whatever you want with this stuff. If we meet some day, and you think
// this stuff is worth it, you can buy me a shot of scotch in return
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <errors/errors.h>
#include <ast/ast.h>

#ifdef __debug__
void __debug(std::string msg, std::string file, int line) {
		std::cout << "Debug: " << msg <<" -> "<< file << " at "<< line << std::endl;
}
#endif

bool error_flag = false;  // flipped to stop walk()
int line_number;	// handled by lex for us
int col_number;	// handled by lex for us
void runtime_error(std::string msg, AstNode* node) {
	debug("entering runtime_error");
	error_flag = true;
	if (node != NULL)
		switch (node->type) {
			// I cleared this out because I plan to go with an exception based model,
			// I just havent yet because I have more fun things to work on right now
			default:
				std::cerr << "Runtime Error at line "<< node->linenumber << " column " << node->colnumber << ": " << msg << std::endl;
				return;
			}
	else
		std::cerr << "Runtime Error:" << msg << std::endl;
}

void fatal_error(std::string msg) {
	std::cerr << "Fatal Error: " << msg << std::endl;
	exit(-1);
}


void parse_error(std::string msg) {
	std::cerr << "Parse Error at  line " << line_number << " column " << col_number << ": " << msg << std::endl;
}



