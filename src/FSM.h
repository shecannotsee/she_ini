//
// Created by shecannotsee on 2022/12/19.
//
// 该类是一个状态机的类，设计初衷希望能够不过多的参与业务处理，仅仅作为一个框架进行使用
//

#ifndef SHEINI_SRC_FSM_H_
#define SHEINI_SRC_FSM_H_

#include <string>
#include <tuple>
#include <FSMState.h>
#include <DealIni.h>

namespace sheIni {
class FSM {
 public:
  FSM();
  ~FSM() = default;
  // Disable copy
  FSM(const FSM &) = delete;
  FSM &operator=(const FSM &) = delete;
  // Disable move
  FSM(FSM &&) = delete;
  FSM &operator=(FSM &&) = delete;

 private:
  FSM_state state_;
 private:
  void running(char);
 public:
  // 传入一个字符推动自动机运行并获取运行结果
  bool isEnd(char);
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 private:
  // 无法避免的业务成员变量
  DealIni dealIni_;
 public:
  // 无法避免的接口函数
  std::tuple<INI_line_state,INI_value_type,std::string,std::string> get();


};// class FSM
};// namespace sheIni



#endif //SHEINI_SRC_FSM_H_
