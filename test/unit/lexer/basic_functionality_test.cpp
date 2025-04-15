#include <lexer.h>
#include <she_test.h>

TEST3(unit, lexer, basic_functionality_test) {
  ini::detail::lexer test_lexer("../resource/escape.ini");

  for (auto line = test_lexer.get_token(); !line.empty(); line = test_lexer.get_token()) {
    for (const auto& c : line) {
      std::cout <<"TEST:" <<c.value << std::endl;
    }
  }
}