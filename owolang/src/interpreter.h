#ifndef OWOLANG_OWOLANG_OWOLANG_SRC_INTERPRETER_H
#define OWOLANG_OWOLANG_OWOLANG_SRC_INTERPRETER_H

#include "code_visitor.h"
#include "parser.h"
class Interpreter {
  Parser parser_;

public:
  explicit Interpreter(Parser &Parser);

  // todo: implement ir code generation
  std::string Interpret();
};

#endif
