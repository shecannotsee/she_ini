#include <she_test.h>
#include <source_loader.h>

#include <filesystem>

TEST(unit, source_loader_test) {
  // Prepare the data //////////////////////////////////////////////////////////////////////////////////////////////////
  const auto current_path = std::filesystem::current_path();
  std::cout << "The current path is: " << current_path << "\n";

  // check and create dir
  const auto temp_dir = "temp";
  if (!std::filesystem::exists(temp_dir)) {
    std::cout << "Directory [" << temp_dir << "] does not exist.\n";
    std::filesystem::create_directory(temp_dir);
  }

  const auto data_file_path = current_path / temp_dir / "source_loader_test.ini";

  // check file
  if (!std::filesystem::exists(data_file_path)) {
    std::cout << "File [" << data_file_path << "] does not exist.\n";
  }

  // write to file
  std::ofstream write_file(data_file_path);
  if (!write_file.is_open()) {
    std::cerr << "Open file failed: " << data_file_path << "\n";
  }
  write_file << "; this is comment\n";
  write_file << "[ip]\n";
  write_file << "host = 127.0.0.1\n";
  write_file << "server = 192.168.10.100\n";
  write_file.close();
  std::cout << "file size is: " << std::filesystem::file_size(data_file_path) << " Bytes\n";

  // start test ////////////////////////////////////////////////////////////////////////////////////////////////////////
  ini::detail::source_loader test_loader_1(data_file_path);
  std::cout << "\n" << "test read_buffer" << "\n";
  for (std::vector<char> buffer = test_loader_1.read_buffer(); !buffer.empty(); buffer = test_loader_1.read_buffer()) {
    for (const auto& ch : buffer) {
      std::cout << ch;
    }
  }

  ini::detail::source_loader test_loader_2(data_file_path);
  std::cout << "\n" << "test read_char" << "\n";
  while (auto ch = test_loader_2.read_char()) {
    std::cout << (*ch);
  }

  // clear data ////////////////////////////////////////////////////////////////////////////////////////////////////////
  std::filesystem::remove_all(temp_dir);
}