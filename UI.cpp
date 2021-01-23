#include <iostream>
#include <algorithm>
#include <sstream>

#include "UI.hpp"


UI::UI() {
   general_actions.insert({ "look", 0 });
   general_actions.insert({ "help", 1 });
   general_actions.insert({ "inventory", 2 });
   general_actions.insert({ "savegame", 3 });
   general_actions.insert({ "loadgame", 4 });
   general_actions.insert({ "time", 5 });
   general_actions.insert({ "pause", 6 });
   general_actions.insert({ "unpause", 7 });
   general_actions.insert({ "map", 8 });
   general_actions.insert({ "look", 9 });
   general_actions.insert({ "go", 10 });
   general_actions.insert({ "exit", 11 });

   menu_options.insert({"new", 0});
   menu_options.insert({"load", 1});
   menu_options.insert({"exit", 2});

}
UI::~UI() {}

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
   }
   return retChoice;
}

std::vector<std::string> UI::getInput(){
   std::string input = "";

   while(input.empty()){
      std::cout << "Enter choice: ";
      if(!std::getline(std::cin, input)){
	       //IO ERROR
        return {};
      }
      if(!input.empty()){
        std::vector<std::string> input_vec = parseClean(input);
        return input_vec;
      }
   }
   return {};
}

void UI::play(){
   std::vector<std::string> input = getInput();
   if(general_actions.find(input[0]) != general_actions.end()){
      generalActions(input);
   }
}

//Convert everything to lowercase and tokenize
std::vector<std::string> UI::parseClean(std::string str){
   std::transform(str.begin(), str.end(), str.begin(), ::tolower);

   std::istringstream ss(str);
   std::string word;
   std::vector<std::string> input;

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
	 break;
      case 11:
	 break;

   }
}


void UI::showMap(){

   //print ASCII art of Map

}

void UI::help(){
   for(auto command : general_actions){
      std::cout << command.first << std::endl;
   }
}



// dummy
int main(){
   return 0;
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
