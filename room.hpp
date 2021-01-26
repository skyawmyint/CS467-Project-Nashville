/*****************************************************************
Project Nashville
CS467 - Online Capstone Project
Description: This is the class specification header file that
contains the class declaration for the class room.
It declares all our member variables and member function prototypes.
******************************************************************/

#ifndef CS467_PROJECT_NASHVILLE2_ROOM_H
#define CS467_PROJECT_NASHVILLE2_ROOM_H

#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <memory>

#include "Item.hpp"
#include "character.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::shared_ptr;
using std::make_shared;

class room{

private:

    string roomName;
    string longDescription;
    string shortDescription;
    vector<room*> connectedRooms;
    vector<item*> startingItems;
    vector<item*> droppedItems;
    int numConnectedRooms;
    bool repeatVisit; // false if it is first visit. true for any other visit

public:

    room(); // Default constructor

    // Name and description functions
    void setName(string nameIn);
    string getName() const;
    void setLongDescription(string stringIn);
    string getLongDescription() const;
    void setShortDescription(string stringIn);
    string getShortDescription() const;

    // Connecting rooms and tracking visited rooms
    void setConnectedRooms(room* inputRoom);
    bool isConnectedRoom(string inputRoomName);
    bool isRepeatVisit();
    void toggleEnteredRoom();

    // Functions to deal with adding/removing items
    void addItemStarting(item* inputItem);
    bool searchItemStarting(string inputItemName);
    item* removeItemStarting(string inputItemName);
    void addItemDropped(item* inputItem);
    bool searchItemDropped(string inputItemName);
    item* removeItemDropped(string inputItemName);
    void listItemDropped();


    // virtual void lookAtFeature();
    // virtual void interactRoom();

    // Destructor
    ~room();

};

#endif //CS467_PROJECT_NASHVILLE2_ROOM_H
