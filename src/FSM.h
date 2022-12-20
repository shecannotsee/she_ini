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
  FSM_S state_; // 状态机当前的状态
  std::unordered_map<char,std::function<void()>> table_; // 根据
  std::string key_;
  std::string value_;
 public:
  // 注册状态机动作
  void registerEvent();
  // 输入一个字符串
  void addLine(std::string line);
  // 获取输出结构
  void getResults();
 private:
  // 添加一些输入的固定动作
  void addState(char, std::function<void()>);
  // 提交可以触发状态机状态改变的事件
  void addEvent(char ch);
};



#endif //SHEINI_SRC_FSM_H_
