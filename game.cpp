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
    this->keyItem = new item();
    this->keyItem->setName("KEY");
    this->keyItem->setDescription("This KEY can be used to escape in the ESCAPE POD.");

    this->badgeItem = new item();
    this->badgeItem->setName("BADGE");
    this->badgeItem->setDescription("This BADGE allows access to open the MAINFRAME ROOM.");

    this->scalpelItem = new item();
    this->scalpelItem->setName("SCALPEL");
    this->scalpelItem->setDescription("This is a handy SCALPEL that can be used in multiple objects to cut and pry.");

    this->workGlovesItem = new item();
    this->workGlovesItem->setName("WORK GLOVES");
    this->workGlovesItem->setDescription("These WORK GLOVES can be handy in working with dangerous electrical objects.");

    this->navCommUpdateModuleItem = new item();
    this->navCommUpdateModuleItem->setName("NAV COMM UPDATE MODULE");
    this->navCommUpdateModuleItem->setDescription("The NAV COMM UPDATE MODULE can be used on a computer to allow a safe route on an escape pod.");

    this->emptyContainerItem = new item();
    this->emptyContainerItem->setName("EMPTY CONTAINER");
    this->emptyContainerItem->setDescription("This EMPTY CONTAINER can be filled with something.");

    this->wrenchItem = new item();
    this->wrenchItem->setName("WRENCH");
    this->wrenchItem->setDescription("This WRENCH can be used to turn valves or bolts.");

    this->flareGunItem = new item();
    this->flareGunItem->setName("FLARE GUN");
    this->flareGunItem->setDescription("This FLARE GUN can probably be used to ignite something with O2.");

    // Setup Rooms in the game
    this->corridor1Room = new corridor1; // Corridors
    this->corridor2Room = new corridor2;
    this->corridor3Room = new corridor3;

    this->medbayRoom = new medbay; // West-side
    this->escapePodRoomRoom = new escapePodRoom;
    this->mainframeRoomRoom = new mainframeRoom;
    this->communicationsRoom = new communications;
    this->electricalRoom = new electrical;
    this->navigationRoom = new navigation;
    this->cafeteriaRoom = new cafeteria; // East-side
    this->reactorRoom = new reactor;
    this->engineBayRoom = new engineBay;
    this->storageRoom = new storage;
    this->lifeSupportO2Room = new lifeSupportO2;
    this->captainsLodgeRoom = new captainsLodge;

    // Connect all rooms together
    this->corridor1Room->setConnectedRooms(medbayRoom);
    this->corridor1Room->setConnectedRooms(escapePodRoomRoom);
    this->corridor1Room->setConnectedRooms(mainframeRoomRoom);
    this->corridor1Room->setConnectedRooms(communicationsRoom);
    this->corridor1Room->setConnectedRooms(electricalRoom);
    this->corridor1Room->setConnectedRooms(navigationRoom);
    this->corridor1Room->setConnectedRooms(corridor2Room);

    this->corridor2Room->setConnectedRooms(corridor1Room);
    this->corridor2Room->setConnectedRooms(corridor3Room);

    this->corridor3Room->setConnectedRooms(cafeteriaRoom);
    this->corridor3Room->setConnectedRooms(reactorRoom);
    this->corridor3Room->setConnectedRooms(engineBayRoom);
    this->corridor3Room->setConnectedRooms(lifeSupportO2Room);
    this->corridor3Room->setConnectedRooms(captainsLodgeRoom);
    this->corridor3Room->setConnectedRooms(corridor2Room);

    this->medbayRoom->setConnectedRooms(corridor1Room);
    this->escapePodRoomRoom->setConnectedRooms(corridor1Room);
    this->mainframeRoomRoom->setConnectedRooms(corridor1Room);
    this->communicationsRoom->setConnectedRooms(corridor1Room);
    this->electricalRoom->setConnectedRooms(corridor1Room);
    this->navigationRoom->setConnectedRooms(corridor1Room);

    this->cafeteriaRoom->setConnectedRooms(corridor3Room);
    this->reactorRoom->setConnectedRooms(corridor3Room);
    this->engineBayRoom->setConnectedRooms(corridor3Room);
    this->storageRoom->setConnectedRooms(lifeSupportO2Room);
    this->lifeSupportO2Room->setConnectedRooms(corridor3Room);
    this->lifeSupportO2Room->setConnectedRooms(storageRoom);
    this->captainsLodgeRoom->setConnectedRooms(corridor3Room);

    // Add starting items to the rooms
    this->storageRoom->addItemStarting(keyItem);
    this->captainsLodgeRoom->addItemStarting(badgeItem);
    this->medbayRoom->addItemStarting(scalpelItem);
    this->engineBayRoom->addItemStarting(workGlovesItem);
    this->reactorRoom->addItemStarting(navCommUpdateModuleItem);
    this->lifeSupportO2Room->addItemStarting(emptyContainerItem);
    this->corridor2Room->addItemStarting(wrenchItem);
    this->medbayRoom->addItemStarting(flareGunItem);

    // Add all the rooms to the roomsVector
    // MAYBE if we want to refactor a bit...

    // Set up a new character
    this->player = new character();

    // CHECKING IF ITEMS WORKING - TEMP!!!!
    // this->player->addItem(badgeItem);
    // this->player->addItem(flareGunItem);
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
    cout << currentPosition->getLongDescription();
    currentPosition->listItemDropped();
    cout << endl;

}

/********************************************************************************
dropItem - drops an item in the player's inventory to the room
**********************************************************************************/
void game::dropItem(string itemName) {

    if(player->searchItem(itemName) == true){
        cout << "\nYou drop the " << itemName << " on the floor of " << currentPosition->getName() << "." << endl;
        currentPosition->addItemDropped(player->removeItem(itemName));
    }
    else{
        cout << "Input not recognized." << endl;
    }
}

/********************************************************************************
takeItem - takes an item and puts it into player's inventory from the room
**********************************************************************************/
void game::takeItem(string itemName) {

    if(currentPosition->searchItemDropped(itemName) == true){
        cout << "\nYou take the " << itemName << " from the floor of " << currentPosition->getName() << "." << endl;
        player->addItem(currentPosition->removeItemDropped(itemName));
    }
    else{
        cout << "Input not recognized." << endl;
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

    this->player->listInventory();

}

/********************************************************************************
lookAtFeatureCall - does the 'Look at' command for the current room the player is
 in.
**********************************************************************************/
void game::lookAtFeatureCall(vector<string> input, int actionSize){

    // Add together all words after the ACTION, this must be the feature...
    string featureInputName = input[actionSize];
    if(input.size()>actionSize+1){
        for(int i = actionSize+1; i<input.size(); i++){
            featureInputName+= " ";
            featureInputName+= input[i];
        }
    }

    // Check if this is an item in inventory
    int inventoryLocation = -1;
    int dropLocation = -1;
    if(player->searchItem(featureInputName) == true){
        inventoryLocation = player->itemIndex(featureInputName);
        this->player->displayItemDescription(inventoryLocation);

    }
    // Check if this is an item on the floor
    else if(currentPosition->searchItemDropped(featureInputName) == true){
        dropLocation = currentPosition->itemIndexDrop(featureInputName);
        this->currentPosition->displayItemDropDescription(dropLocation);
    }
    // Else check for room features
    else{
        this->currentPosition->lookAtFeature(featureInputName);
    }
}



/********************************************************************************
destructor
**********************************************************************************/

game::~game()
{




}
