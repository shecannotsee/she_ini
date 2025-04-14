#ifndef SHE_INI_AST_H
#define SHE_INI_AST_H

namespace ini::detail {

enum class ast_type {
  DIRECTORY,  ///<
  FILE,
  SECTION,
  KEY,
  VALUE,
  ERROR
};

}

#endif  // SHE_INI_AST_H
