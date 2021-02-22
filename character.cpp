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

/*********************************************************************************
returnItem - returns the item object at a given index of the character's inventory
*************************************************************************************/
item* character::returnItem(int inputItemIndex){

    item* tempItemPointer = inventory[inputItemIndex];

    return tempItemPointer;

};

/*********************************************************************************
setPrimer - called when the player finishes priming the pump in the engine room, flips bool
*************************************************************************************/
void character::setPrimer(bool pumpPrimer){

    this->pumpPrimerFull = pumpPrimer;
};

/*********************************************************************************
getPrimer - returns the bool for the primer pump to check if power is restored in comms and nav
*************************************************************************************/
bool character::getPrimer(){

    return this->pumpPrimerFull;
};

/*********************************************************************************
setPanel - called when the player finishes repairing the panel in electrical, flips bool
*************************************************************************************/
void character::setPanel(bool panelRepaired){

    this->electricalPanelRepaired = panelRepaired;
};

/*********************************************************************************
getPanel - returns the bool for the electrical panel to check if power is restored in comms and nav
*************************************************************************************/
bool character::getPanel(){

    return this->electricalPanelRepaired;
};

/*********************************************************************************
setNavigation - called when the player uploaded the navigation, flips bool
*************************************************************************************/
void character::setNavigation(){

    this->navigationUploaded = true;
};

/*********************************************************************************
getNavigation - returns the bool for the navigation being uploaded
*************************************************************************************/
bool character::getNavigation(){

    return this->navigationUploaded;

};

/*********************************************************************************
setNavigation - called when the player uploaded the navigation, flips bool
*************************************************************************************/
void character::setCaptainDoor(){

    this->unlockCaptain = true;
};

/*********************************************************************************
getNavigation - returns the bool for the navigation being uploaded
*************************************************************************************/
bool character::getCaptainDoor(){

    return this->unlockCaptain;

};

/*********************************************************************************
saveGame - saves flags and inventory to a txt file
*************************************************************************************/
bool character::saveGame(){

    // Create and open a text file
    std::ofstream MyFile("savePlayer.txt");

    // Save the inventory
    // If inventory is not empty
    if(inventory.size() != 0){
        MyFile << "inventory\n";
        for(int i = 0; i < inventory.size(); i++){
            MyFile << inventory[i]->getName() << endl;
        }
    }
    else{
        MyFile << "empty inventory" << endl;
    }

    // Save the flags
    MyFile << "pumpPrimerFull\n" << this->pumpPrimerFull << endl;
    MyFile << "electricalPanelRepaired\n" << this->electricalPanelRepaired << endl;
    MyFile << "navigationUploaded\n" << this->navigationUploaded << endl;
    MyFile << "unlockCaptain\n" << this->unlockCaptain << endl;

    // Close the text file
    MyFile.close();

};

/********************************************************************************
destructor
**********************************************************************************/
character::~character()
{

    // Free all the inventory items
    item* tempItemPointer;
    int inventorySize = inventory.size();

    for (int i = 0; i < inventorySize; i++)
    {

        tempItemPointer = inventory[inventorySize-1-i];
        inventory.pop_back();
        free(tempItemPointer);

    }

}
