/*****************************************************************
Project Nashville
CS467 - Online Capstone Project
Description: This is the class specification header file that
contains the class declaration for the class medbay. This is a child
 class of room.
It declares all our member variables and member function prototypes.
******************************************************************/

#ifndef CS467_PROJECT_NASHVILLE2_MEDBAY_H
#define CS467_PROJECT_NASHVILLE2_MEDBAY_H

#include "room.hpp"

using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::shared_ptr;
using std::make_shared;

class medbay : public room {

private:

    bool scalpelTaken = false;
    bool medicalBoxOpened = false;

public:

    medbay();
    void lookAtFeature(string featureInputName);

    //virtual void interactRoom();



};


#endif //CS467_PROJECT_NASHVILLE2_MEDBAY_H
