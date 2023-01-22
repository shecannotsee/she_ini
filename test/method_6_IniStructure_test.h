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
    std::string key1 = IniTestFile_ini.section("section1").getKey("key1");
    std::cout << "[" <<key1 << "]\n";

    std::string key2 = IniTestFile_ini.section("section2").getKey("key2");
    std::cout << "[" <<key2 << "]\n";

    std::string x = IniTestFile_ini.section("section3").getKey("key1");
    std::cout << "[" <<x << "]\n";

  } catch (const std::runtime_error& e) {
    std::cout << "Caught a runtime_error exception: " << e.what() << '\n';
  }

};

};// namespace method_6_IniStructure

#endif //SHEINI_METHOD_6_INISTRUCTURE_TEST_H
