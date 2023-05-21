#ifndef IF_EXPR_AST_HPP
#define IF_EXPR_AST_HPP

#include "ExprAST.hpp"

/// IfExpAst - Classe che rappresenta la definizione di un if
class IfExprAST : public ExprAST {
private:
	ExprAST* Condition;
	ExprAST* Then;
	ExprAST* Else;
  
public:
	IfExprAST(ExprAST* Condition, ExprAST* Then, ExprAST* Else);
	void visit() override;
	Value *codegen(driver& drv) override;
};

#endif // !IF_EXPR_AST_HPP