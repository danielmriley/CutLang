// A Bison parser, made by GNU Bison 3.8.2.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2021 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

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

// "%code top" blocks.
#line 25 "parser.y"

  #include <iostream>
  #include "scanner.hpp"
  #include "Parser.h"
  #include "driver.h"

namespace adl {
  void check_function_table(std::string id);
  void check_property_table(std::string id);
  void check_object_table(std::string id);

  typedef std::vector<Expr*> ExprVector;
  ExprVector lists;
  ExprVector paramlist;
  ExprVector histoIntsLists;
  ExprVector histoNumsLists;
  ExprVector histoBinsLists;
  ExprVector histoFuncsLists;

  std::vector<int> intLists;
  std::vector<double> doubleLists;

  int cutcount;
  int counter = 0;
  int incrementCounter() { counter += 2; return counter; }
}

  static adl::Parser::symbol_type yylex(adl::Scanner &scanner, adl::Driver &driver) {
         return scanner.adl_yylex();
  }
  // extern FILE* adl::Scanner::yyin;

#line 72 "Parser.cpp"




#include "Parser.h"




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

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (false)
# endif


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
# define YY_SYMBOL_PRINT(Title, Symbol)  YY_USE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

#line 10 "parser.y"
namespace  adl  {
#line 172 "Parser.cpp"

  /// Build a parser object.
   Parser :: Parser  (adl::Scanner &scanner_yyarg, adl::Driver &driver_yyarg)
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      scanner (scanner_yyarg),
      driver (driver_yyarg)
  {}

   Parser ::~ Parser  ()
  {}

