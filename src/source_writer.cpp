#include "source_writer.h"

using namespace ini::detail;

source_writer::source_writer(const std::string& file_path) noexcept {
  file_.open(file_path, std::ios::binary | std::ios::out);
  if (!file_.is_open()) {
    const auto error = "Open file failed: " + file_path;
    throw std::runtime_error(error);
  }
}

source_writer::~source_writer() {
  file_.close();
}

void source_writer::write(const char* data, const uint32_t size) noexcept {
  if (file_ && data) {
    file_.write(data, size);
  }
}

void source_writer::write(const std::string& data) noexcept {
  if (file_) {
    file_.write(data.data(), data.size());
  }
}

void source_writer::write(const std::vector<char>& data) noexcept {
  if (file_) {
    file_.write(data.data(), data.size());
  }
}

void source_writer::fflush() noexcept {
  if (file_) {
    file_.flush();
  }
}
