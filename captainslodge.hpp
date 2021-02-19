/*****************************************************************
Project Nashville
CS467 - Online Capstone Project
Description: This is the class specification header file that
contains the class declaration for the class captainsLodge. This is a child
 class of room.
It declares all our member variables and member function prototypes.
******************************************************************/

#ifndef CS467_PROJECT_NASHVILLE2_CAPTAINSLODGE_H
#define CS467_PROJECT_NASHVILLE2_CAPTAINSLODGE_H

#include "room.hpp"

using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::shared_ptr;
using std::make_shared;

class captainsLodge : public room {

private:

    // Vector of action+feature interactions
    std::unordered_map<std::string, int> featureInteraction;

public:

    captainsLodge();
    void lookAtFeature(string featureInputName);
    void interactRoom(string inputString);
    ~captainsLodge();

};


#endif //CS467_PROJECT_NASHVILLE2_CAPTAINSLODGE_H
