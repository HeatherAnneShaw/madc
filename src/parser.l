%top{
////////////////////////////////////////////////////////////////////////////////
// THE SCOTCH-WARE LICENSE (Revision 0):
// <aaronryool@gmail.com> wrote this file. As long as you retain this notice you
// can do whatever you want with this stuff. If we meet some day, and you think
// this stuff is worth it, you can buy me a shot of scotch in return
////////////////////////////////////////////////////////////////////////////////

#include <boost/algorithm/string/replace.hpp>

#include <parser.yacc.h>
#include <config.h>

}

%option bison-complete
%option bison-cc-namespace=yy
%option bison-cc-parser=parser
%option namespace=yy
%option lexer=Lexer
%option lex=yylex

%option exception="yy::parser::syntax_error(\"Unknown token.\")"
%option yylineno

%class{
	int depth;
	void include_file()
	{
		depth++;
		if (depth > MAX_INCLUDE_DEPTH)
			exit(EXIT_FAILURE);
		
		std::string name;
		size_t fq = str().find('"') + 1;
		size_t sq = str().find_last_of('"');
		name = str().substr(fq, (sq - fq));
		
		FILE *fd = fopen(name.c_str(), "r");
		if (! fd)
			exit(EXIT_FAILURE);
		else
			push_matcher(new_matcher(fd));
	}
	bool end_of_file()
	{
		if (depth == 0)
			return true;	// return true: no more input to read
		fclose(in());		// close the file descriptor
		pop_matcher();		// delete current matcher, pop matcher
		depth--;
		return false;		// return false: continue reading
	}
}
%init{
	depth = 0;
}

%%

^\h*import\h*\".*?\"			{ LC_UPDATE; include_file(); }
<<EOF>>										{ if (end_of_file()) return 0; }

\x01 {
	return yy::parser::make_IROOT();
}


\x02 {
	return yy::parser::make_ISTART();
}

\x05	{
	std::string input;
	std::cout << ">> ";
	std::getline(std::cin, input);
	input = "\x02" + input + "\x03\x05";
	push_matcher(new_matcher(input));
}

\x03	{
	return yy::parser::make_IRUN();
}


("//"|"#").*		// ignore comments
"/*"(.|\n)*?"*/"	// ignore multiline comments
"''"(.|\n)*?"''"	// ignore documentation comments
[ \t\r\n]			// ignore whitespace



\"([^\\\"]|\\.)*\" {
	LC_UPDATE;
	std::string st = str();
	unsigned first = st.find('"');
	unsigned last = st.find_last_of('"');
	st = st.substr(first+1,last-first-1);
	boost::replace_all(st, "\\n", "\n");
	boost::replace_all(st, "\\r", "\r");
	boost::replace_all(st, "\\t", "\t");
	boost::replace_all(st, "\\\"", "\"");
	boost::replace_all(st, "\\'", "\'");
	return yy::parser::make_STRING(st);
}


(not)|"!" 			{ LC_UPDATE; return yy::parser::make_NOT(); }

(exit)			 	{ LC_UPDATE; return yy::parser::make_EXIT(); }
(print)				{ LC_UPDATE; return yy::parser::make_PRINT(); }
(type)				{ LC_UPDATE; return yy::parser::make_TYPE(); }

(none)				{ LC_UPDATE; return yy::parser::make_TYPE_NONE(); }
(float)				{ LC_UPDATE; return yy::parser::make_TYPE_FLOAT(); }
(int)				{ LC_UPDATE; return yy::parser::make_TYPE_INT(); }
(str)				{ LC_UPDATE; return yy::parser::make_TYPE_STRING(); }
(truth)				{ LC_UPDATE; return yy::parser::make_TYPE_TRUTH(); }
(list)				{ LC_UPDATE; return yy::parser::make_TYPE_LIST(); }
(true)				{ LC_UPDATE; return yy::parser::make_TRUE(); }
(false)				{ LC_UPDATE; return yy::parser::make_FALSE(); }

("->")|(return)		{ LC_UPDATE; return yy::parser::make_RETURNS(); }
("?")|(if)			{ LC_UPDATE; return yy::parser::make_IF(); }
(else)				{ LC_UPDATE; return yy::parser::make_ELSE(); }
(while)				{ LC_UPDATE; return yy::parser::make_WHILE(); }
(for)				{ LC_UPDATE; return yy::parser::make_FOR(); }
(and)|"&&"			{ LC_UPDATE; return yy::parser::make_LAND(); }
(or)|"||"			{ LC_UPDATE; return yy::parser::make_LOR(); }
((is)[ ]+)|"=="		{ LC_UPDATE; return yy::parser::make_LEQ(); }
((is)[ ]+(not))|(isnt)|"!="	{ LC_UPDATE; return yy::parser::make_LNEQ();}

[0-9]+						{ LC_UPDATE; return yy::parser::make_INT(atoi(text())); }
[0-9]+\.[0-9]+				{ LC_UPDATE; return yy::parser::make_FLOAT(atof(text())); }
0(x|X)[0-9a-fA-F]+			{ LC_UPDATE; return yy::parser::make_INT(atof(text())); }

[a-zA-Z_]([a-zA-Z_]|[0-9])* { LC_UPDATE; return yy::parser::make_VAR(str()); }


"<="				{ LC_UPDATE; return yy::parser::make_LTEQ(); }
">="				{ LC_UPDATE; return yy::parser::make_GTEQ(); }
"**"				{ LC_UPDATE; return yy::parser::make_POW(); }
"+="				{ LC_UPDATE; return yy::parser::make_ADDEQ(); }
"-="				{ LC_UPDATE; return yy::parser::make_SUBEQ(); }
"**="				{ LC_UPDATE; return yy::parser::make_POWEQ(); }
"*="				{ LC_UPDATE; return yy::parser::make_MULEQ(); }
"/="				{ LC_UPDATE; return yy::parser::make_DIVEQ(); }
"%="				{ LC_UPDATE; return yy::parser::make_MODEQ(); }
"&="				{ LC_UPDATE; return yy::parser::make_BANDEQ(); }
"|="				{ LC_UPDATE; return yy::parser::make_BOREQ(); }
"^="				{ LC_UPDATE; return yy::parser::make_BXOREQ(); }

"--"				{ LC_UPDATE; return yy::parser::make_SUBSUB(); }
"++"				{ LC_UPDATE; return yy::parser::make_ADDADD(); }


[&|^><=)(*/%+-}{:,]	{ LC_UPDATE; return yy::parser::symbol_type(chr()); }

;+	{ // catches most extra ';'
	LC_UPDATE; 
	return yy::parser::symbol_type(';');
}


%%





