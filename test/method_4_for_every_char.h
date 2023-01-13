//
// Created by  shecannotsee on 2023/1/13.
//

#ifndef SHEINI_METHOD_4_FOR_EVERY_CHAR_H
#define SHEINI_METHOD_4_FOR_EVERY_CHAR_H

#include <stdio.h>

namespace method_4_for_every_char {

void main() {
  std::ifstream ini_file("../IniTestFile.ini");
  for (char ch; ini_file.get(ch);) {
    if (ch=='\n') {
      std::cout<<"换行符:";
    }
    std::cout << ch;
  }


  ini_file.close();

};


};// namespace method_4_for_every_char

#endif //SHEINI_METHOD_4_FOR_EVERY_CHAR_H
