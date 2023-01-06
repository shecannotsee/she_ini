//
// Created by  shecannotsee on 2023/1/7.
//

#ifndef SHEINI_METHOD_3_FSM_TEST_H
#define SHEINI_METHOD_3_FSM_TEST_H

#include <fstream>
#include <iostream>
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
    if (tool.isEnd(ch)== true) {
      // 一个阶段处理完毕，可以展示数据了
    } else {
      // 还没到处理边界
    };
  };// for


};

};// namespace method_3_FSM_test

#endif //SHEINI_METHOD_3_FSM_TEST_H
