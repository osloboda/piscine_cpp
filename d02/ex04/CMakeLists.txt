cmake_minimum_required(VERSION 3.13)
project(ex04)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(ex04
        Fixed.cpp
        Fixed.hpp
        main.cpp eval_expr.h eval_expr.cpp)
