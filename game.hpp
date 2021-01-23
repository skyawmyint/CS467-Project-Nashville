/*****************************************************************
Project Nashville
CS467 - Online Capstone Project
Description: This is the class specification header file that
contains the class declaration for the class game.
It declares all our member variables and member function prototypes.
******************************************************************/

#ifndef CS467_PROJECT_NASHVILLE2_GAME_H
#define CS467_PROJECT_NASHVILLE2_GAME_H

#include <iostream>
#include <vector>
#include <cstdlib>
#include <memory>
#include <string>

#include "character.hpp"
#include "Item.hpp"
#include "room.hpp"
#include "medbay.hpp"
#include "corridor1.hpp"

class game {

private:

    // Character
    character* player;

    // Items in the game
    item* keyItem;
    item* badgeItem;
    item* scalpelItem;
    item* workGlovesItem;
    item* navCommUpdateModuleItem;
    item* emptyContainerItem;
    item* wrenchItem;
    item* flareGunItem;

    // Rooms in the game
    room* medbayRoom;
    room* corridor1Room;

    // Current room
    room* currentPosition;


public:

    game(); // constructor
    // game(txtInput) EVENTUALLY do a constructor with text file
    void currentRoomDescription();
    void moveRooms(string roomName);

    ~game(); // deconstructor


};


#endif //CS467_PROJECT_NASHVILLE2_GAME_H
