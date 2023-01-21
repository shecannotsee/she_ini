//
// Created by  shecannotsee on 2023/1/21.
//

#ifndef SHEINI_METHOD_6_INISTRUCTURE_TEST_H
#define SHEINI_METHOD_6_INISTRUCTURE_TEST_H

#include <IniStructure.h>

namespace method_6_IniStructure {

void main() {
  sheIni::IniStructure IniTestFile_ini;
  IniTestFile_ini.readFromFile("../IniTestFile.ini");
  try {
    auto key1 = IniTestFile_ini.section("section1").getKey("key1");
    std::cout << key1 << "\n";
  } catch (const std::runtime_error& e) {
    std::cout << "Caught a runtime_error exception: " << e.what() << '\n';
  }

};

};// namespace method_6_IniStructure

#endif //SHEINI_METHOD_6_INISTRUCTURE_TEST_H
