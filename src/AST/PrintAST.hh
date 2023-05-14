#ifndef PRINT_AST_HH
#define PRINT_AST_HH

#include "ExprAST.hh"

/// IfExpAst - Classe che rappresenta la definizione di un if
class PrintAST : public ExprAST {
private:
	ExprAST* Argument;
  
public:
	PrintAST(ExprAST* Argument);
	void visit() override;
	Value *codegen(driver& drv) override;
};

#endif // !PRINT_AST_HH