/*****************************************************************
Name: Clayton Hewitson
Assignment: Final Project
Date: 11/24/2017
Description: This is the class specification header file that
contains the class declaration for the class SPACE.
It declares all our member variables and member function prototypes.
******************************************************************/




#ifndef SPACE_HPP                         //include guard to prevent duplicate header file inclusion
#define SPACE_HPP                         //defines the header file as SPACE_HPP

#include <stddef.h>
#include <iostream>
#include <string>
#include <vector>
#include <memory>

#include "Item.hpp"
#include "Player.hpp"
#include "menuAdventure.hpp"
#include "utilityAdventure.hpp"


using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::shared_ptr;
using std::make_shared;

class Space
{
private:
	Space* right;                                  //pointer to right space object
	Space* left;                                  //pointer to left space object
	Space* top;                                    //pointer to top space object
	Space* bottom;                                 //pointer to bottom space object
	string name;                                  //name of space
	string description;                           //description of the room
	vector<shared_ptr<Item>>items;                 //items in the space

public:
	Space();                                            //constructor
	void setRight(Space* rightSpace);                    //sets pointer to right Space object                       
	Space* getRight() const;                          //returns pointer to right Space object
	void setLeft(Space* leftSpace);                   //sets pointer to left Space object                       
	Space* getLeft() const;                          //returns pointer to left Space object
	void setTop(Space* topSpace);                    //sets pointer to top Space object                       
	Space* getTop() const;                            //returns pointer to top Space object
	void setBottom(Space* bottomSpace);                 //sets pointer to bottom Space object                       
	Space* getBottom() const;                         //returns pointer to bottom Space object
	void setName(string NameIn);                      //sets name of the space
	string getName() const;                           //returns name of space
	void setDescription(string scriptIn);                //sets the description of the space;
	string getDescription() const;                           //returns description of space
	shared_ptr<Item> getItem(int numIn);                           //returns various items in the space, accesses vector items
	void addItem(string nameIn, string descriptionIn);                  //add item to Space
	virtual void torchCount(int torchIn, int maxTorchIn);                        //prints messages based on player torch left
	virtual bool getStatus();                            //returns bool based on if room has been permanently altered
	virtual bool getTime();                              //returns bool based on room alterations
	virtual bool getFuture();                                         //returns bool based on if door at end can be opened
	virtual bool getOldWoman();                                        //returns bool if old woman is dead
	int examine();                                      //allows player to examine items in the room
	virtual void decision(int choiceIn, bool trigger, Player* playIn) = 0;         //method for player interaction in room
	virtual ~Space();                                           //destructor
	
};
#endif       

