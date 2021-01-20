/******************************************************************
Name: Clayton Hewitson
Assignment: Final Project
Date: 11/27/2017
Description: This is the class implementation file for the class PLAYER.
It has four variables, all private. One is a vector which holds pointers to Item
objects for the player's inventory, a pointer to a space object to track the player's
movement, a torchlight which serves as a timer for the Player to complete the game,
and string for the player name. All these variables contain various public member functions
for their manipulation outlined in further detail below.
******************************************************************/

#include "Player.hpp"                           //header file for Player


/********************************************************************************
default constructor, never called
**********************************************************************************/

Player::Player()
{


}

/********************************************************************************
constructor to take Player name and set various game parameters
**********************************************************************************/

Player::Player(string nameIn)
{
	setName(nameIn);
	setTorch(25);
	setMaxTorch(25);
}

/*********************************************************************************
setName sets the name of the Player, it takes a string as a parameter and returns nothing
*************************************************************************************/

void Player::setName(string nameIn)
{
	name = nameIn;
}

/*********************************************************************************
getName returns the name of the Player, it takes nothing as a parameter and returns
a string.
*************************************************************************************/

string Player::getName() const
{
	return name;
}

/*********************************************************************************
setTorch sets the torch of the Player, it takes a int as a parameter and returns nothing
*************************************************************************************/

void Player::setTorch(int torchIn)
{
	torchlight = torchIn;
}

/*********************************************************************************
getTorch returns the torch of the Player, it takes nothing as a parameter and returns an int.
*************************************************************************************/

int Player::getTorch() const
{
	return torchlight;
}

/*********************************************************************************
setMaxTorch sets the maxtorch of the Player, it takes a int as a parameter and returns nothing
*************************************************************************************/

void Player::setMaxTorch(int torchIn)
{
	maxTorch = torchIn;
}

/*********************************************************************************
getMaxTorch returns the maxtorch of the Player, it takes nothing as a parameter and returns an int.
*************************************************************************************/

int Player::getMaxTorch() const
{
	return maxTorch;
}

/*******************************************************************************
decrementTorch decrements the torchlight counter by one for every action the player takes,
serving as the game's timer. If the torchlight runs out the Player will be eaten by a grue
and the game shall end. Torchlight can be replenished via another function. It takes no
parameters and returns nothing.
*******************************************************************************/

void Player::decrementTorch()
{
	torchlight--;
}

/*******************************************************************************
addTorch replenishes some of the torchlight to the torch, giving the Player extra time
to explore. This can be done at a couple key rooms in the game. It takes no
parameters and returns nothing.
*******************************************************************************/

void Player::addTorch(int TorchIN)
{
	int tempTorch = getTorch();
	tempTorch += TorchIN;

	if (tempTorch > getMaxTorch())
	{
		setTorch(getMaxTorch());
	}
	else
	{
		setTorch(tempTorch);
	}
}

/*********************************************************************************************
addItem adds a new item shared pointer into the vector inventory, thus instantiating a
new item object off of the heap. It takes two parameters, all needed to construct a new item pointer.
It then uses emplace_back to place the pointer into the vector. It returns nothing.
*********************************************************************************************/

void Player::addItem(string nameIn, string descriptionIn)
{
	cout << nameIn << " added to backpack." << endl;
	cout << endl;
	inventory.emplace_back(make_shared<Item>(nameIn, descriptionIn));

}

/************************************************************************************
checkInventory checks to see if the max inventory has been reache in the Player's backpack.
It returns a bool, true if the player's inventory is full, false if it is not. It takes
no parameters. The player can carry a maximum of six items
***********************************************************************************/

bool Player::checkInventory()
{
	bool maxInventory = false;

	if (inventory.size() >= 3)
	{
		cout << endl;
		cout << "However, your backpack is completely full. You cannot carry anymore items." << endl;
		maxInventory = true;
	}

	return maxInventory;
}

/*********************************************************************************************
removeItem removes an item shared pointer from the vector inventory.
It takes one parameter, an int, to indicate a menu choicse of which item to be removed.
It then uses erase to destroy the pointer and item. It returns nothing.
*********************************************************************************************/

void Player::removeItem(int choiceIn)
{
	int eraseChoice = choiceIn;
	cout << inventory[eraseChoice]->getName() << " removed from backpack." << endl;
	inventory.erase(inventory.begin() + eraseChoice);
}

/*******************************************************************************************
searchItems searches the inventory for a specific item based on passed string. If found, the
subscript within the vecotr of the item is then returned, along delete to be called on it if necessary.
It takes a string as a parameter and returns an int
********************************************************************************************/

int Player::searchItems(string stringIn)
{
	for (int i = 0; i < inventory.size(); i++)
	{
		if (stringIn == inventory[i]->getName())
		{
			return i;
		}
	}

	return -1;
}

/*********************************************************************************************
emptyItems removes all pointers from the vector inventory, emptying it clean
It uses erase to destroy the pointers. It returns nothing.
*********************************************************************************************/

void Player::emptyItems()
{
	cout << "All items have vanished from the backpack. So...very...odd..." << endl;
	inventory.clear();
}

/*****************************************************************************************
useItems iterates through the vector inventory, printing out all information (name and description
of every item pointer currently in the vector. It takes no arguments and returns nothing.
******************************************************************************************/

void Player::useItems() const
{
	if (inventory.size() == 0)
	{
		cout << "Your backpack can carry a max of three items." << endl;
		cout << "There's nothing in your backpack." << endl;
	}
	else
	{
		cout << "Your backpack can carry a max of three items." << endl;
		cout << "Current items in your backpack:" << endl;
		cout << endl;
		for (std::size_t k = 0; k < inventory.size(); k++)
		{
			cout << k + 1 << ". Name: " << inventory[k]->getName() << endl;
			cout << "   Description: " << inventory[k]->getDescription() << endl;
			cout << endl;
		}
	}
}

/********************************************************************************
destructor
**********************************************************************************/

Player::~Player()
{


}