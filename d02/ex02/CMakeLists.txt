cmake_minimum_required(VERSION 3.13)
project(ex02)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(ex02
        Fixed.cpp
        Fixed.hpp
        main.cpp)
