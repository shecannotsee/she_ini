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
    std::cout<<"section1\n";
    std::string key1 = IniTestFile_ini.section("section1").getKey("key1");
    std::cout << "[" <<key1 << "]\n";
    std::string key2 = IniTestFile_ini.section("section1").getKey("key2");
    std::cout << "[" <<key2 << "]\n";
    std::string key3 = IniTestFile_ini.section("section1").getKey("key3");
    std::cout << "[" <<key3 << "]\n";

    std::cout<< "section2\n";
    std::string key4 = IniTestFile_ini.section("section2").getKey("key1");
    std::cout << "[" <<key4 << "]\n";
    std::string key5 = IniTestFile_ini.section("section2").getKey("key2");
    std::cout << "[" <<key5 << "]\n";

    std::cout<< "section3\n";
    std::string s3_key1 = IniTestFile_ini.section("section3").getKey("key1");
    std::cout << "[" <<s3_key1 << "]\n";
    std::string s3_seconds = IniTestFile_ini.section("section3").getKey("seconds");
    std::cout << "[" <<s3_seconds << "]\n";
    std::string s3_x = IniTestFile_ini.section("section3").getKey("x");
    std::cout << "[" <<s3_x << "]\n";

  } catch (const std::runtime_error& e) {
    std::cout << "Caught a runtime_error exception: " << e.what() << '\n';
  }

};

};// namespace method_6_IniStructure

#endif //SHEINI_METHOD_6_INISTRUCTURE_TEST_H
