#include <ast.h>
#include <she_test.h>

TEST3(unit, ast_test, node_test) {
  using namespace ini::detail;
  ast::node root{ast::t::FILE, "test.ini"};

  root.add({ast::t::SECTION, "admin"});
  root.add({ast::t::SECTION, "jack"});
  root.add({ast::t::SECTION, "test"});

  const auto admin = root.children["admin"];  // 获取引用
  admin->add({ast::t::KEY, "age"})->add({ast::t::VALUE, "12"});
  admin->add({ast::t::KEY, "address"})->add({ast::t::VALUE, "adc"});
  admin->add({ast::t::KEY, "name"})->add({ast::t::VALUE, "sheccannotsee"});

  std::cout << root.value << std::endl;
  const auto& level_0 = root;
  for (auto section_level = level_0.children.begin(); section_level != level_0.children.end(); ++section_level) {
    auto section         = std::get<0>(*section_level);
    bool is_last_section = std::next(section_level) == level_0.children.end();  // 判断是否为最后一个section

    std::cout << (is_last_section ? "└── " : "├── ") << section << std::endl;

    auto level_1 = *std::get<1>(*section_level);
    for (auto key_level = level_1.children.begin(); key_level != level_1.children.end(); ++key_level) {
      auto key         = std::get<0>(*key_level);
      bool is_last_key = std::next(key_level) == level_1.children.end();  // 判断是否为最后一个key

      std::cout << "\t" << (is_last_key ? "└── " : "├── ") << key << ": ";

      auto level_2 = *std::get<1>(*key_level);
      for (auto value_level = level_2.children.begin(); value_level != level_2.children.end(); ++value_level) {
        auto value         = std::get<0>(*value_level);
        bool is_last_value = std::next(value_level) == level_2.children.end();  // 判断是否为最后一个value

        std::cout << value << (is_last_value ? "" : " ") << std::endl;
      }
    }
  }

  std::cout << root.children["admin"]->children["age"]->children["12"]->value<< std::endl;
}

TEST(unit, ast_test) {
  using namespace ini::detail;
  // ast ast({});
  //
  // ast.insert(ast::t::FILE,  // file
  //            "test.ini",    // file name
  //            {});
  // ast.insert(ast::t::SECTION,  // section
  //            "admin",          // [admin]
  //            {"test.ini"});
  //
  // ast.insert(ast::t::SECTION,  // section
  //            "admin",          // [admin]
  //            {"test.ini"});
}
