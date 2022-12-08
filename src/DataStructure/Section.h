//
// Created by shecannotsee on 2022/10/8.
//
// An A contains many key value pairs
// You can use vector or array to represent many sections,like this:
// *******************************************************************
// vector<Section> section_s;
// Section* section_s_ptr = new Sections(N);//remember to delete[] this.
// ******************************************************************
//

#ifndef SHE_INI_PARSE_TEST_SHEINI_SRC_DATASTRUCTURE_SECTION_H_
#define SHE_INI_PARSE_TEST_SHEINI_SRC_DATASTRUCTURE_SECTION_H_

#include <string>
#include <vector>
#include <map>
#include <tuple>
#include <memory>

namespace sheIni {
using std::string;
using std::unique_ptr;
using std::map;
using std::vector;
using std::tuple;

class Section {
 private:
  string _section_name;
  unique_ptr<map<string,string>> _kv_p;

 public:
  Section()
      : Section(" ") {};

  explicit Section(const string& section_name)
      : _section_name(section_name),
        _kv_p(std::make_unique<map<string,string>>()) {};

  ~Section() = default;;
  Section(const Section&) = delete;
  Section& operator=(const Section&) = delete;
  Section(Section&&) = default;
  Section& operator=(Section&&) = default;
  
 public:
  void setSection(const string& section_name) {
    _section_name = section_name;
  };

  string getSection() {
    return _section_name;
  };

  void setKV(const string& key, const string& value) {
    _kv_p->insert(map<string,string>::value_type(key,value));
  };

  vector<tuple<string,string>> getAllKV() {
    vector<tuple<string,string>> res;
    for (auto& e: (*_kv_p)) {
      res.emplace_back(e.first,e.second);
    }
    return res;
  };

};

};//namespace sheINI

#endif //SHE_INI_PARSE_TEST_SHEINI_SRC_DATASTRUCTURE_SECTION_H_
