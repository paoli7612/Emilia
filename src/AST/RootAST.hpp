#ifndef ROOT_AST_HPP
#define ROOT_AST_HPP

#include "llvm/IR/Value.h"
#include "../driver.hpp"

// Classe base dell'intera gerarchia di classi che rappresentano
// gli elementi del programma
class RootAST {
public:
  virtual ~RootAST() {};
  virtual void visit() {};
  virtual llvm::Value *codegen(driver& drv) { return nullptr; };
};

#endif // !ROOT_AST_HPP