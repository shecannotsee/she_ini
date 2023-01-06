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
  INI_line_state          result_;    // 主要确定返回的内容
  std::string             section_;   // ini:section
  std::string             key_;       // ini:key
  std::string             value_;     // ini:value
  sheIni::INI_value_type  type_;      // ini extend:value type

 public:
  FSM_state interface(char);
  FSM_state singleNote();
  FSM_state multipleSection();
  FSM_state multipleType();
  FSM_state singleEqual();
  FSM_state singleLineEnd();
  FSM_state singleLinuxLineBreak();
  FSM_state multipleWindowsLineBreak();

 public:
  std::tuple<INI_line_state,INI_value_type,std::string,std::string> get();

};// class DealIni
};// namespace sheIni


#endif //SHEINI_DEALINI_H
