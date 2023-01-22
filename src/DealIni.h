//
// Created by  shecannotsee on 2023/1/7.
//
// 该类是处理ini具体字符的类
// 该类的一切行为和成员变量都和ini文件的属性有关
//

#ifndef SHEINI_DEALINI_H
#define SHEINI_DEALINI_H

#include <string>
#include <tuple>
#include <FSMState.h>
#include <IniState.h>

namespace sheIni {
class DealIni {
 public:
  DealIni();
  ~DealIni() = default;
  // Disable copy
  DealIni(const DealIni&) = delete;
  DealIni& operator=(const DealIni&) = delete;
  // Disable move
  DealIni(DealIni&&) = delete;
  DealIni& operator=(DealIni&&) = delete;

 private:
  INI_line_state              line_state_;  // 主要确定返回的内容
  sheIni::INI_value_type      type_;        // ini extend:value type
  std::string                 key_;         // ini:key
  std::string                 value_;       // ini:value
  INI_reading_pointer         next_;        // 用来处理在解析时的各种状态
  // TODO:多字符的复杂状态应为其单独创建一个枚举类,参考type
  INI_reading_pointer         temp_;        // 仅对'\r'变化的复原,

 public:
  // 重制该类所有变量
  void setDefault();
  // 对外的通用接口,接收一个字符
  FSM_state interface(char);
 private:
  // 传入的是'#'
  FSM_state singleNote(char);
  // 传入的是'['或者']'
  FSM_state multipleSection(char);
  // 传入的是'('或者'）'
  FSM_state multipleType(char);
  // 传入的是'='
  FSM_state singleEqual(char);
  // 传入的是';'
  FSM_state singleLineEnd(char);
  // 传入的是'\n'
  FSM_state singleLinuxLineBreak(char);
  // 传入的是'\r'
  FSM_state multipleWindowsLineBreak(char);
  // 除上述字符之外的所有其他字符
  FSM_state dealOtherChar(char);

 public:
  // std::get<0>() 为ini line类型
  // std::get<1>() 为value类型,如果有的话
  // std::get<2>() 为key或者section或者注释(仅在测试时存储注释) 的std::string
  // std::get<3>() 为value的std::string
  std::tuple<INI_line_state,INI_value_type,std::string,std::string> get();

};// class DealIni
};// namespace sheIni


#endif //SHEINI_DEALINI_H
