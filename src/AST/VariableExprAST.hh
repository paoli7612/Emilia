#ifndef VARIABLE_EXPR_AST_HH
#define VARIABLE_EXPR_AST_HH

#include "ExprAST.hh"
#include <string>

/// VariableExprAST - Classe per la rappresentazione di riferimenti a variabili
class VariableExprAST : public ExprAST {
private:
  std::string Name;
  
public:
  VariableExprAST(std::string &Name);
  const std::string &getName() const;
  void visit() override;
  Value *codegen(driver& drv) override;
};

#endif // !VARIABLE_EXPR_AST_HH