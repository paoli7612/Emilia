#ifndef UNARY_EXPR_AST_HH
#define UNARY_EXPR_AST_HH

#include "ExprAST.hh"

/// BinaryExprAST - Classe per la rappresentazione di operatori unari
class UnaryExprAST : public ExprAST {
private:
  char Op;
  ExprAST* Expr;

public:
  UnaryExprAST(char Op, ExprAST* Expr);
  void visit() override;
  Value *codegen(driver& drv) override;
};

#endif // !UNARY_EXPR_AST_HH