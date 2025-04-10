#include <she_test.h>
#include <source_writer.h>

#include <filesystem>

TEST(unit, source_writer_test) {
  // Prepare the data //////////////////////////////////////////////////////////////////////////////////////////////////
  const auto current_path = std::filesystem::current_path();
  std::cout << "The current path is: " << current_path << "\n";

  // check and create dir
  const auto temp_dir = "temp";
  if (!std::filesystem::exists(temp_dir)) {
    std::cout << "Directory [" << temp_dir << "] does not exist.\n";
    std::filesystem::create_directory(temp_dir);
  }

  const auto data_file_path = current_path / temp_dir / "source_writer_test.ini";

  // check file
  if (!std::filesystem::exists(data_file_path)) {
    std::cout << "File [" << data_file_path << "] does not exist.\n";
  }

  // start test ////////////////////////////////////////////////////////////////////////////////////////////////////////
  ini::detail::source_writer test(data_file_path);
  test.write("; this is comment\n");
  test.write("[ip]\n");
  test.write("host = 127.0.0.1\n");
  test.write("server = 192.168.10.100\n");
  test.fflush();

  // read from file
  std::ifstream read_file(data_file_path);
  if (!read_file.is_open()) {
    std::cerr << "Open file failed: " << data_file_path << "\n";
  }
  // 逐字读取
  for (char ch; read_file.get(ch);) {
    std::cout << ch;
  }
  read_file.close();
  // clear data ////////////////////////////////////////////////////////////////////////////////////////////////////////
  std::filesystem::remove_all(temp_dir);
}