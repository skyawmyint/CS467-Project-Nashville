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

    startMenuOptions.push_back("NEW GAME");
    startMenuOptions.push_back("LOAD GAME");
    startMenuOptions.push_back("EXIT GAME");


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

   /*
   menu_options.insert({"NEW GAME", 0});
   menu_options.insert({"LOAD GAME", 1});
   menu_options.insert({"EXIT GAME", 2});
*/

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
    cout << "Welcome to Project Nashville" << endl;
    cout << "New game" << endl; //0
    cout << "Load game" << endl; //1
    cout << "Exit game" << endl; //2

    while(retChoice == -1){
        // Valid menu option
        //0: new game
        //1: load Game
        //2: exit game
        vector<string> input = getInput();
        if(input.size() > 1){
            string check = input[0] + " " + input[1];
            for(int i = 0; i<startMenuOptions.size(); i++) {
                if(check == startMenuOptions[i]) {
                    retChoice = i;
                }
            }
        }
        if(retChoice == -1){
            cout << "Invalid input." << endl;
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

    // Since it will be new game, output description of first room
    currentGame->currentRoomDescription();

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

    std::vector<std::string> input = getInput();

    if(general_actions.find(input[0]) != general_actions.end()){
      generalActions(input);
    } else {
        std::cout << "Input not recognized." << std::endl;
    }
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

void UI::generalActions(std::vector<std::string> input){

   switch(general_actions[input[0]]){
      case 0:
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
	 break;
      case 10:
	 if(input.size() > 1 && rooms.find(input[1]) != rooms.end()){
	    currentGame->moveRooms(input[1]);
	 }
	 break;
      case 11:
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
