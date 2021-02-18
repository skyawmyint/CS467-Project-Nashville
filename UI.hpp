
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
      std::unordered_map<std::string, int> rooms;
      std::unordered_set<std::string> items;
      std::vector<std::string> parseClean(std::string);
      void generalActions(vector<string> input, int actionChoice, int actionSize);
      void showMap();
      void help();
      void moveRoomCall(vector<string>input, int actionSize);
      void dropTakeItemCall(vector<string> input, int actionChoice, int actionSize);
      void featureActionCall(vector<string>input);
    void pauseGame();

   public:
     std::vector<std::string> getInput();
     int menuStartUp();
     void makeNewGame();
     void selectDifficulty();
     // void makeLoadGame();
     bool play();
      UI();
      ~UI();
};
#endif
