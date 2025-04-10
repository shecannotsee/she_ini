#ifndef SHE_INI_LEXER_H
#define SHE_INI_LEXER_H

#include <string>

namespace ini::detail {

enum class token_type {
  SECTION_BEGIN   = '[',
  SECTION_END     = ']',
  TYPE_CONVERSION = '=',

  COMMENT_1  = '#',
  COMMENT_2  = ';',
  LINE_BREAK = '\n',

  ESCAPE = '\\',
  VALUE  = 0
};

class lexer {
  bool init;

 public:
  lexer();
  lexer(std::string_view);
  ~lexer();

 public:
};

}  // namespace ini::detail

#endif  // SHE_INI_LEXER_H
