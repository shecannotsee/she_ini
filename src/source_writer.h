#ifndef SHE_INI_SOURCE_WRITER_H
#define SHE_INI_SOURCE_WRITER_H

#include <fstream>
#include <vector>

namespace ini::detail {

class source_writer {
  std::ofstream file_;

 public:
  explicit source_writer(const std::string& file_path) noexcept;

  ~source_writer();

  void write(const char* data, uint32_t size) noexcept;

  void write(const std::string& data) noexcept;

  void write(const std::vector<char>& data) noexcept;

  void fflush() noexcept;
};

}  // namespace ini::detail

#endif  // SHE_INI_SOURCE_WRITER_H
