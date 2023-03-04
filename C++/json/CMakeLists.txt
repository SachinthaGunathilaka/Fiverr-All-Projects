cmake_minimum_required(VERSION 3.20)
project(json)

set(CMAKE_CXX_STANDARD 14)

add_executable(json Date.cc Library.cc main.cc Reservation.cc Room.cc Student.cc)