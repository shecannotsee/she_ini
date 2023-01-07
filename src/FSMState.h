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

// TODO:需要根据世纪业务对该类型进行更细致的处理,
//      该状态表示FSM的输入,也许是一个字符,一个类或者其他的东西,
//      或许要对
enum class FSM_input_type : unsigned char {
  singleChar = 1
};

};// namespace sheIni

#endif //SHEINI_SRC_STATE_H_
