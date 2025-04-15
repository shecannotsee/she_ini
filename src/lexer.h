#ifndef SHE_INI_LEXER_H
#define SHE_INI_LEXER_H

#include <string>

#include "source_loader.h"

namespace ini::detail {

struct token {
  enum class t : char {
    SECTION_BEGIN   = '[',
    SECTION_END     = ']',
    TYPE_CONVERSION = '=',

    COMMENT_1  = '#',
    COMMENT_2  = ';',
    LINE_BREAK = '\n',

    ESCAPE = '\\',
    VALUE  = 1,
    NONE   = 0,
  };
  t type;
  std::string value;
};

class lexer {
  source_loader loader_;

 public:
  explicit lexer(const std::string& file_path);
  ~lexer() = default;

  auto get_token() -> std::vector<token>;
};

}  // namespace ini::detail

#endif  // SHE_INI_LEXER_H
