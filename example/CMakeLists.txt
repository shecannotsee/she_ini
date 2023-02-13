cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(PROJECT_NAME "example")
set(CMAKE_CXX_FLAGS "-g")# 断点无效处理方案
project(${PROJECT_NAME})

set(sheIni "${CMAKE_SOURCE_DIR}/sheIni")

# include
include_directories(${sheIni}/include)
# lib
link_directories(${sheIni}/lib)

file(GLOB_RECURSE SRC "${CMAKE_SOURCE_DIR}/example.cpp")
add_executable(${PROJECT_NAME} ${SRC})

# 链接库
target_link_libraries(${PROJECT_NAME} "-pthread"
        sheIni)