//
// Created by shecannotsee on 2022/12/21.
//

#ifndef SHEINI_TEST_METHOD_2_H_
#define SHEINI_TEST_METHOD_2_H_

#include <fstream>
#include <iostream>

// 按照字符串读取
namespace method_2 {

void main() {
  std::ifstream ini_file("../IniTestFile.ini");
  if (!ini_file.is_open()) {
    std::cout << "Failed to open INI file" << std::endl;
    return;
  }

  std::string section;
  std::string key;
  std::string value;
  std::string type;
  std::string* p = nullptr;
  int state = 0;
  for (char ch;!ini_file.eof();) {
    ini_file >> ch;
    if (ch=='\n') {
      std::cout<<value;
      p = nullptr;
      section.clear();
      key.clear();
      value.clear();
      type.clear();
      p=&key;
    }
    else if (ch==';'||ch=='#') {
      std::cout<<"this is a note.\n";
      ;
    }
    else if (ch=='[') {
      std::cout<<"Start parse a section.";
      p = &section;
    }
    else if (ch==']') {
      std::cout<<"section is :["<<(*p)<<"].\n";
    }
    else if (ch=='(') {
      std::cout<<"Start parse a type.";
      p = &type;
    }
    else if (ch==')') {
      std::cout<<"type is :["<<(*p)<<"].\n";
      p = &key;
    }
    else if (ch=='=') {
      std::cout<<"key is :["<<(*p)<<"].\n";
      p=&value;
    }
    else if (ch==' ') {

    }
    else {
      if (p== nullptr)
        p = &key;
      (*p)+=ch;
    }
  }

};

};// namespace method_2

#endif //SHEINI_TEST_METHOD_2_H_
