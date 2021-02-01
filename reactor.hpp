/*****************************************************************
Project Nashville
CS467 - Online Capstone Project
Description: This is the class specification header file that
contains the class declaration for the class reactor. This is a child
 class of room.
It declares all our member variables and member function prototypes.
******************************************************************/

#ifndef CS467_PROJECT_NASHVILLE2_REACTOR_H
#define CS467_PROJECT_NASHVILLE2_REACTOR_H

#include "room.hpp"

using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::shared_ptr;
using std::make_shared;

class reactor : public room {


private:

    // Vector of action+feature interactions
    std::unordered_map<std::string, int> featureInteraction;

    // Flags for the room
    bool noisyValveOpen = true;
    bool navCommTaken = false;

public:

    reactor();
    void lookAtFeature(string featureInputName);
    bool isTakeableFromStarting(string inputItemName);
    void interactRoom(string inputString);

    // ~reactor();



};


#endif //CS467_PROJECT_NASHVILLE2_REACTOR_H
