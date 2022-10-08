//
// Created by shecannotsee on 2022/10/8.
//

#ifndef SHE_INI_PARSE_TEST_SHEINI_SRC_STRINGEXTEND_H_
#define SHE_INI_PARSE_TEST_SHEINI_SRC_STRINGEXTEND_H_

#include <string>
#include <tuple>
using std::string;
using std::tuple;

string& trim(string& s){
  if(s.empty()) return s;
  s.erase(0, s.find_first_not_of(' '));
  s.erase(s.find_last_not_of(' ') + 1);
  return s;
};

tuple<bool, string> getSection(const string& s) {
  string section;
  tuple<bool, string> res;
  std::get<0>(res) = false;
  std::get<1>(res) = section;

  bool set_to_res = false;
  for(auto& e:s) {
    if(e=='[')
      set_to_res = true;
    else if (e==']') {
      set_to_res = false;
      std::get<0>(res) = true;
    }

    if(set_to_res && e!='[')
      section += e;
  }
  std::get<1>(res) = section;
  return res;
};

tuple<bool,string,string> getKV(const string& s) {
  tuple<bool,string,string> res;
  string key,value;
  std::get<0>(res) = false;
  std::get<1>(res) = key;
  std::get<2>(res) = value;

  bool key_to_value = false;
  for( auto& e:s) {
    if( e=='=') {
      key_to_value = true;
      std::get<0>(res) = true;
    }
    else {
      if (key_to_value)
        value += e;
      else
        key += e;
    }
  }
  std::get<1>(res) = trim(key);
  std::get<2>(res) = trim(value);
  return res;
};



#endif //SHE_INI_PARSE_TEST_SHEINI_SRC_STRINGEXTEND_H_
