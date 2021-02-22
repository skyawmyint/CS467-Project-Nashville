/*****************************************************************
Project Nashville
CS467 - Online Capstone Project
Description: This is the class specification header file that
contains the class declaration for the class lifeSupportO2. This is a child
 class of room.
It declares all our member variables and member function prototypes.
******************************************************************/

#ifndef CS467_PROJECT_NASHVILLE2_LIFESUPPORTO2_H
#define CS467_PROJECT_NASHVILLE2_LIFESUPPORTO2_H

#include "room.hpp"

using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::shared_ptr;
using std::make_shared;

class lifeSupportO2 : public room {

private:

    // Vector of action+feature interactions
    std::unordered_map<std::string, int> featureInteraction;

    // Flags
    bool O2CanistersDestroyed = false;

public:

    lifeSupportO2();
    void lookAtFeature(string featureInputName);
    bool isTakeableFromStarting(string inputItemName);
    bool isO2CanistersDestroyed();
    void interactRoom(string inputString);
    void saveGame();
    ~lifeSupportO2();

};


#endif //CS467_PROJECT_NASHVILLE2_LIFESUPPORTO2_H
