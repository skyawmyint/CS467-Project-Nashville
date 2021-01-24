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

   /*startMenuOptions.push_back("NEW");
   startMenuOptions.push_back("LOAD");
   startMenuOptions.push_back("EXIT");*/


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

   rooms.insert("ESCAPE POD");
   rooms.insert("MED BAY");
   rooms.insert("MAIN FRAME");
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

   std::cout << "Welcome to Project Nashville" << std::endl;
   std::cout << "New game" << std::endl; //0
   std::cout << "Load game" << std::endl; //1
   std::cout << "Exit game" << std::endl; //2

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
      std::cout << "Invalid input." << std::endl;
      input = getInput();
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
	 moveRoom(input);
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

void UI::moveRoom(std::vector<std::string>input){
   std::string room_name = "";
   if(input.size() > 1) {
      for(int i = 1; i < input.size(); i++){
	 if(input[i] != "TO"){
	    if(room_name.length() < 1){
	       room_name = input[i];
	    }
	    else {
	       room_name = room_name + " " + input[i];
	    }
	 }
      }
   }
   std::cout << room_name << std::endl; 
   if(input.size() > 1 && rooms.find(room_name) != rooms.end()){
    //  std::cout << room_name << " found." << std::endl;
      currentGame->moveRooms(room_name);

   } else {
      std::cout << "Invalid command." << std::endl;
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
