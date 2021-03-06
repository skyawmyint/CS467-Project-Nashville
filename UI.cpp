#include <iostream>
#include <algorithm>
#include <sstream>
#include <chrono>
#include <fstream>

#include "UI.hpp"

using std::cout;
using std::string;
using std::endl;
using std::cin;
using std::vector;

/********************************************************************************
  default constructor
 **********************************************************************************/
UI::UI() {

    // Case 0 - LOOK
   general_actions.insert({ "LOOK", 0 });

   // Case 1 - HELP
   general_actions.insert({ "HELP", 1 });

   // Case 2 - INVENTORY
   general_actions.insert({ "INVENTORY", 2 });

   // Case 3 - SAVE GAME
   general_actions.insert({ "SAVE GAME", 3 });
   general_actions.insert({ "SAVEGAME", 3 });
    general_actions.insert({ "SAVE", 3 });

   // Case 4 - LOAD GAME
   general_actions.insert({ "LOAD GAME", 4 });
   general_actions.insert({ "LOADGAME", 4 });
   general_actions.insert({ "LOAD", 4 });

   general_actions.insert({ "TIME", 5 });

   // Case 6 - PAUSE
   general_actions.insert({ "PAUSE", 6 });

   //general_actions.insert({ "UNPAUSE", 7 });

   // Case 8 - MAP
   general_actions.insert({ "MAP", 8 });

   // Case 9 - LOOK AT
   general_actions.insert({ "LOOK AT", 9 });

   // Case 10 - GO
   general_actions.insert({ "GO", 10 });
   general_actions.insert({"GO TO", 10 });
   rooms.insert({"ESCAPE POD ROOM", 10});
   rooms.insert({"MEDBAY",10});
   rooms.insert({"MAINFRAME" , 10});
   rooms.insert({"COMMUNICATIONS", 10});
   rooms.insert({"ELECTRICAL", 10});
   rooms.insert({"NAVIGATION", 10});
   rooms.insert({"CORRIDOR 1", 10});
   rooms.insert({"CORRIDOR 2", 10});
   rooms.insert({"CORRIDOR 3", 10});
   rooms.insert({"REACTOR", 10});
   rooms.insert({"ENGINE BAY", 10});
   rooms.insert({"CAFETERIA", 10});
   rooms.insert({"CAPTAIN'S LODGE", 10});
   rooms.insert({"LIFE SUPPORT O2", 10});
   rooms.insert({"STORAGE", 10});

   // Case 11 - EXIT GAME
   general_actions.insert({ "EXIT GAME", 11 });

   // Case 12 - DROP <OBJECT>
   general_actions.insert({ "DROP", 12 });
   general_actions.insert({ "LEAVE", 12 });
   general_actions.insert({ "LEAVE BEHIND", 12 });

   // Case 13 - TAKE <OBJECT>
   general_actions.insert({ "TAKE", 13 });
   general_actions.insert({ "PICK UP", 13 });

   // Case 14 - Junk cases to deal with overriding some previous actions
    general_actions.insert({ "LOOK OUT", 14 });

   // MENU OPTIONS
   menu_options.insert({"NEW", 0});
   menu_options.insert({"NEW GAME", 0});
   menu_options.insert({"LOAD", 1});
   menu_options.insert({"LOAD GAME", 1});
   menu_options.insert({"EXIT", 2});
   menu_options.insert({"EXIT GAME", 2});

   // ITEMS
   items.insert("KEY");
   items.insert("BADGE");
   items.insert("SCALPEL");
   items.insert("WORK GLOVES");
   items.insert("NAV COMM UPDATE MODULE");
   items.insert("EMPTY CONTAINER");
   items.insert("WRENCH");
   items.insert("FLARE GUN");
   items.insert("FILLED CONTAINER");

   this->gameRunning = true;

}

/********************************************************************************
  menuStartUp() - prompts the user if  they would like to create a New Game, Load
  Game, or Exit game. This will then return an int value back to main.
 **********************************************************************************/
