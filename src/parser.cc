// A Bison parser, made by GNU Bison 3.0.4.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015 Free Software Foundation, Inc.

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

// Take the name prefix into account.
#define yylex   GLEFFECTSlex

// First part of user declarations.
#line 4 "parser.yy" // lalr1.cc:404
 /*** C/C++ Declarations ***/

#include <cstdio>
#include <string>
#include <vector>

#include "gleffects.h"

class TechniqueNode;



#line 51 "parser.cc" // lalr1.cc:404

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

#include "parser.h"

// User implementation prologue.
#line 133 "parser.yy" // lalr1.cc:412


#include "driver.h"
#include "scanner.h"

/* this "connects" the bison parser in the driver to the flex scanner class
 * object. it defines the yylex() function call to pull the next token from the
 * current lexer object of the driver context. */
#undef yylex
#define yylex driver.lexer->lex


#line 77 "parser.cc" // lalr1.cc:412


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
    while (/*CONSTCOND*/ false)
# endif


// Suppress unused-variable warnings by "using" E.
#define YYUSE(E) ((void) (E))

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
      *yycdebug_ << std::endl;                  \
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
      yystack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE(Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void>(0)
# define YY_STACK_PRINT()                static_cast<void>(0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)


namespace GLEFFECTS {
#line 163 "parser.cc" // lalr1.cc:479

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  Parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr = "";
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
              // Fall through.
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


  /// Build a parser object.
  Parser::Parser (class Driver& driver_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      driver (driver_yyarg)
  {}

  Parser::~Parser ()
  {}


  /*---------------.
  | Symbol types.  |
  `---------------*/

  inline
  Parser::syntax_error::syntax_error (const location_type& l, const std::string& m)
    : std::runtime_error (m)
    , location (l)
  {}

  // basic_symbol.
  template <typename Base>
  inline
  Parser::basic_symbol<Base>::basic_symbol ()
    : value ()
  {}

  template <typename Base>
  inline
  Parser::basic_symbol<Base>::basic_symbol (const basic_symbol& other)
    : Base (other)
    , value ()
    , location (other.location)
  {
    value = other.value;
  }


  template <typename Base>
  inline
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const semantic_type& v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}


  /// Constructor for valueless symbols.
  template <typename Base>
  inline
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const location_type& l)
    : Base (t)
    , value ()
    , location (l)
  {}

  template <typename Base>
  inline
  Parser::basic_symbol<Base>::~basic_symbol ()
  {
    clear ();
  }

  template <typename Base>
  inline
  void
  Parser::basic_symbol<Base>::clear ()
  {
    Base::clear ();
  }

  template <typename Base>
  inline
  bool
  Parser::basic_symbol<Base>::empty () const
  {
    return Base::type_get () == empty_symbol;
  }

  template <typename Base>
  inline
  void
  Parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move(s);
    value = s.value;
    location = s.location;
  }

  // by_type.
  inline
  Parser::by_type::by_type ()
    : type (empty_symbol)
  {}

  inline
  Parser::by_type::by_type (const by_type& other)
    : type (other.type)
  {}

  inline
  Parser::by_type::by_type (token_type t)
    : type (yytranslate_ (t))
  {}

  inline
  void
  Parser::by_type::clear ()
  {
    type = empty_symbol;
  }

  inline
  void
  Parser::by_type::move (by_type& that)
  {
    type = that.type;
    that.clear ();
  }

  inline
  int
  Parser::by_type::type_get () const
  {
    return type;
  }


  // by_state.
  inline
  Parser::by_state::by_state ()
    : state (empty_state)
  {}

  inline
  Parser::by_state::by_state (const by_state& other)
    : state (other.state)
  {}

  inline
  void
  Parser::by_state::clear ()
  {
    state = empty_state;
  }

  inline
  void
  Parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  inline
  Parser::by_state::by_state (state_type s)
    : state (s)
  {}

  inline
  Parser::symbol_number_type
  Parser::by_state::type_get () const
  {
    if (state == empty_state)
      return empty_symbol;
    else
      return yystos_[state];
  }

  inline
  Parser::stack_symbol_type::stack_symbol_type ()
  {}


  inline
  Parser::stack_symbol_type::stack_symbol_type (state_type s, symbol_type& that)
    : super_type (s, that.location)
  {
    value = that.value;
    // that is emptied.
    that.type = empty_symbol;
  }

  inline
  Parser::stack_symbol_type&
  Parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    value = that.value;
    location = that.location;
    return *this;
  }


  template <typename Base>
  inline
  void
  Parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);

    // User destructor.
    switch (yysym.type_get ())
    {
            case 11: // IDENTIFIER

#line 118 "parser.yy" // lalr1.cc:617
        { delete (yysym.value.stringVal); }
#line 416 "parser.cc" // lalr1.cc:617
        break;

      case 31: // stmt_string

#line 119 "parser.yy" // lalr1.cc:617
        { delete (yysym.value.stringVal); }
#line 423 "parser.cc" // lalr1.cc:617
        break;

      case 32: // stmt_state_value

#line 123 "parser.yy" // lalr1.cc:617
        { delete (yysym.value.stateValue); }
#line 430 "parser.cc" // lalr1.cc:617
        break;

      case 34: // stmt_state

#line 124 "parser.yy" // lalr1.cc:617
        { delete (yysym.value.stateAssignmentValue); }
#line 437 "parser.cc" // lalr1.cc:617
        break;

      case 35: // stmt_state_list

#line 125 "parser.yy" // lalr1.cc:617
        { delete (yysym.value.stateAssignmentValues); }
#line 444 "parser.cc" // lalr1.cc:617
        break;

      case 36: // stmt_pass

#line 121 "parser.yy" // lalr1.cc:617
        { delete (yysym.value.passValue); }
#line 451 "parser.cc" // lalr1.cc:617
        break;

      case 37: // stmt_pass_list

#line 122 "parser.yy" // lalr1.cc:617
        { delete (yysym.value.passValues); }
#line 458 "parser.cc" // lalr1.cc:617
        break;

      case 38: // stmt_tec

#line 120 "parser.yy" // lalr1.cc:617
        { delete (yysym.value.techValue); }
#line 465 "parser.cc" // lalr1.cc:617
        break;

      case 40: // stmt_code_block

#line 126 "parser.yy" // lalr1.cc:617
        { delete (yysym.value.codeblockValue); }
#line 472 "parser.cc" // lalr1.cc:617
        break;

      case 41: // stmt_uniform

#line 128 "parser.yy" // lalr1.cc:617
        { delete (yysym.value.uniformValue); }
#line 479 "parser.cc" // lalr1.cc:617
        break;

      case 42: // stmt_uniform_list

#line 129 "parser.yy" // lalr1.cc:617
        { delete (yysym.value.uniformValues); }
#line 486 "parser.cc" // lalr1.cc:617
        break;

      case 43: // stmt_code_block_list

#line 127 "parser.yy" // lalr1.cc:617
        { delete (yysym.value.codeblockValues); }
#line 493 "parser.cc" // lalr1.cc:617
        break;


      default:
        break;
    }
  }

