#ifndef PROTOTYPE_AST_HPP
#define PROTOTYPE_AST_HPP

#include "RootAST.hpp"

/// PrototypeAST - Classe per la rappresentazione dei prototipi di funzione
/// (nome, numero e nome dei parametri; in questo caso il tipo è implicito
/// perché unico)
class PrototypeAST : public RootAST {
private:
  std::string Name;
  std::vector<std::string> Args;
  bool emit;

public:
  PrototypeAST(std::string Name, std::vector<std::string> Args);
  const std::string &getName() const;
  const std::vector<std::string> &getArgs() const; 
  void visit() override;
  Function *codegen(driver& drv) override;
  void noemit();
  bool emitp();
};

#endif // !PROTOTYPE_AST_HPP