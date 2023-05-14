#ifndef NUMBER_EXPR_AST_HH
#define NUMBER_EXPR_AST_HH

#include "ExprAST.hh"

/// NumberExprAST - Classe per la rappresentazione di costanti numeriche
class NumberExprAST : public ExprAST {
private:
  double Val;

public:
  NumberExprAST(double Val);
  void visit() override;
  Value *codegen(driver& drv) override;
};

#endif // !NUMBER_EXPR_AST_HH