   Parser ::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------.
  | symbol.  |
  `---------*/



  // by_state.
   Parser ::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

   Parser ::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
   Parser ::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
   Parser ::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

   Parser ::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

   Parser ::symbol_kind_type
   Parser ::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

   Parser ::stack_symbol_type::stack_symbol_type ()
  {}

   Parser ::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_definition: // definition
      case symbol_kind::S_table: // table
      case symbol_kind::S_function: // function
      case symbol_kind::S_param_list: // param_list
      case symbol_kind::S_object_block: // object_block
      case symbol_kind::S_take: // take
      case symbol_kind::S_take_id: // take_id
      case symbol_kind::S_id_list: // id_list
      case symbol_kind::S_id_list_params: // id_list_params
      case symbol_kind::S_region_block: // region_block
      case symbol_kind::S_criterion: // criterion
      case symbol_kind::S_chained_cond: // chained_cond
      case symbol_kind::S_chain: // chain
      case symbol_kind::S_not: // not
      case symbol_kind::S_condition: // condition
      case symbol_kind::S_expr: // expr
      case symbol_kind::S_factor: // factor
      case symbol_kind::S_term: // term
      case symbol_kind::S_id_qualifiers: // id_qualifiers
      case symbol_kind::S_id_qualifier: // id_qualifier
      case symbol_kind::S_dot_op: // dot_op
      case symbol_kind::S_range: // range
      case symbol_kind::S_num: // num
      case symbol_kind::S_int: // int
      case symbol_kind::S_real: // real
      case symbol_kind::S_id: // id
        value.YY_MOVE_OR_COPY< adl::Expr* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_boolean: // boolean
        value.YY_MOVE_OR_COPY< bool > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_REAL: // REAL
      case symbol_kind::S_tablelist: // tablelist
      case symbol_kind::S_value: // value
        value.YY_MOVE_OR_COPY< double > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INT: // INT
      case symbol_kind::S_index: // index
        value.YY_MOVE_OR_COPY< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_DEFINE: // DEFINE
      case symbol_kind::S_REGION: // REGION
      case symbol_kind::S_OBJECT: // OBJECT
      case symbol_kind::S_TAKE: // TAKE
      case symbol_kind::S_COMMAND: // COMMAND
      case symbol_kind::S_HISTO: // HISTO
      case symbol_kind::S_HISTOLIST: // HISTOLIST
      case symbol_kind::S_TABLE: // TABLE
      case symbol_kind::S_TABLETYPE: // TABLETYPE
      case symbol_kind::S_NVARS: // NVARS
      case symbol_kind::S_ERRORS: // ERRORS
      case symbol_kind::S_UNION: // UNION
      case symbol_kind::S_ID: // ID
      case symbol_kind::S_ERROR: // ERROR
      case symbol_kind::S_FLAG: // FLAG
      case symbol_kind::S_LPAR: // LPAR
      case symbol_kind::S_RPAR: // RPAR
      case symbol_kind::S_VAR: // VAR
      case symbol_kind::S_QUOTE: // QUOTE
      case symbol_kind::S_DESC: // DESC
      case symbol_kind::S_INFO: // INFO
      case symbol_kind::S_PLUS: // PLUS
      case symbol_kind::S_SUBTRACT: // SUBTRACT
      case symbol_kind::S_MULTIPLY: // MULTIPLY
      case symbol_kind::S_DIVIDE: // DIVIDE
      case symbol_kind::S_POW: // POW
      case symbol_kind::S_ASSIGN: // ASSIGN
      case symbol_kind::S_PLUSMINUS: // PLUSMINUS
      case symbol_kind::S_GT: // GT
      case symbol_kind::S_LT: // LT
      case symbol_kind::S_GE: // GE
      case symbol_kind::S_LE: // LE
      case symbol_kind::S_EQ: // EQ
      case symbol_kind::S_NE: // NE
      case symbol_kind::S_TRUE: // TRUE
      case symbol_kind::S_FALSE: // FALSE
      case symbol_kind::S_AND: // AND
      case symbol_kind::S_OR: // OR
      case symbol_kind::S_NOT: // NOT
      case symbol_kind::S_PIPE: // PIPE
      case symbol_kind::S_LBRACKET: // LBRACKET
      case symbol_kind::S_RBRACKET: // RBRACKET
      case symbol_kind::S_LCBRACE: // LCBRACE
      case symbol_kind::S_RCBRACE: // RCBRACE
      case symbol_kind::S_COLON: // COLON
      case symbol_kind::S_QUES: // QUES
      case symbol_kind::S_COMMA: // COMMA
      case symbol_kind::S_DOT: // DOT
      case symbol_kind::S_INCLUSIVE: // INCLUSIVE
      case symbol_kind::S_EXCLUSIVE: // EXCLUSIVE
      case symbol_kind::S_UNDERSCORE: // UNDERSCORE
      case symbol_kind::S_info: // info
      case symbol_kind::S_compare_op: // compare_op
      case symbol_kind::S_logic_op: // logic_op
      case symbol_kind::S_expr_op: // expr_op
      case symbol_kind::S_factor_op: // factor_op
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_bins: // bins
        value.YY_MOVE_OR_COPY< std::vector<double> > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

   Parser ::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_definition: // definition
      case symbol_kind::S_table: // table
      case symbol_kind::S_function: // function
      case symbol_kind::S_param_list: // param_list
      case symbol_kind::S_object_block: // object_block
      case symbol_kind::S_take: // take
      case symbol_kind::S_take_id: // take_id
      case symbol_kind::S_id_list: // id_list
      case symbol_kind::S_id_list_params: // id_list_params
      case symbol_kind::S_region_block: // region_block
      case symbol_kind::S_criterion: // criterion
      case symbol_kind::S_chained_cond: // chained_cond
      case symbol_kind::S_chain: // chain
      case symbol_kind::S_not: // not
      case symbol_kind::S_condition: // condition
      case symbol_kind::S_expr: // expr
      case symbol_kind::S_factor: // factor
      case symbol_kind::S_term: // term
      case symbol_kind::S_id_qualifiers: // id_qualifiers
      case symbol_kind::S_id_qualifier: // id_qualifier
      case symbol_kind::S_dot_op: // dot_op
      case symbol_kind::S_range: // range
      case symbol_kind::S_num: // num
      case symbol_kind::S_int: // int
      case symbol_kind::S_real: // real
      case symbol_kind::S_id: // id
        value.move< adl::Expr* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_boolean: // boolean
        value.move< bool > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_REAL: // REAL
      case symbol_kind::S_tablelist: // tablelist
      case symbol_kind::S_value: // value
        value.move< double > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INT: // INT
      case symbol_kind::S_index: // index
        value.move< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_DEFINE: // DEFINE
      case symbol_kind::S_REGION: // REGION
      case symbol_kind::S_OBJECT: // OBJECT
      case symbol_kind::S_TAKE: // TAKE
      case symbol_kind::S_COMMAND: // COMMAND
      case symbol_kind::S_HISTO: // HISTO
      case symbol_kind::S_HISTOLIST: // HISTOLIST
      case symbol_kind::S_TABLE: // TABLE
      case symbol_kind::S_TABLETYPE: // TABLETYPE
      case symbol_kind::S_NVARS: // NVARS
      case symbol_kind::S_ERRORS: // ERRORS
      case symbol_kind::S_UNION: // UNION
      case symbol_kind::S_ID: // ID
      case symbol_kind::S_ERROR: // ERROR
      case symbol_kind::S_FLAG: // FLAG
      case symbol_kind::S_LPAR: // LPAR
      case symbol_kind::S_RPAR: // RPAR
      case symbol_kind::S_VAR: // VAR
      case symbol_kind::S_QUOTE: // QUOTE
      case symbol_kind::S_DESC: // DESC
      case symbol_kind::S_INFO: // INFO
      case symbol_kind::S_PLUS: // PLUS
      case symbol_kind::S_SUBTRACT: // SUBTRACT
      case symbol_kind::S_MULTIPLY: // MULTIPLY
      case symbol_kind::S_DIVIDE: // DIVIDE
      case symbol_kind::S_POW: // POW
      case symbol_kind::S_ASSIGN: // ASSIGN
      case symbol_kind::S_PLUSMINUS: // PLUSMINUS
      case symbol_kind::S_GT: // GT
      case symbol_kind::S_LT: // LT
      case symbol_kind::S_GE: // GE
      case symbol_kind::S_LE: // LE
      case symbol_kind::S_EQ: // EQ
      case symbol_kind::S_NE: // NE
      case symbol_kind::S_TRUE: // TRUE
      case symbol_kind::S_FALSE: // FALSE
      case symbol_kind::S_AND: // AND
      case symbol_kind::S_OR: // OR
      case symbol_kind::S_NOT: // NOT
      case symbol_kind::S_PIPE: // PIPE
      case symbol_kind::S_LBRACKET: // LBRACKET
      case symbol_kind::S_RBRACKET: // RBRACKET
      case symbol_kind::S_LCBRACE: // LCBRACE
      case symbol_kind::S_RCBRACE: // RCBRACE
      case symbol_kind::S_COLON: // COLON
      case symbol_kind::S_QUES: // QUES
      case symbol_kind::S_COMMA: // COMMA
      case symbol_kind::S_DOT: // DOT
      case symbol_kind::S_INCLUSIVE: // INCLUSIVE
      case symbol_kind::S_EXCLUSIVE: // EXCLUSIVE
      case symbol_kind::S_UNDERSCORE: // UNDERSCORE
      case symbol_kind::S_info: // info
      case symbol_kind::S_compare_op: // compare_op
      case symbol_kind::S_logic_op: // logic_op
      case symbol_kind::S_expr_op: // expr_op
      case symbol_kind::S_factor_op: // factor_op
        value.move< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_bins: // bins
        value.move< std::vector<double> > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
   Parser ::stack_symbol_type&
   Parser ::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_definition: // definition
      case symbol_kind::S_table: // table
      case symbol_kind::S_function: // function
      case symbol_kind::S_param_list: // param_list
      case symbol_kind::S_object_block: // object_block
      case symbol_kind::S_take: // take
      case symbol_kind::S_take_id: // take_id
      case symbol_kind::S_id_list: // id_list
      case symbol_kind::S_id_list_params: // id_list_params
      case symbol_kind::S_region_block: // region_block
      case symbol_kind::S_criterion: // criterion
      case symbol_kind::S_chained_cond: // chained_cond
      case symbol_kind::S_chain: // chain
      case symbol_kind::S_not: // not
      case symbol_kind::S_condition: // condition
      case symbol_kind::S_expr: // expr
      case symbol_kind::S_factor: // factor
      case symbol_kind::S_term: // term
      case symbol_kind::S_id_qualifiers: // id_qualifiers
      case symbol_kind::S_id_qualifier: // id_qualifier
      case symbol_kind::S_dot_op: // dot_op
      case symbol_kind::S_range: // range
      case symbol_kind::S_num: // num
      case symbol_kind::S_int: // int
      case symbol_kind::S_real: // real
      case symbol_kind::S_id: // id
        value.copy< adl::Expr* > (that.value);
        break;

      case symbol_kind::S_boolean: // boolean
        value.copy< bool > (that.value);
        break;

      case symbol_kind::S_REAL: // REAL
      case symbol_kind::S_tablelist: // tablelist
      case symbol_kind::S_value: // value
        value.copy< double > (that.value);
        break;

      case symbol_kind::S_INT: // INT
      case symbol_kind::S_index: // index
        value.copy< int > (that.value);
        break;

      case symbol_kind::S_DEFINE: // DEFINE
      case symbol_kind::S_REGION: // REGION
      case symbol_kind::S_OBJECT: // OBJECT
      case symbol_kind::S_TAKE: // TAKE
      case symbol_kind::S_COMMAND: // COMMAND
      case symbol_kind::S_HISTO: // HISTO
      case symbol_kind::S_HISTOLIST: // HISTOLIST
      case symbol_kind::S_TABLE: // TABLE
      case symbol_kind::S_TABLETYPE: // TABLETYPE
      case symbol_kind::S_NVARS: // NVARS
      case symbol_kind::S_ERRORS: // ERRORS
      case symbol_kind::S_UNION: // UNION
      case symbol_kind::S_ID: // ID
      case symbol_kind::S_ERROR: // ERROR
      case symbol_kind::S_FLAG: // FLAG
      case symbol_kind::S_LPAR: // LPAR
      case symbol_kind::S_RPAR: // RPAR
      case symbol_kind::S_VAR: // VAR
      case symbol_kind::S_QUOTE: // QUOTE
      case symbol_kind::S_DESC: // DESC
      case symbol_kind::S_INFO: // INFO
      case symbol_kind::S_PLUS: // PLUS
      case symbol_kind::S_SUBTRACT: // SUBTRACT
      case symbol_kind::S_MULTIPLY: // MULTIPLY
      case symbol_kind::S_DIVIDE: // DIVIDE
      case symbol_kind::S_POW: // POW
      case symbol_kind::S_ASSIGN: // ASSIGN
      case symbol_kind::S_PLUSMINUS: // PLUSMINUS
      case symbol_kind::S_GT: // GT
      case symbol_kind::S_LT: // LT
      case symbol_kind::S_GE: // GE
      case symbol_kind::S_LE: // LE
      case symbol_kind::S_EQ: // EQ
      case symbol_kind::S_NE: // NE
      case symbol_kind::S_TRUE: // TRUE
      case symbol_kind::S_FALSE: // FALSE
      case symbol_kind::S_AND: // AND
      case symbol_kind::S_OR: // OR
      case symbol_kind::S_NOT: // NOT
      case symbol_kind::S_PIPE: // PIPE
      case symbol_kind::S_LBRACKET: // LBRACKET
      case symbol_kind::S_RBRACKET: // RBRACKET
      case symbol_kind::S_LCBRACE: // LCBRACE
      case symbol_kind::S_RCBRACE: // RCBRACE
      case symbol_kind::S_COLON: // COLON
      case symbol_kind::S_QUES: // QUES
      case symbol_kind::S_COMMA: // COMMA
      case symbol_kind::S_DOT: // DOT
      case symbol_kind::S_INCLUSIVE: // INCLUSIVE
      case symbol_kind::S_EXCLUSIVE: // EXCLUSIVE
      case symbol_kind::S_UNDERSCORE: // UNDERSCORE
      case symbol_kind::S_info: // info
      case symbol_kind::S_compare_op: // compare_op
      case symbol_kind::S_logic_op: // logic_op
      case symbol_kind::S_expr_op: // expr_op
      case symbol_kind::S_factor_op: // factor_op
        value.copy< std::string > (that.value);
        break;

      case symbol_kind::S_bins: // bins
        value.copy< std::vector<double> > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }

   Parser ::stack_symbol_type&
   Parser ::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_definition: // definition
      case symbol_kind::S_table: // table
      case symbol_kind::S_function: // function
      case symbol_kind::S_param_list: // param_list
      case symbol_kind::S_object_block: // object_block
      case symbol_kind::S_take: // take
      case symbol_kind::S_take_id: // take_id
      case symbol_kind::S_id_list: // id_list
      case symbol_kind::S_id_list_params: // id_list_params
      case symbol_kind::S_region_block: // region_block
      case symbol_kind::S_criterion: // criterion
      case symbol_kind::S_chained_cond: // chained_cond
      case symbol_kind::S_chain: // chain
      case symbol_kind::S_not: // not
      case symbol_kind::S_condition: // condition
      case symbol_kind::S_expr: // expr
      case symbol_kind::S_factor: // factor
      case symbol_kind::S_term: // term
      case symbol_kind::S_id_qualifiers: // id_qualifiers
      case symbol_kind::S_id_qualifier: // id_qualifier
      case symbol_kind::S_dot_op: // dot_op
      case symbol_kind::S_range: // range
      case symbol_kind::S_num: // num
      case symbol_kind::S_int: // int
      case symbol_kind::S_real: // real
      case symbol_kind::S_id: // id
        value.move< adl::Expr* > (that.value);
        break;

      case symbol_kind::S_boolean: // boolean
        value.move< bool > (that.value);
        break;

      case symbol_kind::S_REAL: // REAL
      case symbol_kind::S_tablelist: // tablelist
      case symbol_kind::S_value: // value
        value.move< double > (that.value);
        break;

      case symbol_kind::S_INT: // INT
      case symbol_kind::S_index: // index
        value.move< int > (that.value);
        break;

      case symbol_kind::S_DEFINE: // DEFINE
      case symbol_kind::S_REGION: // REGION
      case symbol_kind::S_OBJECT: // OBJECT
      case symbol_kind::S_TAKE: // TAKE
      case symbol_kind::S_COMMAND: // COMMAND
      case symbol_kind::S_HISTO: // HISTO
      case symbol_kind::S_HISTOLIST: // HISTOLIST
      case symbol_kind::S_TABLE: // TABLE
      case symbol_kind::S_TABLETYPE: // TABLETYPE
      case symbol_kind::S_NVARS: // NVARS
      case symbol_kind::S_ERRORS: // ERRORS
      case symbol_kind::S_UNION: // UNION
      case symbol_kind::S_ID: // ID
      case symbol_kind::S_ERROR: // ERROR
      case symbol_kind::S_FLAG: // FLAG
      case symbol_kind::S_LPAR: // LPAR
      case symbol_kind::S_RPAR: // RPAR
      case symbol_kind::S_VAR: // VAR
      case symbol_kind::S_QUOTE: // QUOTE
      case symbol_kind::S_DESC: // DESC
      case symbol_kind::S_INFO: // INFO
      case symbol_kind::S_PLUS: // PLUS
      case symbol_kind::S_SUBTRACT: // SUBTRACT
      case symbol_kind::S_MULTIPLY: // MULTIPLY
      case symbol_kind::S_DIVIDE: // DIVIDE
      case symbol_kind::S_POW: // POW
      case symbol_kind::S_ASSIGN: // ASSIGN
      case symbol_kind::S_PLUSMINUS: // PLUSMINUS
      case symbol_kind::S_GT: // GT
      case symbol_kind::S_LT: // LT
      case symbol_kind::S_GE: // GE
      case symbol_kind::S_LE: // LE
      case symbol_kind::S_EQ: // EQ
      case symbol_kind::S_NE: // NE
      case symbol_kind::S_TRUE: // TRUE
      case symbol_kind::S_FALSE: // FALSE
      case symbol_kind::S_AND: // AND
      case symbol_kind::S_OR: // OR
      case symbol_kind::S_NOT: // NOT
      case symbol_kind::S_PIPE: // PIPE
      case symbol_kind::S_LBRACKET: // LBRACKET
      case symbol_kind::S_RBRACKET: // RBRACKET
      case symbol_kind::S_LCBRACE: // LCBRACE
      case symbol_kind::S_RCBRACE: // RCBRACE
      case symbol_kind::S_COLON: // COLON
      case symbol_kind::S_QUES: // QUES
      case symbol_kind::S_COMMA: // COMMA
      case symbol_kind::S_DOT: // DOT
      case symbol_kind::S_INCLUSIVE: // INCLUSIVE
      case symbol_kind::S_EXCLUSIVE: // EXCLUSIVE
      case symbol_kind::S_UNDERSCORE: // UNDERSCORE
      case symbol_kind::S_info: // info
      case symbol_kind::S_compare_op: // compare_op
      case symbol_kind::S_logic_op: // logic_op
      case symbol_kind::S_expr_op: // expr_op
      case symbol_kind::S_factor_op: // factor_op
        value.move< std::string > (that.value);
        break;

      case symbol_kind::S_bins: // bins
        value.move< std::vector<double> > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
   Parser ::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
   Parser ::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YY_USE (yyoutput);
    if (yysym.empty ())
      yyo << "empty symbol";
    else
      {
        symbol_kind_type yykind = yysym.kind ();
        yyo << (yykind < YYNTOKENS ? "token" : "nterm")
            << ' ' << yysym.name () << " ("
            << yysym.location << ": ";
        YY_USE (yykind);
        yyo << ')';
      }
  }
#endif

  void
   Parser ::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
   Parser ::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
   Parser ::yypop_ (int n) YY_NOEXCEPT
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
   Parser ::debug_stream () const
  {
    return *yycdebug_;
  }

  void
   Parser ::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


   Parser ::debug_level_type
   Parser ::debug_level () const
  {
    return yydebug_;
  }

  void
   Parser ::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

   Parser ::state_type
   Parser ::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
   Parser ::yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yypact_ninf_;
  }

  bool
   Parser ::yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yytable_ninf_;
  }

  int
   Parser ::operator() ()
  {
    return parse ();
  }

  int
   Parser ::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

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
            symbol_type yylookahead (yylex (scanner, driver));
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
      case symbol_kind::S_definition: // definition
      case symbol_kind::S_table: // table
      case symbol_kind::S_function: // function
      case symbol_kind::S_param_list: // param_list
      case symbol_kind::S_object_block: // object_block
      case symbol_kind::S_take: // take
      case symbol_kind::S_take_id: // take_id
      case symbol_kind::S_id_list: // id_list
      case symbol_kind::S_id_list_params: // id_list_params
      case symbol_kind::S_region_block: // region_block
      case symbol_kind::S_criterion: // criterion
      case symbol_kind::S_chained_cond: // chained_cond
      case symbol_kind::S_chain: // chain
      case symbol_kind::S_not: // not
      case symbol_kind::S_condition: // condition
      case symbol_kind::S_expr: // expr
      case symbol_kind::S_factor: // factor
      case symbol_kind::S_term: // term
      case symbol_kind::S_id_qualifiers: // id_qualifiers
      case symbol_kind::S_id_qualifier: // id_qualifier
      case symbol_kind::S_dot_op: // dot_op
      case symbol_kind::S_range: // range
      case symbol_kind::S_num: // num
      case symbol_kind::S_int: // int
      case symbol_kind::S_real: // real
      case symbol_kind::S_id: // id
        yylhs.value.emplace< adl::Expr* > ();
        break;

      case symbol_kind::S_boolean: // boolean
        yylhs.value.emplace< bool > ();
        break;

      case symbol_kind::S_REAL: // REAL
      case symbol_kind::S_tablelist: // tablelist
      case symbol_kind::S_value: // value
        yylhs.value.emplace< double > ();
        break;

      case symbol_kind::S_INT: // INT
      case symbol_kind::S_index: // index
        yylhs.value.emplace< int > ();
        break;

      case symbol_kind::S_DEFINE: // DEFINE
      case symbol_kind::S_REGION: // REGION
      case symbol_kind::S_OBJECT: // OBJECT
      case symbol_kind::S_TAKE: // TAKE
      case symbol_kind::S_COMMAND: // COMMAND
      case symbol_kind::S_HISTO: // HISTO
      case symbol_kind::S_HISTOLIST: // HISTOLIST
      case symbol_kind::S_TABLE: // TABLE
      case symbol_kind::S_TABLETYPE: // TABLETYPE
      case symbol_kind::S_NVARS: // NVARS
      case symbol_kind::S_ERRORS: // ERRORS
      case symbol_kind::S_UNION: // UNION
      case symbol_kind::S_ID: // ID
      case symbol_kind::S_ERROR: // ERROR
      case symbol_kind::S_FLAG: // FLAG
      case symbol_kind::S_LPAR: // LPAR
      case symbol_kind::S_RPAR: // RPAR
      case symbol_kind::S_VAR: // VAR
      case symbol_kind::S_QUOTE: // QUOTE
      case symbol_kind::S_DESC: // DESC
      case symbol_kind::S_INFO: // INFO
      case symbol_kind::S_PLUS: // PLUS
      case symbol_kind::S_SUBTRACT: // SUBTRACT
      case symbol_kind::S_MULTIPLY: // MULTIPLY
      case symbol_kind::S_DIVIDE: // DIVIDE
      case symbol_kind::S_POW: // POW
      case symbol_kind::S_ASSIGN: // ASSIGN
      case symbol_kind::S_PLUSMINUS: // PLUSMINUS
      case symbol_kind::S_GT: // GT
      case symbol_kind::S_LT: // LT
      case symbol_kind::S_GE: // GE
      case symbol_kind::S_LE: // LE
      case symbol_kind::S_EQ: // EQ
      case symbol_kind::S_NE: // NE
      case symbol_kind::S_TRUE: // TRUE
      case symbol_kind::S_FALSE: // FALSE
      case symbol_kind::S_AND: // AND
      case symbol_kind::S_OR: // OR
      case symbol_kind::S_NOT: // NOT
      case symbol_kind::S_PIPE: // PIPE
      case symbol_kind::S_LBRACKET: // LBRACKET
      case symbol_kind::S_RBRACKET: // RBRACKET
      case symbol_kind::S_LCBRACE: // LCBRACE
      case symbol_kind::S_RCBRACE: // RCBRACE
      case symbol_kind::S_COLON: // COLON
      case symbol_kind::S_QUES: // QUES
      case symbol_kind::S_COMMA: // COMMA
      case symbol_kind::S_DOT: // DOT
      case symbol_kind::S_INCLUSIVE: // INCLUSIVE
      case symbol_kind::S_EXCLUSIVE: // EXCLUSIVE
      case symbol_kind::S_UNDERSCORE: // UNDERSCORE
      case symbol_kind::S_info: // info
      case symbol_kind::S_compare_op: // compare_op
      case symbol_kind::S_logic_op: // logic_op
      case symbol_kind::S_expr_op: // expr_op
      case symbol_kind::S_factor_op: // factor_op
        yylhs.value.emplace< std::string > ();
        break;

      case symbol_kind::S_bins: // bins
        yylhs.value.emplace< std::vector<double> > ();
        break;

      default:
        break;
    }


      // Default location.
      {
        stack_type::slice range (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, range, yylen);
        yyerror_range[1].location = yylhs.location;
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2: // start: info objects
#line 90 "parser.y"
                                                {}
#line 1102 "Parser.cpp"
    break;

  case 3: // start: info table objects
#line 91 "parser.y"
                                                {}
#line 1108 "Parser.cpp"
    break;

  case 4: // start: table objects
#line 92 "parser.y"
                                                {}
#line 1114 "Parser.cpp"
    break;

  case 5: // start: objects
#line 93 "parser.y"
                                                {}
#line 1120 "Parser.cpp"
    break;

  case 6: // start: info
#line 94 "parser.y"
                                                {}
#line 1126 "Parser.cpp"
    break;

  case 7: // info: INFO info_list
#line 97 "parser.y"
                                                {}
#line 1132 "Parser.cpp"
    break;

  case 14: // objects: object_block
#line 103 "parser.y"
                                                {}
#line 1138 "Parser.cpp"
    break;

  case 15: // objects: object_block objects
#line 104 "parser.y"
                                                {}
#line 1144 "Parser.cpp"
    break;

  case 16: // objects: definitions
#line 105 "parser.y"
                                                {}
#line 1150 "Parser.cpp"
    break;

  case 17: // objects: definitions objects
#line 106 "parser.y"
                                                {}
#line 1156 "Parser.cpp"
    break;

  case 18: // definitions: definition
#line 109 "parser.y"
                                                {}
#line 1162 "Parser.cpp"
    break;

  case 19: // definitions: definition definitions
#line 110 "parser.y"
                                                {}
#line 1168 "Parser.cpp"
    break;

  case 20: // definitions: regions
#line 111 "parser.y"
                                                {}
#line 1174 "Parser.cpp"
    break;

  case 21: // regions: region_block
#line 114 "parser.y"
                                                {}
#line 1180 "Parser.cpp"
    break;

  case 22: // regions: region_block regions
#line 115 "parser.y"
                                                {}
#line 1186 "Parser.cpp"
    break;

  case 23: // definition: DEFINE id ASSIGN condition
#line 118 "parser.y"
                                                { yylhs.value.as < adl::Expr* > () = new adl::DefineNode(incrementCounter(), "DEFINE", yystack_[2].value.as < adl::Expr* > (), yystack_[0].value.as < adl::Expr* > ()); driver.ast.push_back(yylhs.value.as < adl::Expr* > ()); /* std::cout << "define: " << $2->getId() << "\n"; */ }
#line 1192 "Parser.cpp"
    break;

  case 24: // definition: DEFINE id COLON condition
#line 119 "parser.y"
                                     { yylhs.value.as < adl::Expr* > () = new adl::DefineNode(incrementCounter(), "DEFINE", yystack_[2].value.as < adl::Expr* > (), yystack_[0].value.as < adl::Expr* > ()); driver.ast.push_back(yylhs.value.as < adl::Expr* > ()); /* std::cout << "define: " << $2->getId() << "\n"; */ }
#line 1198 "Parser.cpp"
    break;

  case 25: // definition: table
#line 120 "parser.y"
                                                { /* make tableNode here. */ }
#line 1204 "Parser.cpp"
    break;

  case 26: // table: TABLE ID TABLETYPE ID NVARS INT ERRORS boolean tablelist
#line 124 "parser.y"
                                                { /* Put this info into a tableNode. */ }
#line 1210 "Parser.cpp"
    break;

  case 27: // tablelist: value tablelist
#line 126 "parser.y"
                                                { doubleLists.push_back(yystack_[1].value.as < double > ()); }
#line 1216 "Parser.cpp"
    break;

  case 28: // tablelist: value
#line 127 "parser.y"
                                                { doubleLists.push_back(yystack_[0].value.as < double > ()); }
#line 1222 "Parser.cpp"
    break;

  case 29: // value: REAL
#line 130 "parser.y"
                                                { yylhs.value.as < double > () = yystack_[0].value.as < double > (); }
#line 1228 "Parser.cpp"
    break;

  case 30: // function: id LPAR param_list RPAR
#line 133 "parser.y"
                                                { yylhs.value.as < adl::Expr* > () = new adl::FunctionNode(incrementCounter(), "FUNCTION", yystack_[3].value.as < adl::Expr* > (), paramlist); paramlist.clear(); }
#line 1234 "Parser.cpp"
    break;

  case 31: // function: LCBRACE param_list RCBRACE id
#line 134 "parser.y"
                                                { yylhs.value.as < adl::Expr* > () = new adl::FunctionNode(incrementCounter(), "FUNCTION", yystack_[0].value.as < adl::Expr* > (), paramlist); paramlist.clear(); }
#line 1240 "Parser.cpp"
    break;

  case 32: // function: PIPE int PIPE
#line 135 "parser.y"
                                                { Expr* e = new adl::VarNode(incrementCounter(),"ID","abs", "", "", {},""); yylhs.value.as < adl::Expr* > () = new adl::FunctionNode(incrementCounter(), "FUNCTION", e, ExprVector(1,yystack_[1].value.as < adl::Expr* > ())); }
#line 1246 "Parser.cpp"
    break;

  case 33: // function: PIPE real PIPE
#line 136 "parser.y"
                                                { Expr* e = new adl::VarNode(incrementCounter(),"ID","abs", "", "", {},""); yylhs.value.as < adl::Expr* > () = new adl::FunctionNode(incrementCounter(), "FUNCTION", e, ExprVector(1,yystack_[1].value.as < adl::Expr* > ())); }
#line 1252 "Parser.cpp"
    break;

  case 34: // function: PIPE id PIPE
#line 137 "parser.y"
                                                { Expr* e = new adl::VarNode(incrementCounter(),"ID","abs", "", "", {},""); yylhs.value.as < adl::Expr* > () = new adl::FunctionNode(incrementCounter(), "FUNCTION", e, ExprVector(1,yystack_[1].value.as < adl::Expr* > ())); }
#line 1258 "Parser.cpp"
    break;

  case 35: // param_list: chain COMMA param_list
#line 140 "parser.y"
                                                { paramlist.push_back(yystack_[2].value.as < adl::Expr* > ()); }
#line 1264 "Parser.cpp"
    break;

  case 36: // param_list: chain
#line 141 "parser.y"
                                                { paramlist.push_back(yystack_[0].value.as < adl::Expr* > ()); }
#line 1270 "Parser.cpp"
    break;

  case 37: // object_block: OBJECT id takes
#line 144 "parser.y"
                                                { yylhs.value.as < adl::Expr* > () = new astObjectNode(incrementCounter(), "OBJECT", yystack_[1].value.as < adl::Expr* > (), lists); driver.ast.push_back(yylhs.value.as < adl::Expr* > ()); lists.clear(); /* std::cout << "object: " << $2->getId() << "\n"; */ }
#line 1276 "Parser.cpp"
    break;

  case 38: // object_block: OBJECT id takes criteria
#line 145 "parser.y"
                                                { yylhs.value.as < adl::Expr* > () = new astObjectNode(incrementCounter(), "OBJECT", yystack_[2].value.as < adl::Expr* > (), lists); driver.ast.push_back(yylhs.value.as < adl::Expr* > ()); lists.clear(); /* std::cout << "object: " << $2->getId() << "\n"; */ }
#line 1282 "Parser.cpp"
    break;

  case 39: // takes: take takes
#line 148 "parser.y"
                                                { lists.push_back(yystack_[1].value.as < adl::Expr* > ()); }
#line 1288 "Parser.cpp"
    break;

  case 40: // takes: take
#line 149 "parser.y"
                                                { lists.push_back(yystack_[0].value.as < adl::Expr* > ()); }
#line 1294 "Parser.cpp"
    break;

  case 41: // take: TAKE take_id
#line 152 "parser.y"
                                                { yylhs.value.as < adl::Expr* > () = new CommandNode(incrementCounter(), yystack_[1].value.as < std::string > (),yystack_[0].value.as < adl::Expr* > ()); }
#line 1300 "Parser.cpp"
    break;

  case 42: // take: COLON take_id
#line 153 "parser.y"
                                                { yylhs.value.as < adl::Expr* > () = new CommandNode(incrementCounter(), "TAKE",yystack_[0].value.as < adl::Expr* > ()); }
#line 1306 "Parser.cpp"
    break;

  case 43: // take: TAKE UNION LPAR id COMMA id RPAR
#line 154 "parser.y"
                                                { yylhs.value.as < adl::Expr* > () = new CommandNode(incrementCounter(), "TAKE",yystack_[3].value.as < adl::Expr* > ()); lists.push_back(new CommandNode(incrementCounter(), "TAKE",yystack_[1].value.as < adl::Expr* > ())); }
#line 1312 "Parser.cpp"
    break;

  case 44: // take: COLON UNION LPAR id COMMA id RPAR
#line 155 "parser.y"
                                                { yylhs.value.as < adl::Expr* > () = new CommandNode(incrementCounter(), "TAKE",yystack_[3].value.as < adl::Expr* > ()); lists.push_back(new CommandNode(incrementCounter(), "TAKE",yystack_[1].value.as < adl::Expr* > ())); }
#line 1318 "Parser.cpp"
    break;

  case 45: // take_id: id
#line 158 "parser.y"
                                                { yylhs.value.as < adl::Expr* > () = yystack_[0].value.as < adl::Expr* > (); }
#line 1324 "Parser.cpp"
    break;

  case 46: // take_id: id LPAR id_list RPAR
#line 159 "parser.y"
                                                { yylhs.value.as < adl::Expr* > () = yystack_[3].value.as < adl::Expr* > (); Expr* cn = new CommandNode(incrementCounter(),"TAKE",yystack_[1].value.as < adl::Expr* > ()); lists.push_back(cn); }
#line 1330 "Parser.cpp"
    break;

  case 47: // take_id: id id_list
#line 160 "parser.y"
                                                { yylhs.value.as < adl::Expr* > () = new VarNode(incrementCounter(),"ID",yystack_[1].value.as < adl::Expr* > ()->getId(),yystack_[0].value.as < adl::Expr* > ()->getId(), "", {},""); }
#line 1336 "Parser.cpp"
    break;

  case 48: // id_list: id_list_params
#line 163 "parser.y"
                                                { yylhs.value.as < adl::Expr* > () = yystack_[0].value.as < adl::Expr* > (); }
#line 1342 "Parser.cpp"
    break;

  case 49: // id_list: id_list_params COMMA id_list
#line 164 "parser.y"
                                                { yylhs.value.as < adl::Expr* > () = yystack_[2].value.as < adl::Expr* > (); }
#line 1348 "Parser.cpp"
    break;

  case 50: // id_list_params: id
#line 167 "parser.y"
                                                { yylhs.value.as < adl::Expr* > () = yystack_[0].value.as < adl::Expr* > (); }
#line 1354 "Parser.cpp"
    break;

  case 51: // id_list_params: num
#line 168 "parser.y"
                                                { yylhs.value.as < adl::Expr* > () = yystack_[0].value.as < adl::Expr* > (); }
#line 1360 "Parser.cpp"
    break;

  case 52: // region_block: REGION id criteria
#line 171 "parser.y"
                                                { yylhs.value.as < adl::Expr* > () = new RegionNode(incrementCounter(), "REGION", yystack_[1].value.as < adl::Expr* > (), lists); driver.ast.push_back(yylhs.value.as < adl::Expr* > ()); lists.clear(); /* std::cout << "region: " << $2->getId() << "\n"; */ }
#line 1366 "Parser.cpp"
    break;

  case 53: // region_block: HISTOLIST id criteria
#line 172 "parser.y"
                                                { yylhs.value.as < adl::Expr* > () = new RegionNode(incrementCounter(), "HISTOLIST", yystack_[1].value.as < adl::Expr* > (), lists); driver.ast.push_back(yylhs.value.as < adl::Expr* > ()); lists.clear(); /* std::cout << "histo: " << $2->getId() << "\n"; */ }
#line 1372 "Parser.cpp"
    break;

  case 54: // criteria: criterion criteria
#line 175 "parser.y"
                                                { lists.push_back(yystack_[1].value.as < adl::Expr* > ()); }
#line 1378 "Parser.cpp"
    break;

  case 55: // criteria: criterion
#line 176 "parser.y"
                                                { lists.push_back(yystack_[0].value.as < adl::Expr* > ()); }
#line 1384 "Parser.cpp"
    break;

  case 56: // criterion: COMMAND chained_cond
#line 179 "parser.y"
                                                { yylhs.value.as < adl::Expr* > () = new CommandNode(incrementCounter(), yystack_[1].value.as < std::string > (),yystack_[0].value.as < adl::Expr* > ()); }
#line 1390 "Parser.cpp"
    break;

  case 57: // criterion: HISTO id COMMA DESC comma_sep
#line 180 "parser.y"
                                                { yylhs.value.as < adl::Expr* > () = new HistoNode(incrementCounter(),yystack_[4].value.as < std::string > (),yystack_[3].value.as < adl::Expr* > (),yystack_[1].value.as < std::string > (),histoIntsLists,histoNumsLists,histoBinsLists,histoFuncsLists); }
#line 1396 "Parser.cpp"
    break;

  case 58: // criterion: id
#line 181 "parser.y"
                                                { yylhs.value.as < adl::Expr* > () = new CommandNode(incrementCounter(),"SELECT",yystack_[0].value.as < adl::Expr* > ()); }
#line 1402 "Parser.cpp"
    break;

  case 59: // comma_sep: COMMA comma_sep
#line 184 "parser.y"
                                                {  }
#line 1408 "Parser.cpp"
    break;

  case 60: // comma_sep: num comma_sep
#line 185 "parser.y"
                                                { histoNumsLists.push_back(yystack_[1].value.as < adl::Expr* > ()); }
#line 1414 "Parser.cpp"
    break;

  case 61: // comma_sep: id comma_sep
#line 186 "parser.y"
                                                { histoFuncsLists.push_back(yystack_[1].value.as < adl::Expr* > ()); }
#line 1420 "Parser.cpp"
    break;

  case 62: // comma_sep: function comma_sep
#line 187 "parser.y"
                                                { histoFuncsLists.push_back(yystack_[1].value.as < adl::Expr* > ()); }
#line 1426 "Parser.cpp"
    break;

  case 63: // comma_sep: LBRACKET bins RBRACKET comma_sep
#line 188 "parser.y"
                                                { /*histoBinsLists.push_back($1);*/ }
#line 1432 "Parser.cpp"
    break;

  case 64: // comma_sep: num
#line 189 "parser.y"
                                                { histoNumsLists.push_back(yystack_[0].value.as < adl::Expr* > ()); }
#line 1438 "Parser.cpp"
    break;

  case 65: // comma_sep: id
#line 190 "parser.y"
                                                { histoFuncsLists.push_back(yystack_[0].value.as < adl::Expr* > ()); }
#line 1444 "Parser.cpp"
    break;

  case 66: // comma_sep: LBRACKET bins RBRACKET
#line 191 "parser.y"
                                                { /*histoBinsLists.push_back($1);*/ }
#line 1450 "Parser.cpp"
    break;

  case 67: // comma_sep: function
#line 192 "parser.y"
                                                { histoFuncsLists.push_back(yystack_[0].value.as < adl::Expr* > ()); }
#line 1456 "Parser.cpp"
    break;

  case 68: // bins: bins num
#line 195 "parser.y"
                                                { histoBinsLists.push_back(yystack_[0].value.as < adl::Expr* > ()); }
#line 1462 "Parser.cpp"
    break;

  case 69: // bins: num
#line 196 "parser.y"
                                                { histoBinsLists.push_back(yystack_[0].value.as < adl::Expr* > ()); }
#line 1468 "Parser.cpp"
    break;

  case 70: // chained_cond: LPAR chain RPAR
#line 199 "parser.y"
                                                            { yylhs.value.as < adl::Expr* > () = yystack_[1].value.as < adl::Expr* > (); }
#line 1474 "Parser.cpp"
    break;

  case 71: // chained_cond: LPAR chain RPAR logic_op chained_cond
#line 200 "parser.y"
                                                            { yylhs.value.as < adl::Expr* > () = new adl::BinNode(incrementCounter(), "LOGICOP",yystack_[3].value.as < adl::Expr* > (),yystack_[1].value.as < std::string > (),yystack_[0].value.as < adl::Expr* > ()); }
#line 1480 "Parser.cpp"
    break;

  case 72: // chained_cond: chain
#line 201 "parser.y"
                                                            { yylhs.value.as < adl::Expr* > () = yystack_[0].value.as < adl::Expr* > (); }
#line 1486 "Parser.cpp"
    break;

  case 73: // chained_cond: chain QUES chain COLON chain
#line 202 "parser.y"
                                                            { yylhs.value.as < adl::Expr* > () = new ITENode(incrementCounter(), "ITE", yystack_[4].value.as < adl::Expr* > (), yystack_[2].value.as < adl::Expr* > (), yystack_[0].value.as < adl::Expr* > ()); }
#line 1492 "Parser.cpp"
    break;

  case 74: // chained_cond: chain QUES chain
#line 203 "parser.y"
                                                            { yylhs.value.as < adl::Expr* > () = new ITENode(incrementCounter(), "ITE", yystack_[2].value.as < adl::Expr* > (), yystack_[0].value.as < adl::Expr* > (), nullptr); }
#line 1498 "Parser.cpp"
    break;

  case 75: // chained_cond: id range
#line 204 "parser.y"
                                                            { yylhs.value.as < adl::Expr* > () = new VarNode(incrementCounter(),"ID",yystack_[1].value.as < adl::Expr* > ()->getId(),"","",intLists); intLists.clear(); }
#line 1504 "Parser.cpp"
    break;

  case 76: // chain: condition
#line 207 "parser.y"
                                        { yylhs.value.as < adl::Expr* > () = yystack_[0].value.as < adl::Expr* > (); }
#line 1510 "Parser.cpp"
    break;

  case 77: // chain: condition logic_op chain
#line 208 "parser.y"
                                        { yylhs.value.as < adl::Expr* > () = new adl::BinNode(incrementCounter(), "LOGICOP",yystack_[2].value.as < adl::Expr* > (),yystack_[1].value.as < std::string > (),yystack_[0].value.as < adl::Expr* > ()); }
#line 1516 "Parser.cpp"
    break;

  case 78: // chain: not condition
#line 209 "parser.y"
                                        { paramlist.push_back(yystack_[0].value.as < adl::Expr* > ()); yylhs.value.as < adl::Expr* > () = new adl::FunctionNode(incrementCounter(), "FUNCTION", yystack_[1].value.as < adl::Expr* > (), paramlist); paramlist.clear(); }
#line 1522 "Parser.cpp"
    break;

  case 79: // not: NOT
#line 212 "parser.y"
                                        { yylhs.value.as < adl::Expr* > () = new adl::VarNode(incrementCounter(), "ID", "not", "", "", {},""); }
#line 1528 "Parser.cpp"
    break;

  case 80: // condition: expr
#line 215 "parser.y"
                                        { yylhs.value.as < adl::Expr* > () = yystack_[0].value.as < adl::Expr* > (); }
#line 1534 "Parser.cpp"
    break;

  case 81: // condition: expr compare_op condition
#line 217 "parser.y"
                                        { yylhs.value.as < adl::Expr* > () = new adl::BinNode(incrementCounter(), "COMPAREOP",yystack_[2].value.as < adl::Expr* > (),yystack_[1].value.as < std::string > (),yystack_[0].value.as < adl::Expr* > ()); }
#line 1540 "Parser.cpp"
    break;

  case 82: // condition: expr INCLUSIVE num num
#line 218 "parser.y"
                                        {
                                          Expr* en = yystack_[3].value.as < adl::Expr* > ()->clone(incrementCounter());
                                          Expr* comp1 = new adl::BinNode(incrementCounter(), "COMPAREOP",yystack_[3].value.as < adl::Expr* > (),">=",yystack_[1].value.as < adl::Expr* > ());
                                          Expr* comp2 = new adl::BinNode(incrementCounter(), "COMPAREOP",en,"<=",yystack_[0].value.as < adl::Expr* > ());
                                          yylhs.value.as < adl::Expr* > () = new adl::BinNode(incrementCounter(), "COMPAREOP",comp1,"AND",comp2);
                                        }
#line 1551 "Parser.cpp"
    break;

  case 83: // condition: expr EXCLUSIVE num num
#line 224 "parser.y"
                                        {
                                          Expr* en = yystack_[3].value.as < adl::Expr* > ()->clone(incrementCounter());
                                          Expr* comp1 = new adl::BinNode(incrementCounter(), "COMPAREOP",en,"<=",yystack_[1].value.as < adl::Expr* > ());
                                          Expr* comp2 = new adl::BinNode(incrementCounter(), "COMPAREOP",yystack_[3].value.as < adl::Expr* > (),">=",yystack_[0].value.as < adl::Expr* > ());
                                          yylhs.value.as < adl::Expr* > () = new adl::BinNode(incrementCounter(), "COMPAREOP",comp1,"OR",comp2);
                                        }
#line 1562 "Parser.cpp"
    break;

  case 84: // compare_op: GT
#line 232 "parser.y"
                                  { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1568 "Parser.cpp"
    break;

  case 85: // compare_op: LT
#line 233 "parser.y"
                                  { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1574 "Parser.cpp"
    break;

  case 86: // compare_op: GE
#line 234 "parser.y"
                                  { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1580 "Parser.cpp"
    break;

  case 87: // compare_op: LE
#line 235 "parser.y"
                                  { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1586 "Parser.cpp"
    break;

  case 88: // compare_op: EQ
#line 236 "parser.y"
                                  { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1592 "Parser.cpp"
    break;

  case 89: // compare_op: NE
#line 237 "parser.y"
                                  { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1598 "Parser.cpp"
    break;

  case 90: // logic_op: AND
#line 240 "parser.y"
                                  { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1604 "Parser.cpp"
    break;

  case 91: // logic_op: OR
#line 241 "parser.y"
                                  { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1610 "Parser.cpp"
    break;

  case 92: // expr: factor
#line 244 "parser.y"
                                  { yylhs.value.as < adl::Expr* > () = yystack_[0].value.as < adl::Expr* > (); }
#line 1616 "Parser.cpp"
    break;

  case 93: // expr: factor expr_op expr
#line 245 "parser.y"
                                  { yylhs.value.as < adl::Expr* > () = new adl::BinNode(incrementCounter(), "EXPROP",yystack_[2].value.as < adl::Expr* > (),yystack_[1].value.as < std::string > (),yystack_[0].value.as < adl::Expr* > ()); }
#line 1622 "Parser.cpp"
    break;

  case 94: // expr_op: PLUS
#line 248 "parser.y"
                                  { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1628 "Parser.cpp"
    break;

  case 95: // expr_op: SUBTRACT
#line 249 "parser.y"
                                  { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1634 "Parser.cpp"
    break;

  case 96: // factor: term
#line 252 "parser.y"
                                  { yylhs.value.as < adl::Expr* > () = yystack_[0].value.as < adl::Expr* > (); }
#line 1640 "Parser.cpp"
    break;

  case 97: // factor: term factor_op factor
#line 253 "parser.y"
                                  { yylhs.value.as < adl::Expr* > () = new adl::BinNode(incrementCounter(), "FACTOROP",yystack_[2].value.as < adl::Expr* > (),yystack_[1].value.as < std::string > (),yystack_[0].value.as < adl::Expr* > ()); }
#line 1646 "Parser.cpp"
    break;

  case 98: // factor_op: MULTIPLY
#line 256 "parser.y"
                                  { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1652 "Parser.cpp"
    break;

  case 99: // factor_op: DIVIDE
#line 257 "parser.y"
                                  { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1658 "Parser.cpp"
    break;

  case 100: // factor_op: POW
#line 258 "parser.y"
                                  { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1664 "Parser.cpp"
    break;

  case 101: // term: id_qualifiers
#line 261 "parser.y"
                                  { yylhs.value.as < adl::Expr* > () = yystack_[0].value.as < adl::Expr* > (); }
#line 1670 "Parser.cpp"
    break;

  case 102: // term: function
#line 262 "parser.y"
                                  { yylhs.value.as < adl::Expr* > () = yystack_[0].value.as < adl::Expr* > (); }
#line 1676 "Parser.cpp"
    break;

  case 103: // term: function dot_op
#line 263 "parser.y"
                                  { yylhs.value.as < adl::Expr* > () = yystack_[1].value.as < adl::Expr* > (); }
#line 1682 "Parser.cpp"
    break;

  case 104: // term: num
#line 264 "parser.y"
                                  { yylhs.value.as < adl::Expr* > () = yystack_[0].value.as < adl::Expr* > (); }
#line 1688 "Parser.cpp"
    break;

  case 105: // term: LPAR expr RPAR
#line 265 "parser.y"
                                  { yylhs.value.as < adl::Expr* > () = yystack_[1].value.as < adl::Expr* > (); }
#line 1694 "Parser.cpp"
    break;

  case 106: // id_qualifiers: id_qualifier id_qualifiers
#line 268 "parser.y"
                                              { yylhs.value.as < adl::Expr* > () = new VarNode(incrementCounter(),"ID",yystack_[1].value.as < adl::Expr* > ()->getId(),"",yystack_[0].value.as < adl::Expr* > ()->getId(), {},""); }
#line 1700 "Parser.cpp"
    break;

  case 107: // id_qualifiers: id_qualifier
#line 269 "parser.y"
                                              { yylhs.value.as < adl::Expr* > () = yystack_[0].value.as < adl::Expr* > (); }
#line 1706 "Parser.cpp"
    break;

  case 108: // id_qualifier: dot_op
#line 272 "parser.y"
                                                                 { yylhs.value.as < adl::Expr* > () = yystack_[0].value.as < adl::Expr* > (); }
#line 1712 "Parser.cpp"
    break;

  case 109: // id_qualifier: id
#line 274 "parser.y"
                                                                 { yylhs.value.as < adl::Expr* > () = yystack_[0].value.as < adl::Expr* > (); }
#line 1718 "Parser.cpp"
    break;

  case 110: // id_qualifier: id LBRACKET index RBRACKET
#line 275 "parser.y"
                                                                 { VarNode* vn = static_cast<VarNode*>(yystack_[3].value.as < adl::Expr* > ()); yylhs.value.as < adl::Expr* > () = new VarNode(incrementCounter(),"ID",vn->getId(),vn->getAlias(),vn->getDotOp(),{yystack_[1].value.as < int > ()},vn->getType()); }
#line 1724 "Parser.cpp"
    break;

  case 111: // id_qualifier: id UNDERSCORE index COLON index
#line 276 "parser.y"
                                                                 { VarNode* vn = static_cast<VarNode*>(yystack_[4].value.as < adl::Expr* > ()); yylhs.value.as < adl::Expr* > () = new VarNode(incrementCounter(),"ID",vn->getId(),vn->getAlias(),vn->getDotOp(),{yystack_[2].value.as < int > (), yystack_[0].value.as < int > ()},vn->getType()); }
#line 1730 "Parser.cpp"
    break;

  case 112: // id_qualifier: id UNDERSCORE index
#line 277 "parser.y"
                                                                 { VarNode* vn = static_cast<VarNode*>(yystack_[2].value.as < adl::Expr* > ()); yylhs.value.as < adl::Expr* > () = new VarNode(incrementCounter(),"ID",vn->getId(),vn->getAlias(),vn->getDotOp(),{yystack_[0].value.as < int > ()},vn->getType()); }
#line 1736 "Parser.cpp"
    break;

  case 113: // id_qualifier: id LBRACKET index COLON index RBRACKET
#line 278 "parser.y"
                                                                 { VarNode* vn = static_cast<VarNode*>(yystack_[5].value.as < adl::Expr* > ()); yylhs.value.as < adl::Expr* > () = new VarNode(incrementCounter(),"ID",vn->getId(),vn->getAlias(),vn->getDotOp(),{yystack_[3].value.as < int > (), yystack_[1].value.as < int > ()},vn->getType()); }
#line 1742 "Parser.cpp"
    break;

  case 114: // dot_op: DOT id
#line 284 "parser.y"
                            { yylhs.value.as < adl::Expr* > () = yystack_[0].value.as < adl::Expr* > (); }
#line 1748 "Parser.cpp"
    break;

  case 115: // range: range num
#line 287 "parser.y"
                            { yylhs.value.as < adl::Expr* > () = yystack_[0].value.as < adl::Expr* > (); intLists.push_back(static_cast<int>(yystack_[0].value.as < adl::Expr* > ()->value())); }
#line 1754 "Parser.cpp"
    break;

  case 116: // range: num
#line 288 "parser.y"
                            { yylhs.value.as < adl::Expr* > () = yystack_[0].value.as < adl::Expr* > (); intLists.push_back(static_cast<int>(yystack_[0].value.as < adl::Expr* > ()->value())); }
#line 1760 "Parser.cpp"
    break;

  case 117: // boolean: TRUE
#line 291 "parser.y"
                            { yylhs.value.as < bool > () = 1; }
#line 1766 "Parser.cpp"
    break;

  case 118: // boolean: FALSE
#line 292 "parser.y"
                            { yylhs.value.as < bool > () = 0; }
#line 1772 "Parser.cpp"
    break;

  case 119: // num: int
#line 295 "parser.y"
                            { yylhs.value.as < adl::Expr* > () = yystack_[0].value.as < adl::Expr* > (); }
#line 1778 "Parser.cpp"
    break;

  case 120: // num: real
#line 296 "parser.y"
                            { yylhs.value.as < adl::Expr* > () = yystack_[0].value.as < adl::Expr* > (); }
#line 1784 "Parser.cpp"
    break;

  case 121: // index: SUBTRACT INT
#line 298 "parser.y"
                            { yylhs.value.as < int > () = -yystack_[0].value.as < int > (); }
#line 1790 "Parser.cpp"
    break;

  case 122: // index: INT
#line 299 "parser.y"
                            { yylhs.value.as < int > () = yystack_[0].value.as < int > (); }
#line 1796 "Parser.cpp"
    break;

  case 123: // index: %empty
#line 300 "parser.y"
                            { yylhs.value.as < int > () = 6213;}
#line 1802 "Parser.cpp"
    break;

  case 124: // int: INT
#line 303 "parser.y"
                            { yylhs.value.as < adl::Expr* > () = new adl::NumNode(incrementCounter(), "INT", yystack_[0].value.as < int > ()); }
#line 1808 "Parser.cpp"
    break;

  case 125: // real: REAL
#line 306 "parser.y"
                            { yylhs.value.as < adl::Expr* > () = new adl::NumNode(incrementCounter(), "REAL", yystack_[0].value.as < double > ()); }
#line 1814 "Parser.cpp"
    break;

  case 126: // id: ID
#line 309 "parser.y"
                            { yylhs.value.as < adl::Expr* > () = new adl::VarNode(incrementCounter(), "ID", yystack_[0].value.as < std::string > (), "", "", {},""); }
#line 1820 "Parser.cpp"
    break;


#line 1824 "Parser.cpp"

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
        context yyctx (*this, yyla);
        std::string msg = yysyntax_error_ (yyctx);
        error (yyla.location, YY_MOVE (msg));
      }


    yyerror_range[1].location = yyla.location;
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

        yyerror_range[1].location = yystack_[0].location;
        yy_destroy_ ("Error: popping", yystack_[0]);
        yypop_ ();
        YY_STACK_PRINT ();
      }
    {
      stack_symbol_type error_token;

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

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
   Parser ::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what ());
  }

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
   Parser ::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr;
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              else
                goto append;

            append:
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }

  std::string
   Parser ::symbol_name (symbol_kind_type yysymbol)
  {
    return yytnamerr_ (yytname_[yysymbol]);
  }



  //  Parser ::context.
   Parser ::context::context (const  Parser & yyparser, const symbol_type& yyla)
    : yyparser_ (yyparser)
    , yyla_ (yyla)
  {}

  int
   Parser ::context::expected_tokens (symbol_kind_type yyarg[], int yyargn) const
  {
    // Actual number of expected tokens
    int yycount = 0;

    const int yyn = yypact_[+yyparser_.yystack_[0].state];
    if (!yy_pact_value_is_default_ (yyn))
      {
        /* Start YYX at -YYN if negative to avoid negative indexes in
           YYCHECK.  In other words, skip the first -YYN actions for
           this state because they are default actions.  */
        const int yyxbegin = yyn < 0 ? -yyn : 0;
        // Stay within bounds of both yycheck and yytname.
        const int yychecklim = yylast_ - yyn + 1;
        const int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
        for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
          if (yycheck_[yyx + yyn] == yyx && yyx != symbol_kind::S_YYerror
              && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
            {
              if (!yyarg)
                ++yycount;
              else if (yycount == yyargn)
                return 0;
              else
                yyarg[yycount++] = YY_CAST (symbol_kind_type, yyx);
            }
      }

    if (yyarg && yycount == 0 && 0 < yyargn)
      yyarg[0] = symbol_kind::S_YYEMPTY;
    return yycount;
  }






  int
   Parser ::yy_syntax_error_arguments_ (const context& yyctx,
                                                 symbol_kind_type yyarg[], int yyargn) const
  {
    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state merging
         (from LALR or IELR) and default reductions corrupt the expected
         token list.  However, the list is correct for canonical LR with
         one exception: it will still contain any token that will not be
         accepted due to an error action in a later state.
    */

    if (!yyctx.lookahead ().empty ())
      {
        if (yyarg)
          yyarg[0] = yyctx.token ();
        int yyn = yyctx.expected_tokens (yyarg ? yyarg + 1 : yyarg, yyargn - 1);
        return yyn + 1;
      }
    return 0;
  }

  // Generate an error message.
  std::string
   Parser ::yysyntax_error_ (const context& yyctx) const
  {
    // Its maximum.
    enum { YYARGS_MAX = 5 };
    // Arguments of yyformat.
    symbol_kind_type yyarg[YYARGS_MAX];
    int yycount = yy_syntax_error_arguments_ (yyctx, yyarg, YYARGS_MAX);

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
      default: // Avoid compiler warnings.
        YYCASE_ (0, YY_("syntax error"));
        YYCASE_ (1, YY_("syntax error, unexpected %s"));
        YYCASE_ (2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_ (3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_ (4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_ (5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    std::ptrdiff_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += symbol_name (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const short  Parser ::yypact_ninf_ = -149;

  const signed char  Parser ::yytable_ninf_ = -1;

  const short
   Parser ::yypact_[] =
  {
     208,     1,     1,     1,     1,    35,    61,    64,   179,  -149,
     179,  -149,   226,   179,   179,    90,  -149,   -15,   105,     6,
     105,    57,    61,    61,    61,  -149,  -149,  -149,   179,  -149,
    -149,  -149,  -149,  -149,  -149,    91,    91,    20,     1,  -149,
     105,  -149,   120,   133,   105,     6,  -149,    65,  -149,  -149,
    -149,  -149,    91,    43,    69,     1,  -149,  -149,    32,  -149,
     174,   134,   116,  -149,    -4,  -149,  -149,  -149,  -149,    26,
    -149,    69,  -149,  -149,    45,    91,   175,   110,    47,  -149,
      84,  -149,    12,    97,  -149,  -149,  -149,   109,    98,    87,
      89,    95,   114,   106,  -149,  -149,  -149,  -149,  -149,  -149,
    -149,  -149,   178,   178,    91,  -149,  -149,    91,  -149,  -149,
    -149,    91,  -149,   -22,    69,    -7,    -7,   147,   168,    69,
    -149,  -149,  -149,    69,   178,  -149,   152,     1,    43,  -149,
     137,  -149,  -149,     1,   138,  -149,  -149,  -149,  -149,     1,
      69,   178,   178,  -149,  -149,  -149,   197,   143,  -149,   -24,
     176,   175,   187,  -149,  -149,   136,   190,   202,    43,   191,
     228,  -149,  -149,  -149,  -149,  -149,  -149,  -149,    -7,    -7,
      20,    69,   178,   136,   136,  -149,   136,   107,     1,  -149,
    -149,     1,   200,   199,  -149,  -149,  -149,    46,  -149,  -149,
    -149,  -149,  -149,   225,   227,  -149,  -149,   192,  -149,   136,
    -149,  -149,  -149,  -149,  -149,   192,  -149,  -149
  };

  const signed char
   Parser ::yydefact_[] =
  {
       0,     0,     0,     0,     0,     0,     0,     0,     6,     5,
      16,    20,    18,    25,    14,    21,   126,     0,     0,     0,
       0,     0,    11,    12,    13,     7,     1,     2,    25,    17,
      25,    19,     4,    15,    22,     0,     0,     0,     0,    52,
      55,    58,     0,     0,    37,    40,    53,     0,     8,     9,
      10,     3,     0,     0,     0,     0,   124,   125,   102,    23,
      80,    92,    96,   101,   107,   108,   104,   119,   120,   109,
      24,     0,    79,    56,    72,     0,    76,   109,     0,    54,
       0,    41,    45,     0,    42,    38,    39,     0,     0,     0,
       0,     0,     0,    36,   114,   103,    84,    85,    86,    87,
      88,    89,     0,     0,     0,    94,    95,     0,    98,    99,
     100,     0,   106,   109,     0,   123,   123,     0,    80,     0,
      78,    90,    91,     0,    75,   116,     0,     0,     0,    47,
      48,    51,    50,     0,     0,   105,    32,    33,    34,     0,
       0,     0,     0,    81,    93,    97,     0,     0,   122,     0,
     112,    70,    74,    77,   115,     0,     0,     0,     0,     0,
       0,    31,    35,    82,    83,    30,   121,   110,   123,   123,
       0,     0,     0,     0,    67,    57,    64,    65,     0,    46,
      49,     0,     0,     0,   111,    71,    73,     0,    69,    59,
      62,    60,    61,     0,     0,   117,   118,     0,   113,    66,
      68,    43,    44,    29,    26,    28,    63,    27
  };

  const short
   Parser ::yypgoto_[] =
  {
    -149,  -149,  -149,   172,   214,   233,   234,  -149,    77,    48,
    -149,  -148,   -92,  -149,   203,  -149,   207,  -113,  -149,  -149,
      51,  -149,    -6,  -149,    81,   -31,  -149,   -26,  -149,   101,
     -47,  -149,   144,  -149,  -149,   193,  -149,   196,  -149,  -149,
     -69,  -112,   205,   206,    -1
  };

  const unsigned char
   Parser ::yydefgoto_[] =
  {
       0,     7,     8,    25,     9,    10,    11,    12,    30,   204,
     205,    58,    92,    14,    44,    45,    81,   129,   130,    15,
      39,    40,   175,   187,    73,    93,    75,    76,   104,   123,
      60,   107,    61,   111,    62,    63,    64,    65,   124,   197,
      66,   149,    67,    68,    69
  };

  const unsigned char
   Parser ::yytable_[] =
  {
      17,    18,    19,    20,   150,    88,    74,   174,   125,    59,
      70,    16,    42,   131,    35,   157,    16,    41,   147,    41,
     167,   115,   146,   168,   118,   174,   174,    16,   174,   174,
     128,   116,    36,   141,   142,    16,    77,    78,    71,    41,
     117,    82,    82,    41,   114,   180,    55,   148,   162,   120,
      21,   174,    91,    43,    94,   154,   183,   184,    16,   131,
     144,    72,    53,   113,    26,    54,    56,    57,    47,   115,
      55,    46,   163,   164,    56,    57,    22,    13,   143,   116,
      87,   132,    55,    23,    16,    28,   176,    52,   152,   131,
     199,    79,   153,   119,     2,    85,   126,    56,    57,     4,
      56,    57,   127,   188,   176,   176,    16,   176,   176,    52,
      72,    53,    37,    38,    54,   133,    24,   135,   200,    55,
      16,   134,    16,    56,    57,   114,   156,   132,   114,   136,
     176,   137,   159,    53,    80,    16,    54,   138,   161,    74,
     186,    55,   108,   109,   110,    56,    57,    83,    16,    53,
     172,    16,    54,   115,   177,   140,   173,   132,   105,   106,
     139,    56,    57,   116,    56,    57,   151,   189,   190,    77,
     191,   192,   177,   177,   155,   177,   177,   193,    53,   172,
     194,    54,     1,     2,     3,   173,   158,   135,     4,     5,
      56,    57,   160,   206,    48,    49,    50,   166,   177,    96,
      97,    98,    99,   100,   101,    96,    97,    98,    99,   100,
     101,     1,     2,     3,   121,   122,   165,     4,     5,   102,
     103,   179,    27,   169,    29,   102,   103,    32,    33,     1,
       2,     6,    56,    57,   171,     4,     5,   195,   196,   178,
     181,   182,    51,   198,   201,    31,   202,   203,    86,    34,
      84,   185,   170,   207,    95,   145,     0,   112,    89,    90
  };

  const short
   Parser ::yycheck_[] =
  {
       1,     2,     3,     4,   116,    52,    37,   155,    77,    35,
      36,    15,     6,    82,    29,   128,    15,    18,    25,    20,
      44,    43,   114,    47,    71,   173,   174,    15,   176,   177,
      18,    53,    47,   102,   103,    15,    37,    38,    18,    40,
      71,    42,    43,    44,    18,   158,    50,    54,   140,    75,
      15,   199,    53,    47,    55,   124,   168,   169,    15,   128,
     107,    41,    42,    64,     0,    45,    54,    55,    11,    43,
      50,    20,   141,   142,    54,    55,    15,     0,   104,    53,
      15,    82,    50,    22,    15,     8,   155,    18,   119,   158,
      44,    40,   123,    48,     4,    44,    49,    54,    55,     9,
      54,    55,    18,   172,   173,   174,    15,   176,   177,    18,
      41,    42,     7,     8,    45,    18,    55,    19,   187,    50,
      15,    12,    15,    54,    55,    18,   127,   128,    18,    42,
     199,    42,   133,    42,    14,    15,    45,    42,   139,   170,
     171,    50,    26,    27,    28,    54,    55,    14,    15,    42,
      43,    15,    45,    43,   155,    49,    49,   158,    24,    25,
      46,    54,    55,    53,    54,    55,    19,   173,   174,   170,
     176,   177,   173,   174,    22,   176,   177,   178,    42,    43,
     181,    45,     3,     4,     5,    49,    49,    19,     9,    10,
      54,    55,    54,   199,    22,    23,    24,    54,   199,    31,
      32,    33,    34,    35,    36,    31,    32,    33,    34,    35,
      36,     3,     4,     5,    39,    40,    19,     9,    10,    51,
      52,    19,     8,    47,    10,    51,    52,    13,    14,     3,
       4,    23,    54,    55,    47,     9,    10,    37,    38,    49,
      49,    13,    28,    44,    19,    12,    19,    55,    45,    15,
      43,   170,   151,   205,    58,   111,    -1,    64,    53,    53
  };

  const signed char
   Parser ::yystos_[] =
  {
       0,     3,     4,     5,     9,    10,    23,    57,    58,    60,
      61,    62,    63,    64,    69,    75,    15,   100,   100,   100,
     100,    15,    15,    22,    55,    59,     0,    60,    64,    60,
      64,    61,    60,    60,    62,    29,    47,     7,     8,    76,
      77,   100,     6,    47,    70,    71,    76,    11,    59,    59,
      59,    60,    18,    42,    45,    50,    54,    55,    67,    83,
      86,    88,    90,    91,    92,    93,    96,    98,    99,   100,
      83,    18,    41,    80,    81,    82,    83,   100,   100,    76,
      14,    72,   100,    14,    72,    76,    70,    15,    86,    98,
      99,   100,    68,    81,   100,    93,    31,    32,    33,    34,
      35,    36,    51,    52,    84,    24,    25,    87,    26,    27,
      28,    89,    91,   100,    18,    43,    53,    81,    86,    48,
      83,    39,    40,    85,    94,    96,    49,    18,    18,    73,
      74,    96,   100,    18,    12,    19,    42,    42,    42,    46,
      49,    96,    96,    83,    86,    88,    68,    25,    54,    97,
      97,    19,    81,    81,    96,    22,   100,    73,    49,   100,
      54,   100,    68,    96,    96,    19,    54,    44,    47,    47,
      85,    47,    43,    49,    67,    78,    96,   100,    49,    19,
      73,    49,    13,    97,    97,    80,    81,    79,    96,    78,
      78,    78,    78,   100,   100,    37,    38,    95,    44,    44,
      96,    19,    19,    55,    65,    66,    78,    65
  };

  const signed char
   Parser ::yyr1_[] =
  {
       0,    56,    57,    57,    57,    57,    57,    58,    59,    59,
      59,    59,    59,    59,    60,    60,    60,    60,    61,    61,
      61,    62,    62,    63,    63,    63,    64,    65,    65,    66,
      67,    67,    67,    67,    67,    68,    68,    69,    69,    70,
      70,    71,    71,    71,    71,    72,    72,    72,    73,    73,
      74,    74,    75,    75,    76,    76,    77,    77,    77,    78,
      78,    78,    78,    78,    78,    78,    78,    78,    79,    79,
      80,    80,    80,    80,    80,    80,    81,    81,    81,    82,
      83,    83,    83,    83,    84,    84,    84,    84,    84,    84,
      85,    85,    86,    86,    87,    87,    88,    88,    89,    89,
      89,    90,    90,    90,    90,    90,    91,    91,    92,    92,
      92,    92,    92,    92,    93,    94,    94,    95,    95,    96,
      96,    97,    97,    97,    98,    99,   100
  };

  const signed char
   Parser ::yyr2_[] =
  {
       0,     2,     2,     3,     2,     1,     1,     2,     2,     2,
       2,     1,     1,     1,     1,     2,     1,     2,     1,     2,
       1,     1,     2,     4,     4,     1,     9,     2,     1,     1,
       4,     4,     3,     3,     3,     3,     1,     3,     4,     2,
       1,     2,     2,     7,     7,     1,     4,     2,     1,     3,
       1,     1,     3,     3,     2,     1,     2,     5,     1,     2,
       2,     2,     2,     4,     1,     1,     3,     1,     2,     1,
       3,     5,     1,     5,     3,     2,     1,     3,     2,     1,
       1,     3,     4,     4,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     1,     1,     1,     3,     1,     1,
       1,     1,     1,     2,     1,     3,     2,     1,     1,     1,
       4,     5,     3,     6,     2,     2,     1,     1,     1,     1,
       1,     2,     1,     0,     1,     1,     1
  };


#if YYDEBUG || 1
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const  Parser ::yytname_[] =
  {
  "\"end of file\"", "error", "\"invalid token\"", "DEFINE", "REGION",
  "OBJECT", "TAKE", "COMMAND", "HISTO", "HISTOLIST", "TABLE", "TABLETYPE",
  "NVARS", "ERRORS", "UNION", "ID", "ERROR", "FLAG", "LPAR", "RPAR", "VAR",
  "QUOTE", "DESC", "INFO", "PLUS", "SUBTRACT", "MULTIPLY", "DIVIDE", "POW",
  "ASSIGN", "PLUSMINUS", "GT", "LT", "GE", "LE", "EQ", "NE", "TRUE",
  "FALSE", "AND", "OR", "NOT", "PIPE", "LBRACKET", "RBRACKET", "LCBRACE",
  "RCBRACE", "COLON", "QUES", "COMMA", "DOT", "INCLUSIVE", "EXCLUSIVE",
  "UNDERSCORE", "INT", "REAL", "$accept", "start", "info", "info_list",
  "objects", "definitions", "regions", "definition", "table", "tablelist",
  "value", "function", "param_list", "object_block", "takes", "take",
  "take_id", "id_list", "id_list_params", "region_block", "criteria",
  "criterion", "comma_sep", "bins", "chained_cond", "chain", "not",
  "condition", "compare_op", "logic_op", "expr", "expr_op", "factor",
  "factor_op", "term", "id_qualifiers", "id_qualifier", "dot_op", "range",
  "boolean", "num", "index", "int", "real", "id", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const short
   Parser ::yyrline_[] =
  {
       0,    90,    90,    91,    92,    93,    94,    97,   100,   100,
     100,   100,   100,   100,   103,   104,   105,   106,   109,   110,
     111,   114,   115,   118,   119,   120,   123,   126,   127,   130,
     133,   134,   135,   136,   137,   140,   141,   144,   145,   148,
     149,   152,   153,   154,   155,   158,   159,   160,   163,   164,
     167,   168,   171,   172,   175,   176,   179,   180,   181,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   195,   196,
     199,   200,   201,   202,   203,   204,   207,   208,   209,   212,
     215,   217,   218,   224,   232,   233,   234,   235,   236,   237,
     240,   241,   244,   245,   248,   249,   252,   253,   256,   257,
     258,   261,   262,   263,   264,   265,   268,   269,   272,   274,
     275,   276,   277,   278,   284,   287,   288,   291,   292,   295,
     296,   298,   299,   300,   303,   306,   309
  };

  void
   Parser ::yy_stack_print_ () const
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
   Parser ::yy_reduce_print_ (int yyrule) const
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


#line 10 "parser.y"
} //  adl 
#line 2451 "Parser.cpp"

#line 311 "parser.y"


void adl::Parser::error(const location_type& l, const std::string& msg) {
    std::cerr << "ERROR: line " << incrementCounter() << " : " << msg << "\n";
    std::cerr << " : Last token was " << scanner.YYText() << "\n";
}
