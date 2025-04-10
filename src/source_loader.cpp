#include "source_loader.h"

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

auto source_loader::read_buffer(const uint8_t size) -> std::vector<char> {
  std::vector<char> buffer(size);
  file_.read(buffer.data(), size);
  buffer.resize(static_cast<size_t>(file_.gcount()));
  return buffer;
}