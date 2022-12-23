//
// Created by shecannotsee on 2022/12/19.
//

#ifndef SHEINI_SRC_FSM_H_
#define SHEINI_SRC_FSM_H_

#include "state.h"
#include <string>
#include <tuple>
#include <unordered_map>
#include <functional>

class FSM {
 public:
  FSM();
  ~FSM() = default;
  // copy
  FSM(const FSM&) = delete;
  FSM& operator=(const FSM&) = delete;
  // move
  FSM(FSM&&) = delete;
  FSM& operator=(FSM&&) = delete;

 private:

 public:

};



#endif //SHEINI_SRC_FSM_H_
