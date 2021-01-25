
#ifndef UI_HPP
#define UI_HPP

#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include "game.hpp"
#include "utilityFunctions.hpp"

using std::vector;
using std::string;

class UI {

   private:

      game* currentGame;
      bool gameRunning; // Flag to see if the game is ever to exit.

      std::unordered_map<std::string, int> general_actions;
      std::unordered_map<std::string, int> menu_options;
      std::unordered_set<std::string> rooms;


      std::vector<std::string> getInput();
      std::vector<std::string> parseClean(std::string);
      void generalActions(vector<string> input, int actionChoice);
      void showMap();
      void help();
      string combineRoomItemName(vector<string>input);


   public:
     int menuStartUp();
     void makeNewGame();
     // void makeLoadGame();
     bool play();
      UI();
      ~UI();
};
#endif
