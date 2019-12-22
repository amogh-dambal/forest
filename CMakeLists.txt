cmake_minimum_required(VERSION 3.13)
project(forest)

include_directories(include)

set(CMAKE_CXX_STANDARD 11)
set(SOURCE_FILES src/main.cpp src/bst.cpp)
add_executable(tester ${SOURCE_FILES} )