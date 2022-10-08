//
// Created by shecannotsee on 2022/10/8.
//

#include "Parse.h"

sheIni::IniFile::IniFile()
    : IniFile("./config.ini") {};

sheIni::IniFile::IniFile(const string& path)
    : _file_path(path),
      _info(std::make_tuple(false, "default init.")) {
  _infile.open(_file_path, std::ios::in);
  if (_infile.is_open())
    _info = std::make_tuple(false,"open file failed.");
};

sheIni::IniFile::~IniFile() {
  _infile.close();
}

void sheIni::IniFile::parse(vector<Section>& sections) {
  string buf;
  int section_next = NO_SECTION_LOAD;
  tuple<bool,string> success_section;
  tuple<bool,string,string> success_key_value;

  while (getline(_infile,buf)) {
    buf = StringExtend::trim(buf);
    if (buf[0] == ';' || buf[0]=='#') {}
    else if (buf[0] == '[') /* get section */
      success_section = IniFile::getSection(buf);
    else                    /* get KV */
      success_key_value = IniFile::getKV(buf);

    if (std::get<0>(success_section)) {
      section_next = SECTION_CHANGE;
    }

    if (section_next==SECTION_CHANGE) {
      /* add sectiona */
      sections.push_back(Section(std::get<1>(success_section)));
      section_next = SECTION_LOAD;
      std::get<0>(success_section) = false;//Throw it away after use, otherwise it will affect the value of section_next
    } else if (section_next==SECTION_LOAD) {
      /* add kv to section */
      if (std::get<0>(success_key_value)) {
        sections.back().setKV(
            std::get<1>(success_key_value),
            std::get<2>(success_key_value)
        );
      }
    }

  }//read line
};

std::tuple<bool, std::string>
sheIni::IniFile::getInfo() {
  return _info;
};

std::tuple<bool, std::string>
sheIni::IniFile::getSection(const string& s) {
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

std::tuple<bool,std::string,std::string>
sheIni::IniFile::getKV(const string& s) {
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
  std::get<1>(res) = sheIni::StringExtend::trim(key);
  std::get<2>(res) = sheIni::StringExtend::trim(value);
  return res;
};