int UI::menuStartUp()
{

   // Track the menu startup choice
   int retChoice = -1;

   // Make a cool starting screen!
   cout << "|----------------------------|" << endl;
   cout << "|     Project Nashville      |" << endl;
   cout << "|----------------------------|" << endl;
   cout << "|          New  game         |" << std::endl; //0
   cout << "|          Load game         |" << std::endl; //1
   cout << "|          Exit game         |" << std::endl; //2
   cout << "|----------------------------|" << endl;

   // Get the input from the user
   std::vector<std::string> input = getInput();

   string combinedInput = "";

   for(int i = 0; i<input.size(); i++){
      if(i == input.size()-1){
	 combinedInput += input[i];
      }
      else{
	 combinedInput+= input[i] + " ";
      }
   }

   while(retChoice == -1){
      //Valid menu option
      //0: new game
      //1: load Game
      //2: exit game
      if(menu_options.find(combinedInput) != menu_options.end()){
	 retChoice = menu_options[combinedInput];
	 break;
      }
      if(retChoice == -1){
	 std::cout << "Input not recognized." << std::endl;
	 input = getInput();
	 combinedInput = "";
	 for(int i = 0; i<input.size(); i++){
	    if(i == input.size()-1){
	       combinedInput += input[i];
	    }
	    else{
	       combinedInput+= input[i] + " ";
	    }
	 }
      }
   }
   return retChoice;
}

/********************************************************************************
  selectDifficulty() - prompts the user the difficulty they'd like to play the game
 **********************************************************************************/
void UI::selectDifficulty(){
     while(true){
       cout << "|----------------------------|" << endl;
       cout << "|      Select Difficulty:    |" << endl;
       cout << "|----------------------------|" << endl;
       cout << "|            Easy            |" << std::endl; //0
       cout << "|           Medium           |" << std::endl; //1
       cout << "|            Hard            |" << std::endl; //2
       cout << "|----------------------------|" << endl;

       std::vector<string>choice = getInput();
       if(choice[0] == "EASY"){
          currentGame->setTime(3600);
          break;
       }
       else if(choice[0] == "MEDIUM"){
          currentGame->setTime(1800);
          break;
       }
       else if(choice[0] == "HARD"){
          currentGame->setTime(900);
          break;
       }
       else{
          std::cout << "Input not recognized." << std::endl;
       }
     }

     // INSTRUCTIONS
     cout << endl;
     cout << "|----------------------------------------------------------------------------------------------------|" << endl;
     cout << "|                                              INSTRUCTIONS                                          |" << endl;
     cout << "|----------------------------------------------------------------------------------------------------|" << endl;
     cout << "| Project Nashville utilizes user inputs in navigating and interacting with the game. The player may |" << endl;
     cout << "| use the command GO TO <ROOM NAME> to navigate to a specific room. The command LOOK repeats the     |" << endl;
     cout << "| description of a room. The command LOOK AT <FEATURE NAME> returns a description of a feature or    |" << endl;
     cout << "| item, likely giving a hint for further interactions. For all the general actions that are present  |" << endl;
     cout << "| in the game, use the command HELP.                                                                 |" << endl;
     cout << "|----------------------------------------------------------------------------------------------------|" << endl;

    cout << endl;
    cout << "You jolt awake. Cold steel presses against your back and a bright lamp glares overhead. " << endl <<
            "You hear a loud beeping sound accompanied by a voice counting down numbers. Something bad is going on!" << endl <<
            "You sit up. You appear to be lying on some kind of surgical table. You get up and look around the room... " << endl <<
            "there is no one in sight. The last thing you remember is working on a cure for a deadly virus affecting Earth " << endl <<
            "on the Project Nashville space station." << endl;
    cout << endl;
    cout << "As you look around, you see that you are surrounded by white walls that are very bright and clean." << endl <<
            "The walls feel empty with very little in the room. The only things in the room that you see are the surgical " << endl <<
            "table that you woke up on with a SCALPEL on it, a MEDICAL BOX on the far wall, and a door leading to a " << endl <<
            "dark hall. You also see a COMPUTER on top of the metal table that looks functional. Gathering all this information, " << endl <<
            "you remember that you must be in the MEDBAY and the door must lead to CORRIDOR 1. The countdown must mean that " << endl <<
            "something bad is happening to the station and you must escape by any means possible!" << endl;
}

