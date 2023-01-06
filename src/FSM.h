//
// Created by shecannotsee on 2022/12/19.
//

#ifndef SHEINI_SRC_FSM_H_
#define SHEINI_SRC_FSM_H_

#include <FSMState.h>

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

};// class FSM
};// namespace sheIni



#endif //SHEINI_SRC_FSM_H_
