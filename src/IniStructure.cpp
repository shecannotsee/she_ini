//
// Created by  shecannotsee on 2023/1/21.
//

#include "IniStructure.h"
#include <fstream>

sheIni::IniStructure::IniStructure()
    : IniStructure_(),
      section_(std::string()) {
};

void sheIni::IniStructure::trustProcess(char ch,sheIni::FSM& characterParser) {
  characterParser.add(ch);
  if (characterParser.getState()==sheIni::FSM_state::Stop) {
    auto ret = characterParser.get();
    if (std::get<0>(ret) == sheIni::INI_line_state::note ||
        std::get<0>(ret) == sheIni::INI_line_state::defaultValue) {
      // pass
    }
    else if (std::get<0>(ret) == sheIni::INI_line_state::section) {
      section_ = std::get<3>(ret);
      IniStructure_.insert(std::make_pair(section_,map_kv()));
    }
    else if (std::get<0>(ret) == sheIni::INI_line_state::TypeValue ||
             std::get<0>(ret) == INI_line_state::noTypeValue) {
      std::string temp = std::get<3>(ret);
      value v_temp = std::make_tuple(std::string(), 0.0, 0, std::get<3>(ret));/*构造该值*/ {
          if (std::get<1>(ret) != INI_value_type::defaultValue) {
            // value存在类型时
            if (std::get<1>(ret) == INI_value_type::filePath) {
              // 类型为文件路径时
              std::get<0>(v_temp) = std::get<3>(ret);
            } else if (std::get<1>(ret) == INI_value_type::FPN) {
              // 类型为浮点数时
              std::get<1>(v_temp) = std::stod(std::get<3>(ret));
            } else if (std::get<1>(ret) == INI_value_type::integer) {
              // 类型为整数时
              std::get<2>(v_temp) = std::stoi(std::get<3>(ret));
            } else /*deal error*/ {
              throw std::runtime_error("Value type processing error.\n");
            }
          }
        };
      (IniStructure_[section_]).emplace(std::get<2>(ret),v_temp);
    }
    else {
      throw std::runtime_error("An error occurred while organizing the ini data structure.\n");
    }
  }
  else if (characterParser.getState()==sheIni::FSM_state::ERROR) {
    throw std::runtime_error("Maybe some errors have appeared.\n");
  }
  else if (characterParser.getState()==sheIni::FSM_state::Sizzle) {
    // do nothing...
  };
};

void sheIni::IniStructure::readFromFile(const std::string &path) {
  std::ifstream ini_file(path);
  if (!ini_file.is_open()) {
    throw std::runtime_error("Failed to open INI file.\n");
    return;
  }

  sheIni::FSM characterParser;
  for (char ch; ini_file.get(ch);) {
    this->trustProcess(ch,characterParser);
  };
  // 若文件末尾没有结尾标志(换行符或者是';'),需要手动添加结束符号来处理最后一行的数据,否则则会遗漏最后一行的数据
  this->trustProcess('\n',characterParser);
};

sheIni::IniStructure &sheIni::IniStructure::section(const std::string &section) {
  section_ = section;
  return *this;
};

std::string sheIni::IniStructure::getKey(const std::string &key) {
  return std::get<3>(IniStructure_[section_][key]);
};

