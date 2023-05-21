#ifndef EXPR_AST_HPP
#define EXPR_AST_HPP

#include "RootAST.hpp"

/// ExprAST - Classe base per tutti i nodi espressione
class ExprAST : public RootAST {
protected:
  bool top;
public:
  virtual ~ExprAST() {};
  void toggle();
  void setIsSize();
  bool getIsSize();
  bool gettop();
private:
  bool isSize = false;
};

#endif // !EXPR_AST_HPP