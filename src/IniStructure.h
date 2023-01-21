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
  using value    = std::tuple</*file*/std::string,/*d*/double,/*i*/int,/*common*/std::string>;
  using map_kv   = std::unordered_map<std::string,value>;
  using map_s_kv = std::unordered_map<std::string,map_kv>;
  map_s_kv IniStructure_;
  std::string section_;

 public:
  void readFromFile(const std::string& path);
  IniStructure& section(const std::string& section);
  std::string getKey(const std::string& key);




};// class IniStructure
};// namespace sheIni

#endif //SHEINI_INISTRUCTURE_H
