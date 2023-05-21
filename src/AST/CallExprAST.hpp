#ifndef CALL_EXPR_AST_HPP
#define CALL_EXPR_AST_HPP

#include "ExprAST.hpp"
#include <string>
#include <vector>

/// CallExprAST - Classe per la rappresentazione di chiamate di funzione
class CallExprAST : public ExprAST {
private:
  std::string Callee;
  std::vector<ExprAST*> Args;  // ASTs per la valutazione degli argomenti

public:
  CallExprAST(std::string Callee, std::vector<ExprAST*> Args);
  void visit() override;
  Value *codegen(driver& drv) override;
};

#endif // !CALL_EXPR_AST_HPP