cmake_minimum_required(VERSION 3.20)
project(pramatheshmishr)

set(CMAKE_CXX_STANDARD 14)

add_executable(pramatheshmishr main.cpp)
include_directories(libxl-4.1.0/include_cpp)
