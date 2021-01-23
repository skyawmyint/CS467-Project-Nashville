
#ifndef UI_HPP
#define UI_HPP

#include <string>
#include <vector>
#include <unordered_map>

class UI {

   private:
      std::unordered_map<std::string, int> general_actions;
      std::unordered_map<std::string, int> menu_options;

      std::vector<std::string> getInput();
      std::vector<std::string> parseClean(std::string);
      void generalActions(std::vector<std::string> input);
      void showMap();
      void help();

   public:
     int menuStartUp();
     void play();
      UI();
      ~UI();
};
#endif