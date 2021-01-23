/******************************************************************
Project Nashville
CS467 - Online Capstone Project
Description: This is the class implementation file for the class game.
******************************************************************/

#include "game.hpp"

/********************************************************************************
default constructor
**********************************************************************************/
game::game(){

    // Set up the items in the game
    keyItem = new item();
    keyItem->setName("KEY");
    keyItem->setDescription("KEY DESCRIPTION HERE");

    badgeItem = new item();
    badgeItem->setName("BADGE");
    badgeItem->setDescription("BADGE DESCRIPTION HERE");

    scalpelItem = new item();
    scalpelItem->setName("SCALPEL");
    scalpelItem->setDescription("SCALPEL DESCRIPTION HERE");

    workGlovesItem = new item();
    workGlovesItem->setName("WORK GLOVES");
    workGlovesItem->setDescription("WORK GLOVES DESCRIPTION HERE");

    navCommUpdateModuleItem = new item();
    navCommUpdateModuleItem->setName("NAV COMM UPDATE MODULE");
    navCommUpdateModuleItem->setDescription("NAV COMM UPDATE MODULE DESCRIPTION HERE");

    emptyContainerItem = new item();
    emptyContainerItem->setName("EMPTY CONTAINER");
    emptyContainerItem->setDescription("EMPTY CONTAINER DESCRIPTION HERE");

    wrenchItem = new item();
    wrenchItem->setName("WRENCH");
    wrenchItem->setDescription("WRENCH DESCRIPTION HERE");

    flareGunItem = new item();
    flareGunItem->setName("FLARE GUN");
    flareGunItem->setDescription("FLARE GUN DESCRIPTION HERE");

    // Setup Rooms in the game
    medbayRoom = new medbay;
    //corridor1Room = new corridor1;

    // Connect all rooms together
   // medbayRoom->setConnectedRooms(corridor1Room);
    //corridor1Room->setConnectedRooms(medbayRoom);

    // Set up a new character
    character* player = new character();

    // Set up the current position on the game board
    currentPosition = medbayRoom;

}

/********************************************************************************
currentRoomLongDescription - outputs the long description of the current room.
**********************************************************************************/
void game::currentRoomDescription(){

    // Output the room name and long description
    cout << "Current Room: " << currentPosition->getName() << endl;

    // Long description
    if(currentPosition->isRepeatVisit()==false){
        cout << "Room Description: " << currentPosition->getLongDescription() << endl;
        currentPosition->toggleEnteredRoom();
    }
    // Short description
    else{
        cout << "Room Description: " << currentPosition->getShortDescription() << endl;
    }
}

/********************************************************************************
moveRooms - changes the current room to the user input Room string name
**********************************************************************************/
void game::moveRooms(string roomNameInput){

    // Check if this is a connected room
    if(currentPosition->isConnectedRoom(roomNameInput) == true){
        // Go through all our rooms and see if its the same room name
        if(medbayRoom->getName() == roomNameInput){
            currentPosition = medbayRoom;
        }
        else if(corridor1Room->getName() == roomNameInput){
            currentPosition = corridor1Room;
        }
        // Call the current room description
        currentRoomDescription();
    }
    else{
        cout << "This is not a connected room!" << endl;
    }
}

/********************************************************************************
destructor
**********************************************************************************/

game::~game()
{




}
