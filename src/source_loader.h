/**
 * @file source_loader.h
 * @brief Defines the source_loader class responsible for reading characters
 *        or buffered chunks from a given file source.
 *
 * This module provides a low-level file reader that supports sequential
 * character access and buffered reading. It is intended to be used in
 * lexer and parser systems where fine-grained control of source input
 * is necessary.
 */
#ifndef SHE_INI_SOURCE_LOADER_H
#define SHE_INI_SOURCE_LOADER_H

#include <fstream>
#include <optional>
#include <vector>

namespace ini::detail {

/**
 * @class source_loader
 * @brief Provides an interface for reading input from a file.
 *
 * The source_loader class encapsulates an input file stream, allowing
 * for character-by-character reading as well as fixed-size buffered
 * reading. It is typically used as the first stage in a parsing pipeline
 * to provide input data to a lexer.
 */
class source_loader {
  std::ifstream file_;  ///< Internal file stream used for reading.

 public:
  /**
   * @brief Constructs a source_loader and opens the specified file.
   * @param file_path Path to the file to be opened.
   * @throws std::runtime_error If the file cannot be opened.
   * @note The file is opened in binary mode to preserve raw input.
   */
  explicit source_loader(const std::string& file_path) noexcept;

  /**
   * @brief Destructor. Closes the file stream if open.
   */
  ~source_loader();

  /**
   * @brief Reads a single character from the input file.
   * @return An optional character. Returns std::nullopt if the end of the file
   *         is reached or a read error occurs.
   */
  auto read_char() -> std::optional<char>;

  /**
   * @brief Reads a block of characters from the input file.
   * @param size Number of bytes to read into the buffer. Defaults to 1024.
   * @return A vector containing the characters read. The vector size may be less
   *         than the requested size if the end of the file is reached.
   */
  auto read_buffer(uint32_t size = 1024) -> std::vector<char>;
};

}  // namespace ini::detail

#endif  // SHE_INI_SOURCE_LOADER_H
