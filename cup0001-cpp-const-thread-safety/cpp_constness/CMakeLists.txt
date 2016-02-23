cmake_minimum_required(VERSION 3.3)
project(cpp_constness)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

set(SOURCE_FILES main.cpp)
add_executable(cpp_constness ${SOURCE_FILES})
