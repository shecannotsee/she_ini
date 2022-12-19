//
// Created by shecannotsee on 2022/12/19.
//

#include <iostream>
#include <fstream>
#include <string>

int main() {
  std::cout<<"sheIni test start.\n";
  std::ifstream ini_file("../IniTestFile.ini");
  if (!ini_file.is_open()) {
    std::cout << "Failed to open INI file" << std::endl;
    return 0;
  }

  std::string line;
  while (std::getline(ini_file, line)) {

  }


  ini_file.close();

  std::cout<<"sheIni test end.\n";
  return 0;
};

