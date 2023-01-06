//
// Created by  shecannotsee on 2023/1/7.
//

#ifndef SHEINI_METHOD_3_FSM_TEST_H
#define SHEINI_METHOD_3_FSM_TEST_H

#include <fstream>
#include <iostream>
#include <memory>
#include <FSM.h>

namespace method_3_FSM_test {

void main () {
  std::ifstream ini_file("../IniTestFile.ini");
  if (!ini_file.is_open()) {
    std::cout << "Failed to open INI file" << std::endl;
    return;
  }

  sheIni::FSM tool;

  for (char ch;!ini_file.eof();) {
    if (tool.isEnd(ch)) {
      // 一个阶段处理完毕，可以展示数据了
      if (std::get<0>(tool.get())==sheIni::INI_line_state::note) {
        std::cout<<"This line is notes:["
                 <<std::get<2>(tool.get())<<"]\n";

      } else if (std::get<0>(tool.get())==sheIni::INI_line_state::section) {
        std::cout<<"This line is a section:["
                 <<std::get<2>(tool.get())<<"]\n";

      } else if (std::get<0>(tool.get())==sheIni::INI_line_state::noTypeKV) {
        std::cout<<"This line is no type k-v ,k:["
                 <<std::get<2>(tool.get())<<"]"
                 <<"v:["
                 <<std::get<3>(tool.get())<<"]\n";

      } else if (std::get<0>(tool.get())==sheIni::INI_line_state::TypeKV) {
        std::cout<<"This line is no type k-v ,k:["
                 <<std::get<2>(tool.get())<<"]"
                 <<"v:["
                 <<std::get<3>(tool.get())<<"]"
                 <<"type:[";
        if (std::get<1>(tool.get())==sheIni::INI_value_type::filePath) {
          std::cout<<"file path]\n";
        } else if (std::get<1>(tool.get())==sheIni::INI_value_type::FPN) {
          std::cout<<"float]\n";
        } else if (std::get<1>(tool.get())==sheIni::INI_value_type::integer) {
          std::cout<<"integer]\n";
        };

      } else {
        std::cout<<"Maybe have some errors.\n";
      }
    } else {
      // 还没到处理边界
    };
  };// for


};

};// namespace method_3_FSM_test

#endif //SHEINI_METHOD_3_FSM_TEST_H
