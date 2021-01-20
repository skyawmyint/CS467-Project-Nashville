/*****************************************************************
Name: Clayton Hewitson
Assignment: Final Project
Date: 11/27/2017
Description: This is the class specification header file that
contains the class declaration for the class PLAYER.
It declares all our member variables and member function prototypes.
******************************************************************/




#ifndef PLAYER_HPP                         //include guard to prevent duplicate header file inclusion
#define PLAYER_HPP                         //defines the header file as PLAYER_HPP

#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <memory>

#include "Item.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::shared_ptr;
using std::make_shared;
using std::string;

class Player
{
private:
	string name;                               //name of player
	vector<shared_ptr<Item>>inventory;                 //items in the player inventory, max of six
	int torchlight;                             //amount of time left before the torchlight runs out, killing player
	int maxTorch;                               //maximum torchlight allowed

public:
	Player();                               //default constructor, never called
	Player(string nameIn);                    //constructor, takes player name
	void setName(string nameIn);                          //sets the name of the Player
	string getName() const;                   //returns name of the Player
	void setTorch(int torchIn);                          //sets the number of remaining steps for the Player
	int getTorch() const;                   //returns number of remaining steps for the player
	void setMaxTorch(int torchIn);                          //sets the number of max steps for the Player
	int getMaxTorch() const;                   //returns number of max steps for the player
	void decrementTorch();                          //decrements torch for each action player takes
	void addTorch(int torchIn);                         //adds additional torchlight to the player's torch
	void addItem(string nameIn, string descriptionIn);           //adds item to player inventory
	bool checkInventory();                       //bool to check if player's inventory is maxed
	void removeItem(int choiceIn);                                         //remove item from Player inventory
	int searchItems(string stringIn);                      //search backpack for specific item
	void emptyItems();                                   //removes all items from backpack
	void useItems() const;                                 //display all items in player Inventory for use
	~Player();                                         //destructor
};
#endif       

