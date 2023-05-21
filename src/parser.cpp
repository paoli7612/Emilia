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





#include "parser.hpp"


// Unqualified %code blocks.
#line 28 "src/parser.yy"

# include "driver.hpp"
# include "AST/IfExprAST.hpp"
# include "AST/SeqAST.hpp"
# include "AST/FunctionAST.hpp"
# include "AST/PrototypeAST.hpp"
# include "AST/NumberExprAST.hpp"
# include "AST/VariableExprAST.hpp"
# include "AST/BinaryExprAST.hpp"
# include "AST/UnaryExprAST.hpp"
# include "AST/CallExprAST.hpp"
# include "AST/ForExprAST.hpp"
# include "AST/VarExprAST.hpp"
# include "AST/WhileExprAST.hpp"

#line 62 "src/parser.cpp"


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

namespace yy {
#line 154 "src/parser.cpp"

  /// Build a parser object.
  parser::parser (driver& drv_yyarg)
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      drv (drv_yyarg)
  {}

  parser::~parser ()
  {}

  parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------.
  | symbol.  |
  `---------*/



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
    : super_type (YY_MOVE (that.state), YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_exp: // exp
      case symbol_kind::S_idexp: // idexp
      case symbol_kind::S_ifexp: // ifexp
      case symbol_kind::S_forexp: // forexp
      case symbol_kind::S_step: // step
      case symbol_kind::S_whilexp: // whilexp
      case symbol_kind::S_varexp: // varexp
      case symbol_kind::S_assignment: // assignment
        value.YY_MOVE_OR_COPY< ExprAST* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_definition: // definition
        value.YY_MOVE_OR_COPY< FunctionAST* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_external: // external
      case symbol_kind::S_proto: // proto
        value.YY_MOVE_OR_COPY< PrototypeAST* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_program: // program
      case symbol_kind::S_top: // top
        value.YY_MOVE_OR_COPY< RootAST* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_NUMBER: // "number"
        value.YY_MOVE_OR_COPY< double > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_pair: // pair
        value.YY_MOVE_OR_COPY< std::pair<std::string,ExprAST*> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_IDENTIFIER: // "id"
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_optexp: // optexp
      case symbol_kind::S_explist: // explist
        value.YY_MOVE_OR_COPY< std::vector<ExprAST*> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_varlist: // varlist
        value.YY_MOVE_OR_COPY< std::vector<std::pair<std::string, ExprAST*>> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_idseq: // idseq
        value.YY_MOVE_OR_COPY< std::vector<std::string> > (YY_MOVE (that.value));
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
    : super_type (s, YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_exp: // exp
      case symbol_kind::S_idexp: // idexp
      case symbol_kind::S_ifexp: // ifexp
      case symbol_kind::S_forexp: // forexp
      case symbol_kind::S_step: // step
      case symbol_kind::S_whilexp: // whilexp
      case symbol_kind::S_varexp: // varexp
      case symbol_kind::S_assignment: // assignment
        value.move< ExprAST* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_definition: // definition
        value.move< FunctionAST* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_external: // external
      case symbol_kind::S_proto: // proto
        value.move< PrototypeAST* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_program: // program
      case symbol_kind::S_top: // top
        value.move< RootAST* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_NUMBER: // "number"
        value.move< double > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_pair: // pair
        value.move< std::pair<std::string,ExprAST*> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_IDENTIFIER: // "id"
        value.move< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_optexp: // optexp
      case symbol_kind::S_explist: // explist
        value.move< std::vector<ExprAST*> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_varlist: // varlist
        value.move< std::vector<std::pair<std::string, ExprAST*>> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_idseq: // idseq
        value.move< std::vector<std::string> > (YY_MOVE (that.value));
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
      case symbol_kind::S_exp: // exp
      case symbol_kind::S_idexp: // idexp
      case symbol_kind::S_ifexp: // ifexp
      case symbol_kind::S_forexp: // forexp
      case symbol_kind::S_step: // step
      case symbol_kind::S_whilexp: // whilexp
      case symbol_kind::S_varexp: // varexp
      case symbol_kind::S_assignment: // assignment
        value.copy< ExprAST* > (that.value);
        break;

      case symbol_kind::S_definition: // definition
        value.copy< FunctionAST* > (that.value);
        break;

      case symbol_kind::S_external: // external
      case symbol_kind::S_proto: // proto
        value.copy< PrototypeAST* > (that.value);
        break;

      case symbol_kind::S_program: // program
      case symbol_kind::S_top: // top
        value.copy< RootAST* > (that.value);
        break;

      case symbol_kind::S_NUMBER: // "number"
        value.copy< double > (that.value);
        break;

      case symbol_kind::S_pair: // pair
        value.copy< std::pair<std::string,ExprAST*> > (that.value);
        break;

      case symbol_kind::S_IDENTIFIER: // "id"
        value.copy< std::string > (that.value);
        break;

      case symbol_kind::S_optexp: // optexp
      case symbol_kind::S_explist: // explist
        value.copy< std::vector<ExprAST*> > (that.value);
        break;

      case symbol_kind::S_varlist: // varlist
        value.copy< std::vector<std::pair<std::string, ExprAST*>> > (that.value);
        break;

      case symbol_kind::S_idseq: // idseq
        value.copy< std::vector<std::string> > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }

  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_exp: // exp
      case symbol_kind::S_idexp: // idexp
      case symbol_kind::S_ifexp: // ifexp
      case symbol_kind::S_forexp: // forexp
      case symbol_kind::S_step: // step
      case symbol_kind::S_whilexp: // whilexp
      case symbol_kind::S_varexp: // varexp
      case symbol_kind::S_assignment: // assignment
        value.move< ExprAST* > (that.value);
        break;

      case symbol_kind::S_definition: // definition
        value.move< FunctionAST* > (that.value);
        break;

      case symbol_kind::S_external: // external
      case symbol_kind::S_proto: // proto
        value.move< PrototypeAST* > (that.value);
        break;

      case symbol_kind::S_program: // program
      case symbol_kind::S_top: // top
        value.move< RootAST* > (that.value);
        break;

      case symbol_kind::S_NUMBER: // "number"
        value.move< double > (that.value);
        break;

      case symbol_kind::S_pair: // pair
        value.move< std::pair<std::string,ExprAST*> > (that.value);
        break;

      case symbol_kind::S_IDENTIFIER: // "id"
        value.move< std::string > (that.value);
        break;

      case symbol_kind::S_optexp: // optexp
      case symbol_kind::S_explist: // explist
        value.move< std::vector<ExprAST*> > (that.value);
        break;

      case symbol_kind::S_varlist: // varlist
        value.move< std::vector<std::pair<std::string, ExprAST*>> > (that.value);
        break;

      case symbol_kind::S_idseq: // idseq
        value.move< std::vector<std::string> > (that.value);
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
  parser::yypop_ (int n) YY_NOEXCEPT
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
  parser::yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  parser::yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT
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
            symbol_type yylookahead (yylex (drv));
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
      case symbol_kind::S_exp: // exp
      case symbol_kind::S_idexp: // idexp
      case symbol_kind::S_ifexp: // ifexp
      case symbol_kind::S_forexp: // forexp
      case symbol_kind::S_step: // step
      case symbol_kind::S_whilexp: // whilexp
      case symbol_kind::S_varexp: // varexp
      case symbol_kind::S_assignment: // assignment
        yylhs.value.emplace< ExprAST* > ();
        break;

      case symbol_kind::S_definition: // definition
        yylhs.value.emplace< FunctionAST* > ();
        break;

      case symbol_kind::S_external: // external
      case symbol_kind::S_proto: // proto
        yylhs.value.emplace< PrototypeAST* > ();
        break;

      case symbol_kind::S_program: // program
      case symbol_kind::S_top: // top
        yylhs.value.emplace< RootAST* > ();
        break;

      case symbol_kind::S_NUMBER: // "number"
        yylhs.value.emplace< double > ();
        break;

      case symbol_kind::S_pair: // pair
        yylhs.value.emplace< std::pair<std::string,ExprAST*> > ();
        break;

      case symbol_kind::S_IDENTIFIER: // "id"
        yylhs.value.emplace< std::string > ();
        break;

      case symbol_kind::S_optexp: // optexp
      case symbol_kind::S_explist: // explist
        yylhs.value.emplace< std::vector<ExprAST*> > ();
        break;

      case symbol_kind::S_varlist: // varlist
        yylhs.value.emplace< std::vector<std::pair<std::string, ExprAST*>> > ();
        break;

      case symbol_kind::S_idseq: // idseq
        yylhs.value.emplace< std::vector<std::string> > ();
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
  case 2: // startsymb: program
#line 113 "src/parser.yy"
                        { drv.root = yystack_[0].value.as < RootAST* > (); }
#line 798 "src/parser.cpp"
    break;

  case 3: // program: %empty
#line 116 "src/parser.yy"
                        { yylhs.value.as < RootAST* > () = new SeqAST(nullptr,nullptr); }
#line 804 "src/parser.cpp"
    break;

  case 4: // program: top ";" program
#line 117 "src/parser.yy"
                        { yylhs.value.as < RootAST* > () = new SeqAST(yystack_[2].value.as < RootAST* > (),yystack_[0].value.as < RootAST* > ()); }
#line 810 "src/parser.cpp"
    break;

  case 5: // top: %empty
#line 121 "src/parser.yy"
                        { yylhs.value.as < RootAST* > () = nullptr; }
#line 816 "src/parser.cpp"
    break;

  case 6: // top: definition
#line 122 "src/parser.yy"
                        { yylhs.value.as < RootAST* > () = yystack_[0].value.as < FunctionAST* > (); }
#line 822 "src/parser.cpp"
    break;

  case 7: // top: external
#line 123 "src/parser.yy"
                        { yylhs.value.as < RootAST* > () = yystack_[0].value.as < PrototypeAST* > (); }
#line 828 "src/parser.cpp"
    break;

  case 8: // top: exp
#line 124 "src/parser.yy"
                        { yylhs.value.as < RootAST* > () = yystack_[0].value.as < ExprAST* > (); yystack_[0].value.as < ExprAST* > ()->toggle(); }
#line 834 "src/parser.cpp"
    break;

  case 9: // definition: "def" proto exp
#line 128 "src/parser.yy"
                        { yylhs.value.as < FunctionAST* > () = new FunctionAST(yystack_[1].value.as < PrototypeAST* > (),yystack_[0].value.as < ExprAST* > ()); yystack_[1].value.as < PrototypeAST* > ()->noemit(); }
#line 840 "src/parser.cpp"
    break;

  case 10: // external: "extern" proto
#line 132 "src/parser.yy"
                        { yylhs.value.as < PrototypeAST* > () = yystack_[0].value.as < PrototypeAST* > (); }
#line 846 "src/parser.cpp"
    break;

  case 11: // proto: "id" "(" idseq ")"
#line 136 "src/parser.yy"
                        { yylhs.value.as < PrototypeAST* > () = new PrototypeAST(yystack_[3].value.as < std::string > (),yystack_[1].value.as < std::vector<std::string> > ()); }
#line 852 "src/parser.cpp"
    break;

  case 12: // idseq: %empty
#line 140 "src/parser.yy"
                        { std::vector<std::string> args;
                          yylhs.value.as < std::vector<std::string> > () = args; }
#line 859 "src/parser.cpp"
    break;

  case 13: // idseq: "id" idseq
#line 142 "src/parser.yy"
                        { yystack_[0].value.as < std::vector<std::string> > ().insert(yystack_[0].value.as < std::vector<std::string> > ().begin(),yystack_[1].value.as < std::string > ()); yylhs.value.as < std::vector<std::string> > () = yystack_[0].value.as < std::vector<std::string> > (); }
#line 865 "src/parser.cpp"
    break;

  case 14: // exp: exp "+" exp
#line 146 "src/parser.yy"
                        { yylhs.value.as < ExprAST* > () = new BinaryExprAST('+',yystack_[2].value.as < ExprAST* > (),yystack_[0].value.as < ExprAST* > ()); }
#line 871 "src/parser.cpp"
    break;

  case 15: // exp: exp "-" exp
#line 147 "src/parser.yy"
                        { yylhs.value.as < ExprAST* > () = new BinaryExprAST('-',yystack_[2].value.as < ExprAST* > (),yystack_[0].value.as < ExprAST* > ()); }
#line 877 "src/parser.cpp"
    break;

  case 16: // exp: exp "*" exp
#line 148 "src/parser.yy"
                        { yylhs.value.as < ExprAST* > () = new BinaryExprAST('*',yystack_[2].value.as < ExprAST* > (),yystack_[0].value.as < ExprAST* > ()); }
#line 883 "src/parser.cpp"
    break;

  case 17: // exp: exp "/" exp
#line 149 "src/parser.yy"
                        { yylhs.value.as < ExprAST* > () = new BinaryExprAST('/',yystack_[2].value.as < ExprAST* > (),yystack_[0].value.as < ExprAST* > ()); }
#line 889 "src/parser.cpp"
    break;

  case 18: // exp: exp "%" exp
#line 150 "src/parser.yy"
                        { yylhs.value.as < ExprAST* > () = new BinaryExprAST('%',yystack_[2].value.as < ExprAST* > (),yystack_[0].value.as < ExprAST* > ()); }
#line 895 "src/parser.cpp"
    break;

  case 19: // exp: exp "<=" exp
#line 151 "src/parser.yy"
                        { yylhs.value.as < ExprAST* > () = new BinaryExprAST('l',yystack_[2].value.as < ExprAST* > (),yystack_[0].value.as < ExprAST* > ()); }
#line 901 "src/parser.cpp"
    break;

  case 20: // exp: exp ">=" exp
#line 152 "src/parser.yy"
                        { yylhs.value.as < ExprAST* > () = new BinaryExprAST('g',yystack_[2].value.as < ExprAST* > (),yystack_[0].value.as < ExprAST* > ()); }
#line 907 "src/parser.cpp"
    break;

  case 21: // exp: exp "<" exp
#line 153 "src/parser.yy"
                        { yylhs.value.as < ExprAST* > () = new BinaryExprAST('<',yystack_[2].value.as < ExprAST* > (),yystack_[0].value.as < ExprAST* > ()); }
#line 913 "src/parser.cpp"
    break;

  case 22: // exp: exp ">" exp
#line 154 "src/parser.yy"
                        { yylhs.value.as < ExprAST* > () = new BinaryExprAST('>',yystack_[2].value.as < ExprAST* > (),yystack_[0].value.as < ExprAST* > ()); }
#line 919 "src/parser.cpp"
    break;

  case 23: // exp: exp "==" exp
#line 155 "src/parser.yy"
                        { yylhs.value.as < ExprAST* > () = new BinaryExprAST('e',yystack_[2].value.as < ExprAST* > (),yystack_[0].value.as < ExprAST* > ()); }
#line 925 "src/parser.cpp"
    break;

  case 24: // exp: exp "!=" exp
#line 156 "src/parser.yy"
                        { yylhs.value.as < ExprAST* > () = new BinaryExprAST('!',yystack_[2].value.as < ExprAST* > (),yystack_[0].value.as < ExprAST* > ()); }
#line 931 "src/parser.cpp"
    break;

  case 25: // exp: idexp
#line 157 "src/parser.yy"
                        { yylhs.value.as < ExprAST* > () = yystack_[0].value.as < ExprAST* > (); }
#line 937 "src/parser.cpp"
    break;

  case 26: // exp: "(" exp ")"
#line 158 "src/parser.yy"
                        { yylhs.value.as < ExprAST* > () = yystack_[1].value.as < ExprAST* > (); }
#line 943 "src/parser.cpp"
    break;

  case 27: // exp: "number"
#line 159 "src/parser.yy"
                        { yylhs.value.as < ExprAST* > () = new NumberExprAST(yystack_[0].value.as < double > ()); }
#line 949 "src/parser.cpp"
    break;

  case 28: // exp: "-" exp
#line 160 "src/parser.yy"
                        { yylhs.value.as < ExprAST* > () = new UnaryExprAST('-', yystack_[0].value.as < ExprAST* > ()); }
#line 955 "src/parser.cpp"
    break;

  case 29: // exp: "!" exp
#line 161 "src/parser.yy"
                   { yylhs.value.as < ExprAST* > () = new UnaryExprAST('!', yystack_[0].value.as < ExprAST* > ()); }
#line 961 "src/parser.cpp"
    break;

  case 30: // exp: exp ":" exp
#line 162 "src/parser.yy"
                        { yylhs.value.as < ExprAST* > () = new BinaryExprAST(':', yystack_[2].value.as < ExprAST* > (), yystack_[0].value.as < ExprAST* > ()); }
#line 967 "src/parser.cpp"
    break;

  case 31: // exp: ifexp
#line 163 "src/parser.yy"
                        { yylhs.value.as < ExprAST* > () = yystack_[0].value.as < ExprAST* > (); }
#line 973 "src/parser.cpp"
    break;

  case 32: // exp: forexp
#line 164 "src/parser.yy"
                        { yylhs.value.as < ExprAST* > () = yystack_[0].value.as < ExprAST* > (); }
#line 979 "src/parser.cpp"
    break;

  case 33: // exp: varexp
#line 165 "src/parser.yy"
                        { yylhs.value.as < ExprAST* > () = yystack_[0].value.as < ExprAST* > (); }
#line 985 "src/parser.cpp"
    break;

  case 34: // exp: assignment
#line 166 "src/parser.yy"
                        { yylhs.value.as < ExprAST* > () = yystack_[0].value.as < ExprAST* > (); }
#line 991 "src/parser.cpp"
    break;

  case 35: // exp: whilexp
#line 167 "src/parser.yy"
                        { yylhs.value.as < ExprAST* > () = yystack_[0].value.as < ExprAST* > (); }
#line 997 "src/parser.cpp"
    break;

  case 36: // idexp: "id"
#line 171 "src/parser.yy"
                        { yylhs.value.as < ExprAST* > () = new VariableExprAST(yystack_[0].value.as < std::string > ()); }
#line 1003 "src/parser.cpp"
    break;

  case 37: // idexp: "id" "(" optexp ")"
#line 172 "src/parser.yy"
                        { yylhs.value.as < ExprAST* > () = new CallExprAST(yystack_[3].value.as < std::string > (),yystack_[1].value.as < std::vector<ExprAST*> > ()); }
#line 1009 "src/parser.cpp"
    break;

  case 38: // optexp: %empty
#line 176 "src/parser.yy"
                        { std::vector<ExprAST*> args;
                          args.push_back(nullptr);
			                    yylhs.value.as < std::vector<ExprAST*> > () = args; }
#line 1017 "src/parser.cpp"
    break;

  case 39: // optexp: explist
#line 179 "src/parser.yy"
                        { yylhs.value.as < std::vector<ExprAST*> > () = yystack_[0].value.as < std::vector<ExprAST*> > (); }
#line 1023 "src/parser.cpp"
    break;

  case 40: // explist: exp
#line 182 "src/parser.yy"
                        { std::vector<ExprAST*> args;
                          args.push_back(yystack_[0].value.as < ExprAST* > ());
			                    yylhs.value.as < std::vector<ExprAST*> > () = args; }
#line 1031 "src/parser.cpp"
    break;

  case 41: // explist: exp "," explist
#line 185 "src/parser.yy"
                        { yystack_[0].value.as < std::vector<ExprAST*> > ().insert(yystack_[0].value.as < std::vector<ExprAST*> > ().begin(), yystack_[2].value.as < ExprAST* > ()); yylhs.value.as < std::vector<ExprAST*> > () = yystack_[0].value.as < std::vector<ExprAST*> > (); }
#line 1037 "src/parser.cpp"
    break;

  case 42: // ifexp: "if" exp "then" exp "else" exp "end"
#line 189 "src/parser.yy"
                                  { yylhs.value.as < ExprAST* > () = new IfExprAST(yystack_[5].value.as < ExprAST* > (), yystack_[3].value.as < ExprAST* > (), yystack_[1].value.as < ExprAST* > ());}
#line 1043 "src/parser.cpp"
    break;

  case 43: // forexp: "for" "id" "=" exp "," exp step "do" exp "end"
#line 194 "src/parser.yy"
                                             { yylhs.value.as < ExprAST* > () = new ForExprAST(yystack_[8].value.as < std::string > (), yystack_[6].value.as < ExprAST* > (), yystack_[4].value.as < ExprAST* > (), yystack_[3].value.as < ExprAST* > (), yystack_[1].value.as < ExprAST* > ()); }
#line 1049 "src/parser.cpp"
    break;

  case 44: // step: "," exp
#line 198 "src/parser.yy"
            { yylhs.value.as < ExprAST* > () = yystack_[0].value.as < ExprAST* > (); }
#line 1055 "src/parser.cpp"
    break;

  case 45: // step: %empty
#line 199 "src/parser.yy"
            { yylhs.value.as < ExprAST* > () = new NumberExprAST(1.0); }
#line 1061 "src/parser.cpp"
    break;

  case 46: // whilexp: "while" exp "do" exp "end"
#line 203 "src/parser.yy"
                         { yylhs.value.as < ExprAST* > () = new WhileExprAST(yystack_[3].value.as < ExprAST* > (), yystack_[1].value.as < ExprAST* > ()); }
#line 1067 "src/parser.cpp"
    break;

  case 47: // varexp: "with" varlist "do" exp "end"
#line 207 "src/parser.yy"
                                { yylhs.value.as < ExprAST* > () = new VarExprAST(yystack_[3].value.as < std::vector<std::pair<std::string, ExprAST*>> > (), yystack_[1].value.as < ExprAST* > ()); }
#line 1073 "src/parser.cpp"
    break;

  case 48: // varlist: pair
#line 211 "src/parser.yy"
                              { std::vector<std::pair<std::string, ExprAST*>> args;
                                args.push_back(yystack_[0].value.as < std::pair<std::string,ExprAST*> > ());
                                yylhs.value.as < std::vector<std::pair<std::string, ExprAST*>> > () = args; }
#line 1081 "src/parser.cpp"
    break;

  case 49: // varlist: pair "," varlist
#line 214 "src/parser.yy"
                              { yystack_[0].value.as < std::vector<std::pair<std::string, ExprAST*>> > ().insert(yystack_[0].value.as < std::vector<std::pair<std::string, ExprAST*>> > ().begin(), yystack_[2].value.as < std::pair<std::string,ExprAST*> > ()); yylhs.value.as < std::vector<std::pair<std::string, ExprAST*>> > () = yystack_[0].value.as < std::vector<std::pair<std::string, ExprAST*>> > (); }
#line 1087 "src/parser.cpp"
    break;

  case 50: // pair: "id"
#line 218 "src/parser.yy"
                          { yylhs.value.as < std::pair<std::string,ExprAST*> > () = std::make_pair(yystack_[0].value.as < std::string > (), new NumberExprAST(0.0)); }
#line 1093 "src/parser.cpp"
    break;

  case 51: // pair: "id" "=" exp
#line 219 "src/parser.yy"
                          { yylhs.value.as < std::pair<std::string,ExprAST*> > () = std::make_pair(yystack_[2].value.as < std::string > (), yystack_[0].value.as < ExprAST* > ()); }
#line 1099 "src/parser.cpp"
    break;

  case 52: // assignment: "id" "=" exp
#line 223 "src/parser.yy"
                            { yylhs.value.as < ExprAST* > () = new BinaryExprAST('=', new VariableExprAST(yystack_[2].value.as < std::string > ()), yystack_[0].value.as < ExprAST* > ()); }
#line 1105 "src/parser.cpp"
    break;


#line 1109 "src/parser.cpp"

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
  parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what ());
  }

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  parser::yytnamerr_ (const char *yystr)
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
  parser::symbol_name (symbol_kind_type yysymbol)
  {
    return yytnamerr_ (yytname_[yysymbol]);
  }



  // parser::context.
  parser::context::context (const parser& yyparser, const symbol_type& yyla)
    : yyparser_ (yyparser)
    , yyla_ (yyla)
  {}

  int
  parser::context::expected_tokens (symbol_kind_type yyarg[], int yyargn) const
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
  parser::yy_syntax_error_arguments_ (const context& yyctx,
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
  parser::yysyntax_error_ (const context& yyctx) const
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


  const signed char parser::yypact_ninf_ = -31;

  const signed char parser::yytable_ninf_ = -6;

  const short
  parser::yypact_[] =
  {
      48,    -2,    -2,    -2,   -30,   -30,    -2,   -28,   -27,    -2,
       1,   -31,    15,   -31,    17,   -31,   -31,   333,   -31,   -31,
     -31,   -31,   -31,   -31,    11,   318,   348,     6,   -31,    -2,
     248,     5,     7,    -5,    27,   200,    -2,    -2,   -31,    48,
      -2,    -2,    -2,    -2,    -2,    -2,    -2,    -2,    -2,    -2,
      -2,    -2,   -31,     0,   333,    -2,    -2,    -2,    -2,   -27,
      -2,   271,    20,   -31,   348,   -31,    11,    11,   -31,   -31,
      11,     4,     4,     4,     4,     4,     4,   333,     0,    21,
     225,   287,   333,    96,   -31,   122,    -2,   -31,   -31,   -31,
      -2,    -2,   -31,   -31,   -31,   148,   303,   -31,    -2,    23,
     333,    -2,   174,   -31
  };

  const signed char
  parser::yydefact_[] =
  {
       3,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      36,    27,     0,     2,     0,     6,     7,     8,    25,    31,
      32,    35,    33,    34,    28,     0,    29,     0,    10,     0,
       0,     0,    50,     0,    48,     0,    38,     0,     1,     3,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    26,    12,     9,     0,     0,     0,     0,     0,
       0,    40,     0,    39,    52,     4,    15,    14,    16,    17,
      18,    22,    21,    20,    19,    23,    24,    30,    12,     0,
       0,     0,    51,     0,    49,     0,     0,    37,    13,    11,
       0,     0,    47,    46,    41,     0,    45,    42,     0,     0,
      44,     0,     0,    43
  };

  const signed char
  parser::yypgoto_[] =
  {
     -31,   -31,    19,   -31,   -31,   -31,    55,   -17,    -1,   -31,
     -31,   -24,   -31,   -31,   -31,   -31,   -31,     8,   -31,   -31
  };

  const signed char
  parser::yydefgoto_[] =
  {
       0,    12,    13,    14,    15,    16,    28,    79,    17,    18,
      62,    63,    19,    20,    99,    21,    22,    33,    34,    23
  };

  const signed char
  parser::yytable_[] =
  {
      24,    25,    26,     1,    27,    30,    31,    32,    35,    40,
      41,    42,    43,    44,     2,    38,     3,    36,    42,    43,
      39,    37,    53,     6,    58,    56,     7,    57,    54,     8,
       9,    59,    10,    11,    78,    61,    64,    87,    89,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    -5,   101,     1,    80,    81,    82,    83,    65,    85,
      29,    88,    94,     0,     2,     0,     3,    84,     0,     0,
       0,     4,     5,     6,     0,     0,     7,     0,     0,     8,
       9,     0,    10,    11,     0,    61,     0,     0,     0,    95,
      96,     0,     0,     0,     0,     0,     0,   100,     0,     0,
     102,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,     0,     0,     0,    51,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    92,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,     0,     0,
       0,    51,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    93,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,     0,     0,     0,    51,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    97,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
       0,     0,     0,    51,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   103,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,     0,     0,     0,    51,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    60,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,     0,     0,     0,    51,     0,     0,     0,     0,     0,
       0,     0,    90,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,     0,     0,     0,    51,     0,     0,
       0,     0,     0,     0,    55,    86,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,     0,     0,     0,
      51,    91,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,     0,     0,     0,    51,    98,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,     0,
       0,     0,    51,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,     0,    52,     0,    51,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,     0,
       0,     0,    51,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50
  };

  const signed char
  parser::yycheck_[] =
  {
       1,     2,     3,     5,    34,     6,    34,    34,     9,     5,
       6,     7,     8,     9,    16,     0,    18,    16,     7,     8,
       3,    20,    16,    25,    29,    20,    28,    20,    29,    31,
      32,     4,    34,    35,    34,    36,    37,    17,    17,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,     3,    29,     5,    55,    56,    57,    58,    39,    60,
       5,    78,    86,    -1,    16,    -1,    18,    59,    -1,    -1,
      -1,    23,    24,    25,    -1,    -1,    28,    -1,    -1,    31,
      32,    -1,    34,    35,    -1,    86,    -1,    -1,    -1,    90,
      91,    -1,    -1,    -1,    -1,    -1,    -1,    98,    -1,    -1,
     101,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    -1,    -1,    -1,    19,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    30,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    -1,    -1,
      -1,    19,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    30,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    -1,    -1,    -1,    19,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      -1,    -1,    -1,    19,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    30,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    -1,    -1,    -1,    19,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    -1,    -1,    -1,    19,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    27,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    -1,    -1,    -1,    19,    -1,    -1,
      -1,    -1,    -1,    -1,    26,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    -1,    -1,    -1,
      19,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    -1,    -1,    -1,    19,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    -1,
      -1,    -1,    19,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    -1,    17,    -1,    19,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    -1,
      -1,    -1,    19,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15
  };

  const signed char
  parser::yystos_[] =
  {
       0,     5,    16,    18,    23,    24,    25,    28,    31,    32,
      34,    35,    37,    38,    39,    40,    41,    44,    45,    48,
      49,    51,    52,    55,    44,    44,    44,    34,    42,    42,
      44,    34,    34,    53,    54,    44,    16,    20,     0,     3,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    19,    17,    16,    44,    26,    20,    20,    29,     4,
      29,    44,    46,    47,    44,    38,    44,    44,    44,    44,
      44,    44,    44,    44,    44,    44,    44,    44,    34,    43,
      44,    44,    44,    44,    53,    44,     4,    17,    43,    17,
      27,     4,    30,    30,    47,    44,    44,    30,     4,    50,
      44,    29,    44,    30
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    36,    37,    38,    38,    39,    39,    39,    39,    40,
      41,    42,    43,    43,    44,    44,    44,    44,    44,    44,
      44,    44,    44,    44,    44,    44,    44,    44,    44,    44,
      44,    44,    44,    44,    44,    44,    45,    45,    46,    46,
      47,    47,    48,    49,    50,    50,    51,    52,    53,    53,
      54,    54,    55
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     1,     0,     3,     0,     1,     1,     1,     3,
       2,     4,     0,     2,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     1,     3,     1,     2,     2,
       3,     1,     1,     1,     1,     1,     1,     4,     0,     1,
       1,     3,     7,    10,     2,     0,     5,     5,     1,     3,
       1,     3,     3
  };


#if YYDEBUG || 1
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "\"end of file\"", "error", "\"invalid token\"", "\";\"", "\",\"",
  "\"-\"", "\"+\"", "\"*\"", "\"/\"", "\"%\"", "\">\"", "\"<\"", "\">=\"",
  "\"<=\"", "\"==\"", "\"!=\"", "\"(\"", "\")\"", "\"!\"", "\":\"",
  "\"=\"", "\"[\"", "\"]\"", "\"extern\"", "\"def\"", "\"if\"", "\"then\"",
  "\"else\"", "\"for\"", "\"do\"", "\"end\"", "\"with\"", "\"while\"",
  "\"arrof\"", "\"id\"", "\"number\"", "$accept", "startsymb", "program",
  "top", "definition", "external", "proto", "idseq", "exp", "idexp",
  "optexp", "explist", "ifexp", "forexp", "step", "whilexp", "varexp",
  "varlist", "pair", "assignment", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const unsigned char
  parser::yyrline_[] =
  {
       0,   113,   113,   116,   117,   121,   122,   123,   124,   128,
     132,   136,   140,   142,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   171,   172,   176,   179,
     182,   185,   189,   194,   198,   199,   203,   207,   211,   214,
     218,   219,   223
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


} // yy
#line 1694 "src/parser.cpp"

#line 226 "src/parser.yy"


void
yy::parser::error (const location_type& l, const std::string& m)
{
  std::cerr << l << ": " << m << '\n';
}
