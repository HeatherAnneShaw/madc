////////////////////////////////////////////////////////////////////////////////
// THE SCOTCH-WARE LICENSE (Revision 0):
// <aaronryool@gmail.com> wrote this file. As long as you retain this notice you
// can do whatever you want with this stuff. If we meet some day, and you think
// this stuff is worth it, you can buy me a shot of scotch in return
////////////////////////////////////////////////////////////////////////////////

#include <string>
#include <fstream>

#include <parser.lex.h>

#include <errors/errors.h>

extern void mad_parser(std::string x);

int main (int argc, char** argv) {
	if (argc > 1){
		// pretty straightforward, open file -> lexer -> parser -> parse -> fin
		std::ifstream file(argv[1], std::ifstream::binary);
		if (! file)
			fatal_error("Could not open: " + std::string(argv[1]));
		else {
			yy::Lexer lexer(file);
			yy::parser parser(lexer);
			parser.parse();
			file.close();
		}
	}
	else {
		// send the interactive mode control characters,
		/// 03 = generates the root of the AST
		/// 05 = prompt the user for code
		yy::Lexer lexer("\x01\x05");
		yy::parser parser(lexer);
		parser.parse();
		// everything else happens in parser.ll
	}
}

