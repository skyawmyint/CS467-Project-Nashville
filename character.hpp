/*****************************************************************
Project Nashville
CS467 - Online Capstone Project
Description: This is the class specification header file that
contains the class declaration for the class character.
It declares all our member variables and member function prototypes.
******************************************************************/

#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <memory>

#include "room.hpp"
#include "Item.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::shared_ptr;
using std::make_shared;

class character {

private:

    vector<item*> inventory;

public:

    character();  // Constructor
    void addItem(item* inputItem);
    bool searchItem(string inputItemName);
    item* removeItem(string inputItemName);
    void listInventory();
    ~character(); // Destructor

};

#endif //CHARACTER_H
