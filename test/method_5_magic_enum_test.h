//
// Created by  shecannotsee on 2023/1/13.
//

#ifndef SHEINI_METHOD_5_MAGIC_ENUM_TEST_H
#define SHEINI_METHOD_5_MAGIC_ENUM_TEST_H

#include <iostream>

#include "magic_enum.hpp"
#include "IniState.h"

// 主要用来测试magic_enum库的功能,该库能够将枚举的名称通过静态反射来反射成字符串以便于在sheIni中进行debug
namespace method_5_magic_enum_test {

void main() {
  auto single_char = sheIni::INI_char_state::equal;
  auto singe_char_name = magic_enum::enum_name(single_char);
  std::cout<<singe_char_name<<std::endl;
};

};// namespace method_5_magic_enum_test

#endif //SHEINI_METHOD_5_MAGIC_ENUM_TEST_H
