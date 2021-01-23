/*****************************************************************
Project Nashville
CS467 - Online Capstone Project
Description: This is the class specification header file that
contains the class declaration for the class item.
It declares all our member variables and member function prototypes.
******************************************************************/

#ifndef CS467_PROJECT_NASHVILLE2_ITEM_H
#define CS467_PROJECT_NASHVILLE2_ITEM_H

#include <string>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

class item {

private:
    string name; // name of item
    string description; // description of item
    bool triggered; // bool for item use

public:
    item(); // default constructor
    item(string nameIn, string descriptionIn); // constructor for new items
    void setName(string nameIn); // sets the name of the item
    string getName() const; // returns name of the Item
    void setDescription(string descriptionIn);  //sets the description of the item
    string getDescription() const; //returns the description of the item
    void setTrigger(bool triggerIn); //sets the trigger of the item for usage
    bool getTrigger() const; //returns the trigger of the item for usage
    ~item(); // deconstructor

};

#endif //CS467_PROJECT_NASHVILLE2_ITEM_H
