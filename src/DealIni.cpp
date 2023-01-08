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
  switch (ch) {
    case static_cast<int>(INI_char_state::notes_numberSign) : {
      return this->singleNote(ch);
      break;
    }
    case static_cast<int>(INI_char_state::section_start) : {
      return this->multipleSection(ch);
      break;
    }
    case static_cast<int>(INI_char_state::section_end) : {
      return this->multipleSection(ch);
      break;
    }
    case static_cast<int>(INI_char_state::type_start) : {
      return this->multipleType(ch);
      break;
    }
    case static_cast<int>(INI_char_state::type_end) : {
      return this->multipleType(ch);
      break;
    }
    case static_cast<int>(INI_char_state::equal) : {
      return this->singleEqual(ch);
      break;
    }
    case static_cast<int>(INI_char_state::lineEnd) : {
      return this->singleLineEnd(ch);
      break;
    }
    case static_cast<int>(INI_char_state::WindowsLineBreak_first) : {
      return this->multipleWindowsLineBreak(ch);
      break;
    }
    case static_cast<int>(INI_char_state::linuxLineBreak) : {
      return this->singleLinuxLineBreak(ch);
      break;
    }
    default : {
      this->dealOtherChar(ch);
      break;
    }

  }
}

sheIni::FSM_state sheIni::DealIni::singleNote(char ch) {
  result_ = INI_line_state::note;
  return sheIni::FSM_state::Sizzle;
};

sheIni::FSM_state sheIni::DealIni::multipleSection(char ch) {
  if (ch == (int)INI_char_state::section_start) {
    result_ = INI_line_state::section;
  } else if (ch==(int)INI_char_state::section_end) {
    result_ = INI_line_state::defaultValue;
  } else {
    result_ = INI_line_state::error;
  }
  return sheIni::FSM_state::Sizzle;
};

sheIni::FSM_state sheIni::DealIni::multipleType(char ch) {
  if (ch == (int)INI_char_state::type_start) {
    result_ = INI_line_state::TypeValue;
  } else if (ch==(int)INI_char_state::type_end) /*处理完type后续按照正常kv处理即可*/ {
    result_ = INI_line_state::defaultValue;
  } else {
    result_ = INI_line_state::error;
  }
  return sheIni::FSM_state::Sizzle;
}

sheIni::FSM_state sheIni::DealIni::singleEqual(char ch) {
  result_ = INI_line_state::noTypeValue;
  return sheIni::FSM_state::Sizzle;
};

sheIni::FSM_state sheIni::DealIni::singleLineEnd(char ch) {
  // result_ 不应该处于end状态
//  result_ = INI_line_state::end;
  return sheIni::FSM_state::Sizzle;
};

sheIni::FSM_state sheIni::DealIni::singleLinuxLineBreak(char ch) {
  // result_ 不应该处于end状态
  if (result_== INI_line_state::mayBeEnd) /*兼容windows下的换行符*/ {
//    result_ = INI_line_state::end;
  } else /*当然,遇到换行符都是行结束的意思*/ {
//    result_ = INI_line_state::end;
  }
  return sheIni::FSM_state::Stop;
};

sheIni::FSM_state sheIni::DealIni::multipleWindowsLineBreak(char ch) {
  // result_ 不应该处于end状态
//  result_ = INI_line_state::mayBeEnd;
  return sheIni::FSM_state::Stop;
};

sheIni::FSM_state sheIni::DealIni::dealOtherChar(char ch) {
  if (ch == (int )INI_char_state::space) {
    // Space
  }
  else if (result_==INI_line_state::note) /*只是用来测试,生产中不会对任何注释进行解析*/ {
    key_ += ch;
  }
  else if (result_==INI_line_state::section) {
    section_ += ch;
  }
  else if (result_==INI_line_state::defaultValue) /*任意非关键字字符开头处理*/ {
    key_ += ch;
  }
  else if (result_==INI_line_state::noTypeValue) /*value处理*/ {
    value_ += ch;
  }
  else if (result_==INI_line_state::TypeValue) /*处理类型里的字符*/ {
    if (ch == (int)INI_value_type::filePath) {
      type_ = INI_value_type::filePath;
    } else if (ch == (int)INI_value_type::FPN) {
      type_ = INI_value_type::FPN;
    } else if (ch == (int)INI_value_type::integer) {
      type_ = INI_value_type::integer;
    } else {
      type_ = INI_value_type::error;
    }
  }
  else if (result_==INI_line_state::end) {
    return sheIni::FSM_state::ERROR;
  }

  return sheIni::FSM_state::Sizzle;
};

void sheIni::DealIni::setDefault() {
  result_ = INI_line_state::defaultValue;
  section_.clear();
  key_.clear();
  value_.clear();
  type_ = sheIni::INI_value_type::defaultValue;
};

std::tuple<sheIni::INI_line_state, sheIni::INI_value_type, std::string, std::string> sheIni::DealIni::get() {
  return std::make_tuple(result_,type_,key_,value_);
}

