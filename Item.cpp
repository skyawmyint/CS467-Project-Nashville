/******************************************************************
Project Nashville
CS467 - Online Capstone Project
Description: This is the class implementation file for the class item.
******************************************************************/

#include "Item.hpp"

/********************************************************************************
default constructor, never called
**********************************************************************************/
item::item()
{

}

/********************************************************************************
constructor to take Item name, description, and usage code and sets them
**********************************************************************************/

item::item(string nameIn, string descriptionIn)
{
    setName(nameIn);
    setDescription(descriptionIn);
    // setTrigger(false);
}

/*********************************************************************************
setName sets the name of the item it takes a string as a parameter and returns nothing
*************************************************************************************/

void item::setName(string nameIn)
{
    name = nameIn;
}

/*********************************************************************************
getName returns the name of the Item, it takes nothing as a parameter and returns
a string.
*************************************************************************************/

string item::getName() const
{
    return name;
}

/*********************************************************************************
setDescription sets the description of the Player, it takes a string as a parameter and returns nothing
*************************************************************************************/

void item::setDescription(string descriptionIn)
{
    description = descriptionIn;
}

/*********************************************************************************
getDescription returns the description of an Item, it takes nothing as a parameter and returns a string.
*************************************************************************************/

string item::getDescription() const
{
    return description;
}

/*********************************************************************************
setTrigger sets the bool triggered of the Item. it takes a bool as a parameter and returns nothing.
This code is used ingame to determine correct or incorrect item interactions
*************************************************************************************/

/* void item::setTrigger(bool triggerIn)
{
    triggered = triggerIn;
}
 */

/*********************************************************************************
getTrigger gets the bool trigeered of the Item. it takes a nothing as a parameter and returns a bool.
This code is used ingame to determine correct or incorrect item interactions
*************************************************************************************/
/*
bool item::getTrigger() const
{
    return triggered;
}
 */

/********************************************************************************
Destructor
**********************************************************************************/

item::~item()
{


}
