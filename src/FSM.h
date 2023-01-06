//
// Created by shecannotsee on 2022/12/19.
//
// 该类是一个状态机的类，设计初衷希望能够不过多的参与业务处理，仅仅作为一个框架进行使用
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
 private:
  void running(char);
 public:
  // 传入一个字符推动自动机运行并获取运行结果
  bool isEnd(char);
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 private:
  // 无法避免的业务成员变量
  std::unique_ptr<DealIni> dealIni_;// 因为禁用了拷贝和移动，所以用智能指针在类中来管理该对象
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
