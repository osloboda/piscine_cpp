cmake_minimum_required(VERSION 3.13)
project(ex09)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(ex09
        Logger.cpp
        Logger.hpp
        main.cpp)
