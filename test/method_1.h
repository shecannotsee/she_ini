//
// Created by shecannotsee on 2022/12/21.
//

#ifndef SHEINI_TEST_METHOD_1_H_
#define SHEINI_TEST_METHOD_1_H_

#include <iostream>
#include <fstream>
#include <string>

// 按行读取
namespace method_1 {

void main() {
  std::ifstream ini_file("../IniTestFile.ini");
  if (!ini_file.is_open()) {
    std::cout << "Failed to open INI file" << std::endl;
    return;
  }

  std::string line;
  while (std::getline(ini_file, line)) {
    std::string section;
    std::string type;
    std::string key;
    std::string value;
    std::string* p = nullptr;

    for (auto& ch:line) {
      if (ch==';'||ch=='#') {
        std::cout<<"this is a note.\n";
        break;
      } else if (ch=='[') {
        std::cout<<"Start parse a section.";
        p = &section;
      } else if (ch==']') {
        std::cout<<"section is :["<<(*p)<<"].\n";
      } else if (ch=='(') {
        p = &type;
      } else if (ch==')') {
        std::cout<<"type is :["<<(*p)<<"].\n";
        p = &key;
      } else if (ch=='=') {
        std::cout<<"key is :["<<(*p)<<"].\n";
        p = &value;
      } else if (ch==' ') {

      } else {
        if (p== nullptr)
          p = &key;
        (*p)+=ch;
      }
    }// parse a line
    if (value.empty())
      std::cout<<value;
    p = nullptr;
    section.clear();
    type.clear();
    key.clear();
    value.clear();
  }

  ini_file.close();

};

};// namespace method_1

#endif //SHEINI_TEST_METHOD_1_H_
