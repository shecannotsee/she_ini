//
// Created by shecannotsee on 2022/10/14.
//

#ifndef TCP_CLIENT_TEST_SHEINI_SRC_INTERFACEEXAMPLE_H_
#define TCP_CLIENT_TEST_SHEINI_SRC_INTERFACEEXAMPLE_H_

#include <iostream>
#include <vector>
#include "DataStructure/Section.h"
#include "Parse/Parse.h"

/*
 * example to read from server.config
 * ***********************************
 * [server]
 * ip = 127.0.0.1
 * port = 8080
 * ***********************************
 * std::string section_server = "server";
 * std::string ip = "ip";
 * std::string port = "port";
 * get(section_server, ip, port);//get ip and port
 */
void getConfig(std::string& section, std::string& ip, std::string& port) {
  std::vector<sheIni::Section> config;
  /* get config */ {
    sheIni::IniFile config_file("./server.config");
    config_file.parse(config);
  }
  for (auto& e:config) {
    // get section
    if (e.getSection() == section) {
      for (auto& ee: e.getAllKV() ) {
        if      (std::get<0>(ee) == ip)   ip   = std::get<1>(ee);
        else if (std::get<0>(ee) == port) port = std::get<1>(ee);
      }
    }
  }
}


#endif //TCP_CLIENT_TEST_SHEINI_SRC_INTERFACEEXAMPLE_H_
