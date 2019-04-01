cmake_minimum_required(VERSION 3.13)
project(rush00)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(includes)
include_directories(srcs)

add_executable(rush00
        srcs/main.cpp
        includes/Rocket.hpp
        includes/Enemy.hpp
        srcs/Rocket.cpp
        srcs/Enemy.cpp includes/galaxy.hpp)
set(CURSES_NEED_NCURSES TRUE)
find_package(Curses REQUIRED)
if (CURSES_FOUND AND CURSES_HAVE_NCURSES_H)
    include_directories(${CURSES_INCLUDE_DIR})
    target_link_libraries (rush00 ${CURSES_LIBRARIES})
endif()