/********************************************************************************
  makeNewGame() - creates a new game object if the user selects New Game
 **********************************************************************************/
void UI::makeNewGame() {

   // Create new game object
   this->currentGame = new game();
   this->gameMade = true;

}


/********************************************************************************
  getInput() - gets input from the user and separates words to different indexes
 **********************************************************************************/
vector<string> UI::getInput(){
   string input = "";

   while(input.empty()){
      std::cout << "\nEnter choice: ";
      if(!std::getline(cin, input)){
	 //IO ERROR
	 return {};
      }
      if(!input.empty()){
	 vector<string> input_vec = parseClean(input);
	 return input_vec;
      }
   }
   return {};
}

/********************************************************************************
  play() - gets input from the user and calls the game file accordingly.
 **********************************************************************************/
bool UI::play(){

   if(this->currentGame->timeRanOut() == true){
      return false;
   }

   // Get user input
   std::vector<std::string> input = getInput();

   if(this->currentGame->timeRanOut() == true){
      return false;
   }

   // Variables to check input
   int inputChoice = -1;
   int generalActionStringSize = 1;

   // Check for one-word general actions
   if(general_actions.find(input[0]) != general_actions.end()) {
      inputChoice = general_actions[input[0]];
   }
   // One-word room action
   if(rooms.find(input[0]) != rooms.end()){
      inputChoice = rooms[input[0]];
   }

   // Check for two-word general actions
   if(input.size()>1){
      string tempString = input[0] + " " +input[1];
      if(general_actions.find(tempString) != general_actions.end() || rooms.find(tempString) != rooms.end()){
	 inputChoice = general_actions[tempString];
	 generalActionStringSize = 2;
      }
   }
   // Two-word room action
   if(input.size()>1){
      string tempString = input[0] + " " +input[1];
      if(rooms.find(tempString) != rooms.end()){
	 inputChoice = rooms[tempString];
	 generalActionStringSize = 2;
      }
   }

   // Check for three-word general actions
   if(input.size()>2){
      string tempString = input[0] + " " +input[1] + " " + input[2];
      if(general_actions.find(tempString) != general_actions.end() || rooms.find(tempString) != rooms.end()){
	 inputChoice = general_actions[tempString];
	 generalActionStringSize = 3;
      }
   }
   // Three-word room action
   if(input.size()>2){
      string tempString = input[0] + " " +input[1] + " " + input[2];
      if(rooms.find(tempString) != rooms.end()){
	 inputChoice = rooms[tempString];
	 generalActionStringSize = 3;
      }
   }

   // Do the input general action
   if(inputChoice >=0 && inputChoice <= 13){
      generalActions(input, inputChoice, generalActionStringSize);
   }
   // Else, we check for if this is an interactive action for the room
   else{
      featureActionCall(input);
   }

   // Code here if the player wins the game!
   if(this->currentGame->getEscape() == true){
       // Set the game running to false
       this->gameRunning = false;
   }

   return this->gameRunning;
}

/********************************************************************************
  parseClean - converts all the input from the user into upperCase, then
  parses the entire string of words to separate indexes in a vector.
 **********************************************************************************/
vector<string> UI::parseClean(string str){

   // Converts the input string to all capital letters.
   std::transform(str.begin(), str.end(), str.begin(), ::toupper);

   // Tokenizes the string into separate indexes of a vector
   std::istringstream ss(str);
   string word;
   vector<string> input;

   while(ss >> word){
      input.push_back(word);
   }

   return input;
}

/********************************************************************************
  generalActions - does a specific call for a certain input parsing
 **********************************************************************************/
