//
// Created by  shecannotsee on 2023/1/21.
//

#ifndef SHEINI_INISTRUCTURE_H
#define SHEINI_INISTRUCTURE_H

#include <string>
#include <unordered_map>
#include <tuple>

namespace sheIni {
class IniStructure {
 public:
  IniStructure();
  ~IniStructure() = default;
  // Disable copy
  IniStructure(const IniStructure&) = delete;
  IniStructure& operator=(const IniStructure&) = delete;
  // Disable move
  IniStructure(IniStructure &&) = delete;
  IniStructure& operator=(IniStructure&&) = delete;

 private:
  // std::get<0>()  std::string,file path
  // std::get<1>()  double
  // std::get<2>()  int
  // std::get<3>()  std::string
  using value    = std::tuple</*file*/std::string,/*d*/double,/*i*/int,/*common*/std::string>;
  using map_kv   = std::unordered_map<std::string,value>;
  using map_s_kv = std::unordered_map<std::string,map_kv>;
  map_s_kv IniStructure_;
  std::string section_;

  void trustProcess(char ch);

 public:
  // 读取文件并进行解析
  void readFromFile(const std::string& path);
  IniStructure& section(const std::string& section);
  // 通用std::string接口返回
  std::string getKey(const std::string& key);
  // TODO:需要添加特化接口


};// class IniStructure
};// namespace sheIni

#endif //SHEINI_INISTRUCTURE_H
