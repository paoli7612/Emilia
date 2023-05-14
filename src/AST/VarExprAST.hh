#ifndef VAR_EXPR_AST_HH
#define VAR_EXPR_AST_HH

#include "ExprAST.hh"
#include <string>

/// VarExprAST - Classe per i blocchi var in
class VarExprAST : public ExprAST {
private:
  std::vector<std::pair<std::string, ExprAST*>> VarNames;
  ExprAST* Body;
  
public:
  VarExprAST(std::vector<std::pair<std::string, ExprAST*>> VarNames, ExprAST* Body);
  const std::string &getName() const;
  void visit() override;
  Value *codegen(driver& drv) override;
};

#endif // !VAR_EXPR_AST_HH