/*****************************************************************
Project Nashville
CS467 - Online Capstone Project
Description: This is the class specification header file that
contains the class declaration for the class storage. This is a child
 class of room.
It declares all our member variables and member function prototypes.
******************************************************************/

#ifndef CS467_PROJECT_NASHVILLE2_STORAGE_H
#define CS467_PROJECT_NASHVILLE2_STORAGE_H

#include "room.hpp"

using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::shared_ptr;
using std::make_shared;

class storage : public room {


private:
    bool keyTaken = false;


public:

    storage();

    // virtual void interactRoom();

    // ~storage();



};


#endif //CS467_PROJECT_NASHVILLE2_STORAGE_H
