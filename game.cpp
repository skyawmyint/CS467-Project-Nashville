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
    keyItem->setDescription("This KEY can be used to escape in the ESCAPE POD.");

    badgeItem = new item();
    badgeItem->setName("BADGE");
    badgeItem->setDescription("This BADGE allows access to open the MAINFRAME ROOM.");

    scalpelItem = new item();
    scalpelItem->setName("SCALPEL");
    scalpelItem->setDescription("This is a handy SCALPEL that can be used in multiple objects to cut and pry.");

    workGlovesItem = new item();
    workGlovesItem->setName("WORK GLOVES");
    workGlovesItem->setDescription("These WORK GLOVES can be handy in working with dangerous electrical objects.");

    navCommUpdateModuleItem = new item();
    navCommUpdateModuleItem->setName("NAV COMM UPDATE MODULE");
    navCommUpdateModuleItem->setDescription("The NAV COMM UPDATE MODULE can be used on a computer to allow a safe route on an escape pod.");

    emptyContainerItem = new item();
    emptyContainerItem->setName("EMPTY CONTAINER");
    emptyContainerItem->setDescription("This EMPTY CONTAINER can be filled with something.");

    wrenchItem = new item();
    wrenchItem->setName("WRENCH");
    wrenchItem->setDescription("This WRENCH can be used to turn valves or bolts.");

    flareGunItem = new item();
    flareGunItem->setName("FLARE GUN");
    flareGunItem->setDescription("This FLARE GUN can probably be used to ignite something with O2.");

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

    // Add starting items to the rooms
    storageRoom->addItemStarting(keyItem);
    // captainsLodgeRoom->addItemStarting(badgeItem);
    medbayRoom->addItemStarting(scalpelItem);
    engineBayRoom->addItemStarting(workGlovesItem);
    reactorRoom->addItemStarting(navCommUpdateModuleItem);
    lifeSupportO2Room->addItemStarting(emptyContainerItem);
    corridor2Room->addItemStarting(wrenchItem);
    // medbayRoom->addItemStarting(flareGunItem);



    // Add all the rooms to the roomsVector



    // Set up a new character
    character* player = new character();

    // CHECKING IF ITEMS WORKING - TEMP!!!!
    this->player->addItem(badgeItem);
    this->player->addItem(flareGunItem);
    // TEMP CODE!!!!!!!!!!!!!!!!!!!!!!!!!

    // Set up the current position on the game board
    this->currentPosition = medbayRoom;

    // Set up flags
    this->gameStillRunning = true;

    // First game room introduction should be here
    cout << endl;
    cout << "You jolt awake. Cold steel presses against your back and a bright lamp glares overhead. " << endl <<
            "You hear a loud beeping sound accompanied by a voice counting down numbers. Something bad is going on!" << endl <<
            "You sit up. You appear to be lying on some kind of surgical table. You get up and look around the room... " << endl <<
            "there is no one in sight. The last thing you remember is working on a cure for a deadly virus affecting Earth " << endl <<
            "on the Project Nashville space station." << endl;
    cout << endl;
    cout << "As you look around, you see that you are surrounded by white walls that are very bright and clean." << endl <<
            "The walls feel empty with very little in the room. The only things in the room that you see are the surgical " << endl <<
            "table that you woke up on with a SCALPEL on it, a metal table in the corner of the room, and a door leading to a " << endl <<
            "dark hall. You also see a COMPUTER on top of the metal table that looks functional. Gathering all this information, " << endl <<
            "you remember that you must be in the MEDBAY and the door must lead to CORRIDOR 1. The countdown must mean that " << endl <<
            "something bad is happening to the station and you must escape by any means possible!" << endl;

}

/********************************************************************************
currentRoomDescription - outputs the description of the current room.
**********************************************************************************/
void game::currentRoomDescription(){

    // Output the room name and long description
    cout << "\nYou enter the room " << currentPosition->getName() << "..." << endl;

    // Long description
    if(currentPosition->isRepeatVisit()==false){
        cout << currentPosition->getLongDescription();
        currentPosition->listItemDropped();
        cout << endl;
        currentPosition->toggleEnteredRoom();
    }
    // Short description
    else{
        cout << currentPosition->getShortDescription();
        currentPosition->listItemDropped();
        cout << endl;
    }
}

/********************************************************************************
lookDescription - outputs the long description of the current room.
**********************************************************************************/
void game::lookDescription() {

    cout << "\nYou look around the room..." << endl;
    cout << currentPosition->getLongDescription() << endl;

}

/********************************************************************************
dropItem - drops an item in the player's inventory to the room
**********************************************************************************/
void game::dropItem(string itemName) {

    if(player->searchItem(itemName) == true){
        cout << "You drop the " << itemName << " on the floor of " << currentPosition->getName() << "." << endl;
        currentPosition->addItemDropped(player->removeItem(itemName));
    }
    else{
        cout << "Invalid command." << endl;
    }
}

/********************************************************************************
takeItem - takes an item and puts it into player's inventory from the room
**********************************************************************************/
void game::takeItem(string itemName) {

    if(currentPosition->searchItemDropped(itemName) == true){
        cout << "You take the " << itemName << " from the floor of " << currentPosition->getName() << "." << endl;
        player->addItem(currentPosition->removeItemDropped(itemName));
    }
    else{
        cout << "Invalid command." << endl;
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
    else if(currentPosition->getName() == roomNameInput){
        cout << "\nYou are already in that room." << endl;
    }
    else{
        cout << "\nYou look around to go there, but could not find the way to." << endl;
    }
}

/********************************************************************************
displayInventory - shows a list of all items that the character has
**********************************************************************************/
void game::displayInventory() {

    player->listInventory();

}




/********************************************************************************
destructor
**********************************************************************************/

game::~game()
{




}
