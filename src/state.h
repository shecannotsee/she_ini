//
// Created by shecannotsee on 2022/12/20.
//

#ifndef SHEINI_SRC_STATE_H_
#define SHEINI_SRC_STATE_H_

// 状态机的状态
enum class FSM_S :unsigned int {
  start = 0,    // 起始态
  middle,       // 中间态
  end           // 结束状态
};

// 读取ini行后的状态
enum class INI_S : unsigned int {
  Unknown = 0,    // 未知状态
  Note,           // 注释
  IniFile,        // 是一个文件
  Section,        // 是一个Section
  KeyWithValue    // 是一个普通kv键值对
};

#endif //SHEINI_SRC_STATE_H_
