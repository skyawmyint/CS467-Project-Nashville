/******************************************************************
Project Nashville
CS467 - Online Capstone Project
Description: This is the class implementation file for the class character.
******************************************************************/

#include "character.hpp"

/********************************************************************************
default constructor
**********************************************************************************/
character::character()
{

    inventorySize = 0;

}

/*********************************************************************************
addItem adds an item class to the character inventory
*************************************************************************************/
void character::addItem(item *inputItem)
{

    inventory.push_back(inputItem);
    inventorySize++;

}

/*********************************************************************************
searchItem searches for a specific string input if the item exists. Returns a bool
*************************************************************************************/
bool character::searchItem(string inputItemName){

    bool itemExist = false;

    for (int i = 0; i < inventorySize; i++)
    {
        if (inputItemName == inventory[i]->getName())
        {
            itemExist = true;
        }
    }
    return itemExist;
}

/*********************************************************************************
removeItem removes a specific item from the character inventory. Returns that item
 pointer to be added somewhere else
*************************************************************************************/
item* character::removeItem(string inputItemName){

    item* tempItemPointer;

    for (int i = 0; i < inventorySize; i++)
    {
        if (inputItemName == inventory[i]->getName())
        {

            tempItemPointer = inventory[i];
            inventory.erase(inventory.begin() + i);
            inventorySize--;
            break;

        }

    }
    return tempItemPointer;

};

/*********************************************************************************
listInventory outputs the entire inventory that the character has
*************************************************************************************/
void character::listInventory() {

    // ADJUST THIS LATER FOR HOW WE WANT IT TO BE SHOWN
    for(int i = 0; i < inventorySize; i++){

        cout << inventory[i]->getName() << " ";

    }
    cout << endl;

}

/********************************************************************************
destructor
**********************************************************************************/
character::~character()
{


}
