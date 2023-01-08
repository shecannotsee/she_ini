//
// Created by  shecannotsee on 2023/1/6.
//

#ifndef SHEINI_INISTATE_H
#define SHEINI_INISTATE_H

namespace sheIni {

// 核心状态中type里的分类
enum class INI_value_type : unsigned int {
  error = 0 ,
  defaultValue,        // 默认初始化用值,
  filePath = 102,      // 'f',file path
  FPN = 100,           // 'd',float,Floating point number
  integer = 105        // 'i',int or more bits int
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
  space = 32,                     // ' '
  other
};// INI_char_state

// INI每一行的状态
enum class INI_line_state : unsigned int {
  error = 0,          // 错误,一般在解析失败的时候会用到
  note,               // 注释
  section,            // section值
  key,                // key(std::string)
  noTypeValue,        // 无类型的value(std::string)
  TypeValue,          // 有类型的value
  mayBeEnd,           // 对于'\r'的处理
  end,                // 结束符号
  defaultValue        // 默认初始化用值
};// INI_line_state

};// namespace sheIni

#endif //SHEINI_INISTATE_H
