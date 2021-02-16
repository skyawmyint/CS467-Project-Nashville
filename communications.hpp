/*****************************************************************
Project Nashville
CS467 - Online Capstone Project
Description: This is the class specification header file that
contains the class declaration for the class communications. This is a child
 class of room.
It declares all our member variables and member function prototypes.
******************************************************************/

#ifndef CS467_PROJECT_NASHVILLE2_COMMUNICATIONS_H
#define CS467_PROJECT_NASHVILLE2_COMMUNICATIONS_H

#include "room.hpp"

using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::shared_ptr;
using std::make_shared;

class communications : public room {


private:
    bool astronautHailed = false;
    bool astronautCanBeHailed = true;
    bool hasPower = false;

public:

    communications();
    void lookAtFeature(string featureInputName);
    void flagCheck();
    // virtual void interactRoom();

    // ~communications();



};


#endif //CS467_PROJECT_NASHVILLE2_COMMUNICATIONS_H
