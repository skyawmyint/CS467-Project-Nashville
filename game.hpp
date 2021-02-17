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
#include <chrono>

#include "character.hpp"
#include "Item.hpp"
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
    escapePodRoom* escapePodRoomRoom;
    mainframeRoom* mainframeRoomRoom;
    room* communicationsRoom;
    room* electricalRoom;
    room* navigationRoom;

    room* cafeteriaRoom; // East-side
    room* reactorRoom;
    room* engineBayRoom;
    room* storageRoom;
    room* lifeSupportO2Room;
    room* captainsLodgeRoom;

    // Vector of rooms in the game
    // vector<room*> roomVector;

    // Current room
    room* currentPosition;

    // Add some flags here for unlocking doors or powering up electrical, etc
    bool mapSaved; // = false if map hasn't been saved. = true when map has been saved.
    int total_seconds; // TEMPORARY til we figure out countdown.
    int time_left; // TEMPORARY til we figure out countdown.
    std::chrono::high_resolution_clock::time_point start_time;
    bool gameTimerDisabled;
    bool escapeStation = false;
    bool electricalRoomDoorFixed = false;

public:

    game(); // constructor
    // game(txtInput) EVENTUALLY do a constructor with text file
    void currentRoomDescription();
    void lookDescription();
    void dropItem(string itemName);
    void takeItem(string itemName);
    bool hasItem(string itemName);
    void displayInventory();
    void moveRooms(string roomName);
    void lookAtFeatureCall(vector<string>input, int actionSize);
    void interactFeatureCall(string input);
    int getCurrentRoomId();
    bool isMapMade();
    bool timeRanOut();
    void printTime();
    void setTime(int seconds);
    void disableGameTimer();
    void setEscape();
    bool getEscape();

    // int isGameRunning();

    ~game(); // destructor

};
#endif //CS467_PROJECT_NASHVILLE2_GAME_H
