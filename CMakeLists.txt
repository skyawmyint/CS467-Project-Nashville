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
        corridor2.cpp
        corridor2.hpp
        corridor3.cpp
        corridor3.hpp
        escapepodroom.cpp
        escapepodroom.hpp
        mainframeroom.cpp
        mainframeroom.hpp
        communications.cpp
        communications.hpp
        electrical.cpp
        electrical.hpp
        navigation.cpp
        navigation.hpp
        cafeteria.cpp
        cafeteria.hpp
        reactor.cpp
        reactor.hpp
        enginebay.cpp
        enginebay.hpp
        storage.cpp
        storage.hpp
        lifesupporto2.cpp
        lifesupporto2.hpp
        captainslodge.cpp
        captainslodge.hpp
        )
