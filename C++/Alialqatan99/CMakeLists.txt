cmake_minimum_required(VERSION 3.11)
project (hw4)

if (CMAKE_SOURCE_DIR MATCHES "[Hh][Ww]([0-9])$"
        AND NOT PROJECT_NAME MATCHES "${CMAKE_MATCH_1}$")
    message(FATAL_ERROR "Building ${PROJECT_NAME} in ${CMAKE_SOURCE_DIR}")
endif()

add_compile_options(-Wall)
add_compile_options(-Wextra -Wpedantic -std=c++17)

add_library(${PROJECT_NAME} Show.cc Schedule.cc)
add_executable(test test.cc)
target_link_libraries(test ${PROJECT_NAME})


add_custom_target(${PROJECT_NAME}.tar ALL COMMAND
    tar -cf ${PROJECT_NAME}.tar *.cc *.h CMakeLists.txt)
