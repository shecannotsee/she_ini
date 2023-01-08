//
// Created by shecannotsee on 2022/12/19.
//

#include <FSM.h>
#include <DealIni.h>


sheIni::FSM::FSM()
    : state_(FSM_state::Sizzle),
      dealIni_(std::make_unique<DealIni>()){
};

void sheIni::FSM::add(char ch) {
  state_ = dealIni_->interface(ch);
};

bool sheIni::FSM::isEnd(char ch) {
  if (state_==FSM_state::Sizzle) {
    return false;
  } else if (state_==FSM_state::Stop) {
    return true;
  } else if (state_==FSM_state::ERROR) {
    return true;
  }
}

std::tuple<sheIni::INI_line_state, sheIni::INI_value_type, std::string, std::string> sheIni::FSM::get() {
  auto ret = dealIni_->get();
  dealIni_->setDefault();
  return ret;
};


