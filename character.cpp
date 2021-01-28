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


}

/*********************************************************************************
addItem adds an item class to the character inventory
*************************************************************************************/
void character::addItem(item *inputItem)
{

    this->inventory.push_back(inputItem);

}

/*********************************************************************************
searchItem searches for a specific string input if the item exists. Returns a bool
*************************************************************************************/
bool character::searchItem(string inputItemName){

    bool itemExist = false;

    for (int i = 0; i < inventory.size(); i++)
    {
        if (inputItemName == inventory[i]->getName())
        {
            itemExist = true;
        }
    }
    return itemExist;
}

/*********************************************************************************
itemIndex - returns the index if an item was found in the player's inventory
*************************************************************************************/
int character::itemIndex(string inputItemName){

    int itemIndex = -1;

    for (int i = 0; i < inventory.size(); i++)
    {
        if (inputItemName == inventory[i]->getName())
        {
            itemIndex = i;
        }
    }
    return itemIndex;


}

/*********************************************************************************
displayItemDescription - displays the item description at the player's inventory index
*************************************************************************************/
void character::displayItemDescription(int index) {

    // Index cannot be greater than the inventory size or negative
    if(index<inventory.size() && (index > -1)){
        cout << inventory[index]->getDescription() << endl;
    }

}

/*********************************************************************************
removeItem removes a specific item from the character inventory. Returns that item
 pointer to be added somewhere else
*************************************************************************************/
item* character::removeItem(string inputItemName){

    item* tempItemPointer;

    for (int i = 0; i < inventory.size(); i++)
    {
        if (inputItemName == inventory[i]->getName())
        {

            tempItemPointer = inventory[i];
            inventory.erase(inventory.begin() + i);
            break;

        }

    }
    return tempItemPointer;

};

/*********************************************************************************
listInventory outputs the entire inventory that the character has
*************************************************************************************/
void character::listInventory() {

    // If inventory is not empty
    if(inventory.size() != 0){
        cout << "You have the following in your inventory: ";
        for(int i = 0; i < inventory.size(); i++){
            if(i<inventory.size()-1){
                cout << inventory[i]->getName() << ", ";
            }
            else{
                cout << inventory[i]->getName() << ".";
            }
        }
    }
    else{
        cout << "You have nothing in your inventory.";
    }
    cout << endl;

}

/********************************************************************************
destructor
**********************************************************************************/
character::~character()
{


}
