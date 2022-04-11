cmake_minimum_required(VERSION 3.21)
project(main)

set(CMAKE_CXX_STANDARD 17)

include_directories(libraries)

add_executable(main main.cpp)
