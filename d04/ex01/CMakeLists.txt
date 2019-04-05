cmake_minimum_required(VERSION 3.13)
project(ex01)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(ex01
        AWeapon.cpp
        AWeapon.hpp
        Character.cpp
        Character.hpp
        Enemy.cpp
        Enemy.hpp
        main.cpp
        PlasmaRifle.cpp
        PlasmaRifle.hpp
        PowerFist.cpp
        PowerFist.hpp
        RadScorpion.cpp
        RadScorpion.hpp
        SuperMutant.cpp
        SuperMutant.hpp)
