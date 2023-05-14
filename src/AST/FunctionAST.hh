#ifndef FUNCTION_AST_HH
#define FUNCTION_AST_HH

#include "PrototypeAST.hh"

/// FunctionAST - Classe che rappresenta la definizione di una funzione
class FunctionAST : public RootAST {
private:
  PrototypeAST* Proto;
  ExprAST* Body;
  bool external;
  
public:
  FunctionAST(PrototypeAST* Proto, ExprAST* Body);
  void visit() override;
  Function *codegen(driver& drv) override;
};

#endif // !FUNCTION_AST_HH