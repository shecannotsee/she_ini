//
// Created by shecannotsee on 2022/12/19.
//

#include <FSM.h>
#include <DealIni.h>


sheIni::FSM::FSM()
    : state_(FSM_state::Sizzle),
      dealIni_(DealIni()){
}

void sheIni::FSM::running(char ch) {
  state_ = DealIni::interface(ch);
};

bool sheIni::FSM::isEnd(char ch) {
  this->running(ch);
  if (state_==FSM_state::Sizzle) {
    return false;
  } else if (state_==FSM_state::Stop) {
    return true;
  };
}


