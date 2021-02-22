/*****************************************************************
Project Nashville
CS467 - Online Capstone Project
Description: This is the class specification header file that
contains the class declaration for the class corridor3. This is a child
 class of room.
It declares all our member variables and member function prototypes.
******************************************************************/

#ifndef CS467_PROJECT_NASHVILLE2_CORRIDOR3_H
#define CS467_PROJECT_NASHVILLE2_CORRIDOR3_H

#include "room.hpp"

#include "game.hpp"

using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::shared_ptr;
using std::make_shared;

class corridor3 : public room {

private:

    // Vector of action+feature interactions
    std::unordered_map<std::string, int> featureInteraction;

    // Flags
    bool paintingDestroyed = false;
    class game* currentGame;

public:

    corridor3(class game* currentGame);
    void lookAtFeature(string featureInputName, int inputTime);
    void interactRoom(string inputString);
    void saveGame();
    ~corridor3();
};


#endif //CS467_PROJECT_NASHVILLE2_CORRIDOR3_H
