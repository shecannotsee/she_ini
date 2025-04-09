#include <she_test.h>

int main(int argc, char** argv) {
  // To use other output formats, you need to implement and add a custom instance.
  // By default, the framework provides `gtest` and `style_v1` styles for selection.
  she_test::run_all_test<>(argc, argv); // Equivalent to the commented code below
  // she_test::run_all_test<she_test::format::gtest>(argc, argv);
  // Or use the `style_v1` format for output
  // she_test::run_all_test<she_test::format::style_v1>(argc, argv);
  return 0;
}