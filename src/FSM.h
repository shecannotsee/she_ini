//
// Created by shecannotsee on 2022/12/19.
//

#ifndef SHEINI_SRC_FSM_H_
#define SHEINI_SRC_FSM_H_

#include <string>
#include <tuple>

enum class INI_s : unsigned int {
  Unknown = 0,    // 未知状态
  Note,           // 注释
  IniFile,        // 是一个文件
  Section,        // 是一个Section
  KeyWithValue    // 是一个普通kv键值对
};

enum class FSM_S :unsigned int {
  start = 0,
  middle,
  end
};

class FSM {
 private:
  INI_s state_;
  std::string key_;
  std::string value_;
 public:
  FSM() = default;
  ~FSM() = default;
 public:
  void
  std::tuple<INI_s, std::string> getResults();
 private:


};

#endif //SHEINI_SRC_FSM_H_
