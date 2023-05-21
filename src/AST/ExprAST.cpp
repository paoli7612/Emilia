#include "ExprAST.hpp"

/************************ Expression tree *************************/
  // Inverte il flag che definisce le TopLevelExpression
  // ando viene chiamata
void ExprAST::toggle() {
  top = top ? false : true;
};

void ExprAST::setIsSize() {
  isSize = true;
};

bool ExprAST::getIsSize() {
  return isSize;
};

bool ExprAST::gettop() {
  return top;
};