cmake_minimum_required(VERSION 3.20)
project(json_Project_2)

set(CMAKE_CXX_STANDARD 14)

add_executable(json_Project_2 Subscriber.cpp Subscriber.h Episode.cpp Episode.h Podcast.cpp Podcast.h defs.h PodArray.cc Podcast.h Network.cpp Network.h TestControl.cc TestView.cc Client.cpp Client.h main.cc)
