/******************************************************************
  Project Nashville
  CS467 - Online Capstone Project
Description: This is the class implementation file for the class game.
 ******************************************************************/

#include "game.hpp"
#include <iostream>
#include <thread>
#include "utilityFunctions.hpp"

/********************************************************************************
  default constructor
 **********************************************************************************/
game::game(){

   // Set the game timer
   this->gameTimerDisabled = false;

   // Set up the items in the game
   item* keyItem = new item();
   keyItem->setName("KEY");
   keyItem->setDescription("This KEY can be used to escape in the ESCAPE POD.");

   item* badgeItem = new item();
   badgeItem->setName("BADGE");
   badgeItem->setDescription("This BADGE allows access to open the MAINFRAME ROOM.");

   item* scalpelItem = new item();
   scalpelItem->setName("SCALPEL");
   scalpelItem->setDescription("This is a handy SCALPEL that can be used in multiple objects to cut and pry.");

   item* workGlovesItem = new item();
   workGlovesItem->setName("WORK GLOVES");
   workGlovesItem->setDescription("These WORK GLOVES can be handy in working with dangerous electrical objects.");

   item* navCommUpdateModuleItem = new item();
   navCommUpdateModuleItem->setName("NAV COMM UPDATE MODULE");
   navCommUpdateModuleItem->setDescription("The NAV COMM UPDATE MODULE can be used on a computer to allow a safe route on an escape pod.");

   item* emptyContainerItem = new item();
   emptyContainerItem->setName("EMPTY CONTAINER");
   emptyContainerItem->setDescription("This EMPTY CONTAINER can be filled with something.");

   item* wrenchItem = new item();
   wrenchItem->setName("WRENCH");
   wrenchItem->setDescription("This WRENCH can be used to turn valves or bolts.");

   item* flareGunItem = new item();
   flareGunItem->setName("FLARE GUN");
   flareGunItem->setDescription("This FLARE GUN can probably be used to ignite something with O2.");

   // Setup Rooms in the game
   this->corridor1Room = new corridor1; // Corridors
   this->corridor2Room = new corridor2;
   this->corridor3Room = new corridor3(this);

   this->medbayRoom = new medbay; // West-side
   this->escapePodRoomRoom = new escapePodRoom(this);
   this->mainframeRoomRoom = new mainframeRoom(this);
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

   // Set up the current position on the game board
   this->currentPosition = medbayRoom;

   // Set up flags
   this->mapSaved = false; // Map has not been saved yet.

   this->start_time = std::chrono::high_resolution_clock::now();

}

/********************************************************************************
  constructor - for load game
 **********************************************************************************/
