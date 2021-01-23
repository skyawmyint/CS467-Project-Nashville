cmake_minimum_required(VERSION 3.17)
project(CS467_Project_Nashville2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(CS467_Project_Nashville2
        character.cpp
        character.hpp
        game.cpp
        game.hpp
        item.cpp
        item.hpp
        interface.cpp
        medbay.cpp
        medbay.hpp
        room.cpp
        room.hpp
        corridor1.cpp
        corridor1.hpp
        menuOptions.cpp
        menuOptions.hpp
        utilityFunctions.cpp
        utilityFunctions.hpp
        )
