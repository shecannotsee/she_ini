//
// Created by  shecannotsee on 2023/1/6.
//

#ifndef SHEINI_INISTATE_H
#define SHEINI_INISTATE_H

namespace sheIni {

// INI每一行的类型,是注释
enum class INI_line_state : unsigned int {
  error = 0,          // 错误,一般在解析失败的时候会用到
  note,               // 该行是注释
  section,            // 该行是section
  noTypeValue,        // 该行是一个没有类型的k-v
  TypeValue,          // 该行是一个有类型的k-v
  defaultValue        // 默认初始化用值,也许该行什么也没有
};// INI_line_state

// 在读取过程中的存储指针指向
enum class INI_reading_pointer : unsigned int {
  error = 0,
  note,           // 注释,一般在测试时会用到,实际不会去做注释的解析操作
  section,        // section
  type,           // k-v的type
  key,            // key
  value,          // value
  maybe_end,      // 可能是结束符,主要针对windows上的/r/n这种换行模式
  end,            // 结束符
  defaultValue    // 默认初始化用值
};

// 在判断出该行是kv并且带有类型时,具体类型(也与ascii码相对应)的枚举
enum class INI_value_type : unsigned int {
  error = 0 ,
  defaultValue,        // 默认初始化用值,
  filePath = 102,      // 'f',file path
  FPN = 100,           // 'd',float,Floating point number
  integer = 105        // 'i',int or more bits int
};

// 核心字符状态,将字符与对应ascii字符码对应
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


};// namespace sheIni

#endif //SHEINI_INISTATE_H
