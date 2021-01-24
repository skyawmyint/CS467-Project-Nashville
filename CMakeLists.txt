cmake_minimum_required(VERSION 3.17)
project(CS467_Project_Nashville)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(CS467_Project_Nashville
        cafeteria.cpp
        cafeteria.hpp
        captainslodge.cpp
        captainslodge.hpp
        character.cpp
        character.hpp
        communications.cpp
        communications.hpp
        corridor1.cpp
        corridor1.hpp
        corridor2.cpp
        corridor2.hpp
        corridor3.cpp
        corridor3.hpp
        electrical.cpp
        electrical.hpp
        enginebay.cpp
        enginebay.hpp
        escapepodroom.cpp
        escapepodroom.hpp
        game.cpp
        game.hpp
        Item.cpp
        item.hpp
        lifesupporto2.cpp
        lifesupporto2.hpp
        main.cpp
        mainframeroom.cpp
        mainframeroom.hpp
        medbay.cpp
        medbay.hpp
        navigation.cpp
        navigation.hpp
        reactor.cpp
        reactor.hpp
        room.cpp
        room.hpp
        storage.cpp
        storage.hpp
        UI.cpp
        UI.hpp
        utilityFunctions.cpp
        utilityFunctions.hpp)
