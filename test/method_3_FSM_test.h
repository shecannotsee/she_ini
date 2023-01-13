//
// Created by  shecannotsee on 2023/1/7.
//

#ifndef SHEINI_METHOD_3_FSM_TEST_H
#define SHEINI_METHOD_3_FSM_TEST_H

#include <fstream>
#include <iostream>
#include <memory>
#include <FSM.h>
#include "magic_enum.hpp"

namespace method_3_FSM_test {

void main () {
  std::ifstream ini_file("../IniTestFile.ini");
  if (!ini_file.is_open()) {
    std::cout << "Failed to open INI file" << std::endl;
    return;
  }

  sheIni::FSM tool;

  for (char ch; ini_file.get(ch);) {
//    std::cout<<ch;
    tool.add(ch);
    if (tool.getState()==sheIni::FSM_state::Stop) {
      auto ret = tool.get();
      std::cout<<"["<<magic_enum::enum_name(std::get<0>(ret))<<"]:";
      std::cout<<"["<<magic_enum::enum_name(std::get<1>(ret))<<"]:";
      std::cout<<"["<<(std::get<2>(ret))<<"][";
      std::cout<<(std::get<3>(ret));
      std::cout<<"]\n";
    }
    else if (tool.getState()==sheIni::FSM_state::ERROR) {
      std::cout<<"Maybe some errors have appeared.\n";
    }
    else if (tool.getState()==sheIni::FSM_state::Sizzle) {
      // do nothing...
    };
  };// loop in every char
  // 若文件末尾没有结尾标志(换行符或者是';'),需要手动添加结束符号来处理最后一行的数据,否则则会遗漏最后一行的数据
  tool.add('\n');
  if (tool.getState()==sheIni::FSM_state::Stop) {
    auto ret = tool.get();
    std::cout<<"["<<magic_enum::enum_name(std::get<0>(ret))<<"]:";
    std::cout<<"["<<magic_enum::enum_name(std::get<1>(ret))<<"]:";
    std::cout<<"["<<(std::get<2>(ret))<<"][";
    std::cout<<(std::get<3>(ret));
    std::cout<<"]\n";
  }


};

};// namespace method_3_FSM_test

#endif //SHEINI_METHOD_3_FSM_TEST_H