void UI::generalActions(vector<string> input, int actionChoice, int actionSize){

   switch(actionChoice){

      // Case to 'LOOK'
      case 0: {
		 if(input.size() > actionSize){
		    cout << "Input not recognized." << endl;
		 }
		 else{
		    currentGame->lookDescription();
		 }
		 break;
	      }
	      // Case to 'HELP'
      case 1:{
		if(input.size() > actionSize){
		   cout << "Input not recognized." << endl;
		}
		else{
		   help();
		}
		break;
	     }
	     // Case to 'INVENTORY'
      case 2:{
		if(input.size() > actionSize){
		   cout << "Input not recognized." << endl;
		}
		else{
		   currentGame->displayInventory();
		}
		break;
	     }

	     // Case to 'SAVE GAME'

	     case 3: {
             if (input.size() > actionSize) {
                 cout << "Input not recognized." << endl;
             } else {
                 currentGame->saveGame();
             }
             break;
         }

         // Case to 'LOAD GAME'
         case 4: {
          if (input.size() > actionSize) {
              cout << "Input not recognized." << endl;
          } else {
              loadGameFromRunning();
          }
          break;
      }

      // Case to 'TIME' !!UNUSED for now. TIME implemented with CLOCK in corridor 3
      case 5:{

          cout << "Input not recognized." << endl;
          break;
      }

      // Case to 'PAUSE'
      case 6:
          if(input.size() > actionSize){
              cout << "Input not recognized." << endl;
          }
          else {
              pauseGame();
          }
          break;

      case 7:
	     break;



	     // Case to 'MAP'
      case 8:{
          if(input.size() > actionSize){
              cout << "Input not recognized." << endl;
          }
          else{
              if(currentGame->isMapMade() == true){
                  showMap();
              }
              else{
                  cout << "You do not have access the this yet!" << endl;
              }
          }
          break;
      }
	     // Case to 'LOOK AT <FEATURE>'
      case 9:{
		currentGame->lookAtFeatureCall(input, actionSize);
		break;
	     }

	     // Case to 'MOVE <ROOM>'
      case 10: {
		  moveRoomCall(input, actionSize);
		  break;
	       }

	       // Case to 'EXIT'
      case 11: {
		  if(input.size() > actionSize){
		     cout << "Input not recognized." << endl;
		  }
		  else{
		     cout << "\nExiting game!" << endl;
		     this->gameRunning = false;
		  }
		  break;
	       }
	       // Case to 'DROP <ITEM>'
      case 12:{
		 dropTakeItemCall(input, actionChoice, actionSize);
		 break;
	      }
	      // Case to 'TAKE <ITEM>'
      case 13:{
		 dropTakeItemCall(input, actionChoice, actionSize);
		 break;
	      }
   }
}

/********************************************************************************
  showMap() - displays the map of the game to the user
 **********************************************************************************/
