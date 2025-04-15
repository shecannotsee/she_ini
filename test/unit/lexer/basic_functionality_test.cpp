#include <lexer.h>
#include <she_test.h>

TEST3(unit, lexer, basic_functionality_test) {
  ini::detail::lexer test_lexer("../resource/escape.ini");

  auto token_type_to_string = [](ini::detail::token::t type) {
    using namespace ini::detail;
    if (type == token::t::NONE) {
      return "NONE";
    } else if (type == token::t::VALUE) {
      return "VALUE";
    } else if (type == token::t::SECTION_BEGIN) {
      return "SECTION_BEGIN";
    } else if (type == token::t::SECTION_END) {
      return "SECTION_END";
    } else if (type == token::t::TYPE_CONVERSION) {
      return "TYPE_CONVERSION";
    } else if (type == token::t::COMMENT) {
      return "COMMENT";
    }
  };

  for (auto line = test_lexer.get_token(); !line.empty(); line = test_lexer.get_token()) {
    for (const auto& token : line) {
      std::cout << "TEST:" << token_type_to_string(token.type) << " " << token.value << std::endl;
    }
    std::cout << "---------------" << std::endl;
  }
}