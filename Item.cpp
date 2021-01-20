/******************************************************************
Name: Clayton Hewitson
Assignment: Final Project
Date: 11/27/2017
Description: This is the class implementation file for the class ITEM.
It has three variables, all private, which contain information about any
given item object. All these variables contain various public member functions
for their manipulation outlined in further detail below.
******************************************************************/

#include "Item.hpp"                           //header file for Item


/********************************************************************************
default constructor, never called
**********************************************************************************/

Item::Item()
{


}

/********************************************************************************
constructor to take Item name, description, and usage code and sets them
**********************************************************************************/

Item::Item(string nameIn, string descriptionIn)
{
	setName(nameIn);
	setDescription(descriptionIn);
	setTrigger(false);
}

/*********************************************************************************
setName sets the name of the item it takes a string as a parameter and returns nothing
*************************************************************************************/

void Item::setName(string nameIn)
{
	name = nameIn;
}

/*********************************************************************************
getName returns the name of the Item, it takes nothing as a parameter and returns
a string.
*************************************************************************************/

string Item::getName() const
{
	return name;
}

/*********************************************************************************
setDescription sets the description of the Player, it takes a string as a parameter and returns nothing
*************************************************************************************/

void Item::setDescription(string descriptionIn)
{
	description = descriptionIn;
}

/*********************************************************************************
getDescription returns the description of an Item, it takes nothing as a parameter and returns a string.
*************************************************************************************/

string Item::getDescription() const
{
	return description;
}

/*********************************************************************************
setTrigger sets the bool triggered of the Item. it takes a bool as a parameter and returns nothing.
This code is used ingame to determine correct or incorrect item interactions
*************************************************************************************/

void Item::setTrigger(bool triggerIn)
{
	triggered = triggerIn;
}

/*********************************************************************************
getTrigger gets the bool trigeered of the Item. it takes a nothing as a parameter and returns a bool.
This code is used ingame to determine correct or incorrect item interactions
*************************************************************************************/

bool Item::getTrigger() const
{
	return triggered;
}

/********************************************************************************
destructor
**********************************************************************************/

Item::~Item()
{


}
