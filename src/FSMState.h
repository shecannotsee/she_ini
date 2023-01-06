//
// Created by shecannotsee on 2022/12/20.
//

#ifndef SHEINI_SRC_STATE_H_
#define SHEINI_SRC_STATE_H_

namespace sheIni {

// 用该状态来对应fsm里如何运行
enum class FSM_state : unsigned int {
  Sizzle = 0,
  Stop,
  ERROR
};

};// namespace sheIni

#endif //SHEINI_SRC_STATE_H_
