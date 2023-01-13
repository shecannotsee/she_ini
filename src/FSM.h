//
// Created by shecannotsee on 2022/12/19.
//
// 该类是一个状态机的类，设计初衷希望能够不过多的参与业务处理，仅仅作为一个框架进行使用
// 目前该类与DealIni类高度耦合
// 目前该类只有三种状态，正在运行，终止和错误，
// 通过add(char)添加事件,通过getState获取当前状态机状态
//

#ifndef SHEINI_SRC_FSM_H_
#define SHEINI_SRC_FSM_H_

#include <string>
#include <tuple>
#include <memory>
#include <FSMState.h>
#include <DealIni.h>

namespace sheIni {
class FSM {
 public:
  FSM();
  ~FSM() = default;
  // Disable copy
  FSM(const FSM &) = delete;
  FSM &operator=(const FSM &) = delete;
  // Disable move
  FSM(FSM &&) = delete;
  FSM &operator=(FSM &&) = delete;

 private:
  FSM_state state_;
 public:
  void add(char);
  // 获取当前状态及状态
  FSM_state getState();
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  // TODO:或许用继承能够更好的处理业务和FSM框架类的耦合
 private:
  // 无法避免的业务成员变量
  std::unique_ptr<DealIni> dealIni_;// 因为禁用了拷贝和移动,所以用智能指针在类中来管理该对象
 public:
  // 无法避免的接口函数
  // std::get<0>() 为ini line类型
  // std::get<1>() 为value类型,如果有的话
  // std::get<2>() 为key或者section或者注释(仅在测试时存储注释) 的std::string
  // std::get<3>() 为value的std::string
  std::tuple<INI_line_state,INI_value_type,std::string,std::string> get();

};// class FSM
};// namespace sheIni



#endif //SHEINI_SRC_FSM_H_
