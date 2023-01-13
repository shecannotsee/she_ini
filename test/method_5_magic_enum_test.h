//
// Created by  shecannotsee on 2023/1/13.
//

#ifndef SHEINI_METHOD_5_MAGIC_ENUM_TEST_H
#define SHEINI_METHOD_5_MAGIC_ENUM_TEST_H

#include <iostream>

#include "magic_enum.hpp"
#include "IniState.h"

namespace method_5_magic_enum_test {

void main() {
  auto single_char = sheIni::INI_char_state::equal;
  auto singe_char_name = magic_enum::enum_name(single_char);
  std::cout<<singe_char_name<<std::endl;
};

};// namespace method_5_magic_enum_test

#endif //SHEINI_METHOD_5_MAGIC_ENUM_TEST_H
