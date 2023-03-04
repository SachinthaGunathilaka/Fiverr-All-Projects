cmake_minimum_required(VERSION 3.20)
project(mattkerrigan)

set(CMAKE_CXX_STANDARD 14)

add_executable(mattkerrigan MST.cpp MinPriorityQueue.h Edge.h)