game::game(bool inputLoadGame){

    // Set the start time
    this->start_time = std::chrono::high_resolution_clock::now();

    // Create all rooms
    this->corridor1Room = new corridor1(inputLoadGame); // Corridors
    this->corridor2Room = new corridor2(inputLoadGame);
    this->corridor3Room = new corridor3(inputLoadGame,this);
    this->medbayRoom = new medbay(inputLoadGame); // West-side
    this->escapePodRoomRoom = new escapePodRoom(inputLoadGame,this);
    this->mainframeRoomRoom = new mainframeRoom(inputLoadGame,this);
    this->communicationsRoom = new communications(inputLoadGame);
    this->electricalRoom = new electrical(inputLoadGame);
    this->navigationRoom = new navigation(inputLoadGame);
    this->cafeteriaRoom = new cafeteria(inputLoadGame); // East-side
    this->reactorRoom = new reactor(inputLoadGame);
    this->engineBayRoom = new engineBay(inputLoadGame);
    this->storageRoom = new storage(inputLoadGame);
    this->lifeSupportO2Room = new lifeSupportO2(inputLoadGame);
    this->captainsLodgeRoom = new captainsLodge(inputLoadGame);

    // Connect all rooms
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

    // Set up a new character
    this->player = new character(inputLoadGame);

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

    // Read from txt file
    string line;
    std::ifstream myfile ("saveGame.txt");
    if (myfile.is_open())
    {
        // Keep getting each line
        while (getline (myfile,line) )
        {
            // Set currentRoom
            if(line == "currentRoom"){
                getline (myfile,line);
                if(line == "CORRIDOR 1"){
                    this->currentPosition = corridor1Room;
                }
                else if(line == "CORRIDOR 2"){
                    this->currentPosition = corridor2Room;
                }
                else if(line == "CORRIDOR 3"){
                    this->currentPosition = corridor3Room;
                }
                else if(line == "MEDBAY"){
                    this->currentPosition = medbayRoom;
                }
                else if(line == "ESCAPE POD ROOM"){
                    this->currentPosition = escapePodRoomRoom;
                }
                else if(line == "MAINFRAME"){
                    this->currentPosition = mainframeRoomRoom;
                }
                else if(line == "COMMUNICATIONS"){
                    this->currentPosition = communicationsRoom;
                }
                else if(line == "ELECTRICAL"){
                    this->currentPosition = electricalRoom;
                }
                else if(line == "NAVIGATION"){
                    this->currentPosition = navigationRoom;
                }
                else if(line == "CAFETERIA"){
                    this->currentPosition = cafeteriaRoom;
                }
                else if(line == "REACTOR"){
                    this->currentPosition = reactorRoom;
                }
                else if(line == "ENGINE BAY"){
                    this->currentPosition = engineBayRoom;
                }
                else if(line == "STORAGE"){
                    this->currentPosition = storageRoom;
                }
                else if(line == "LIFE SUPPORT O2"){
                    this->currentPosition = lifeSupportO2Room;
                }
                else{
                    this->currentPosition = captainsLodgeRoom;
                }
            }
            else if(line == "mapSaved"){
                getline (myfile,line);
                this->mapSaved = ToBoolean(line);
            }
            else if(line == "total_seconds"){
                getline (myfile,line);
                this->total_seconds = std::stoull(line);
            }
            else if(line == "gameTimerDisabled"){
                getline (myfile,line);
                this->gameTimerDisabled = ToBoolean(line);
            }
            else if(line == "escapeStation"){
                getline (myfile,line);
                this->escapeStation = ToBoolean(line);
            }
            else if(line == "electricalRoomDoorFixed"){
                getline (myfile,line);
                this->electricalRoomDoorFixed = ToBoolean(line);
            }
        }
        myfile.close();
    }

    else{
        cout << "\nUnable to open load file!" << endl;
    }

    // Display the room long description
    cout << "\nYou enter the room " << currentPosition->getName() << "..." << endl;
    cout << currentPosition->getLongDescription();
    currentPosition->listItemDropped();
    cout << endl;

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
  hasItem - takes an item and puts it into player's inventory from the room
 **********************************************************************************/
bool game::hasItem(string itemName) {
   if(player->searchItem(itemName)){
      return true;
   }
   else{
      return false;
   }
}
/********************************************************************************
  moveRooms - changes the current room to the user input Room string name
 **********************************************************************************/
void game::moveRooms(string roomNameInput){

   bool movedRooms = true;
   bool dropItemValidFlag = false;

   // Check if this is a connected room
   if(currentPosition->isConnectedRoom(roomNameInput) == true){
      // Go through all our rooms and see if its the same room name
      if(corridor1Room->getName() == roomNameInput){
	 // If the player is in the MAINFRAME, make sure they have a badge when exiting to corridor 1
	 if(currentPosition->getName() == "MAINFRAME"){
	    if(hasItem("BADGE")){
	       currentPosition = corridor1Room;
	    }
	    else{
	       cout << "\nYou should TAKE the BADGE you've dropped with you. You may lock yourself out!" << endl;
	       dropItemValidFlag = true;
	       movedRooms = false;
	    }
	 }
	 // For all other corridor 1 cases
	 else{
	    currentPosition = corridor1Room;
	 }
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
      else if(mainframeRoomRoom->getName() == roomNameInput) {
          // Need a badge to enter the MAINFRAME
          if (hasItem("BADGE")) {
              currentPosition = mainframeRoomRoom;
          }
          else {
              cout << "\nThe door is locked. A BADGE is required for entry." << endl;
              movedRooms = false;
              return;
          }
      }
      else if(communicationsRoom->getName() == roomNameInput){
	 currentPosition = communicationsRoom;
      }
      else if(electricalRoom->getName() == roomNameInput){
	 // Need the SCALPEL to enter the electrical room
	 if(electricalRoomDoorFixed == false && hasItem("SCALPEL")){

	    // You fix the electrical room door
	    electricalRoomDoorFixed = true;
	    cout << "\nYou try to go through the the door to ELECTRICAL, but see that it is locked. You see some wires hanging" << endl;
	    cout << "from the side of the security lock. Using the SCALPEL you have, you short-circuit the failed security lock by" << endl;
	    cout << "cutting a yellow loose wire!" << endl;
	    currentPosition = electricalRoom;
	 }
	 // Already fixed
	 else if(electricalRoomDoorFixed == true){
	    currentPosition = electricalRoom;
	 }
	 // Need scalpel to fix
	 else{
	    cout << "\nYou see that the door to ELECTRICAL is locked. However you see some wires hanging from the side of the" << endl;
	    cout << "security lock...maybe if you had something to cut these wires you can get in!" << endl;
	    movedRooms = false;
	    return;
	 }
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

	 // Check if the room has been unlocked
	 if(player->getCaptainDoor() == true){
	    currentPosition = captainsLodgeRoom;
	 }
	 else{
	    movedRooms = false;
	    cout << "The door to the CAPTAIN'S LODGE is locked. You muse unlock this from a computer somewhere..." << endl;
	 }
      }

      // Call the current room description
      if(movedRooms == true){
	 currentRoomDescription();
      }
      }
      else if(currentPosition->getName() == roomNameInput){
	 cout << "\nYou are already in that room." << endl;
      }
      else if(dropItemValidFlag == true){

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
  timeRanOut - returns true if time has run out
 **********************************************************************************/
bool game::timeRanOut(){
    if(this->gameTimerDisabled){
        return false;
    }
   auto current_time = std::chrono::high_resolution_clock::now();
   unsigned long long time_elapsed = std::chrono::duration_cast<std::chrono::seconds>(current_time - this->start_time).count();
   if(time_elapsed > this->total_seconds){

       // !! ADD SOME KIND OF STORY FOR STATION EXPLODING EVENTUALLY HERE
       std::cout << "\nYour palms are slippery with sweat \n"
                    "as your realize there is no future. \n"
                    "Why did you linger? \n"
                    "In what room did you spend too much time? \n"
                    "Why you? \n"
                    "Why not you? \n"
                    "The station quakes, and the roar of the self destruct begins \n"
                    "as the reactor goes critical. \n"
                    "You face oblivion, remembering words from a dream... \n"
                    "Good luck....god speed."<< std::endl;
       return true;
   }
      return false;
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
     printTime- prints the time left in the game
     addBackPauseTime - paused time to add back, optional parameter
    **********************************************************************************/
   void game::printTime(){
      if(this->gameTimerDisabled){
	 std::cout << "disabled 00:00" << std::endl;
	 return;
      }
      auto current_time = std::chrono::high_resolution_clock::now();
      unsigned long long time_elapsed = std::chrono::duration_cast<std::chrono::seconds>(current_time - this->start_time).count();
      unsigned long long time_left = this->total_seconds - time_elapsed;
      unsigned long long minutes = time_left/60;
      unsigned long long seconds = time_left % 60;

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
     addBackPauseTime- adds back time lost while paused
    **********************************************************************************/

   void game::addBackPauseTime(unsigned long long pauseSeconds){
      this->total_seconds += pauseSeconds;
   }

   /********************************************************************************
     getTime - gets the game timer
    **********************************************************************************/
   void game::disableGameTimer(){
      this->gameTimerDisabled = true;
   }

   /********************************************************************************
     setEscape - sets the escapeStation flag to true
    **********************************************************************************/
   void game::setEscape() {

      this->escapeStation = true;

   }

   /********************************************************************************
     getEscape - gets the escapeStation flag
    **********************************************************************************/
   bool game::getEscape() {

      return this->escapeStation;

   }

/********************************************************************************
saveGame - creates savegame txt files for the game
**********************************************************************************/
void game::saveGame() {

    // Save the time
    auto current_time = std::chrono::high_resolution_clock::now();
    unsigned long long time_elapsed = std::chrono::duration_cast<std::chrono::seconds>(current_time - this->start_time).count();

    // Verify player wants to save the game
    cout << "\nAre you sure you'd like to save your game?" << endl;
    string input = "";

    // Get input from the user
    //while(input.empty()) {
    std::cout << "Enter choice (Yes/No): ";
    std::getline(cin, input);
    //}

    // If the player wants to save the game
    if(input == "YES" || input == "YEs" || input == "Yes" || input == "yeS" || input == "yES" || input == "yes" ){

        cout << "\nSaving Game!" << endl;

        // Create and open a text file
        std::ofstream MyFile("saveGame.txt");

        // Save all flags
        MyFile << "currentRoom\n" << this->currentPosition->getName() << endl;
        MyFile << "mapSaved\n" << this->mapSaved << endl;
        unsigned long long time_left = this->total_seconds - time_elapsed;
        MyFile << "total_seconds\n" << time_left << endl;
        MyFile << "gameTimerDisabled\n" << this->gameTimerDisabled << endl;
        MyFile << "escapeStation\n" << this->escapeStation << endl;
        MyFile << "electricalRoomDoorFixed\n" << this->electricalRoomDoorFixed << endl;
        MyFile.close();

        // Call the save function for character
        this->player->saveGame();

        // Call the save function for rooms
        this->corridor1Room->saveGame();
        this->corridor2Room->saveGame();
        this->corridor3Room->saveGame();
        this->medbayRoom->saveGame();
        this->escapePodRoomRoom->saveGame();
        this->mainframeRoomRoom->saveGame();
        this->communicationsRoom->saveGame();
        this->electricalRoom->saveGame();
        this->navigationRoom->saveGame();
        this->cafeteriaRoom->saveGame();
        this->reactorRoom->saveGame();
        this->engineBayRoom->saveGame();
        this->storageRoom->saveGame();
        this->lifeSupportO2Room->saveGame();
        this->captainsLodgeRoom->saveGame();

    }

    // Player does not want to save the game
    else if(input == "NO" || input == "No" || input == "nO" || input == "no"){

        cout << "\nNot saving game!" << endl;

    }
    // Invalid input
    else{
        cout << "\nInput not recognized." << endl;
    }
}

   /********************************************************************************
     destructor
    **********************************************************************************/
   game::~game()
   {

       // Free the character object
       free(this->player);

       // Free all the rooms
       free(this->corridor1Room);
       free(this->corridor2Room);
       free(this->corridor3Room);
       free(this->medbayRoom);
       free(this->escapePodRoomRoom);
       free(this->mainframeRoomRoom);
       free(this->communicationsRoom);
       free(this->electricalRoom);
       free(this->navigationRoom);
       free(this->cafeteriaRoom);
       free(this->reactorRoom);
       free(this->engineBayRoom);
       free(this->storageRoom);
       free(this->lifeSupportO2Room);
       free(this->captainsLodgeRoom);

   }
