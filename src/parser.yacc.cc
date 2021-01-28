// A Bison parser, made by GNU Bison 3.7.4.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2020 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.



// First part of user prologue.
#line 19 "./src/parser.y"

  
  #include <parser.lex.h>
  
  #undef yylex
  #define yylex lexer.yylex  // Within bison's parse() we should invoke lexer.yylex(), not the global yylex()


#line 50 "src/parser.yacc.cc"


#include "parser.yacc.h"




#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif


// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif



// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yy_stack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

#line 11 "./src/parser.y"
namespace yy {
#line 129 "src/parser.yacc.cc"

  /// Build a parser object.
  parser::parser (yy::Lexer &lexer_yyarg)
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      lexer (lexer_yyarg)
  {}

  parser::~parser ()
  {}

  parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------------.
  | symbol kinds.  |
  `---------------*/



  // by_state.
  parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  parser::symbol_kind_type
  parser::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

  parser::stack_symbol_type::stack_symbol_type ()
  {}

  parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_loop_statement: // loop_statement
        value.YY_MOVE_OR_COPY< AstNode* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_function_expression: // function_expression
        value.YY_MOVE_OR_COPY< FunctionCallNode* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_function_statement: // function_statement
        value.YY_MOVE_OR_COPY< FunctionNode* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_if_statement: // if_statement
        value.YY_MOVE_OR_COPY< IfNode* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_list_expression: // list_expression
        value.YY_MOVE_OR_COPY< ListNode* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_block: // block
        value.YY_MOVE_OR_COPY< RootNode* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_type_statement: // type_statement
        value.YY_MOVE_OR_COPY< Type > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_TRUTH: // TRUTH
        value.YY_MOVE_OR_COPY< bool > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_FLOAT: // FLOAT
        value.YY_MOVE_OR_COPY< double > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INT: // INT
        value.YY_MOVE_OR_COPY< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_input_list: // input_list
        value.YY_MOVE_OR_COPY< std::list<std::tuple<std::string, Type>> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_VAR: // VAR
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expression_list: // expression_list
        value.YY_MOVE_OR_COPY< std::vector<AstNode*> > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s)
  {
    switch (that.kind ())
    {
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_loop_statement: // loop_statement
        value.move< AstNode* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_function_expression: // function_expression
        value.move< FunctionCallNode* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_function_statement: // function_statement
        value.move< FunctionNode* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_if_statement: // if_statement
        value.move< IfNode* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_list_expression: // list_expression
        value.move< ListNode* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_block: // block
        value.move< RootNode* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_type_statement: // type_statement
        value.move< Type > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_TRUTH: // TRUTH
        value.move< bool > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_FLOAT: // FLOAT
        value.move< double > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INT: // INT
        value.move< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_input_list: // input_list
        value.move< std::list<std::tuple<std::string, Type>> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_VAR: // VAR
        value.move< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expression_list: // expression_list
        value.move< std::vector<AstNode*> > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_loop_statement: // loop_statement
        value.copy< AstNode* > (that.value);
        break;

      case symbol_kind::S_function_expression: // function_expression
        value.copy< FunctionCallNode* > (that.value);
        break;

      case symbol_kind::S_function_statement: // function_statement
        value.copy< FunctionNode* > (that.value);
        break;

      case symbol_kind::S_if_statement: // if_statement
        value.copy< IfNode* > (that.value);
        break;

      case symbol_kind::S_list_expression: // list_expression
        value.copy< ListNode* > (that.value);
        break;

      case symbol_kind::S_block: // block
        value.copy< RootNode* > (that.value);
        break;

      case symbol_kind::S_type_statement: // type_statement
        value.copy< Type > (that.value);
        break;

      case symbol_kind::S_TRUTH: // TRUTH
        value.copy< bool > (that.value);
        break;

      case symbol_kind::S_FLOAT: // FLOAT
        value.copy< double > (that.value);
        break;

      case symbol_kind::S_INT: // INT
        value.copy< int > (that.value);
        break;

      case symbol_kind::S_input_list: // input_list
        value.copy< std::list<std::tuple<std::string, Type>> > (that.value);
        break;

      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_VAR: // VAR
        value.copy< std::string > (that.value);
        break;

      case symbol_kind::S_expression_list: // expression_list
        value.copy< std::vector<AstNode*> > (that.value);
        break;

      default:
        break;
    }

    return *this;
  }

  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_loop_statement: // loop_statement
        value.move< AstNode* > (that.value);
        break;

      case symbol_kind::S_function_expression: // function_expression
        value.move< FunctionCallNode* > (that.value);
        break;

      case symbol_kind::S_function_statement: // function_statement
        value.move< FunctionNode* > (that.value);
        break;

      case symbol_kind::S_if_statement: // if_statement
        value.move< IfNode* > (that.value);
        break;

      case symbol_kind::S_list_expression: // list_expression
        value.move< ListNode* > (that.value);
        break;

      case symbol_kind::S_block: // block
        value.move< RootNode* > (that.value);
        break;

      case symbol_kind::S_type_statement: // type_statement
        value.move< Type > (that.value);
        break;

      case symbol_kind::S_TRUTH: // TRUTH
        value.move< bool > (that.value);
        break;

      case symbol_kind::S_FLOAT: // FLOAT
        value.move< double > (that.value);
        break;

      case symbol_kind::S_INT: // INT
        value.move< int > (that.value);
        break;

      case symbol_kind::S_input_list: // input_list
        value.move< std::list<std::tuple<std::string, Type>> > (that.value);
        break;

      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_VAR: // VAR
        value.move< std::string > (that.value);
        break;

      case symbol_kind::S_expression_list: // expression_list
        value.move< std::vector<AstNode*> > (that.value);
        break;

      default:
        break;
    }

    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  parser::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    if (yysym.empty ())
      yyo << "empty symbol";
    else
      {
        symbol_kind_type yykind = yysym.kind ();
        yyo << (yykind < YYNTOKENS ? "token" : "nterm")
            << ' ' << yysym.name () << " (";
        YYUSE (yykind);
        yyo << ')';
      }
  }
#endif

  void
  parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  parser::yypop_ (int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  parser::debug_level_type
  parser::debug_level () const
  {
    return yydebug_;
  }

  void
  parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  parser::state_type
  parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
  parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  parser::operator() ()
  {
    return parse ();
  }

  int
  parser::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';
    YY_STACK_PRINT ();

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token\n";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            symbol_type yylookahead (yylex ());
            yyla.move (yylookahead);
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    if (yyla.kind () == symbol_kind::S_YYerror)
    {
      // The scanner already issued an error message, process directly
      // to error recovery.  But do not keep the error token as
      // lookahead, it is too special and may lead us to an endless
      // loop in error recovery. */
      yyla.kind_ = symbol_kind::S_YYUNDEF;
      goto yyerrlab1;
    }

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.kind ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.kind ())
      {
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_loop_statement: // loop_statement
        yylhs.value.emplace< AstNode* > ();
        break;

      case symbol_kind::S_function_expression: // function_expression
        yylhs.value.emplace< FunctionCallNode* > ();
        break;

      case symbol_kind::S_function_statement: // function_statement
        yylhs.value.emplace< FunctionNode* > ();
        break;

      case symbol_kind::S_if_statement: // if_statement
        yylhs.value.emplace< IfNode* > ();
        break;

      case symbol_kind::S_list_expression: // list_expression
        yylhs.value.emplace< ListNode* > ();
        break;

      case symbol_kind::S_block: // block
        yylhs.value.emplace< RootNode* > ();
        break;

      case symbol_kind::S_type_statement: // type_statement
        yylhs.value.emplace< Type > ();
        break;

      case symbol_kind::S_TRUTH: // TRUTH
        yylhs.value.emplace< bool > ();
        break;

      case symbol_kind::S_FLOAT: // FLOAT
        yylhs.value.emplace< double > ();
        break;

      case symbol_kind::S_INT: // INT
        yylhs.value.emplace< int > ();
        break;

      case symbol_kind::S_input_list: // input_list
        yylhs.value.emplace< std::list<std::tuple<std::string, Type>> > ();
        break;

      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_VAR: // VAR
        yylhs.value.emplace< std::string > ();
        break;

      case symbol_kind::S_expression_list: // expression_list
        yylhs.value.emplace< std::vector<AstNode*> > ();
        break;

      default:
        break;
    }



      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2: // run: block
#line 143 "./src/parser.y"
                                                                                { if(yystack_[0].value.as < RootNode* > ()) yystack_[0].value.as < RootNode* > ()->walk(); }
#line 786 "src/parser.yacc.cc"
    break;

  case 3: // block: %empty
#line 147 "./src/parser.y"
                                                                                                { yylhs.value.as < RootNode* > () = new RootNode; }
#line 792 "src/parser.yacc.cc"
    break;

  case 4: // block: block statement ';'
#line 158 "./src/parser.y"
                                                {
			if (yystack_[1].value.as < AstNode* > () != NULL)	// cathces special case of empty statements not filtered by lex
				yylhs.value.as < RootNode* > () = yystack_[2].value.as < RootNode* > ()->attach_statement(yystack_[1].value.as < AstNode* > ());
			else yylhs.value.as < RootNode* > () = yystack_[2].value.as < RootNode* > ();
	}
#line 802 "src/parser.yacc.cc"
    break;

  case 5: // block: block if_statement
#line 163 "./src/parser.y"
                                                        { yylhs.value.as < RootNode* > () = yystack_[1].value.as < RootNode* > ()->attach_statement(yystack_[0].value.as < IfNode* > ()); }
#line 808 "src/parser.yacc.cc"
    break;

  case 6: // block: block loop_statement
#line 164 "./src/parser.y"
                                                { yylhs.value.as < RootNode* > () = yystack_[1].value.as < RootNode* > ()->attach_statement(yystack_[0].value.as < AstNode* > ()); }
#line 814 "src/parser.yacc.cc"
    break;

  case 7: // block: block function_statement
#line 165 "./src/parser.y"
                                        { yylhs.value.as < RootNode* > () = yystack_[1].value.as < RootNode* > ()->attach_statement(yystack_[0].value.as < FunctionNode* > ()); }
#line 820 "src/parser.yacc.cc"
    break;

  case 8: // type_statement: TYPE_NONE
#line 177 "./src/parser.y"
                                                {yylhs.value.as < Type > () = NONE;}
#line 826 "src/parser.yacc.cc"
    break;

  case 9: // type_statement: TYPE_INT
#line 178 "./src/parser.y"
                                        {yylhs.value.as < Type > () = INT;}
#line 832 "src/parser.yacc.cc"
    break;

  case 10: // type_statement: TYPE_FLOAT
#line 179 "./src/parser.y"
                                {yylhs.value.as < Type > () = FLOAT;}
#line 838 "src/parser.yacc.cc"
    break;

  case 11: // type_statement: TYPE_STRING
#line 180 "./src/parser.y"
                                {yylhs.value.as < Type > () = STRING;}
#line 844 "src/parser.yacc.cc"
    break;

  case 12: // type_statement: TYPE_TRUTH
#line 181 "./src/parser.y"
                                {yylhs.value.as < Type > () = TRUTH;}
#line 850 "src/parser.yacc.cc"
    break;

  case 13: // type_statement: TYPE_LIST
#line 182 "./src/parser.y"
                                        {yylhs.value.as < Type > () = LIST;}
#line 856 "src/parser.yacc.cc"
    break;

  case 14: // statement: expression
#line 187 "./src/parser.y"
                                                                { yylhs.value.as < AstNode* > () = yystack_[0].value.as < AstNode* > (); }
#line 862 "src/parser.yacc.cc"
    break;

  case 15: // statement: PRINT expression
#line 188 "./src/parser.y"
                                        { yylhs.value.as < AstNode* > () = new BuiltinNode(PRINT, yystack_[0].value.as < AstNode* > ()); }
#line 868 "src/parser.yacc.cc"
    break;

  case 16: // statement: EXIT expression
#line 189 "./src/parser.y"
                                        { yylhs.value.as < AstNode* > () = new BuiltinNode(EXIT, yystack_[0].value.as < AstNode* > ()); }
#line 874 "src/parser.yacc.cc"
    break;

  case 17: // statement: RETURNS expression
#line 190 "./src/parser.y"
                                { yylhs.value.as < AstNode* > () = new FunctionReturnNode(yystack_[0].value.as < AstNode* > ()); }
#line 880 "src/parser.yacc.cc"
    break;

  case 18: // TRUTH: FALSE
#line 195 "./src/parser.y"
                                        { yylhs.value.as < bool > () = 0; }
#line 886 "src/parser.yacc.cc"
    break;

  case 19: // TRUTH: TRUE
#line 196 "./src/parser.y"
                                { yylhs.value.as < bool > () = 1; }
#line 892 "src/parser.yacc.cc"
    break;

  case 20: // expression_list: expression ',' expression
#line 201 "./src/parser.y"
                                                                        { yylhs.value.as < std::vector<AstNode*> > ().push_back(yystack_[2].value.as < AstNode* > ()); yylhs.value.as < std::vector<AstNode*> > ().push_back(yystack_[0].value.as < AstNode* > ());}
#line 898 "src/parser.yacc.cc"
    break;

  case 21: // expression_list: expression_list ',' expression
#line 202 "./src/parser.y"
                                                { yylhs.value.as < std::vector<AstNode*> > ().insert(yylhs.value.as < std::vector<AstNode*> > ().begin(), yystack_[2].value.as < std::vector<AstNode*> > ().begin(), yystack_[2].value.as < std::vector<AstNode*> > ().end()); yylhs.value.as < std::vector<AstNode*> > ().push_back(yystack_[0].value.as < AstNode* > ()); }
#line 904 "src/parser.yacc.cc"
    break;

  case 22: // list_expression: '[' expression_list ']'
#line 207 "./src/parser.y"
                                                { yylhs.value.as < ListNode* > () = new ListNode(yystack_[1].value.as < std::vector<AstNode*> > ()); }
#line 910 "src/parser.yacc.cc"
    break;

  case 23: // list_expression: '[' expression ']'
#line 208 "./src/parser.y"
                                                                {
			yylhs.value.as < ListNode* > () = new ListNode(std::vector<AstNode*>({yystack_[1].value.as < AstNode* > ()}));
	}
#line 918 "src/parser.yacc.cc"
    break;

  case 24: // expression: %empty
#line 213 "./src/parser.y"
                                                                {;}
#line 924 "src/parser.yacc.cc"
    break;

  case 25: // expression: INT
#line 214 "./src/parser.y"
                                                                { yylhs.value.as < AstNode* > () = new IntNode(yystack_[0].value.as < int > ()); }
#line 930 "src/parser.yacc.cc"
    break;

  case 26: // expression: TRUTH
#line 215 "./src/parser.y"
                                                                { yylhs.value.as < AstNode* > () = new TruthNode(yystack_[0].value.as < bool > ()); }
#line 936 "src/parser.yacc.cc"
    break;

  case 27: // expression: FLOAT
#line 216 "./src/parser.y"
                                                                { yylhs.value.as < AstNode* > () = new FloatNode(yystack_[0].value.as < double > ()); }
#line 942 "src/parser.yacc.cc"
    break;

  case 28: // expression: STRING
#line 217 "./src/parser.y"
                                                                { yylhs.value.as < AstNode* > () = new StringNode(yystack_[0].value.as < std::string > ()); }
#line 948 "src/parser.yacc.cc"
    break;

  case 29: // expression: TYPE_NONE
#line 218 "./src/parser.y"
                                                                { yylhs.value.as < AstNode* > () = new NoneNode(); }
#line 954 "src/parser.yacc.cc"
    break;

  case 30: // expression: type_statement VAR '=' expression
#line 219 "./src/parser.y"
                                                { yylhs.value.as < AstNode* > () = new AssignmentNode(yystack_[3].value.as < Type > (), yystack_[2].value.as < std::string > (), yystack_[0].value.as < AstNode* > ()); }
#line 960 "src/parser.yacc.cc"
    break;

  case 31: // expression: VAR
#line 220 "./src/parser.y"
                                                                        { yylhs.value.as < AstNode* > () = new SymbolReference(yystack_[0].value.as < std::string > ()); }
#line 966 "src/parser.yacc.cc"
    break;

  case 32: // expression: list_expression
#line 222 "./src/parser.y"
                                                                { yylhs.value.as < AstNode* > () = yystack_[0].value.as < ListNode* > (); }
#line 972 "src/parser.yacc.cc"
    break;

  case 33: // expression: TYPE expression
#line 223 "./src/parser.y"
                                                                { yylhs.value.as < AstNode* > () = new BuiltinNode(TYPE, yystack_[0].value.as < AstNode* > ()); }
#line 978 "src/parser.yacc.cc"
    break;

  case 34: // expression: NOT expression
#line 224 "./src/parser.y"
                                                        { yylhs.value.as < AstNode* > () = new MathNode(BNOT, NULL, yystack_[0].value.as < AstNode* > ()); }
#line 984 "src/parser.yacc.cc"
    break;

  case 35: // expression: '(' expression ')'
#line 225 "./src/parser.y"
                                                        { yylhs.value.as < AstNode* > () = yystack_[1].value.as < AstNode* > (); }
#line 990 "src/parser.yacc.cc"
    break;

  case 36: // expression: expression '+' expression
#line 226 "./src/parser.y"
                                                        { yylhs.value.as < AstNode* > () = new MathNode(ADD, yystack_[2].value.as < AstNode* > (), yystack_[0].value.as < AstNode* > ()); }
#line 996 "src/parser.yacc.cc"
    break;

  case 37: // expression: expression '-' expression
#line 227 "./src/parser.y"
                                                        { yylhs.value.as < AstNode* > () = new MathNode(SUB, yystack_[2].value.as < AstNode* > (), yystack_[0].value.as < AstNode* > ()); }
#line 1002 "src/parser.yacc.cc"
    break;

  case 38: // expression: expression '*' expression
#line 228 "./src/parser.y"
                                                        { yylhs.value.as < AstNode* > () = new MathNode(MUL, yystack_[2].value.as < AstNode* > (), yystack_[0].value.as < AstNode* > ()); }
#line 1008 "src/parser.yacc.cc"
    break;

  case 39: // expression: expression '/' expression
#line 229 "./src/parser.y"
                                                        { yylhs.value.as < AstNode* > () = new MathNode(DIV, yystack_[2].value.as < AstNode* > (), yystack_[0].value.as < AstNode* > ()); }
#line 1014 "src/parser.yacc.cc"
    break;

  case 40: // expression: expression '%' expression
#line 230 "./src/parser.y"
                                                        { yylhs.value.as < AstNode* > () = new MathNode(MOD, yystack_[2].value.as < AstNode* > (), yystack_[0].value.as < AstNode* > ()); }
#line 1020 "src/parser.yacc.cc"
    break;

  case 41: // expression: expression POW expression
#line 231 "./src/parser.y"
                                                        { yylhs.value.as < AstNode* > () = new MathNode(POW, yystack_[2].value.as < AstNode* > (), yystack_[0].value.as < AstNode* > ()); }
#line 1026 "src/parser.yacc.cc"
    break;

  case 42: // expression: expression '&' expression
#line 232 "./src/parser.y"
                                                        { yylhs.value.as < AstNode* > () = new MathNode(BAND, yystack_[2].value.as < AstNode* > (), yystack_[0].value.as < AstNode* > ()); }
#line 1032 "src/parser.yacc.cc"
    break;

  case 43: // expression: expression '|' expression
#line 233 "./src/parser.y"
                                                        { yylhs.value.as < AstNode* > () = new MathNode(BOR, yystack_[2].value.as < AstNode* > (), yystack_[0].value.as < AstNode* > ()); }
#line 1038 "src/parser.yacc.cc"
    break;

  case 44: // expression: expression '^' expression
#line 234 "./src/parser.y"
                                                        { yylhs.value.as < AstNode* > () = new MathNode(BXOR, yystack_[2].value.as < AstNode* > (), yystack_[0].value.as < AstNode* > ()); }
#line 1044 "src/parser.yacc.cc"
    break;

  case 45: // expression: expression LEQ expression
#line 235 "./src/parser.y"
                                                        { yylhs.value.as < AstNode* > () = new MathNode(LEQ, yystack_[2].value.as < AstNode* > (), yystack_[0].value.as < AstNode* > ()); }
#line 1050 "src/parser.yacc.cc"
    break;

  case 46: // expression: expression LNEQ expression
#line 236 "./src/parser.y"
                                                { yylhs.value.as < AstNode* > () = new MathNode(LNEQ, yystack_[2].value.as < AstNode* > (), yystack_[0].value.as < AstNode* > ()); }
#line 1056 "src/parser.yacc.cc"
    break;

  case 47: // expression: expression LAND expression
#line 237 "./src/parser.y"
                                                { yylhs.value.as < AstNode* > () = new MathNode(LAND, yystack_[2].value.as < AstNode* > (), yystack_[0].value.as < AstNode* > ()); }
#line 1062 "src/parser.yacc.cc"
    break;

  case 48: // expression: expression LOR expression
#line 238 "./src/parser.y"
                                                        { yylhs.value.as < AstNode* > () = new MathNode(LOR, yystack_[2].value.as < AstNode* > (), yystack_[0].value.as < AstNode* > ()); }
#line 1068 "src/parser.yacc.cc"
    break;

  case 49: // expression: expression '<' expression
#line 239 "./src/parser.y"
                                                        { yylhs.value.as < AstNode* > () = new MathNode(LT, yystack_[2].value.as < AstNode* > (), yystack_[0].value.as < AstNode* > ()); }
#line 1074 "src/parser.yacc.cc"
    break;

  case 50: // expression: expression '>' expression
#line 240 "./src/parser.y"
                                                        { yylhs.value.as < AstNode* > () = new MathNode(GT, yystack_[2].value.as < AstNode* > (), yystack_[0].value.as < AstNode* > ()); }
#line 1080 "src/parser.yacc.cc"
    break;

  case 51: // expression: expression LTEQ expression
#line 241 "./src/parser.y"
                                                { yylhs.value.as < AstNode* > () = new MathNode(LTEQ, yystack_[2].value.as < AstNode* > (), yystack_[0].value.as < AstNode* > ()); }
#line 1086 "src/parser.yacc.cc"
    break;

  case 52: // expression: expression GTEQ expression
#line 242 "./src/parser.y"
                                                { yylhs.value.as < AstNode* > () = new MathNode(GTEQ, yystack_[2].value.as < AstNode* > (), yystack_[0].value.as < AstNode* > ()); }
#line 1092 "src/parser.yacc.cc"
    break;

  case 53: // expression: function_expression
#line 243 "./src/parser.y"
                                                        { yylhs.value.as < AstNode* > () = yystack_[0].value.as < FunctionCallNode* > (); }
#line 1098 "src/parser.yacc.cc"
    break;

  case 54: // expression: IF expression ':' expression ':' expression
#line 244 "./src/parser.y"
                                                      { yylhs.value.as < AstNode* > () = new IfNode(yystack_[4].value.as < AstNode* > (), yystack_[2].value.as < AstNode* > (), yystack_[0].value.as < AstNode* > ()); }
#line 1104 "src/parser.yacc.cc"
    break;

  case 55: // input_list: %empty
#line 261 "./src/parser.y"
                                                                                                                { yylhs.value.as < std::list<std::tuple<std::string, Type>> > (); }
#line 1110 "src/parser.yacc.cc"
    break;

  case 56: // input_list: type_statement VAR
#line 262 "./src/parser.y"
                                                                                        { yylhs.value.as < std::list<std::tuple<std::string, Type>> > ().push_back(std::make_tuple(yystack_[0].value.as < std::string > (), yystack_[1].value.as < Type > ()));}
#line 1116 "src/parser.yacc.cc"
    break;

  case 57: // input_list: input_list ',' type_statement VAR
#line 263 "./src/parser.y"
                                                { yylhs.value.as < std::list<std::tuple<std::string, Type>> > ().splice(yylhs.value.as < std::list<std::tuple<std::string, Type>> > ().begin(), yystack_[3].value.as < std::list<std::tuple<std::string, Type>> > ());yylhs.value.as < std::list<std::tuple<std::string, Type>> > ().push_back(std::make_tuple(yystack_[0].value.as < std::string > (), yystack_[1].value.as < Type > ())); }
#line 1122 "src/parser.yacc.cc"
    break;

  case 58: // function_statement: VAR type_statement '{' block '}'
#line 268 "./src/parser.y"
                                         { yylhs.value.as < FunctionNode* > () = new FunctionNode(yystack_[4].value.as < std::string > (), {}, yystack_[3].value.as < Type > (), yystack_[1].value.as < RootNode* > ()); }
#line 1128 "src/parser.yacc.cc"
    break;

  case 59: // function_statement: VAR type_statement ':' expression ';'
#line 269 "./src/parser.y"
                                                { yylhs.value.as < FunctionNode* > () = new FunctionNode(yystack_[4].value.as < std::string > (), {}, yystack_[3].value.as < Type > (), yystack_[1].value.as < AstNode* > ()); }
#line 1134 "src/parser.yacc.cc"
    break;

  case 60: // function_statement: VAR input_list ':' type_statement ':' expression ';'
#line 270 "./src/parser.y"
                                                               { yylhs.value.as < FunctionNode* > () = new FunctionNode(yystack_[6].value.as < std::string > (), yystack_[5].value.as < std::list<std::tuple<std::string, Type>> > (), yystack_[3].value.as < Type > (), yystack_[1].value.as < AstNode* > ()); }
#line 1140 "src/parser.yacc.cc"
    break;

  case 61: // function_statement: VAR input_list ':' type_statement '{' block '}'
#line 271 "./src/parser.y"
                                                          { yylhs.value.as < FunctionNode* > () = new FunctionNode(yystack_[6].value.as < std::string > (), yystack_[5].value.as < std::list<std::tuple<std::string, Type>> > (), yystack_[3].value.as < Type > (), yystack_[1].value.as < RootNode* > ()); }
#line 1146 "src/parser.yacc.cc"
    break;

  case 62: // function_statement: VAR input_list '{' block '}'
#line 272 "./src/parser.y"
                                       { yylhs.value.as < FunctionNode* > () = new FunctionNode(yystack_[4].value.as < std::string > (), yystack_[3].value.as < std::list<std::tuple<std::string, Type>> > (), NONE, yystack_[1].value.as < RootNode* > ()); }
#line 1152 "src/parser.yacc.cc"
    break;

  case 63: // function_expression: VAR '(' expression_list ')'
#line 278 "./src/parser.y"
                                    { yylhs.value.as < FunctionCallNode* > () = new FunctionCallNode(yystack_[3].value.as < std::string > (), yystack_[1].value.as < std::vector<AstNode*> > ()); }
#line 1158 "src/parser.yacc.cc"
    break;

  case 64: // function_expression: VAR '(' expression ')'
#line 279 "./src/parser.y"
                                                        {
			yylhs.value.as < FunctionCallNode* > () = new FunctionCallNode(yystack_[3].value.as < std::string > (), std::vector<AstNode*>({yystack_[1].value.as < AstNode* > ()}));
	}
#line 1166 "src/parser.yacc.cc"
    break;

  case 65: // if_statement: IF expression '{' block '}'
#line 286 "./src/parser.y"
                                                                                                                        { yylhs.value.as < IfNode* > () = new IfNode(yystack_[3].value.as < AstNode* > (), yystack_[1].value.as < RootNode* > (), NULL); }
#line 1172 "src/parser.yacc.cc"
    break;

  case 66: // if_statement: IF expression ':' statement ';'
#line 287 "./src/parser.y"
                                                                                                { yylhs.value.as < IfNode* > () = new IfNode(yystack_[3].value.as < AstNode* > (), yystack_[1].value.as < AstNode* > (), NULL); }
#line 1178 "src/parser.yacc.cc"
    break;

  case 67: // if_statement: IF expression ':' statement ';' ELSE ':' statement ';'
#line 288 "./src/parser.y"
                                                                        { yylhs.value.as < IfNode* > () = new IfNode(yystack_[7].value.as < AstNode* > (), yystack_[5].value.as < AstNode* > (), yystack_[1].value.as < AstNode* > ()); }
#line 1184 "src/parser.yacc.cc"
    break;

  case 68: // if_statement: IF expression '{' block '}' ELSE '{' block '}'
#line 289 "./src/parser.y"
                                                                                                { yylhs.value.as < IfNode* > () = new IfNode(yystack_[7].value.as < AstNode* > (), yystack_[5].value.as < RootNode* > (), yystack_[1].value.as < RootNode* > ()); }
#line 1190 "src/parser.yacc.cc"
    break;

  case 69: // if_statement: IF expression '{' block '}' ELSE ':' statement ';'
#line 290 "./src/parser.y"
                                                                                { yylhs.value.as < IfNode* > () = new IfNode(yystack_[7].value.as < AstNode* > (), yystack_[5].value.as < RootNode* > (), yystack_[1].value.as < AstNode* > ()); }
#line 1196 "src/parser.yacc.cc"
    break;

  case 70: // if_statement: IF expression ':' statement ';' ELSE '{' block '}'
#line 291 "./src/parser.y"
                                                                                { yylhs.value.as < IfNode* > () = new IfNode(yystack_[7].value.as < AstNode* > (), yystack_[5].value.as < AstNode* > (), yystack_[1].value.as < RootNode* > ()); }
#line 1202 "src/parser.yacc.cc"
    break;

  case 71: // loop_statement: WHILE expression '{' block '}'
#line 296 "./src/parser.y"
                                       { yylhs.value.as < AstNode* > () = new LoopNode(yystack_[3].value.as < AstNode* > (), yystack_[1].value.as < RootNode* > ()); }
#line 1208 "src/parser.yacc.cc"
    break;

  case 72: // loop_statement: FOR expression ':' expression ':' expression '{' block '}'
#line 297 "./src/parser.y"
                                                                     {
			yylhs.value.as < AstNode* > () = new ForNode(yystack_[7].value.as < AstNode* > (), yystack_[5].value.as < AstNode* > (), yystack_[3].value.as < AstNode* > (), yystack_[1].value.as < RootNode* > ());
	}
#line 1216 "src/parser.yacc.cc"
    break;


#line 1220 "src/parser.yacc.cc"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        std::string msg = YY_("syntax error");
        error (YY_MOVE (msg));
      }


    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.kind () == symbol_kind::S_YYEOF)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    // Pop stack until we find a state that shifts the error token.
    for (;;)
      {
        yyn = yypact_[+yystack_[0].state];
        if (!yy_pact_value_is_default_ (yyn))
          {
            yyn += symbol_kind::S_YYerror;
            if (0 <= yyn && yyn <= yylast_
                && yycheck_[yyn] == symbol_kind::S_YYerror)
              {
                yyn = yytable_[yyn];
                if (0 < yyn)
                  break;
              }
          }

        // Pop the current state because it cannot handle the error token.
        if (yystack_.size () == 1)
          YYABORT;

        yy_destroy_ ("Error: popping", yystack_[0]);
        yypop_ ();
        YY_STACK_PRINT ();
      }
    {
      stack_symbol_type error_token;


      // Shift the error token.
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    YY_STACK_PRINT ();
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  parser::error (const syntax_error& yyexc)
  {
    error (yyexc.what ());
  }

#if YYDEBUG || 0
  const char *
  parser::symbol_name (symbol_kind_type yysymbol)
  {
    return yytname_[yysymbol];
  }
#endif // #if YYDEBUG || 0





  const signed char parser::yypact_ninf_ = -66;

  const signed char parser::yytable_ninf_ = -56;

  const short
  parser::yypact_[] =
  {
     -66,     8,    84,   -66,   739,   739,   739,   739,   739,   739,
     -66,   -66,   -66,   -66,   -66,   -21,   -66,   -66,   739,   -66,
     -66,   -66,   827,   739,   739,   739,   -18,   -34,   -66,   -66,
     859,   -66,   -66,   -66,   -66,   739,   -20,   859,   859,   859,
     128,   171,   322,   -66,   -66,   739,   -27,    56,   802,   -66,
      53,   226,    -3,   -66,   739,   739,   739,   739,   739,   739,
     739,   739,   739,   739,   739,   739,   739,   739,   739,   739,
     739,   332,   715,   -66,   -66,   739,   -25,   783,   -66,   739,
     -66,   127,   127,   -66,   -66,   739,   -66,   739,   -66,   739,
     869,   869,     4,     4,     4,     4,   -66,     4,     4,    97,
      97,    97,    29,    29,    24,    24,    24,   739,   -29,   382,
     435,   459,   392,   -66,   -66,   269,   505,     3,   -51,   529,
     859,   859,   859,   382,    23,   739,    25,   -66,   739,   -66,
     -66,   -66,   739,   -66,   -66,   -39,   -66,   -37,   214,   279,
     575,   715,   -66,   715,   -66,   -66,   -66,   -66,    16,   599,
      17,   645,   669,   -66,   -66,   -66,   -66,   -66
  };

  const signed char
  parser::yydefact_[] =
  {
       3,     0,    24,     1,    24,    24,    24,    24,    24,    24,
      19,    18,     9,    10,    11,    29,    12,    13,    24,    25,
      27,    28,    31,    24,    24,    24,     0,     0,    26,    32,
      14,     7,    53,     5,     6,    24,    31,    17,    16,    15,
       0,     0,     0,    33,     8,    24,     0,     0,     0,    34,
       0,     0,     0,     4,    24,    24,    24,    24,    24,    24,
      24,    24,    24,    24,    24,    24,    24,    24,    24,    24,
      24,     0,    24,     3,     3,    24,     0,     0,    56,    24,
       3,     0,     0,     3,    35,    24,    22,    24,    23,    24,
      47,    48,    45,    46,    51,    52,    41,    49,    50,    42,
      43,    44,    36,    37,    38,    39,    40,    24,     0,    14,
      24,    24,     0,    63,    64,     0,    24,     0,     0,    24,
      21,    20,    30,     0,    66,    24,    65,    71,    24,    59,
      58,    57,    24,     3,    62,     0,    54,     0,     0,     0,
      24,    24,     3,    24,     3,     3,    60,    61,     0,    24,
       0,    24,    24,    67,    70,    69,    68,    72
  };

  const signed char
  parser::yypgoto_[] =
  {
     -66,   -66,   -56,   -12,   -65,   -66,    22,   -66,    -4,   -66,
     -66,   -66,   -66,   -66
  };

  const signed char
  parser::yydefgoto_[] =
  {
      -1,     1,     2,    26,    27,    28,    50,    29,    30,    47,
      31,    32,    33,    34
  };

  const short
  parser::yytable_[] =
  {
      37,    38,    39,    40,    41,    42,    78,   108,     3,    85,
      46,   132,    -8,    60,    43,    52,   133,   110,   111,    48,
      49,    51,   113,   141,   116,   143,    45,   119,   142,    53,
     144,    71,    89,    60,   124,    79,   131,   135,    60,   137,
      80,    77,    63,    64,    65,    66,    67,    68,    69,    70,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,    76,   109,   117,
     118,   112,    68,    69,    70,   115,   148,   140,   150,   153,
     155,   120,     0,   121,    -2,   122,   149,    85,   151,   152,
      81,     0,     0,     0,     4,     5,     6,     7,     0,     8,
       9,    10,    11,   123,     0,     0,    60,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    82,    86,
       0,   136,     0,    83,   138,     0,     0,     0,   139,     0,
      23,    54,    55,    56,    57,    58,    59,    60,    66,    67,
      68,    69,    70,     0,    24,     0,     0,     0,     0,    25,
      12,    13,    14,    44,    16,    17,     0,     0,     0,     0,
       0,     0,     0,     0,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    54,    55,    56,    57,    58,    59,
      60,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      72,     0,     0,     0,     0,    73,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    54,    55,    56,
      57,    58,    59,    60,     0,     0,     0,     0,     0,    54,
      55,    56,    57,    58,    59,    60,     0,     0,    74,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      87,     0,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    54,    55,    56,    57,    58,    59,    60,     0,
       0,   145,    54,    55,    56,    57,    58,    59,    60,     0,
       0,     0,    88,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    54,    55,    56,    57,    58,
      59,    60,   129,     0,     0,    54,    55,    56,    57,    58,
      59,    60,   146,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,     0,     0,
       0,     0,     0,     0,    75,    54,    55,    56,    57,    58,
      59,    60,     0,     0,   107,    54,    55,    56,    57,    58,
      59,    60,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,     0,     0,
       0,     0,     0,     0,   125,     4,     5,     6,     7,     0,
       8,     9,    10,    11,   128,     0,     0,     0,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,     4,
       5,     6,     7,     0,     8,     9,    10,    11,     0,     0,
       0,    23,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,     0,     0,    24,     0,     0,     0,     0,
      25,     0,     0,   126,     0,    23,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     4,     5,     6,     7,    24,
       8,     9,    10,    11,    25,     0,     0,   127,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,     4,
       5,     6,     7,     0,     8,     9,    10,    11,     0,     0,
       0,    23,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,     0,     0,    24,     0,     0,     0,     0,
      25,     0,     0,   130,     0,    23,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     4,     5,     6,     7,    24,
       8,     9,    10,    11,    25,     0,     0,   134,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,     4,
       5,     6,     7,     0,     8,     9,    10,    11,     0,     0,
       0,    23,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,     0,     0,    24,     0,     0,     0,     0,
      25,     0,     0,   147,     0,    23,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     4,     5,     6,     7,    24,
       8,     9,    10,    11,    25,     0,     0,   154,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,     4,
       5,     6,     7,     0,     8,     9,    10,    11,     0,     0,
       0,    23,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,     0,     0,    24,     0,     0,     0,     0,
      25,     0,     0,   156,     0,    23,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     4,     5,     6,    35,    24,
       0,     0,    10,    11,    25,     0,     0,   157,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    36,     0,
       0,     0,    35,     0,     0,     0,    10,    11,     0,     0,
       0,    23,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    36,     0,     0,    24,     0,     0,     0,     0,
      25,     0,     0,     0,     0,    23,    54,    55,    56,    57,
      58,    59,    60,     0,     0,     0,     0,     0,     0,    24,
       0,     0,     0,     0,    25,    54,    55,    56,    57,    58,
      59,    60,     0,     0,     0,     0,     0,    87,     0,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,     0,
     114,     0,     0,     0,     0,     0,     0,     0,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,     0,    84,
      12,    13,    14,    44,    16,    17,     0,     0,     0,     0,
       0,   -55,    54,    55,    56,    57,    58,    59,    60,     0,
       0,     0,     0,    45,    56,    57,    58,    59,    60,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   -55,
       0,     0,     0,     0,   -55,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70
  };

  const short
  parser::yycheck_[] =
  {
       4,     5,     6,     7,     8,     9,    33,    72,     0,    34,
      22,    62,    33,     9,    18,    33,    67,    73,    74,    23,
      24,    25,    47,    62,    80,    62,    46,    83,    67,    63,
      67,    35,    35,     9,    63,    62,    33,    14,     9,    14,
      67,    45,    38,    39,    40,    41,    42,    43,    44,    45,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    45,    72,    81,
      82,    75,    43,    44,    45,    79,   141,   133,   143,    63,
      63,    85,    -1,    87,     0,    89,   142,    34,   144,   145,
      34,    -1,    -1,    -1,    10,    11,    12,    13,    -1,    15,
      16,    17,    18,   107,    -1,    -1,     9,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    62,    66,
      -1,   125,    -1,    67,   128,    -1,    -1,    -1,   132,    -1,
      46,     3,     4,     5,     6,     7,     8,     9,    41,    42,
      43,    44,    45,    -1,    60,    -1,    -1,    -1,    -1,    65,
      23,    24,    25,    26,    27,    28,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,     3,     4,     5,     6,     7,     8,
       9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      62,    -1,    -1,    -1,    -1,    67,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,     3,     4,     5,
       6,     7,     8,     9,    -1,    -1,    -1,    -1,    -1,     3,
       4,     5,     6,     7,     8,     9,    -1,    -1,    67,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      34,    -1,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,     3,     4,     5,     6,     7,     8,     9,    -1,
      -1,    67,     3,     4,     5,     6,     7,     8,     9,    -1,
      -1,    -1,    66,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,     3,     4,     5,     6,     7,
       8,     9,    63,    -1,    -1,     3,     4,     5,     6,     7,
       8,     9,    63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    -1,    -1,
      -1,    -1,    -1,    -1,    62,     3,     4,     5,     6,     7,
       8,     9,    -1,    -1,    62,     3,     4,     5,     6,     7,
       8,     9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    -1,    -1,
      -1,    -1,    -1,    -1,    62,    10,    11,    12,    13,    -1,
      15,    16,    17,    18,    62,    -1,    -1,    -1,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    10,
      11,    12,    13,    -1,    15,    16,    17,    18,    -1,    -1,
      -1,    46,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    -1,    -1,    60,    -1,    -1,    -1,    -1,
      65,    -1,    -1,    68,    -1,    46,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    10,    11,    12,    13,    60,
      15,    16,    17,    18,    65,    -1,    -1,    68,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    10,
      11,    12,    13,    -1,    15,    16,    17,    18,    -1,    -1,
      -1,    46,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    -1,    -1,    60,    -1,    -1,    -1,    -1,
      65,    -1,    -1,    68,    -1,    46,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    10,    11,    12,    13,    60,
      15,    16,    17,    18,    65,    -1,    -1,    68,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    10,
      11,    12,    13,    -1,    15,    16,    17,    18,    -1,    -1,
      -1,    46,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    -1,    -1,    60,    -1,    -1,    -1,    -1,
      65,    -1,    -1,    68,    -1,    46,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    10,    11,    12,    13,    60,
      15,    16,    17,    18,    65,    -1,    -1,    68,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    10,
      11,    12,    13,    -1,    15,    16,    17,    18,    -1,    -1,
      -1,    46,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    -1,    -1,    60,    -1,    -1,    -1,    -1,
      65,    -1,    -1,    68,    -1,    46,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    10,    11,    12,    13,    60,
      -1,    -1,    17,    18,    65,    -1,    -1,    68,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    -1,
      -1,    -1,    13,    -1,    -1,    -1,    17,    18,    -1,    -1,
      -1,    46,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    -1,    -1,    60,    -1,    -1,    -1,    -1,
      65,    -1,    -1,    -1,    -1,    46,     3,     4,     5,     6,
       7,     8,     9,    -1,    -1,    -1,    -1,    -1,    -1,    60,
      -1,    -1,    -1,    -1,    65,     3,     4,     5,     6,     7,
       8,     9,    -1,    -1,    -1,    -1,    -1,    34,    -1,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    -1,
      47,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    -1,    47,
      23,    24,    25,    26,    27,    28,    -1,    -1,    -1,    -1,
      -1,    34,     3,     4,     5,     6,     7,     8,     9,    -1,
      -1,    -1,    -1,    46,     5,     6,     7,     8,     9,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    62,
      -1,    -1,    -1,    -1,    67,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45
  };

  const signed char
  parser::yystos_[] =
  {
       0,    70,    71,     0,    10,    11,    12,    13,    15,    16,
      17,    18,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    46,    60,    65,    72,    73,    74,    76,
      77,    79,    80,    81,    82,    13,    33,    77,    77,    77,
      77,    77,    77,    77,    26,    46,    72,    78,    77,    77,
      75,    77,    33,    63,     3,     4,     5,     6,     7,     8,
       9,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    77,    62,    67,    67,    62,    75,    77,    33,    62,
      67,    34,    62,    67,    47,    34,    66,    34,    66,    35,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    77,    77,    62,    73,    77,
      71,    71,    77,    47,    47,    77,    71,    72,    72,    71,
      77,    77,    77,    77,    63,    62,    68,    68,    62,    63,
      68,    33,    62,    67,    68,    14,    77,    14,    77,    77,
      71,    62,    67,    62,    67,    67,    63,    68,    73,    71,
      73,    71,    71,    63,    68,    63,    68,    68
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    69,    70,    71,    71,    71,    71,    71,    72,    72,
      72,    72,    72,    72,    73,    73,    73,    73,    74,    74,
      75,    75,    76,    76,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    78,    78,    78,    79,    79,
      79,    79,    79,    80,    80,    81,    81,    81,    81,    81,
      81,    82,    82
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     1,     0,     3,     2,     2,     2,     1,     1,
       1,     1,     1,     1,     1,     2,     2,     2,     1,     1,
       3,     3,     3,     3,     0,     1,     1,     1,     1,     1,
       4,     1,     1,     2,     2,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     1,     6,     0,     2,     4,     5,     5,
       7,     7,     5,     4,     4,     5,     5,     9,     9,     9,
       9,     5,     9
  };


#if YYDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "\"end of file\"", "error", "\"invalid token\"", "LAND", "LOR", "LEQ",
  "LNEQ", "LTEQ", "GTEQ", "POW", "RETURNS", "EXIT", "PRINT", "IF", "ELSE",
  "WHILE", "FOR", "TRUE", "FALSE", "IMPORT", "IRUN", "ISTART", "IROOT",
  "TYPE_INT", "TYPE_FLOAT", "TYPE_STRING", "TYPE_NONE", "TYPE_TRUTH",
  "TYPE_LIST", "TYPE", "INT", "FLOAT", "STRING", "VAR", "','", "'='",
  "'<'", "'>'", "'&'", "'|'", "'^'", "'+'", "'-'", "'*'", "'/'", "'%'",
  "'('", "')'", "ADDEQ", "SUBEQ", "POWEQ", "MULEQ", "DIVEQ", "MODEQ",
  "BANDEQ", "BOREQ", "BXOREQ", "ADDADD", "SUBSUB", "NEG", "NOT", "'!'",
  "':'", "';'", "NO_ELSE", "'['", "']'", "'{'", "'}'", "$accept", "run",
  "block", "type_statement", "statement", "TRUTH", "expression_list",
  "list_expression", "expression", "input_list", "function_statement",
  "function_expression", "if_statement", "loop_statement", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const short
  parser::yyrline_[] =
  {
       0,   143,   143,   147,   158,   163,   164,   165,   177,   178,
     179,   180,   181,   182,   187,   188,   189,   190,   195,   196,
     201,   202,   207,   208,   213,   214,   215,   216,   217,   218,
     219,   220,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   261,   262,   263,   268,   269,
     270,   271,   272,   278,   279,   286,   287,   288,   289,   290,
     291,   296,   297
  };

  void
  parser::yy_stack_print_ () const
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  void
  parser::yy_reduce_print_ (int yyrule) const
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG


#line 11 "./src/parser.y"
} // yy
#line 1773 "src/parser.yacc.cc"

#line 303 "./src/parser.y"



extern void parse_error(std::string msg);
void yy::parser::error (const std::string& msg)
{
  parse_error(msg.c_str());
}

