cmake_minimum_required(VERSION 3.20)
project(natpbean C)

set(CMAKE_C_STANDARD 99)

add_executable(natpbean main.c src/search.c src/extensions.c)
