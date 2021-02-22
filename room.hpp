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
#include <unordered_map>
#include <fstream>

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

    // Room ID to keep track of map
    int room_id;

    // Point to the player in the room
    character* playerPointer;

    // Initialize setup of room with descriptions
    string roomName;
    string longDescription;
    string shortDescription;
    vector<room*> connectedRooms;

    // Tracks items in the room
    vector<item*> startingItems;
    vector<item*> droppedItems;

    // Features of the rooms
    vector<string>feature;
    vector<string>featureDescription;

    bool repeatVisit = false; // false if it is first visit. true for any other visit

public:

    room(); // Default constructor
    room(int id); // Constructor with just the room ID

    // Functions dealing with the character
    void setCharacter(character* inputCharacter);
    character* getCharacter();

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
    void addFeature(string inputName, string inputDescription);
    int searchFeature(string inputName);
    void displayFeatureDescription(int indexInput);
    virtual void lookAtFeature(string inputFeature);
    virtual void lookAtFeature(string inputFeature, int inputTime); // For look at TIME in corridor 3

    // Functions to deal with interacting with Room feature
    virtual void interactRoom(string inputString);
    virtual int interactRoom(string inputString, bool inputMap);

    // Virtual function to deal with save/load
    virtual void saveGame();
    void saveInputFile(std::ofstream &inputFile);

    // Misc Virtual Functions
    virtual bool isO2CanistersDestroyed();

    // Retrieve room ID
    int getRoomId();
    // Destructor
    ~room();

};

#endif //CS467_PROJECT_NASHVILLE2_ROOM_H
