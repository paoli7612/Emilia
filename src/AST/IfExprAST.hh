#ifndef IF_EXPR_AST_HH
#define IF_EXPR_AST_HH

#include "ExprAST.hh"

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

#endif // !IF_EXPR_AST_HH