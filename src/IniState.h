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
  notes_numberSign = 0,     // '#',It means to use # to express comments
  section_start,            // '['
  section_end,              // ']'
  type_start,               // '('
  type_end,                 // ')'
  equal,                    // '='
  lineEnd,                  // ';'
  linuxLineBreaks,          // '\n'
  WindowsLineBreak_first,   // '\r'
  WindowsLineBreak_second   // '\n'

};// INI_state

};// namespace sheIni

#endif //SHEINI_INISTATE_H
