/*****************************************************************
Project Nashville
CS467 - Online Capstone Project
Description: This is the class specification header file that
contains the class declaration for the class corridor1. This is a child
 class of room.
It declares all our member variables and member function prototypes.
******************************************************************/

#ifndef PROJECT_NASHVILLE2_CORRIDOR1_H
#define PROJECT_NASHVILLE2_CORRIDOR1_H

#include "room.hpp"

using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::shared_ptr;
using std::make_shared;

class corridor1 : public room {

private:

    // Vector of action+feature interactions
    std::unordered_map<std::string, int> featureInteraction;

    // Flags
    bool statueBroken = false;

public:

    corridor1();
    corridor1(bool inputLoad);
    void insertInteractions();
    void lookAtFeature(string featureInputName);
    int interactRoom(string inputString, bool inputMap);
    void saveGame();
    ~corridor1();

};

#endif //CS467_PROJECT_NASHVILLE2_CORRIDOR1_H