void UI::showMap(){

   //Eventuall have the game class return the player location
   int player_location  = this->currentGame->getCurrentRoomId();

   std::cout << "           ________________________________                                  ________________________________" << std::endl;
   std::cout << "          /                 /              |                                |              \\                 \\" << std::endl;
   std::cout << "         /  ESCAPE POD     /               |                                |               \\                 \\" << std::endl;
   std::cout << "        /   ROOM          X                |                                |                X     REACTOR     \\" << std::endl;

   //Player in Escape Pod
   if(player_location == 0){
      std::cout << "       /        *        /                /                                  \\                \\                 \\" << std::endl;
   }
   //Player in Reactor
   else if(player_location == 1){
      std::cout << "       /                 /                /                                  \\                \\        *        \\" << std::endl;
   }
   else{
      std::cout << "       /                 /                /                                  \\                \\                 \\" << std::endl;
   }

   std::cout << "      /_________________/                /                                    \\                \\_________________\\" << std::endl;
   std::cout << "     /                 /                /                                      \\                \\                 \\" << std::endl;
   std::cout << "    /                 /                /                                        \\                \\                 \\" << std::endl;
   std::cout << "   /    MEDBAY       X                /                                          \\                X    ENGINE BAY   \\" << std::endl;

   //Player in Med Bay
   if(player_location == 2){
      std::cout << "  /        *        /                /                                            \\                \\                 \\" << std::endl;
   }
   //Player in Engine Bay
   else if(player_location == 3){
      std::cout << "  /                 /                /                                            \\                \\        *        \\" << std::endl;
   }
   else{
      std::cout << "  /                 /                /                                            \\                \\                 \\" << std::endl;
   }
   std::cout << " /_________________/                /                                              \\                \\_________________\\" << std::endl;
   std::cout << "|                  |       C       /                                                \\       C       |                  |" << std::endl;
   std::cout << "|                  |       O      /                                                  \\      O       |                  |" << std::endl;
   std::cout << "|   MAINFRAME      X       R      |__________________________________________________|      R       X    CAFETERIA     |" << std::endl;

   //Player in Mainframe
   if(player_location == 4){
      std::cout << "|         *        |       R                                                                R       |                  |" << std::endl;
   }
   //Player in Cafeteria
   else if(player_location == 5){
      std::cout << "|                  |       R                                                                R       |        *         |" << std::endl;
   }
   else{
      std::cout << "|                  |       R                                                                R       |                  |" << std::endl;
   }

   //Player in Corridor 1
   if(player_location == 6){
      std::cout << "|__________________|  *    I                           CORRIDOR 2                           I       |__________________|" << std::endl;
   }
   //Player in Corridor 3
   else if(player_location == 7){
      std::cout << "|__________________|       I                           CORRIDOR 2                           I  *    |__________________|" << std::endl;
   }
   else{
      std::cout << "|__________________|       I                           CORRIDOR 2                           I       |__________________|" << std::endl;
   }

   //Player in Corridor 2
   if(player_location == 8){
      std::cout << "|                  |       D                               *                                D       |                  |" << std::endl;
   }
   else{
      std::cout << "|                  |       D                                                                D       |                  |" << std::endl;
   }
   std::cout << "|                  |       O       __________________________________________________       O       |    CAPTAIN'S     |" << std::endl;
   std::cout << "|  COMMUNICATIONS  X       R      |                                                  |      R       X      LODGE       |" << std::endl;

   //Plyaer in Communications
   if(player_location == 9){
      std::cout << "|        *         |              \\                                                 /               |                  |" << std::endl;
   }
   //Player in Captain's Lodge
   else if(player_location == 10){
      std::cout << "|                  |              \\                                                 /               |        *         |" << std::endl;
   }
   else{
      std::cout << "|                  |              \\                                                 /               |                  |" << std::endl;
   }
   std::cout << "|__________________|       1       \\                                               /        3       |__________________|" << std::endl;
   std::cout << " \\                  \\               \\                                             /                 /                 /" << std::endl;
   std::cout << "  \\                  \\               \\                                           /                 /     LIFE        /" << std::endl;
   std::cout << "   \\    ELECTRICAL    X               \\                                         /                 X     SUPPORT     /" << std::endl;

   //Player in Electrical
   if(player_location == 11){
      std::cout << "    \\         *        \\               \\                                       /                 /        O2       /" << std::endl;
   }
   //Player in LifeSupport O2
   else if(player_location == 12){
      std::cout << "    \\                  \\               \\                                       /                 /     *  O2       /" << std::endl;
   }
   else{
      std::cout << "    \\                  \\               \\                                       /                 /        O2       /" << std::endl;
   }
   std::cout << "     \\__________________\\               \\                                     /                 /_________________/" << std::endl;
   std::cout << "      \\                  \\               \\                                   /                 /                 /" << std::endl;
   std::cout << "       \\                  \\               \\                                 /                 /     STORAGE     /" << std::endl;
   std::cout << "        \\    NAVIGATION    X               |                               |                 /                 /" << std::endl;

   //Player in Navigation
   if(player_location == 13){
      std::cout << "         \\         *        \\              |                               |                /                 /" << std::endl;
   }
   //Player in Storage
   else if(player_location == 14){
      std::cout << "         \\                  \\              |                               |                /         *       /" << std::endl;
   }
   else{
      std::cout << "         \\                  \\              |                               |                /                 /" << std::endl;
   }
   std::cout << "          \\__________________\\_____________|                               |______________ /_________________/" << std::endl;

}

