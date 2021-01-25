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
   general_actions.insert({ "GO", 10 });
   general_actions.insert({ "EXIT", 11 });

   
   menu_options.insert({"NEW", 0});
   menu_options.insert({"LOAD", 1});
   menu_options.insert({"EXIT", 2});

   rooms.insert("ESCAPE POD ROOM");
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
      for(int i = 0; i<input.size(); i++){
          if(menu_options.find(input[i]) != menu_options.end()) {
              retChoice = menu_options[input[i]];
          }
      // if(menu_options.find(input[0]) != menu_options.end()){
	 // retChoice = menu_options[input[0]];
	 // break;
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
      std::cout << "Enter choice: ";
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
    bool inputFound = false;
    int inputChoice = -1;

    // Check for each input index
    for(int i = 0; i < input.size(); i++){

        // Work with one-word actions
        if(general_actions.find(input[i]) != general_actions.end()) {
            inputChoice = general_actions[input[i]];
            inputFound = true;
        }

        // Work with two-word actions
        if(i < input.size()-1){
            string tempString = input[i] + " " +input[i+1];
            if(general_actions.find(tempString) != general_actions.end()){
                inputChoice = general_actions[tempString];
            }
        }
        // Break if an input was found
        if(inputFound == true){
            break;
        }

    }

    // Do the input action
    if(inputFound == true){
        generalActions(input, inputChoice);
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

void UI::generalActions(vector<string> input, int actionChoice){

   switch(actionChoice){
      case 0:
          cout << "We made it to the LOOK branch!"<< endl;
	 break;
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
          string roomInputName = combineRoomItemName(input);
          currentGame->moveRooms(roomInputName);
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
      std::cout << command.first << std::endl;
   }
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
