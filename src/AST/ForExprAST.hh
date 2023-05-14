#ifndef FOR_EXPR_AST_HH
#define FOR_EXPR_AST_HH

#include "ExprAST.hh"

/// ForExpAst - Classe che rappresenta la definizione di un for
class ForExprAST : public ExprAST {
private:
    std::string VarName;
    ExprAST* Start;
    ExprAST* End;
    ExprAST* Step;
    ExprAST* Body;
    
public:
    ForExprAST(
        const std::string &VarName, 
        ExprAST* Start,
        ExprAST* End, 
        ExprAST* Step,
        ExprAST* Body
    );
    void visit() override;
    Value *codegen(driver& drv) override;
};

#endif // !FOR_EXPR_AST_HH