//
// Created by  shecannotsee on 2023/1/7.
//

#include "DealIni.h"

sheIni::DealIni::DealIni()
    : result_(INI_line_state::defaultValue),
      section_(std::string()),
      key_(std::string()),
      value_(std::string()),
      type_(sheIni::INI_value_type::defaultValue){
};

sheIni::FSM_state sheIni::DealIni::interface(char ch) {
  if ( ch==(int)INI_char_state::notes_numberSign ) {

  } else if ( ch == (int)INI_char_state::section_start ) {

  } else if ( ch == (int)INI_char_state::section_end ) {

  }
}

