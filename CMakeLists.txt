cmake_minimum_required(VERSION 3.13)
project(crcxx)

set(CMAKE_CXX_STANDARD 14)

enable_testing()
add_executable(crcxx_test test/crcxx_test.cpp)
add_test(NAME crcxx_test COMMAND crcxx_test)
