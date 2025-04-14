#include <she_test.h>

TEST3(unit, lexer, basic_functionality_test) {
  std::vector<std::string> line = {
    {std::string("[admin]\n")},
    {std::string("adress = aaaaaaaaaaaaaaaaaaaaaaaaaaaa\\\n         bbbbbbbbbbbb\n")},
    {std::string("name = jac\\\n          k\n")},
    {std::string("\n")},
    {std::string("a\n")},
    {std::string("des = asdsadasd\\asdasdasdas\\dasdasdsad")}
  };
  std::vector<std::string> line_without_line_break = {
    {std::string("[admin]")},
    {std::string("adress = aaaaaaaaaaaaaaaaaaaaaaaaaaaa\\\n         bbbbbbbbbbbb")},
    {std::string("name = jac\\\n          k")},
    {std::string("")},
    {std::string("a")},
    {std::string("des = asdsadasd\\asdasdasdas\\dasdasdsad")}
  };


}