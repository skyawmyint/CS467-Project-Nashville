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

    // Initialize setup of room with descriptions
    string roomName;
    string longDescription;
    string shortDescription;
    vector<room*> connectedRooms;

    // Tracks items in the room
    vector<item*> startingItems;
    vector<item*> droppedItems;

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
    int itemIndexDrop(string inputItemName);
    void displayItemDropDescription(int index);
    // Take items from starting vector! - separated since some flags may be necessary to take
    virtual bool isTakeableFromStarting(string inputItemName);

    // Functions and variables to deal with features
    vector<string>feature;
    vector<string>featureDescription;
    vector<vector<string>>featureInteraction; //Each x index will iterate through different feature action. Each y will be synonyms for the action
    void addFeature(string inputName, string inputDescription);
    virtual void lookAtFeature(string inputFeature);

    // virtual void interactRoom();

    // Destructor
    ~room();

};

#endif //CS467_PROJECT_NASHVILLE2_ROOM_H
