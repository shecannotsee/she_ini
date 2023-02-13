#include <iostream>
#include <string>
// You should use this head file.
#include <IniStructure.h>

int main() {
  sheIni::IniStructure web_config;
  // Load the file data to your memory object.
  web_config.readFromFile("../config.ini");
  // And use the results.
  auto ip       = web_config.section("config-set").getKey("ip");
  auto port     = web_config.section("config-set").getKey("port");
  auto cfg_path = web_config.section("config-set").getKey("config_path");
  auto log_path = web_config.section("config-set").getKey("log_path");

  using ::std::cout;using ::std::endl;
  // print
  cout << "http://" << ip << ":" << port << endl;
  cout << "Config peth :[" << cfg_path << "]\n";
  cout << "log path :[" << log_path << "]\n";


  return 0;
};