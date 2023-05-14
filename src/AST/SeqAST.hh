#ifndef SEQ_AST_HH
#define SEQ_AST_HH

#include "RootAST.hh"

// Classe che rappresenta la sequenza di statement
class SeqAST : public RootAST {
private:
  RootAST* first;
  RootAST* continuation;

public:
  SeqAST(RootAST* first, RootAST* continuation);
  void visit() override;
  Value *codegen(driver& drv) override;
};

#endif // !SEQ_AST_HH