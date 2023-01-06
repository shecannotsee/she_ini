//
// Created by  shecannotsee on 2023/1/6.
//

#ifndef SHEINI_INISTATE_H
#define SHEINI_INISTATE_H

namespace sheIni {

// 核心状态中type里的分类
enum class INI_value_type : unsigned int {
  defaultValue = 0 ,
  filePath,           // file path
  FPN,                // float,Floating point number
  integer,            // int or more bits int
  error
};

// 核心字符状态
enum class INI_char_state : unsigned int {
  notes_numberSign = 0,           // '#',It means to use # to express comments
  section_start = 91,             // '['
  section_end = 93,               // ']'
  type_start = 40,                // '('
  type_end = 41,                  // ')'
  equal = 61,                     // '='
  lineEnd = 59,                   // ';'
  linuxLineBreak = 10,            // '\n'
  WindowsLineBreak_first = 13,    // '\r'
//WindowsLineBreak_second,/*=10*/ // '\n'
  other
};// INI_char_state

// INI每一行的状态
enum class INI_line_state : unsigned int {
  defaultValue = 0,
  section,
  noTypeKV,
  TypeKV,
  error
};// INI_line_state

};// namespace sheIni

#endif //SHEINI_INISTATE_H
