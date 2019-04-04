cmake_minimum_required(VERSION 3.13)
project(ex00)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(ex00
        main.cpp
        Peon.cpp
        Peon.hpp
        Sorcerer.cpp
        Sorcerer.hpp
        Victim.cpp
        Victim.hpp)
