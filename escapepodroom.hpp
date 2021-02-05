/*****************************************************************
Project Nashville
CS467 - Online Capstone Project
Description: This is the class specification header file that
contains the class declaration for the class escapePodRoom. This is a child
 class of room.
It declares all our member variables and member function prototypes.
******************************************************************/

#ifndef CS467_PROJECT_NASHVILLE2_ESCAPEPODROOM_H
#define CS467_PROJECT_NASHVILLE2_ESCAPEPODROOM_H

#include "room.hpp"

using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::shared_ptr;
using std::make_shared;

class escapePodRoom : public room {

private:
    bool navCoordinatesUploaded = false;
    bool escapePodUnlocked = false;

public:

    escapePodRoom();
    void lookAtFeature(string featureInputName);
    // virtual void interactRoom();

    // ~escapePodRoom();



};


#endif //CS467_PROJECT_NASHVILLE2_ESCAPEPODROOM_H
