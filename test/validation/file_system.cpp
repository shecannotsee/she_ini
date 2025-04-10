#include <she_test.h>

#include <filesystem>
#include <fstream>  //

TEST(validation, file_system) {
  const auto current_path = std::filesystem::current_path();
  std::cout << "The current path is: " << current_path << "\n";

  // check and create dir
  const auto temp_dir = "temp";
  if (!std::filesystem::exists(temp_dir)) {
    std::cout << "Directory [" << temp_dir << "] does not exist.\n";
    std::filesystem::create_directory(temp_dir);
  }

  const auto web_config_file_path = current_path / temp_dir / "web_config.ini";

  // check file
  if (!std::filesystem::exists(web_config_file_path)) {
    std::cout << "File [" << web_config_file_path << "] does not exist.\n";
  }

  // write to file
  std::ofstream write_file(web_config_file_path);
  if (!write_file.is_open()) {
    std::cerr << "Open file failed: " << web_config_file_path << "\n";
  }
  write_file << "; this is comment\n";
  write_file << "[ip]\n";
  write_file << "host = 127.0.0.1\n";
  write_file << "server = 192.168.10.100\n";
  write_file.close();

  // read from file
  std::ifstream read_file(web_config_file_path);
  if (!read_file.is_open()) {
    std::cerr << "Open file failed: " << web_config_file_path << "\n";
  }
  // 逐字读取
  for (char ch; read_file.get(ch);) {
    std::cout << ch;
  }
  read_file.close();

  std::filesystem::remove_all(temp_dir);
}