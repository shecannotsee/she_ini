//
// Created by shecannotsee on 2022/10/8.
//

#ifndef SHE_INI_PARSE_TEST_SHEINI_SRC_TEMP_H_
#define SHE_INI_PARSE_TEST_SHEINI_SRC_TEMP_H_

#include <string>
#include <fstream>
#include <tuple>
#include <vector>
#include <map>
#include <memory>
#include "StringExtend.h"

namespace temp {
template<typename T, typename... Args>
std::unique_ptr<T> make_unique(Args &&... args) {
  return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
}
}//namespace temp


using std::string;
using std::vector;
using std::map;

void method1() {
  vector<
      tuple<string,std::unique_ptr< map<string,string> >>
      > section_kv;

  std::ifstream infile;
  infile.open("./config.ini", std::ios::in);

  if (!infile.is_open()) {
    std::cout<<"Open filed.\n";
    exit(1);
  }

  string buf;
  // three status:
  // 0-no section loading
  // 1-section has been loaded
  // 2-section has changed
  int section_next = 0;
  tuple<bool,string> success_section;
  tuple<bool,string,string> success_key_value;
  while (getline(infile, buf)) {
    buf = trim(buf);
    if (buf[0] == ';' || buf[0]=='#')
      std::cout<<"// is:====="<<buf<<"=====\n";
    else if (buf[0]=='[')
      success_section = getSection(buf);
    else
      success_key_value = getKV(buf);

    if (std::get<0>(success_section)) {
      section_next = 2;
    }

    if (section_next==2) {
      // add sectiona
      section_kv.emplace_back(std::get<1>(success_section), temp::make_unique<map<string,string>>());
      section_next = 1;
      std::get<0>(success_section) = false;//Throw it away after use, otherwise it will affect the value of section_next
    } else if (section_next == 1) {
      // add kv to section
      std::get<1>(section_kv.back())->
          insert(map<string,string>::value_type(
              std::get<1>(success_key_value),
              std::get<2>(success_key_value)
              ));
    }

  }//read over

  // Display the read results
  for(auto & e : section_kv) {
    std::cout<<"section is:"<<std::get<0>(e)<<"\n";

    for( auto& ee:*(std::get<1>(e)) ) {
      std::cout<<"key:"<<ee.first<<"==========="
               <<"value:"<<ee.second<<"\n";
    }

  }

};//method1

#endif //SHE_INI_PARSE_TEST_SHEINI_SRC_TEMP_H_