#if YYDEBUG
  template <typename Base>
  void
  Parser::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
    // Avoid a (spurious) G++ 4.8 warning about "array subscript is
    // below array bounds".
    if (yysym.empty ())
      std::abort ();
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " ("
        << yysym.location << ": ";
    YYUSE (yytype);
    yyo << ')';
  }
#endif

  inline
  void
  Parser::yypush_ (const char* m, state_type s, symbol_type& sym)
  {
    stack_symbol_type t (s, sym);
    yypush_ (m, t);
  }

  inline
  void
  Parser::yypush_ (const char* m, stack_symbol_type& s)
  {
    if (m)
      YY_SYMBOL_PRINT (m, s);
    yystack_.push (s);
  }

  inline
  void
  Parser::yypop_ (unsigned int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  Parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  Parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  Parser::debug_level_type
  Parser::debug_level () const
  {
    return yydebug_;
  }

  void
  Parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  inline Parser::state_type
  Parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  inline bool
  Parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  inline bool
  Parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  Parser::parse ()
  {
    // State.
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

    // FIXME: This shoud be completely indented.  It is not yet to
    // avoid gratuitous conflicts when merging into the master branch.
    try
      {
    YYCDEBUG << "Starting parse" << std::endl;


    // User initialization code.
    #line 44 "parser.yy" // lalr1.cc:745
{
    // initialize the initial location object
    yyla.location.begin.filename = yyla.location.end.filename = &driver.streamname;
}

#line 631 "parser.cc" // lalr1.cc:745

    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, yyla);

    // A new symbol was pushed on the stack.
  yynewstate:
    YYCDEBUG << "Entering state " << yystack_[0].state << std::endl;

    // Accept?
    if (yystack_[0].state == yyfinal_)
      goto yyacceptlab;

    goto yybackup;

    // Backup.
  yybackup:

    // Try to take a decision without lookahead.
    yyn = yypact_[yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token: ";
        try
          {
            yyla.type = yytranslate_ (yylex (&yyla.value, &yyla.location));
          }
        catch (const syntax_error& yyexc)
          {
            error (yyexc);
            goto yyerrlab1;
          }
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
      goto yydefault;

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
    yypush_ ("Shifting", yyn, yyla);
    goto yynewstate;

  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;

  /*-----------------------------.
  | yyreduce -- Do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_(yystack_[yylen].state, yyr1_[yyn]);
      /* If YYLEN is nonzero, implement the default value of the
         action: '$$ = $1'.  Otherwise, use the top of the stack.

         Otherwise, the following line sets YYLHS.VALUE to garbage.
         This behavior is undocumented and Bison users should not rely
         upon it.  */
      if (yylen)
        yylhs.value = yystack_[yylen - 1].value;
      else
        yylhs.value = yystack_[0].value;

      // Compute the default @$.
      {
        slice<stack_symbol_type, stack_type> slice (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, slice, yylen);
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
      try
        {
          switch (yyn)
            {
  case 2:
#line 150 "parser.yy" // lalr1.cc:859
    {(yylhs.value.floatVal) = (yystack_[0].value.floatVal);}
#line 741 "parser.cc" // lalr1.cc:859
    break;

  case 3:
#line 151 "parser.yy" // lalr1.cc:859
    {(yylhs.value.floatVal) = (yystack_[0].value.integerVal);}
#line 747 "parser.cc" // lalr1.cc:859
    break;

  case 4:
#line 153 "parser.yy" // lalr1.cc:859
    {(yylhs.value.stringVal) = (yystack_[0].value.stringVal);}
#line 753 "parser.cc" // lalr1.cc:859
    break;

  case 5:
#line 154 "parser.yy" // lalr1.cc:859
    {(yylhs.value.stringVal) = (yystack_[0].value.stringVal);}
#line 759 "parser.cc" // lalr1.cc:859
    break;

  case 6:
#line 155 "parser.yy" // lalr1.cc:859
    {(yylhs.value.stringVal) = (yystack_[0].value.stringVal);}
#line 765 "parser.cc" // lalr1.cc:859
    break;

  case 7:
#line 158 "parser.yy" // lalr1.cc:859
    {(yylhs.value.stateValue) = new StateIntegerValue((yystack_[0].value.integerVal));}
#line 771 "parser.cc" // lalr1.cc:859
    break;

  case 8:
#line 159 "parser.yy" // lalr1.cc:859
    {(yylhs.value.stateValue) = new StateFloatValue((yystack_[0].value.floatVal));}
#line 777 "parser.cc" // lalr1.cc:859
    break;

  case 9:
#line 160 "parser.yy" // lalr1.cc:859
    {(yylhs.value.stateValue) = new StateBooleanValue((yystack_[0].value.boolVal));}
#line 783 "parser.cc" // lalr1.cc:859
    break;

  case 10:
#line 161 "parser.yy" // lalr1.cc:859
    {(yylhs.value.stateValue) = new StateStringValue(*(yystack_[0].value.stringVal));delete (yystack_[0].value.stringVal);}
#line 789 "parser.cc" // lalr1.cc:859
    break;

  case 11:
#line 162 "parser.yy" // lalr1.cc:859
    {(yylhs.value.stateValue) = new StateCompileValue(*(yystack_[3].value.stringVal),*(yystack_[2].value.stringVal));delete (yystack_[3].value.stringVal);delete (yystack_[2].value.stringVal);}
#line 795 "parser.cc" // lalr1.cc:859
    break;

  case 12:
#line 163 "parser.yy" // lalr1.cc:859
    {(yylhs.value.stateValue) = new StateCompileValue(*(yystack_[3].value.stringVal),*(yystack_[2].value.stringVal));delete (yystack_[3].value.stringVal);delete (yystack_[2].value.stringVal);}
#line 801 "parser.cc" // lalr1.cc:859
    break;

  case 13:
#line 164 "parser.yy" // lalr1.cc:859
    {
					float temp[2] = {(yystack_[3].value.floatVal),(yystack_[1].value.floatVal)};
					(yylhs.value.stateValue) = new StateFloat2Value(temp);
				}
#line 810 "parser.cc" // lalr1.cc:859
    break;

  case 14:
#line 168 "parser.yy" // lalr1.cc:859
    {
					float temp[3] = {(yystack_[5].value.floatVal),(yystack_[3].value.floatVal),(yystack_[1].value.floatVal)};
					(yylhs.value.stateValue) = new StateFloat3Value(temp);
				}
#line 819 "parser.cc" // lalr1.cc:859
    break;

  case 15:
#line 172 "parser.yy" // lalr1.cc:859
    {
					float temp[4] = {(yystack_[7].value.floatVal),(yystack_[5].value.floatVal),(yystack_[3].value.floatVal),(yystack_[1].value.floatVal)};
					(yylhs.value.stateValue) = new StateFloat4Value(temp);
				}
#line 828 "parser.cc" // lalr1.cc:859
    break;

  case 16:
#line 178 "parser.yy" // lalr1.cc:859
    {(yylhs.value.integerVal) = (yystack_[1].value.integerVal);}
#line 834 "parser.cc" // lalr1.cc:859
    break;

  case 17:
#line 180 "parser.yy" // lalr1.cc:859
    {(yylhs.value.stateAssignmentValue) = new StateAssignmentNode(*(yystack_[3].value.stringVal),(yystack_[1].value.stateValue),-1);delete (yystack_[3].value.stringVal);}
#line 840 "parser.cc" // lalr1.cc:859
    break;

  case 18:
#line 181 "parser.yy" // lalr1.cc:859
    {(yylhs.value.stateAssignmentValue) = new StateAssignmentNode(*(yystack_[4].value.stringVal),(yystack_[1].value.stateValue),(yystack_[3].value.integerVal));delete (yystack_[4].value.stringVal);}
#line 846 "parser.cc" // lalr1.cc:859
    break;

  case 19:
#line 183 "parser.yy" // lalr1.cc:859
    {(yylhs.value.stateAssignmentValues) = new std::vector<StateAssignmentNode*>();}
#line 852 "parser.cc" // lalr1.cc:859
    break;

  case 20:
#line 184 "parser.yy" // lalr1.cc:859
    {
												(yylhs.value.stateAssignmentValues) = new std::vector<StateAssignmentNode*>();
												(yylhs.value.stateAssignmentValues)->push_back((yystack_[1].value.stateAssignmentValue));
												(yylhs.value.stateAssignmentValues)->insert((yylhs.value.stateAssignmentValues)->end(),(yystack_[0].value.stateAssignmentValues)->begin(),(yystack_[0].value.stateAssignmentValues)->end());
												delete (yystack_[0].value.stateAssignmentValues);
											  }
#line 863 "parser.cc" // lalr1.cc:859
    break;

  case 21:
#line 191 "parser.yy" // lalr1.cc:859
    {(yylhs.value.passValue) = new PassNode(*(yystack_[3].value.stringVal),*(yystack_[1].value.stateAssignmentValues));delete (yystack_[3].value.stringVal);}
#line 869 "parser.cc" // lalr1.cc:859
    break;

  case 22:
#line 193 "parser.yy" // lalr1.cc:859
    {(yylhs.value.passValues) = new std::vector<PassNode*>();(yylhs.value.passValues)->push_back((yystack_[0].value.passValue));}
#line 875 "parser.cc" // lalr1.cc:859
    break;

  case 23:
#line 194 "parser.yy" // lalr1.cc:859
    {
											(yylhs.value.passValues) = new std::vector<PassNode*>();
											(yylhs.value.passValues)->push_back((yystack_[1].value.passValue));
											(yylhs.value.passValues)->insert((yylhs.value.passValues)->end(),(yystack_[0].value.passValues)->begin(),(yystack_[0].value.passValues)->end());
											delete (yystack_[0].value.passValues);
										   }
#line 886 "parser.cc" // lalr1.cc:859
    break;

  case 24:
#line 201 "parser.yy" // lalr1.cc:859
    {
                                                                (yylhs.value.techValue) = new TechniqueNode(*(yystack_[3].value.stringVal),*(yystack_[1].value.passValues));
																driver.tree.AddTechnique(*(yylhs.value.techValue));
																delete (yystack_[3].value.stringVal);
                                                                delete (yystack_[1].value.passValues);
                                                            }
#line 897 "parser.cc" // lalr1.cc:859
    break;

  case 25:
#line 208 "parser.yy" // lalr1.cc:859
    {}
#line 903 "parser.cc" // lalr1.cc:859
    break;

  case 26:
#line 209 "parser.yy" // lalr1.cc:859
    {}
#line 909 "parser.cc" // lalr1.cc:859
    break;

  case 27:
#line 211 "parser.yy" // lalr1.cc:859
    {
					(yylhs.value.codeblockValue) = new CodeBlock(*(yystack_[0].value.stringVal),*(yystack_[1].value.stringVal));
					delete (yystack_[0].value.stringVal);
					delete (yystack_[1].value.stringVal);
					driver.tree.AddCodeBlock((yylhs.value.codeblockValue));
				}
#line 920 "parser.cc" // lalr1.cc:859
    break;

  case 28:
#line 217 "parser.yy" // lalr1.cc:859
    {
					(yylhs.value.codeblockValue) = new CodeBlock(*(yystack_[0].value.stringVal),*(yystack_[1].value.stringVal));
					delete (yystack_[0].value.stringVal);
					delete (yystack_[1].value.stringVal);
					driver.tree.AddCodeBlock((yylhs.value.codeblockValue));
				}
#line 931 "parser.cc" // lalr1.cc:859
    break;

  case 29:
#line 224 "parser.yy" // lalr1.cc:859
    {
				Uniform* value = new Uniform(*(yystack_[2].value.stringVal),*(yystack_[1].value.stringVal),"");
				delete (yystack_[2].value.stringVal);
				delete (yystack_[1].value.stringVal);
				driver.tree.AddUniform(*value);
}
#line 942 "parser.cc" // lalr1.cc:859
    break;

  case 30:
#line 230 "parser.yy" // lalr1.cc:859
    {
				Uniform* value = new Uniform(*(yystack_[4].value.stringVal),*(yystack_[3].value.stringVal),*(yystack_[1].value.stringVal));
				delete (yystack_[4].value.stringVal);
				delete (yystack_[3].value.stringVal);
				delete (yystack_[1].value.stringVal);
				driver.tree.AddUniform(*value);

}
#line 955 "parser.cc" // lalr1.cc:859
    break;

  case 31:
#line 239 "parser.yy" // lalr1.cc:859
    {}
#line 961 "parser.cc" // lalr1.cc:859
    break;

  case 32:
#line 240 "parser.yy" // lalr1.cc:859
    {}
#line 967 "parser.cc" // lalr1.cc:859
    break;

  case 33:
#line 241 "parser.yy" // lalr1.cc:859
    {}
#line 973 "parser.cc" // lalr1.cc:859
    break;

  case 34:
#line 243 "parser.yy" // lalr1.cc:859
    {}
#line 979 "parser.cc" // lalr1.cc:859
    break;

  case 35:
#line 244 "parser.yy" // lalr1.cc:859
    {}
#line 985 "parser.cc" // lalr1.cc:859
    break;

  case 37:
#line 248 "parser.yy" // lalr1.cc:859
    {}
#line 991 "parser.cc" // lalr1.cc:859
    break;


#line 995 "parser.cc" // lalr1.cc:859
            default:
              break;
            }
        }
      catch (const syntax_error& yyexc)
        {
          error (yyexc);
          YYERROR;
        }
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;
      YY_STACK_PRINT ();

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, yylhs);
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
        error (yyla.location, yysyntax_error_ (yystack_[0].state, yyla));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
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

    /* Pacify compilers like GCC when the user code never invokes
       YYERROR and the label yyerrorlab therefore never appears in user
       code.  */
    if (false)
      goto yyerrorlab;
    yyerror_range[1].location = yystack_[yylen - 1].location;
    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    goto yyerrlab1;

  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    {
      stack_symbol_type error_token;
      for (;;)
        {
          yyn = yypact_[yystack_[0].state];
          if (!yy_pact_value_is_default_ (yyn))
            {
              yyn += yyterror_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
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

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = yyn;
      yypush_ ("Shifting", error_token);
    }
    goto yynewstate;

    // Accept.
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;

    // Abort.
  yyabortlab:
    yyresult = 1;
    goto yyreturn;

  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack"
                 << std::endl;
        // Do not try to display the values of the reclaimed symbols,
        // as their printer might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
  }

  void
  Parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what());
  }

  // Generate an error message.
  std::string
  Parser::yysyntax_error_ (state_type yystate, const symbol_type& yyla) const
  {
    // Number of reported tokens (one for the "unexpected", one per
    // "expected").
    size_t yycount = 0;
    // Its maximum.
    enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
    // Arguments of yyformat.
    char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];

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
         scanner and before detecting a syntax error.  Thus, state
         merging (from LALR or IELR) and default reductions corrupt the
         expected token list.  However, the list is correct for
         canonical LR with one exception: it will still contain any
         token that will not be accepted due to an error action in a
         later state.
    */
    if (!yyla.empty ())
      {
        int yytoken = yyla.type_get ();
        yyarg[yycount++] = yytname_[yytoken];
        int yyn = yypact_[yystate];
        if (!yy_pact_value_is_default_ (yyn))
          {
            /* Start YYX at -YYN if negative to avoid negative indexes in
               YYCHECK.  In other words, skip the first -YYN actions for
               this state because they are default actions.  */
            int yyxbegin = yyn < 0 ? -yyn : 0;
            // Stay within bounds of both yycheck and yytname.
            int yychecklim = yylast_ - yyn + 1;
            int yyxend = yychecklim < yyntokens_ ? yychecklim : yyntokens_;
            for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
              if (yycheck_[yyx + yyn] == yyx && yyx != yyterror_
                  && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
                {
                  if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                    {
                      yycount = 1;
                      break;
                    }
                  else
                    yyarg[yycount++] = yytname_[yyx];
                }
          }
      }

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
        YYCASE_(0, YY_("syntax error"));
        YYCASE_(1, YY_("syntax error, unexpected %s"));
        YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    size_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += yytnamerr_ (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const signed char Parser::yypact_ninf_ = -57;

  const signed char Parser::yytable_ninf_ = -1;

  const signed char
  Parser::yypact_[] =
  {
      -4,   -16,     1,    20,    -3,     0,     1,    21,   -57,   -57,
     -57,   -57,    -3,    -3,    -1,   -57,   -57,   -57,    13,    21,
     -57,   -23,   -57,   -57,     3,   -57,   -57,    -3,    28,     8,
      23,    28,    11,   -57,    14,   -57,   -57,    26,   -10,    26,
      12,    24,    39,    18,   -57,   -57,    33,    17,    32,    38,
     -57,   -57,   -57,    -3,   -57,    34,    39,   -57,     9,     9,
       9,    10,   -57,    35,   -57,   -57,    41,    42,    43,    47,
      48,   -57,     9,     9,     9,    25,    40,    45,    49,    50,
     -57,   -57,   -57,     9,     9,    46,    51,   -57,     9,    52,
     -57
  };

  const unsigned char
  Parser::yydefact_[] =
  {
       0,     0,     0,     0,    31,     0,    34,     0,     1,     5,
       4,     6,     0,    31,     0,    27,    28,    35,     0,    25,
      37,     0,    33,    36,     0,    26,    29,     0,     0,     0,
       0,    22,     0,    30,     0,    23,    24,    19,     0,    19,
       0,     0,     0,     0,    20,    21,     0,     0,     0,     0,
       7,     8,     9,     0,    10,     0,     0,    16,     0,     0,
       0,     0,    17,     0,     3,     2,     0,     0,     0,     0,
       0,    18,     0,     0,     0,     0,     0,     0,     0,     0,
      12,    11,    13,     0,     0,     0,     0,    14,     0,     0,
      15
  };

  const signed char
  Parser::yypgoto_[] =
  {
     -57,   -56,   -12,    16,   -57,   -57,    29,   -57,    44,   -57,
      55,   -57,   -57,    63,    71,   -57,   -57
  };

  const signed char
  Parser::yydefgoto_[] =
  {
      -1,    66,    12,    55,    43,    39,    40,    31,    32,    19,
      20,     6,    13,    14,     7,     2,     3
  };

  const unsigned char
  Parser::yytable_[] =
  {
      21,     1,    26,    67,    68,    27,     9,    10,    11,    15,
       4,    16,    41,     5,    42,    29,    77,    78,    79,    69,
       8,    70,    64,    65,    24,    18,    23,    85,    86,    28,
      54,    30,    89,    33,    34,    38,    58,    46,    36,    45,
      37,    61,    56,    80,    54,    47,    48,    49,     9,    10,
      11,    59,    50,    51,    52,    53,    57,    60,    81,    62,
      71,    72,    73,    74,    75,    76,    82,    87,    44,    83,
      84,    88,    63,    90,    25,    35,    22,    17
  };

  const unsigned char
  Parser::yycheck_[] =
  {
      12,     5,    25,    59,    60,    28,     9,    10,    11,     9,
      26,    11,    22,    12,    24,    27,    72,    73,    74,     9,
       0,    11,    13,    14,    11,     4,    27,    83,    84,    26,
      42,     3,    88,    25,    11,     9,    19,    13,    27,    27,
      26,    53,    24,    18,    56,     6,     7,     8,     9,    10,
      11,    19,    13,    14,    15,    16,    23,    19,    18,    25,
      25,    20,    20,    20,    17,    17,    21,    21,    39,    20,
      20,    20,    56,    21,    19,    31,    13,     6
  };

  const unsigned char
  Parser::yystos_[] =
  {
       0,     5,    44,    45,    26,    12,    40,    43,     0,     9,
      10,    11,    31,    41,    42,     9,    11,    43,     4,    38,
      39,    31,    42,    27,    11,    39,    25,    28,    26,    31,
       3,    36,    37,    25,    11,    37,    27,    26,     9,    34,
      35,    22,    24,    33,    35,    27,    13,     6,     7,     8,
      13,    14,    15,    16,    31,    32,    24,    23,    19,    19,
      19,    31,    25,    32,    13,    14,    30,    30,    30,     9,
      11,    25,    20,    20,    20,    17,    17,    30,    30,    30,
      18,    18,    21,    20,    20,    30,    30,    21,    20,    30,
      21
  };

  const unsigned char
  Parser::yyr1_[] =
  {
       0,    29,    30,    30,    31,    31,    31,    32,    32,    32,
      32,    32,    32,    32,    32,    32,    33,    34,    34,    35,
      35,    36,    37,    37,    38,    39,    39,    40,    40,    41,
      41,    42,    42,    42,    43,    43,    44,    45
  };

  const unsigned char
  Parser::yyr2_[] =
  {
       0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     5,     5,     6,     8,    10,     3,     4,     5,     0,
       2,     5,     1,     2,     5,     1,     2,     2,     2,     3,
       5,     0,     1,     2,     1,     2,     4,     3
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const Parser::yytname_[] =
  {
  "END", "error", "$undefined", "PASS", "TECHNIQUE", "UNIFORMS", "FLOAT2",
  "FLOAT3", "FLOAT4", "STATE_NAME", "STRING", "IDENTIFIER", "CODE_BLOCK",
  "INTEGER", "FLOAT", "BOOLEAN", "COMPILE", "'('", "')'", "'<'", "','",
  "'>'", "'['", "']'", "'='", "';'", "'{'", "'}'", "':'", "$accept",
  "stmt_float", "stmt_string", "stmt_state_value", "stmt_state_name_index",
  "stmt_state", "stmt_state_list", "stmt_pass", "stmt_pass_list",
  "stmt_tec", "stmt_tec_list", "stmt_code_block", "stmt_uniform",
  "stmt_uniform_list", "stmt_code_block_list", "stmt_uniform_block",
  "start", YY_NULLPTR
  };

#if YYDEBUG
  const unsigned char
  Parser::yyrline_[] =
  {
       0,   150,   150,   151,   153,   154,   155,   158,   159,   160,
     161,   162,   163,   164,   168,   172,   178,   180,   181,   183,
     184,   191,   193,   194,   201,   208,   209,   211,   217,   224,
     230,   239,   240,   241,   243,   244,   246,   248
  };

  // Print the state stack on the debug stream.
  void
  Parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << i->state;
    *yycdebug_ << std::endl;
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  Parser::yy_reduce_print_ (int yyrule)
  {
    unsigned int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):" << std::endl;
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG

  // Symbol number corresponding to token number t.
  inline
  Parser::token_number_type
  Parser::yytranslate_ (int t)
  {
    static
    const token_number_type
    translate_table[] =
    {
     0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      17,    18,     2,     2,    20,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    28,    25,
      19,    24,    21,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    22,     2,    23,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    26,     2,    27,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16
    };
    const unsigned int user_token_number_max_ = 271;
    const token_number_type undef_token_ = 2;

    if (static_cast<int>(t) <= yyeof_)
      return yyeof_;
    else if (static_cast<unsigned int> (t) <= user_token_number_max_)
      return translate_table[t];
    else
      return undef_token_;
  }


} // GLEFFECTS
#line 1465 "parser.cc" // lalr1.cc:1167
#line 252 "parser.yy" // lalr1.cc:1168
 /*** Additional Code ***/

void GLEFFECTS::Parser::error(const Parser::location_type& l,
			    const std::string& m)
{
    driver.error(l, m);
}
