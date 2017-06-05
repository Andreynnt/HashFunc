cmake_minimum_required(VERSION 3.7)
project(Hash)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp AutoTests.hpp Hash.hpp Hash.cpp)
add_executable(Hash ${SOURCE_FILES})