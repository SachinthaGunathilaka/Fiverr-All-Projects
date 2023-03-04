cmake_minimum_required(VERSION 3.20)
project(elokingz C)

set(CMAKE_C_STANDARD 99)

add_executable(elokingz alphanim.c nim.c nim.h nimhelp.c)
