//
// Created by  shecannotsee on 2023/1/21.
//

#ifndef SHEINI_INISTRUCTURE_H
#define SHEINI_INISTRUCTURE_H
namespace sheIni {
class IniStructure {
 public:
  IniStructure() = default;
  ~IniStructure() = default;
  // copy
  IniStructure(const IniStructure&) = delete;
  IniStructure& operator=(const IniStructure&) = delete;
  // move
  IniStructure(IniStructure &&) = delete;
  IniStructure& operator=(IniStructure&&) = delete;

};// class IniStructure
};// namespace sheIni

#endif //SHEINI_INISTRUCTURE_H
