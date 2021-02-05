/*****************************************************************
Project Nashville
CS467 - Online Capstone Project
Description: This is the class specification header file that
contains the class declaration for the class cafeteria. This is a child
 class of room.
It declares all our member variables and member function prototypes.
******************************************************************/

#ifndef CS467_PROJECT_NASHVILLE2_CAFETERIA_H
#define CS467_PROJECT_NASHVILLE2_CAFETERIA_H

#include "room.hpp"

using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::shared_ptr;
using std::make_shared;

class cafeteria : public room {


private:




public:

    cafeteria();
    void lookAtFeature(string featureInputName);
    // virtual void interactRoom();

    // ~cafeteria();



};


#endif //CS467_PROJECT_NASHVILLE2_CAFETERIA_H
