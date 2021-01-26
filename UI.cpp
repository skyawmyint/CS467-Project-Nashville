#include <iostream>
#include <algorithm>
#include <sstream>

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

   general_actions.insert({ "LOOK", 0 });
   general_actions.insert({ "HELP", 1 });
   general_actions.insert({ "INVENTORY", 2 });
   general_actions.insert({ "SAVEGAME", 3 });
   general_actions.insert({ "LOADGAME", 4 });
   general_actions.insert({ "TIME", 5 });
   general_actions.insert({ "PAUSE", 6 });
   general_actions.insert({ "UNPAUSE", 7 });
   general_actions.insert({ "MAP", 8 });
   general_actions.insert({ "LOOK AT", 9 });

   // Case 10 - GO
   general_actions.insert({ "GO", 10 });
   general_actions.insert({"GO TO", 10 });
   
   rooms.insert({"ESCAPE POD ROOM", 10});
   rooms.insert({"MEDBAY",10});
   rooms.insert({"MAINFRAME ROOM" , 10});
   rooms.insert({"COMMUNICATION", 10});
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


   general_actions.insert({ "EXIT GAME", 11 });

   
   menu_options.insert({"NEW", 0});
   menu_options.insert({"LOAD", 1});
   menu_options.insert({"EXIT", 2});

  /* rooms.insert("ESCAPE POD ROOM");
   rooms.insert("MEDBAY");
   rooms.insert("MAINFRAME ROOM");
   rooms.insert("COMMUNICATION");
   rooms.insert("ELECTRICAL");
   rooms.insert("NAVIGATION");
   rooms.insert("CORRIDOR 1");
   rooms.insert("CORRIDOR 2");
   rooms.insert("CORRIDOR 3");
   rooms.insert("REACTOR");
   rooms.insert("ENGINE BAY");
   rooms.insert("CAFETERIA");
   rooms.insert("CAPTAIN'S LODGE");
   rooms.insert("LIFE SUPPORT O2");
   rooms.insert("STORAGE");
*/

   gameRunning = true;

}

/********************************************************************************
destructor
**********************************************************************************/
UI::~UI() {}



/********************************************************************************
menuStartUp() - prompts the user if  they would like to create a New Game, Load
 Game, or Exit game. This will then return an int value back to main.
**********************************************************************************/
int UI::menuStartUp()
{
   int retChoice = -1;

   cout << "|----------------------------|" << endl;
   cout << "|     Project Nashville      |" << endl;
   cout << "|----------------------------|" << endl;
   cout << "|          New game          |" << std::endl; //0
   cout << "|          Load game         |" << std::endl; //1
   cout << "|          Exit game         |" << std::endl; //2
   cout << "|----------------------------|" << endl;
   cout << endl;

   std::vector<std::string> input = getInput();

   while(retChoice == -1){
      //Valid menu optio
      //0: new game
      //1: load Game
      //2: exit game
      if(menu_options.find(input[0]) != menu_options.end()){
          retChoice = menu_options[input[0]];
          break;
      }
      if(retChoice == -1){
        std::cout << "Invalid input." << std::endl;
        input = getInput();
    }
   }
   return retChoice;
}



/********************************************************************************
makeNewGame() - creates a new game object if the user selects New Game
**********************************************************************************/
void UI::makeNewGame() {

    // Create new game object
    currentGame = new game();

}


/********************************************************************************
getInput() -
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

    // Get user input
    std::vector<std::string> input = getInput();

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
    if(inputChoice >=0 && inputChoice <= 11){
        generalActions(input, inputChoice, generalActionStringSize);
    }
    else{
        cout << "Input not recognized." << endl;
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

void UI::generalActions(vector<string> input, int actionChoice, int actionSize){

   switch(actionChoice){

       // Case to 'LOOK'
       case 0: {
           currentGame->lookDescription();
           break;
       }

      case 1:
	 help();
	 break;
      case 2:
	 break;
      case 3:
	 break;
      case 4:
	 break;
      case 5:
	 break;
      case 6:
	 break;
      case 7:
	 break;
      case 8:
	 showMap();
	 break;
      case 9:
          cout << "We made it to the LOOK AT branch!" << endl;
	 break;

	 // Case to move rooms
      case 10: {
          moveRoomCall(input, actionSize);
          break;
      }

	 // Case to exit the game
      case 11:
          cout << "Exiting game now." << endl;
          this->gameRunning = false;
	 break;

   }
}


void UI::showMap(){

   std::cout << "print ASCII art of Map" << std::endl;

}

void UI::help(){
   for(auto command : general_actions){
      if(command.first == "GO"){
	 continue;
      }
      std::cout << command.first;
      if(command.first == "GO TO"){
	 std::cout << " <ROOM>";
      }
      else if(command.first == "LOOK AT"){
	 std::cout <<" <OBJECT>";
      }
      std::cout << std::endl;
   }
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
combineRoomItemName - takes in a vector of a parsed string input and finds a
 Room or Item name and combines and returns it into a single string
**********************************************************************************/
string UI::combineRoomItemName(vector<string> input) {

    // Setup the return string variable
    string newString = "BAD INPUT";

    // Flag to break if a room was found
    bool roomItemFound = false;

    // Go through all the indexes
    for(int i = 0; i < input.size(); i++){

        // Work with one-word rooms
        if(rooms.find(input[i]) != rooms.end()) {
            newString = input[i];
            roomItemFound = true;
        }

        // Work with two-word rooms
        if(i < input.size()-1){
            string tempString = input[i] + " " +input[i+1];
            if(rooms.find(tempString) != rooms.end()){
                newString = tempString;
                roomItemFound = true;
            }
        }

        // Work with three-word rooms
        if(i < input.size()-2){
            string tempString = input[i] + " " +input[i+1] + " " + input[i+2];
            if(rooms.find(tempString) != rooms.end()){
                newString = tempString;
                roomItemFound = true;
            }
        }

        if(roomItemFound == true){
            break;
        }
    }

    // Add something for Item




    return newString;

}










/*
   std::vector<Room*> loadRooms(){

   Load room files and return a Rooms vec to Game?
   start with instantiating with items current in room

   }
   */



/*void saveRoomFiles(std::vector<Room*> rooms, int time = -1){
  If timer does not equal -1, timer is not disabled
  store curr_time to file and timer state to a game file
  Read out room files?
  Room files have vector of Items
  Iterate through Items to store file
  Different room states ?
  }*/
