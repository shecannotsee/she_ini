#ifndef SHE_INI_AST_H
#define SHE_INI_AST_H

#include <memory>
#include <stdexcept>
#include <string>
#include <unordered_map>
#include <vector>

namespace ini::detail {

class ast {
 public:
  enum class t {
    DIRECTORY,  ///<
    FILE,
    SECTION,
    KEY,
    VALUE,
  };

  struct node {
    t type;
    std::string value;
    std::unordered_map<std::string, std::shared_ptr<node>> children;
    auto add(node to_insert) noexcept -> std::shared_ptr<node> {
      if (children.find(to_insert.value) == children.end()) {
        children[to_insert.value] = std::make_shared<node>(to_insert);
        return children[to_insert.value];
      } else {
        throw std::runtime_error("Duplicate key");
      }
    }

    auto operator[](std::string key) const noexcept -> std::string {
      if (children.find(key) == children.end()) {
      }
      return {};
    }
  };

 private:
  node root_;

 public:
  void insert(t type, std::string value, std::vector<std::string> path) {
  }

  void dump();

  ast& operator[](std::string key) {
    return *this;
  }

  void value(std::string key) {
  }
};

}  // namespace ini::detail

#endif  // SHE_INI_AST_H
