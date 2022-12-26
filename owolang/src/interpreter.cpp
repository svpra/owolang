#include "interpreter.h"

Interpreter::Interpreter(Parser &Parser) : parser_(Parser) {}

std::string Interpreter::Interpret() {

  Token token;
  CodeVisitor visitor;
  while ((token = parser_.GetTokenType()) != tok_eof) {
    switch (token) {
    case tok_semicolon: // ignore top-level semicolons.
      parser_.SkipToken();
      break;

    case tok_owo: { // def owo
      auto owo = parser_.HandleDefinition();
      owo->GenerateCode(visitor);
    } break;

    case tok_meow: { // extern meow
      auto meow = parser_.HandleExtern();
      meow->GenerateCode(visitor);
    } break;

    default: { // top nya
      auto nya = parser_.HandleTopLevelExpression();
      nya->GenerateCode(visitor);
    } break;
    }
  }
  std::string code;
  llvm::raw_string_ostream code_stream(code);
  code_stream << *visitor.module_;
  code_stream.flush();
  return code;
}
