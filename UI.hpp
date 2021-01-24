
#ifndef UI_HPP
#define UI_HPP

#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include "game.hpp"

class UI {

   private:

      game* currentGame;
      std::unordered_map<std::string, int> general_actions;
      std::unordered_map<std::string, int> menu_options;
      std::unordered_set<std::string> rooms;

      std::vector<std::string> getInput();
      std::vector<std::string> parseClean(std::string);
      void generalActions(std::vector<std::string> input);
      void showMap();
      void help();
      void moveRoom(std::vector<std::string> input);


   public:
     int menuStartUp();
     void play();
      UI(game* currentGame);
      ~UI();
};
#endif
