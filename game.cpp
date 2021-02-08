/******************************************************************
  Project Nashville
  CS467 - Online Capstone Project
Description: This is the class implementation file for the class game.
 ******************************************************************/

#include "game.hpp"
#include <iostream>


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
    this->corridor3Room = new corridor3(this);

    this->medbayRoom = new medbay; // West-side
    this->escapePodRoomRoom = new escapePodRoom;
    this->mainframeRoomRoom = new mainframeRoom;
    this->communicationsRoom = new communications;
    this->electricalRoom = new electrical;
    this->navigationRoom = new navigation;
    this->cafeteriaRoom = new cafeteria; // East-side
    this->reactorRoom = new reactor();
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

    // Set up a new character
    this->player = new character();

    // Place a player pointer in each of the rooms
    this->corridor1Room->setCharacter(player);
    this->corridor2Room->setCharacter(player);
    this->corridor3Room->setCharacter(player);
    this->medbayRoom->setCharacter(player);
    this->escapePodRoomRoom->setCharacter(player);
    this->mainframeRoomRoom->setCharacter(player);
    this->communicationsRoom->setCharacter(player);
    this->electricalRoom->setCharacter(player);
    this->navigationRoom->setCharacter(player);
    this->cafeteriaRoom->setCharacter(player);
    this->reactorRoom->setCharacter(player);
    this->engineBayRoom->setCharacter(player);
    this->storageRoom->setCharacter(player);
    this->lifeSupportO2Room->setCharacter(player);
    this->captainsLodgeRoom->setCharacter(player);

    // CHECKING IF ITEMS WORKING - TEMP!!!!
    // this->player->addItem(wrenchItem);
    // this->player->addItem(badgeItem);
    // this->player->addItem(flareGunItem);
    // TEMP CODE!!!!!!!!!!!!!!!!!!!!!!!!!

    // Set up the current position on the game board
    this->currentPosition = medbayRoom;

    // Set up flags
    this->stationPowerRestored = 0; // No Power!
    this->mapSaved = false; // Map has not been saved yet.
    this->gameStillRunning = 1; // Game Running

    this->time_left = 10; // We need to have a countdown for the CLOCK eventually.
    this->total_seconds = 500; //Currently minute 30 seconds for testing, eventually have user set difficulty
    this->start_time = std::chrono::high_resolution_clock::now();


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
   else if(currentPosition->isTakeableFromStarting(itemName) == true){
      cout << "\nYou take the " << itemName << " and put it in your inventory." << endl;
      player->addItem(currentPosition->removeItemStarting(itemName));
   }
   else{
      cout << "Input not recognized." << endl;
   }
}

/********************************************************************************
  moveRooms - changes the current room to the user input Room string name
 **********************************************************************************/
void game::moveRooms(string roomNameInput){

    bool movedRooms = true;

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
          if(lifeSupportO2Room->isO2CanistersDestroyed() == true){
              currentPosition = storageRoom;
          }
          else{
              movedRooms = false;
              cout << "You do not see the entrance to the STORAGE room." << endl;
          }
      }
      else if(lifeSupportO2Room->getName() == roomNameInput){
          currentPosition = lifeSupportO2Room;
      }
      else if(captainsLodgeRoom->getName() == roomNameInput){
	 currentPosition = captainsLodgeRoom;
      }

      // Call the current room description
      if(movedRooms == true){
          currentRoomDescription();
      }
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
    string featureInputName;
    if(input.size()>actionSize){
        featureInputName = input[actionSize];
    }
    else{
        featureInputName = "BAD STUFF";
    }
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
    // Special 'LOOK AT' for Corridor 3
    else if(currentPosition->getName() == "CORRIDOR 3"){
        this->currentPosition->lookAtFeature(featureInputName, this->total_seconds);
    }
    // Else check for room features
    else{
        this->currentPosition->lookAtFeature(featureInputName);
    }
}

/********************************************************************************
  interactFeatureCall - calls a room function to do a certain interactive action with
  the string input
 **********************************************************************************/
void game::interactFeatureCall(string input) {

    // Call the interactRoom for the current position
    // For Corridors 1
    if(this->currentPosition->getName() == "CORRIDOR 1"){

        int makeMap = 0;
        makeMap = this->currentPosition->interactRoom(input, this->mapSaved);
        // Set the mapSaved to true in order for map command to be useable now.
        if(makeMap == 1){
            this->mapSaved = true;
        }
    }
    // For all other rooms
    else{
        this->currentPosition->interactRoom(input);
    }
}

/********************************************************************************
  getCurrentRoomId - return id of current room
 **********************************************************************************/
int game::getCurrentRoomId(){
   return this->currentPosition->getRoomId();
}

/********************************************************************************
  isMapMade - returns the
 **********************************************************************************/
bool game::isMapMade(){

   return this->mapSaved;

}

/********************************************************************************
  timeRanOut - returns true if time has run out
 **********************************************************************************/
bool game::timeRanOut(){
   auto current_time = std::chrono::high_resolution_clock::now();
   int time_elapsed = std::chrono::duration_cast<std::chrono::seconds>(current_time - this->start_time).count();
   if((this->total_seconds - time_elapsed) <= 0){

       // !! ADD SOME KIND OF STORY FOR STATION EXPLODING EVENTUALLY HERE
       std::cout << "TIME RAN OUT. GAME OVER" << std::endl;
      return true;
   }
   return false;

}

/********************************************************************************
  printTime- prints the time left in the game
 **********************************************************************************/
void game::printTime(){

   auto current_time = std::chrono::high_resolution_clock::now();
   int time_elapsed = std::chrono::duration_cast<std::chrono::seconds>(current_time - this->start_time).count();
   int time_left = this->total_seconds - time_elapsed;
   int minutes = time_left/60;
   int seconds = time_left % 60;

   if(minutes <= 0){
      std::cout << "00" << ":";
   }
   else if(minutes < 10){
      std::cout << "0" << minutes << ":";
   }
   else{
      std::cout << minutes << ":";
   }
   if(seconds <= 0){
      std::cout << "00" << std::endl;
   }
   else if(seconds < 10){
      std::cout << "0" << seconds << std::endl;
   }
   else{
      std::cout << seconds << std::endl;
   }
}

/********************************************************************************
  setTime - sets total time until station explodes
 **********************************************************************************/

void game::setTime(int seconds){
   this->total_seconds = seconds;
}

/********************************************************************************
destructor
**********************************************************************************/

game::~game()
{


}