/********************************************************************************
help() - displays all the general commands the player can do
**********************************************************************************/
void UI::help(){

    cout << "\nGeneral Actions:" << endl;
    cout << "LOOK - repeats the long form explanation of the room currently in." << endl;
    cout << "GO TO <ROOM NAME> - navigates to the specific room." << endl;
    cout << "LOOK AT <ITEM/FEATURE NAME> - Gives explanation of the feature or item in the room or inventory.\n"
            "Interact with features in rooms by inputting the Interactive Verbs hinted at using this command." << endl;
    cout << "INVENTORY - lists the contents of your inventory." << endl;
    cout << "TAKE <Item> - picks up an item from the floor." << endl;
    cout << "DROP <Item> - drops an item to the floor." << endl;
    cout << "HELP - lists a set of general actions the game understands." << endl;
    cout << "PAUSE - pauses the countdown timer of the self-destruct until another command is inputted." << endl;
    cout << "MAP - shows the player the map of the space station. (Must be unlocked)" << endl;
    cout << "SAVE GAME - saves the game." << endl;
    cout << "LOAD GAME - loads a previously saved game." << endl;
    cout << "EXIT GAME - stops and exits the game." << endl;

}

/********************************************************************************
moveRoomCall - calls the moveRoom from the game in order to change the character
 room location
**********************************************************************************/
void UI::moveRoomCall(vector<string>input, int actionSize) {

    string roomName = "";
    string tempName = "";
    int roomFoundCount = 0;
    bool roomFound = false;

    // If a Room was used as the action
    if(input.size() == 1){
        // One-word room
        if(rooms.find(input[0]) != rooms.end()){
            roomName = input[0];
            roomFound = true;

        }
    }
    // Two-word room
    else if(input.size() == 2){
        string twoRoom = input[0] + " " + input[1];
        if(rooms.find(twoRoom) != rooms.end()){
            roomName = twoRoom;
            roomFound = true;
        }
    }
    // Three-word room
    else if(input.size() == 3){
        string threeRoom = input[0] + " " + input[1] + " " + input[2];
        if(rooms.find(threeRoom) != rooms.end()){
            roomName = threeRoom;
            roomFound = true;
        }
    }

    // If no room was found as an action
    if(roomFound == false){
        // Check for one-word rooms
        if(input.size() == actionSize+1){
            tempName = input[actionSize];
            if(rooms.find(tempName) != rooms.end()) {
                roomName = tempName;
                roomFoundCount = 1;
            }
        }
            // Check for two-word rooms
        else if(input.size() == actionSize+2){
            tempName = input[actionSize] + " " + input[actionSize+1];
            if(rooms.find(tempName) != rooms.end()) {
                roomName = tempName;
                roomFoundCount = 2;
            }
        }
            // Check for three-word rooms
        else if(input.size() == actionSize+3){
            tempName = input[actionSize] + " " + input[actionSize+1] + " " + input[actionSize+2];
            if(rooms.find(tempName) != rooms.end()) {
                roomName = tempName;
                roomFoundCount = 3;
            }
        }

    }

    // Error if size too big
    if(input.size() > (actionSize + roomFoundCount)){
        cout << "Input not recognized." << endl;
    }
    else{
        currentGame->moveRooms(roomName);
    };
}

