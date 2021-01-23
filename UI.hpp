
#ifndef UI_HPP
#define UI_HPP

#include <string>
#include <vector>
#include <unordered_map>
class UI {

   private:
      std::unordered_map<std::string, int> general_actions;

      void getInput();
      std::vector<std::string> parseClean(std::string);
      void generalActions(std::vector<std::string> input);
      void showMap();
      void help();

   public:
      UI();
      ~UI();
};
#endif
