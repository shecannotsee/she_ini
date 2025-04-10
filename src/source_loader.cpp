#include "source_loader.h"

#include <iostream>
#include <stdexcept>

using namespace ini::detail;

source_loader::source_loader(const std::string& file_path) noexcept {
  file_.open(file_path, std::ios::binary);
  if (!file_.is_open()) {
    const auto error = "Open file failed: " + file_path;
    throw std::runtime_error(error);
  }
}
source_loader::~source_loader() {
  file_.close();
}

auto source_loader::read_char() -> std::optional<char> {
  if (char ch; file_.get(ch)) {
    return ch;
  } else {
    return std::nullopt;
  }
}

auto source_loader::read_buffer(const uint32_t size) -> std::vector<char> {
  // Get seek flag
  const std::streampos current_pos = file_.tellg();

  // Get file size
  file_.seekg(0, std::ios::end);
  const std::streampos file_end = file_.tellg();
  file_.seekg(current_pos);  // recover seek flag

  // Cal remaining and Create return buffer
  const std::streampos remaining = file_end - current_pos;
  std::vector<char> buffer(remaining);

  // read
  if (remaining >= size) {
    buffer.resize(size);
    file_.read(buffer.data(), size);
  } else {
    // read all
    buffer.resize(static_cast<size_t>(remaining));
    file_.read(buffer.data(), remaining);
  }

  return buffer;
}