/********************************************************************************
dropTakeItemCall -
**********************************************************************************/
void UI::dropTakeItemCall(vector<string> input, int actionChoice, int actionSize) {

    string itemName = "";
    string tempName = "";
    int itemFoundCount = 0;

    // Check for one-word items
    if(input.size() == actionSize+1){
        tempName = input[actionSize];
        if(items.find(tempName) != items.end()) {
            itemName = tempName;
            itemFoundCount = 1;
        }
    }
    // Check for two-word items
    else if(input.size() == actionSize+2){
        tempName = input[actionSize] + " " + input[actionSize+1];
        if(items.find(tempName) != items.end()) {
            itemName = tempName;
            itemFoundCount = 2;
        }
    }
    // Check for three-word items
    else if(input.size() == actionSize+3){
        tempName = input[actionSize] + " " + input[actionSize+1]+ " " + input[actionSize+2];
        if(items.find(tempName) != items.end()) {
            itemName = tempName;
            itemFoundCount = 3;
        }
    }
    // Check for four-word items
    else if(input.size() == actionSize+4){
        tempName = input[actionSize] + " " + input[actionSize+1]+ " " + input[actionSize+2]+ " " + input[actionSize+3];
        if(items.find(tempName) != items.end()) {
            itemName = tempName;
            itemFoundCount = 4;
        }
    }

    // Error if size too big
    if(input.size() > (actionSize + itemFoundCount)){
        cout << "Input not recognized." << endl;
    }
    else if(input.size() == actionSize){
        cout << "Input not recognized." << endl;
    }
    // Call drop/take game functions
    else{
        // Drop item for case 12
        if(actionChoice == 12){
            currentGame->dropItem(itemName);
        }
        // take item for case 13
        else if(actionChoice == 13){
            currentGame->takeItem(itemName);
        }
    }
}

/********************************************************************************
featureActionCall - Parses for the interactive feature action to be passed into the
 game object function.
**********************************************************************************/
void UI::featureActionCall(vector<string> input) {

    // Parse back string vector into one string
    if(input.size()!=0){

        string combinedInput = input[0];
        for(int i = 1; i<input.size();i++){
            combinedInput+= " ";
            combinedInput+= input[i];
        }

        // Call the game function to interact with the feature
        currentGame->interactFeatureCall(combinedInput);
    }
    else{
        cout << "Input not recognized." << endl;
    }
}

/********************************************************************************
pauseGame
**********************************************************************************/
void UI::pauseGame(){
    auto start_time = std::chrono::high_resolution_clock::now();
    std::cout << "\nGame paused. Press ENTER to continue." << std::endl;
    system("read");
    auto current_time = std::chrono::high_resolution_clock::now();
    unsigned long long time_elapsed = std::chrono::duration_cast<std::chrono::seconds>(current_time - start_time).count();
    this->currentGame->addBackPauseTime(time_elapsed);
}

/********************************************************************************
makeLoadGame - creates a game from a load text file
**********************************************************************************/
bool UI::makeLoadGame(){

    /* try to open file to read */
    std::ifstream ifile;
    ifile.open("saveGame.txt");
    // If a txt file exists
    if(ifile) {

        // Close the file
        ifile.close();

        // Make a load game
        cout << "\nLoading existing game!" << endl;
        this->currentGame = new game(true);
        this->gameMade = true;
        return true;
    }
    // There is no txt file
    else {
        return false;
    }
}

/********************************************************************************
loadGameFromRunning - loads an existing game while it is running
**********************************************************************************/
void UI::loadGameFromRunning(){

    // Verify player wants to save the game
    cout << "\nAre you sure you'd like to load previous game?" << endl;
    string input = "";
    std::cout << "Enter choice (Yes/No): ";
    std::getline(cin, input);

    // If the player wants to load the game
    if(input == "YES" || input == "YEs" || input == "Yes" || input == "yeS" || input == "yES" || input == "yes" ) {

        /* try to open file to read */
        std::ifstream ifile;
        ifile.open("saveGame.txt");
        // If a txt file exists
        if (ifile) {

            // Close the file
            ifile.close();

            // Delete game currently running
            free(this->currentGame);

            // Make a load game
            cout << "\nLoading existing game!" << endl;
            this->currentGame = new game(true);
            this->gameMade = true;
        }
            // There is no txt file
        else {
            cout << "\nNo load file exists!" << endl;
        }
    }
        // Player does not want to load the game
    else if(input == "NO" || input == "No" || input == "nO" || input == "no"){

        cout << "\nNot loading game!" << endl;

    }
        // Invalid input
    else{
        cout << "\nInput not recognized." << endl;
    }
}

/*********************************************************************************************************
  destructor
 *******************************************************************/
UI::~UI() {

    // Free the current game
    if(gameMade == true){
        free(this->currentGame);
    }

    // Clear all the unordered maps
    general_actions.clear();
    menu_options.clear();
    rooms.clear();
    items.clear();

}