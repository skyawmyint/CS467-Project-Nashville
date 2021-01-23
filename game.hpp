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
#include "item.hpp"
#include "room.hpp"

#include "corridor1.hpp"
#include "corridor2.hpp"
#include "corridor3.hpp"

#include "medbay.hpp"
#include "escapepodroom.hpp"
#include "mainframeroom.hpp"
#include "communications.hpp"
#include "electrical.hpp"
#include "navigation.hpp"

#include "cafeteria.hpp"
#include "reactor.hpp"
#include "enginebay.hpp"
#include "storage.hpp"
#include "lifesupporto2.hpp"
#include "captainslodge.hpp"

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
    room* corridor1Room; // Corridors
    room* corridor2Room;
    room* corridor3Room;

    room* medbayRoom; // West-side
    room* escapePodRoomRoom;
    room* mainframeRoomRoom;
    room* communicationsRoom;
    room* electricalRoom;
    room* navigationRoom;

    room* cafeteriaRoom; // East-side
    room* reactorRoom;
    room* engineBayRoom;
    room* storageRoom;
    room* lifeSupportO2Room;
    room* captainsLodgeRoom;

    // Current room
    room* currentPosition;

    // Add some flags here for unlocking doors or powering up electrical, etc



public:

    game(); // constructor
    // game(txtInput) EVENTUALLY do a constructor with text file
    void currentRoomDescription();
    void moveRooms(string roomName);

    ~game(); // destructor


};


#endif //CS467_PROJECT_NASHVILLE2_GAME_H
