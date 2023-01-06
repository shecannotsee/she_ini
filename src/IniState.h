//
// Created by  shecannotsee on 2023/1/6.
//

#ifndef SHEINI_INISTATE_H
#define SHEINI_INISTATE_H

namespace sheIni {

// 核心状态中type里的分类
enum class type : unsigned int {
  filePath = 0,   // file path
  FPN,            // float,Floating point number
  integer         // int or more bits int
};

// 核心状态
enum class INI_state : unsigned int {
  notes_numberSign = 0,           // '#',It means to use # to express comments
  section_start = 91,             // '['
  section_end = 93,               // ']'
  type_start = 40,                // '('
  type_end = 41,                  // ')'
  equal = 61,                     // '='
  lineEnd = 59,                   // ';'
  linuxLineBreak = 10,            // '\n'
  WindowsLineBreak_first = 13,    // '\r'
  WindowsLineBreak_second         // '\n'

};// INI_state

};// namespace sheIni

#endif //SHEINI_INISTATE_H
