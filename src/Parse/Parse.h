//
// Created by shecannotsee on 2022/10/8.
//

#ifndef SHE_INI_PARSE_TEST_SHEINI_SRC_PARSE_PARSE_H_
#define SHE_INI_PARSE_TEST_SHEINI_SRC_PARSE_PARSE_H_

#include <string>
#include <tuple>
#include <vector>
#include <fstream>
#include "../DataStructure/Section.h"

namespace sheIni {
using std::string;
using std::tuple;
using std::vector;

class StringExtend{
 public:
  static string& trim(string& s){
    if(s.empty()) return s;
    s.erase(0, s.find_first_not_of(' '));
    s.erase(s.find_last_not_of(' ') + 1);
    return s;
  };
};

enum {
  NO_SECTION_LOAD,
  SECTION_LOAD,
  SECTION_CHANGE
};

class IniFile {
 private:
  std::ifstream _infile;
  string _file_path;
  tuple<bool,string> _info;
 public:
  IniFile();
  explicit IniFile(const string& path);
  ~IniFile();
 public:
  tuple<bool, string> getInfo();
  void parse(vector<Section>&);

 public:
  static tuple<bool, string> getSection(const string& );
  static tuple<bool,string,string> getKV(const string& );

};

};

#endif //SHE_INI_PARSE_TEST_SHEINI_SRC_PARSE_PARSE_H_
