# internal project
include_directories(${CMAKE_SOURCE_DIR}/src)
include_directories(${CMAKE_SOURCE_DIR}/test)

########################################################################################################################
# set: she_test
set(_she_test_path "${CMAKE_CURRENT_SOURCE_DIR}/third_party/she_test")
set(she_test_include_dir "${_she_test_path}/include")
set(she_test_lib_dir "${_she_test_path}/lib")
set(she_test_link_libs she_test)
# import gtest
include_directories(${she_test_include_dir})
link_directories(${she_test_lib_dir})
list(APPEND test_link_dependency ${she_test_link_libs})
########################################################################################################################


