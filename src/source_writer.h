/**
 * @file source_writer.h
 * @brief Header file for the source_writer class, responsible for writing data to a file.
 *
 * This file defines the source_writer class, which provides functionality for writing
 * raw data, strings, and vectors of characters to a file. The class also provides a method
 * for flushing the file buffer to ensure data is written to disk.
 */
#ifndef SHE_INI_SOURCE_WRITER_H
#define SHE_INI_SOURCE_WRITER_H

#include <fstream>
#include <vector>

namespace ini::detail {

/**
 * @class source_writer
 * @brief A utility class for writing data to a file.
 *
 * The source_writer class handles writing raw data, strings, and vectors of characters
 * to a file. It ensures that data is written in binary format and provides a method for
 * flushing the output buffer to ensure data is immediately written to the file.
 */
class source_writer {
  std::ofstream file_;  ///< Output file stream to write data to the file.

 public:
  /**
   * @brief Constructs a source_writer object and opens the specified file for writing.
   *
   * @param file_path The path to the file where data will be written.
   * @note The file is opened in binary mode.
   */
  explicit source_writer(const std::string& file_path) noexcept;

  /**
   * @brief Destructor that closes the file stream if it's open.
   */
  ~source_writer();

  /**
   * @brief Writes raw data (character array) to the file.
   *
   * @param data A pointer to the data to be written.
   * @param size The size of the data to write.
   * @note This function writes the raw binary data to the file.
   */
  void write(const char* data, uint32_t size) noexcept;

  /**
   * @brief Writes a string to the file.
   *
   * @param data The string to be written to the file.
   * @note This function writes the string as raw binary data.
   */
  void write(const std::string& data) noexcept;

  /**
   * @brief Writes a vector of characters to the file.
   *
   * @param data The vector of characters to be written to the file.
   * @note This function writes the contents of the vector as raw binary data.
   */
  void write(const std::vector<char>& data) noexcept;

  /**
   * @brief Flushes the file buffer, ensuring that all written data is physically written to disk.
   *
   * This method ensures that all previously written data is flushed from the internal
   * buffer to the file on disk. It is useful when you want to guarantee data is written
   * before closing the file or before performing other operations.
   */
  void fflush() noexcept;
};

}  // namespace ini::detail

#endif  // SHE_INI_SOURCE_WRITER_H
