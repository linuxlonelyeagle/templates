cmake_minimum_required(VERSION 3.5)
project(Templates)
set(CMAKE_CXX_STANDARD 17)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

add_executable(print print.cpp)
add_executable(enable_if_t enable_if_t.cpp)
