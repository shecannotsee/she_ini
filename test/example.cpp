//
// Created by shecannotsee on 2022/10/8.
//

#include <iostream>
#include <vector>
#include <temp.h>
#include <DataStructure/Section.h>
#include <Parse/Parse.h>

int main() {
  std::cout<<"start.\n";
  //method1();
  std::vector<sheIni::Section> config;
  {
    sheIni::IniFile config_file("../config.ini");
    config_file.parse(config);
  }

  for (auto& e:config) {
    std::cout<<"section is:"<<e.getSection()<<"\n";

    for (auto& ee: e.getAllKV() ) {
      std::cout<<"key:【"<<std::get<0>(ee)<<"】="
              <<"value【"<<std::get<1>(ee)<<"】\n";
    }
  }


  std::cout<<"end.\n";
  return 0;
};
