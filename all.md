--- PARSER 
%skeleton "lalr1.cc" /* -*- C++ -*- */
%require "3.2"
%defines

%define api.token.constructor
%define api.location.file none
%define api.value.type variant
%define parse.assert

%code requires {
  #include <string>
  #include <exception>
  class RootAST;
  class ExprAST;
  class driver;
  class FunctionAST;
  class PrototypeAST;
}

// The parsing context.
%param { driver& drv }

%locations

%define parse.trace
%define parse.error verbose

%code {
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
}

%define api.token.prefix {TOK_}
%token
  END 0 "end of file"
  SEMICOLON  ";"
  COMMA      ","
  MINUS      "-"
  PLUS       "+"
  STAR       "*"
  SLASH      "/"
  MODULO     "%"
  GT         ">"
  LT         "<"
  GE         ">="
  LE         "<="
  EQ         "=="
  NE         "!="
  LPAREN     "("
  RPAREN     ")"
  NOT        "!"
  CONCAT     ":"
  ASSIGN     "="
  LSQUARE    "["
  RSQUARE    "]"
  EXTERN     "extern"
  FUN        "fun"
  IF         "if"
  THEN       "then"
  ELSE       "else"
  FOR        "for"
  DO         "do"
  ENDKW      "end"
  WITH        "with"
  WHILE      "while"
  ARROF      "arrof"
;

%token <std::string> IDENTIFIER "id"
%token <double> NUMBER "number"
%type <ExprAST*> exp
%type <ExprAST*> idexp
%type <std::vector<ExprAST*>> optexp
%type <std::vector<ExprAST*>> explist
%type <ExprAST*> ifexp
%type <ExprAST*> forexp
%type <ExprAST*> whilexp
%type <ExprAST*> step
%type <RootAST*> program
%type <RootAST*> top
%type <FunctionAST*> definition
%type <PrototypeAST*> external
%type <PrototypeAST*> proto
%type <std::vector<std::string>> idseq
%type <ExprAST*> varexp
%type <ExprAST*> assignment
%type <std::pair<std::string,ExprAST*>> pair
%type <std::vector<std::pair<std::string, ExprAST*>>> varlist

%right ":"
%left "="
%left "!"
%left "<" ">" EQ NE LE GE
%left "+" "-" "%"
%left "*" "/"

%%
%start startsymb;

startsymb:
program                 { drv.root = $1; };

program:
  %empty                { $$ = new SeqAST(nullptr,nullptr); }
|  top ";" program      { $$ = new SeqAST($1,$3); }
;

top:
%empty                  { $$ = nullptr; }
| definition            { $$ = $1; }
| external              { $$ = $1; }
| exp                   { $$ = $1; $1->toggle(); }
;

definition:
  "fun" proto exp       { $$ = new FunctionAST($2,$3); $2->noemit(); }
;

external:
  "extern" proto        { $$ = $2; }
;

proto:
  "id" "(" idseq ")"    { $$ = new PrototypeAST($1,$3); }
;

idseq:
  %empty                { std::vector<std::string> args;
                          $$ = args; }
| "id" idseq            { $2.insert($2.begin(),$1); $$ = $2; }
;

exp:
  exp "+" exp           { $$ = new BinaryExprAST('+',$1,$3); }
| exp "-" exp           { $$ = new BinaryExprAST('-',$1,$3); }
| exp "*" exp           { $$ = new BinaryExprAST('*',$1,$3); }
| exp "/" exp           { $$ = new BinaryExprAST('/',$1,$3); }
| exp "%" exp           { $$ = new BinaryExprAST('%',$1,$3); }
| exp LE  exp %prec LE  { $$ = new BinaryExprAST('l',$1,$3); }
| exp GE  exp %prec GE  { $$ = new BinaryExprAST('g',$1,$3); }
| exp "<" exp           { $$ = new BinaryExprAST('<',$1,$3); }
| exp ">" exp           { $$ = new BinaryExprAST('>',$1,$3); }
| exp EQ exp            { $$ = new BinaryExprAST('e',$1,$3); }
| exp NE exp            { $$ = new BinaryExprAST('!',$1,$3); }
| idexp                 { $$ = $1; }
| "(" exp ")"           { $$ = $2; }
| "number"              { $$ = new NumberExprAST($1); }
| "-" exp               { $$ = new UnaryExprAST('-', $2); }
| "!" exp          { $$ = new UnaryExprAST('!', $2); }
| exp ":" exp           { $$ = new BinaryExprAST(':', $1, $3); }
| ifexp                 { $$ = $1; }
| forexp                { $$ = $1; }
| varexp                { $$ = $1; }
| assignment            { $$ = $1; }
| whilexp               { $$ = $1; }
;

idexp:
  "id"                  { $$ = new VariableExprAST($1); }
| "id" "(" optexp ")"   { $$ = new CallExprAST($1,$3); }
;

optexp:
%empty                  { std::vector<ExprAST*> args;
                          args.push_back(nullptr);
			                    $$ = args; }
| explist               { $$ = $1; };

explist:
  exp                   { std::vector<ExprAST*> args;
                          args.push_back($1);
			                    $$ = args; }
| exp "," explist       { $3.insert($3.begin(), $1); $$ = $3; }
;

ifexp:
  IF exp THEN exp ELSE exp ENDKW  { $$ = new IfExprAST($2, $4, $6);}
/* | IF exp THEN exp ENDKW        { $$ = new IfExprAST($2, $4, nullptr); } */
;

