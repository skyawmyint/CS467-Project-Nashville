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
    corridor1Room = new corridor1; // Corridors
    corridor2Room = new corridor2;
    corridor3Room = new corridor3;

    medbayRoom = new medbay; // West-side
    escapePodRoomRoom = new escapePodRoom;
    mainframeRoomRoom = new mainframeRoom;
    communicationsRoom = new communications;
    electricalRoom = new electrical;
    navigationRoom = new navigation;

    cafeteriaRoom = new cafeteria;
    reactorRoom = new reactor;
    engineBayRoom = new engineBay;
    storageRoom = new storage;
    lifeSupportO2Room = new lifeSupportO2;
    captainsLodgeRoom = new captainsLodge;

    // Connect all rooms together
    corridor1Room->setConnectedRooms(medbayRoom);
    corridor1Room->setConnectedRooms(escapePodRoomRoom);
    corridor1Room->setConnectedRooms(mainframeRoomRoom);
    corridor1Room->setConnectedRooms(communicationsRoom);
    corridor1Room->setConnectedRooms(electricalRoom);
    corridor1Room->setConnectedRooms(navigationRoom);
    corridor1Room->setConnectedRooms(corridor2Room);

    corridor2Room->setConnectedRooms(corridor1Room);
    corridor2Room->setConnectedRooms(corridor3Room);

    corridor3Room->setConnectedRooms(cafeteriaRoom);
    corridor3Room->setConnectedRooms(reactorRoom);
    corridor3Room->setConnectedRooms(engineBayRoom);
    corridor3Room->setConnectedRooms(lifeSupportO2Room);
    corridor3Room->setConnectedRooms(captainsLodgeRoom);
    corridor3Room->setConnectedRooms(corridor2Room);

    medbayRoom->setConnectedRooms(corridor1Room);
    escapePodRoomRoom->setConnectedRooms(corridor1Room);
    mainframeRoomRoom->setConnectedRooms(corridor1Room);
    communicationsRoom->setConnectedRooms(corridor1Room);
    electricalRoom->setConnectedRooms(corridor1Room);
    navigationRoom->setConnectedRooms(corridor1Room);

    cafeteriaRoom->setConnectedRooms(corridor3Room);
    reactorRoom->setConnectedRooms(corridor3Room);
    engineBayRoom->setConnectedRooms(corridor3Room);
    storageRoom->setConnectedRooms(lifeSupportO2Room);
    lifeSupportO2Room->setConnectedRooms(corridor3Room);
    lifeSupportO2Room->setConnectedRooms(storageRoom);
    captainsLodgeRoom->setConnectedRooms(corridor3Room);

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
        if(corridor1Room->getName() == roomNameInput){
            currentPosition = corridor1Room;
        }
        else if(corridor2Room->getName() == roomNameInput){
            currentPosition = corridor2Room;
        }
        else if(corridor3Room->getName() == roomNameInput){
            currentPosition = corridor3Room;
        }
        else if(medbayRoom->getName() == roomNameInput){
            currentPosition = medbayRoom;
        }
        else if(escapePodRoomRoom->getName() == roomNameInput){
            currentPosition = escapePodRoomRoom;
        }
        else if(mainframeRoomRoom->getName() == roomNameInput){
            currentPosition = mainframeRoomRoom;
        }
        else if(communicationsRoom->getName() == roomNameInput){
            currentPosition = communicationsRoom;
        }
        else if(electricalRoom->getName() == roomNameInput){
            currentPosition = electricalRoom;
        }
        else if(navigationRoom->getName() == roomNameInput){
            currentPosition = navigationRoom;
        }
        else if(cafeteriaRoom->getName() == roomNameInput){
            currentPosition = cafeteriaRoom;
        }
        else if(reactorRoom->getName() == roomNameInput){
            currentPosition = reactorRoom;
        }
        else if(engineBayRoom->getName() == roomNameInput){
            currentPosition = engineBayRoom;
        }
        else if(storageRoom->getName() == roomNameInput){
            currentPosition = storageRoom;
        }
        else if(lifeSupportO2Room->getName() == roomNameInput){
            currentPosition = lifeSupportO2Room;
        }
        else if(captainsLodgeRoom->getName() == roomNameInput){
            currentPosition = captainsLodgeRoom;
        }

        // Call the current room description
        currentRoomDescription();
    }
    else{
        cout << "You look around to go to " << roomNameInput << ", but could not find the way." << endl;
    }
}

/********************************************************************************
destructor
**********************************************************************************/

game::~game()
{




}
