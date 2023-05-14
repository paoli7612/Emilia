#ifndef ARRAY_EXPR_AST_HH
#define ARRAY_EXPR_AST_HH

#include "ExprAST.hh"

/// ArrayExprAST - Classe che rappresenta l'accesso ad un array in lettura
class ArrayExprAST : public ExprAST {
private:
	std::string VarName;
    ExprAST* Index;
  
public:
	ArrayExprAST(std::string VarName, ExprAST* Index);
	void visit() override;
	Value *codegen(driver& drv) override;
};


#endif // !ARRAY_EXPR_AST_HH