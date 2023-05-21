#ifndef ARRAY_ASSING_EXPR_AST_HPP
#define ARRAY_ASSING_EXPR_AST_HPP

#include "ExprAST.hpp"

/// ArrayAssignExprAST - Classe che rappresenta l'accesso ad un array in scrittura
class ArrayAssignExprAST : public ExprAST {
private:
	std::string VarName;
    ExprAST* Index;
    ExprAST* Val;
  
public:
	ArrayAssignExprAST(std::string VarName, ExprAST* Index, ExprAST* Val);
	void visit() override;
	Value *codegen(driver& drv) override;
};


#endif // !ARRAY_ASSIGN_EXPR_AST_HPP