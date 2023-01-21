//
// Created by  shecannotsee on 2023/1/21.
//

#include "IniStructure.h"
#include <fstream>
#include <FSM.h>

sheIni::IniStructure::IniStructure()
    : IniStructure_(),
      section_(std::string()) {
};


void sheIni::IniStructure::readFromFile(const std::string &path) {
  std::ifstream ini_file("../IniTestFile.ini");
  if (!ini_file.is_open()) {
    throw std::runtime_error("Failed to open INI file.\n");
    return;
  }

  sheIni::FSM characterParser;
  for (char ch; ini_file.get(ch);) {
    characterParser.add(ch);
    if (characterParser.getState()==sheIni::FSM_state::Stop) {
      auto ret = characterParser.get();
      if (std::get<0>(ret) == sheIni::INI_line_state::note || std::get<0>(ret) == sheIni::INI_line_state::defaultValue) {
        // pass
      }
      else if (std::get<0>(ret) == sheIni::INI_line_state::section) {
        section_ = std::get<3>(ret);
      }
      else if (std::get<0>(ret) == sheIni::INI_line_state::TypeValue) {
        std::string temp = std::get<3>(ret);
        value v_temp = std::make_tuple(std::string(),0.0,0,std::get<3>(ret));
      }
      else if (std::get<0>(ret) == INI_line_state::noTypeValue) {
        std::string temp = std::get<3>(ret);
        value v_temp = std::make_tuple(std::string(),0.0,0,std::get<3>(ret));
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
  };// loop in every char

  // 若文件末尾没有结尾标志(换行符或者是';'),需要手动添加结束符号来处理最后一行的数据,否则则会遗漏最后一行的数据
  characterParser.add('\n');
  if (characterParser.getState()==sheIni::FSM_state::Stop) {
    auto ret = characterParser.get();
  }
};

sheIni::IniStructure &sheIni::IniStructure::section(const std::string &section) {
  section_ = section;
  return *this;
};

std::string sheIni::IniStructure::getKey(const std::string &key) {
  return IniStructure_[section_][key];
};
