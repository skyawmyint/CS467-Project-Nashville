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
#include <fstream>

#include "Item.hpp"
#include "utilityFunctions.hpp"

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
    bool pumpPrimerFull = false;
    bool electricalPanelRepaired = false;
    bool navigationUploaded = false;
    bool unlockCaptain = false;

public:

    character();  // Default
    character(bool loadInput); // Constructor for load game
    void addItem(item* inputItem);
    bool searchItem(string inputItemName);
    int itemIndex(string inputItemName);
    void displayItemDescription(int index);
    item* removeItem(string inputItemName);
    void listInventory();
    item* returnItem(int itemIndexInput);
    void setPrimer(bool pumpPrimer);
    bool getPrimer();
    void setPanel(bool panelRepaired);
    bool getPanel();
    void setNavigation();
    bool getNavigation();
    void setCaptainDoor();
    bool getCaptainDoor();
    void saveGame();
    ~character(); // Destructor

};

#endif //CHARACTER_H
