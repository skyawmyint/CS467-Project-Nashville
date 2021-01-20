/*****************************************************************
Name: Clayton Hewitson
Assignment: Final Project
Date: 11/27/2017
Description: This is the class specification header file that
contains the class declaration for the class ITEM.
It declares all our member variables and member function prototypes.
******************************************************************/




#ifndef ITEM_HPP                         //include guard to prevent duplicate header file inclusion
#define ITEM_HPP                         //defines the header file as ITEM_HPP


#include <string>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

class Item
{
private:
	string name;                               //name of item
	string description;                        //description of item
	bool triggered;                                   //bool for item use

public:
	Item();                               //default constructor, never called
	Item(string nameIn, string descriptionIn);          //constructor for new items
	void setName(string nameIn);                          //sets the name of the Item
	string getName() const;                             //returns name of the Item
	void setDescription(string descriptionIn);                          //sets the description of the item
	string getDescription() const;                   //returns the description of the item
	void setTrigger(bool triggerIn);                          //sets the trigger of the item for usage
	bool getTrigger() const;                                //returns the trigger of the item for usage
	~Item();                                         //destructor
};
#endif       