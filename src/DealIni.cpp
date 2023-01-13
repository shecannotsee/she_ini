//
// Created by  shecannotsee on 2023/1/7.
//

#include "DealIni.h"

sheIni::DealIni::DealIni()
    : line_state_(INI_line_state::defaultValue),
      type_(INI_value_type::defaultValue),
      key_(std::string()),
      value_(std::string()),
      next_(INI_reading_pointer::defaultValue) {
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
  // 该行是一个注释
  line_state_ = INI_line_state::note;
  // 仅在测试时将注释写入value
  next_ = INI_reading_pointer::value;
  return FSM_state::Sizzle;
};

sheIni::FSM_state sheIni::DealIni::multipleSection(char ch) {
  if (ch == (int)INI_char_state::section_start) {
    // 该行是一个section
    line_state_ = INI_line_state::section;
    next_ = INI_reading_pointer::value;
  } else if (ch==(int)INI_char_state::section_end) {
    next_ = INI_reading_pointer::defaultValue;
  } else {
    line_state_ = INI_line_state::error;
    next_ = INI_reading_pointer::error;
  }
  return sheIni::FSM_state::Sizzle;
};

sheIni::FSM_state sheIni::DealIni::multipleType(char ch) {
  if (ch == (int)INI_char_state::type_start) {
    // 该行是一个有类型的k-v
    line_state_ = INI_line_state::TypeValue;
    next_ = INI_reading_pointer::type;
  } else if (ch==(int)INI_char_state::type_end) /*处理完type后续按照正常kv处理即可*/ {
    next_ = INI_reading_pointer::key;
  } else {
    line_state_ = INI_line_state::error;
  }
  return sheIni::FSM_state::Sizzle;
}

sheIni::FSM_state sheIni::DealIni::singleEqual(char ch) {
  // 如果该行仍为默认状态,那么该行是一个无类型k-b
  if (line_state_==INI_line_state::defaultValue) {
    line_state_ == INI_line_state::noTypeValue;
  }
  next_ = INI_reading_pointer::value;
  return sheIni::FSM_state::Sizzle;
};

sheIni::FSM_state sheIni::DealIni::singleLineEnd(char ch) {
  return FSM_state::Stop;
};

sheIni::FSM_state sheIni::DealIni::singleLinuxLineBreak(char ch) {
  if (next_== INI_reading_pointer::maybe_end) /*兼容windows下的换行符*/ {
    return  FSM_state::Stop;
  } else /*当然,遇到换行符都是行结束的意思*/ {
    return sheIni::FSM_state::Stop;
  }
};

sheIni::FSM_state sheIni::DealIni::multipleWindowsLineBreak(char ch) {
  //临时存储,若'\r'后不是'\n'时用来复原状态
  temp_ = next_;
  next_ = INI_reading_pointer::maybe_end;
  return sheIni::FSM_state::Sizzle;
};

sheIni::FSM_state sheIni::DealIni::dealOtherChar(char ch) {
  if (ch == (int )INI_char_state::space) {
    // Space
  }
  else if (next_==INI_reading_pointer::note) {
    // 只是用来测试,生产中不会对任何注释进行解析
    value_ += ch;
  }
  else if (next_==INI_reading_pointer::section) {
    value_ += ch;
  }
  else if (next_==INI_reading_pointer::type) {
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
  else if (next_==INI_reading_pointer::key) /*仅处理了有类型的key*/ {
    key_ += ch;
  }
  else if (next_==INI_reading_pointer::value) {
    value_ +=ch;
  }
  else if (next_==INI_reading_pointer::maybe_end) {
    // 运行到此分支代表'\r'后的字符不是'\n'
    next_ = temp_;// 还原状态
    this->dealOtherChar('\r');
    this->dealOtherChar(ch);
  }
  else if (next_==INI_reading_pointer::end) {
    // 此分支不会被运行
  }
  else /*处理一些其他的字符以及其他情况*/ {
    // 处理无类型k-v
    if (next_==INI_reading_pointer::defaultValue) {
      // 表明该行是noType k-v
      line_state_ = INI_line_state::noTypeValue;
      // 变更下次处理的状态
      next_==INI_reading_pointer::key;
      // 处理传入字符
      key_ += ch;
    } else {
      line_state_ == INI_line_state::error;
      return FSM_state::Stop;
    }
  }

  return FSM_state::Sizzle;
};

void sheIni::DealIni::setDefault() {
  line_state_ = INI_line_state::defaultValue;
  type_ = INI_value_type::defaultValue;
  key_.clear();
  value_.clear();
  next_ = INI_reading_pointer::defaultValue;
  temp_ = INI_reading_pointer::defaultValue;
};

std::tuple<sheIni::INI_line_state, sheIni::INI_value_type, std::string, std::string> sheIni::DealIni::get() {
  return std::make_tuple(line_state_,type_,key_,value_);
};

