#ifndef BINARY_EXPR_AST_HH
#define BINARY_EXPR_AST_HH

#include "ExprAST.hh"

/// BinaryExprAST - Classe per la rappresentazione di operatori binary
class BinaryExprAST : public ExprAST {
private:
  char Op;
  ExprAST* LHS;
  ExprAST* RHS;

public:
  BinaryExprAST(char Op, ExprAST* LHS, ExprAST* RHS);
  void visit() override;
  Value *codegen(driver& drv) override;
};

#endif // !BINARY_EXPR_AST_HH