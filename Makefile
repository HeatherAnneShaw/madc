
INCLUDE		:= ./include
SRCDIR		:= ./src
OBJDIR		:= ./obj
BUILD			:= ./build

OBJ				:= $(addprefix $(OBJDIR)/, \
							main.o \
							ast.o \
							ast_value.o \
							ast_string.o \
							ast_list.o \
							ast_float.o \
							ast_int.o \
							ast_truth.o \
							ast_symbol.o \
							ast_function.o \
							ast_branch.o \
							math.o \
							errors.o \
							builtins.o \
							parser.lex.o \
							parser.yacc.o \
							)
LIBS 			:= -lreflex
APPNAME		:= parser

CXX 			:= g++
CXXFLAGS	:= -I$(INCLUDE) -std=c++17 -pedantic-errors -Wall -Wextra -Werror
#FLEXFLAGS  := -d -p
BISONFLAGS := -Wcounterexamples -v

all: main parser ast errors builtins math
	$(CXX) $(CXXFLAGS) -o $(BUILD)/$(APPNAME) $(OBJ) $(LIBS)

main: parser
	$(CXX) $(CXXFLAGS) -c $(SRCDIR)/$@.cc -o $(OBJDIR)/$@.o

parser: ast errors
	reflex $(FLEXFLAGS) --header-file=$(INCLUDE)/$@.lex.h -o $(SRCDIR)/$@.lex.cc $(SRCDIR)/$@.l
	bison ${BISONFLAGS} --defines=$(INCLUDE)/$@.yacc.h -o $(SRCDIR)/$@.yacc.cc $(SRCDIR)/$@.y
	$(CXX) $(CXXFLAGS) -c $(SRCDIR)/$@.yacc.cc -o $(OBJDIR)/$@.yacc.o
	$(CXX) $(CXXFLAGS) -c $(SRCDIR)/$@.lex.cc -o $(OBJDIR)/$@.lex.o

ast: errors
	$(CXX) $(CXXFLAGS) -c $(SRCDIR)/$@/ast.cc -o $(OBJDIR)/ast.o
	$(CXX) $(CXXFLAGS) -c $(SRCDIR)/$@/value.cc -o $(OBJDIR)/$@_value.o
	$(CXX) $(CXXFLAGS) -c $(SRCDIR)/$@/string.cc -o $(OBJDIR)/$@_string.o
	$(CXX) $(CXXFLAGS) -c $(SRCDIR)/$@/list.cc -o $(OBJDIR)/$@_list.o
	$(CXX) $(CXXFLAGS) -c $(SRCDIR)/$@/float.cc -o $(OBJDIR)/$@_float.o
	$(CXX) $(CXXFLAGS) -c $(SRCDIR)/$@/int.cc -o $(OBJDIR)/$@_int.o
	$(CXX) $(CXXFLAGS) -c $(SRCDIR)/$@/truth.cc -o $(OBJDIR)/$@_truth.o
	$(CXX) $(CXXFLAGS) -c $(SRCDIR)/$@/symbol.cc -o $(OBJDIR)/$@_symbol.o
	$(CXX) $(CXXFLAGS) -c $(SRCDIR)/$@/function.cc -o $(OBJDIR)/$@_function.o
	$(CXX) $(CXXFLAGS) -c $(SRCDIR)/$@/branch.cc -o $(OBJDIR)/$@_branch.o


errors:
	$(CXX) $(CXXFLAGS) -c $(SRCDIR)/$@/errors.cc -o $(OBJDIR)/errors.o

builtins:
	$(CXX) $(CXXFLAGS) -c $(SRCDIR)/$@/builtins.cc -o $(OBJDIR)/builtins.o

math:
	$(CXX) $(CXXFLAGS) -c $(SRCDIR)/$@/math.cc -o $(OBJDIR)/math.o


clean:
	rm -f $(BUILD)/* $(OBJDIR)/*

