//
// Created by  shecannotsee on 2023/1/7.
//
// 该函数是处理ini具体字符的类
//

#ifndef SHEINI_DEALINI_H
#define SHEINI_DEALINI_H

#include <IniState.h>

class DealIni {
  static void singleNote();
  static void multipleSection();
  static void multipleType();
  static void singleEqual();
  static void singleLineEnd();
  static void singleLinuxLineBreak();
  static void multipleWindowsLineBreak();
};


#endif //SHEINI_DEALINI_H