forexp:
  FOR "id" "=" exp "," exp step DO exp ENDKW { $$ = new ForExprAST($2, $4, $6, $7, $9); }
;

step:
  "," exp   { $$ = $2; }
| %empty    { $$ = new NumberExprAST(1.0); }
;

whilexp:
  WHILE exp DO exp ENDKW { $$ = new WhileExprAST($2, $4); }
;

varexp:
  WITH varlist DO exp ENDKW     { $$ = new VarExprAST($2, $4); }
;

varlist:
  pair                        { std::vector<std::pair<std::string, ExprAST*>> args;
                                args.push_back($1);
                                $$ = args; }
| pair "," varlist            { $3.insert($3.begin(), $1); $$ = $3; }
;

pair:
  "id"                    { $$ = std::make_pair($1, new NumberExprAST(0.0)); }
| "id" "=" exp            { $$ = std::make_pair($1, $3); }
;

assignment:
  "id" "=" exp              { $$ = new BinaryExprAST('=', new VariableExprAST($1), $3); }
;

%%

void
yy::parser::error (const location_type& l, const std::string& m)
{
  std::cerr << l << ": " << m << '\n';
}
--- SCANNER
%{ /* -*- C++ -*- */
# include <cerrno>
# include <climits>
# include <cstdlib>
# include <string>
# include <cmath>
# include "driver.hpp"
# include "parser.hpp"

# undef yywrap
# define yywrap() 1

#if defined __GNUC__ && 7 <= __GNUC__
# pragma GCC diagnostic ignored "-Wnull-dereference"
#endif

yy::parser::symbol_type check_keywords(std::string lexeme, yy::location& loc);
%}

%option noyywrap nounput batch debug noinput

id      [a-zA-Z][a-zA-Z_0-9]*
fpnum   [0-9]*\.?[0-9]+([eE][-+]?[0-9]+)?
fixnum  (0|[1-9][0-9]*)\.?[0-9]*
num     {fpnum}|{fixnum}
blank   [ \t\r]
comment \/\/.*

%{
  # define YY_USER_ACTION loc.columns(yyleng);
%}
%%
%{
  yy::location& loc = drv.location;
  loc.step ();
%}
{blank}+   loc.step ();
{comment}  loc.step ();
[\n]+      loc.lines (yyleng); loc.step ();

"-"      return yy::parser::make_MINUS     (loc);
"+"      return yy::parser::make_PLUS      (loc);
"*"      return yy::parser::make_STAR      (loc);
"/"      return yy::parser::make_SLASH     (loc);
"%"      return yy::parser::make_MODULO    (loc);
"("      return yy::parser::make_LPAREN    (loc);
")"      return yy::parser::make_RPAREN    (loc);
";"      return yy::parser::make_SEMICOLON (loc);
","      return yy::parser::make_COMMA     (loc);
":"      return yy::parser::make_CONCAT    (loc);
"!"      return yy::parser::make_NOT       (loc);
">"      return yy::parser::make_GT        (loc);
"<"      return yy::parser::make_LT        (loc);
"<="     return yy::parser::make_LE        (loc);
">="     return yy::parser::make_GE        (loc);
"=="     return yy::parser::make_EQ        (loc);
"!="     return yy::parser::make_NE        (loc);
"="      return yy::parser::make_ASSIGN    (loc);
"["      return yy::parser::make_LSQUARE   (loc);
"]"      return yy::parser::make_RSQUARE   (loc);

{num}      {
  errno = 0;
  double n = strtod(yytext, NULL);
  if (! (n!=HUGE_VAL && n!=-HUGE_VAL && errno != ERANGE))
    throw yy::parser::syntax_error (loc, "Float value is out of range: "
                                    + std::string(yytext));
  return yy::parser::make_NUMBER (n, loc);
}
{id}       return check_keywords(yytext, loc);
.          {
             throw yy::parser::syntax_error
               (loc, "invalid character: " + std::string(yytext));
}
<<EOF>>    return yy::parser::make_END (loc);
%%

yy::parser::symbol_type check_keywords(std::string lexeme, yy::location& loc)  {
   if (lexeme == "fun") 
     return yy::parser::make_FUN(loc);
   else if (lexeme == "extern")
     return yy::parser::make_EXTERN(loc);
   else if (lexeme == "if")
     return yy::parser::make_IF(loc);
   else if (lexeme == "then")
     return yy::parser::make_THEN(loc);
   else if (lexeme == "else") 
     return yy::parser::make_ELSE(loc);
   else if (lexeme == "for")
     return yy::parser::make_FOR(loc);
   else if (lexeme == "do")
     return yy::parser::make_DO(loc);
   else if (lexeme == "end")
     return yy::parser::make_ENDKW(loc);
   else if (lexeme == "with")
     return yy::parser::make_WITH(loc);
   else if (lexeme == "while")
     return yy::parser::make_WHILE(loc);
   else if (lexeme == "arrof")
     return yy::parser::make_ARROF(loc);
   else
     return yy::parser::make_IDENTIFIER (yytext, loc);
}

void driver::scan_begin ()
{
  yy_flex_debug = trace_scanning;
  if (file.empty () || file == "-")
    yyin = stdin;
  else if (!(yyin = fopen (file.c_str (), "r")))
    {
      std::cerr << "cannot open " << file << ": " << strerror(errno) << '\n';
      exit (EXIT_FAILURE);
    }
}

void driver::scan_end ()
{
  fclose (yyin);
}
