//
// Created by Stuart on 1/20/2021.
//

#include <iostream>
#include <vector>
// #include <sys/ioctl.h>
#include <stdio.h>
#include <unistd.h>

#include <cstdlib>
#include <memory>
#include <string>

#include "UI.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main(){

    // Check if the console screen size is adequate
    // Reference: https://stackoverflow.com/questions/1022957/getting-terminal-width-in-c
    // struct winsize w;
    // ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    // Need a size of 30x130. Uncomment when finished!
    /*
    if(w.ws_row < 30 || w.ws_col < 130){
        cout << "Please resize console screen to have a minimum 30 width by 130 height!" << endl;
        return 0;
    }
     */

    UI* user_interface = new UI();

    bool continueSim = true; //bool for do-while loop.

    // Acquire whether to play New Game, Load Game, or Exit Game
    int menuChoice1 = user_interface->menuStartUp();

    // Exit game if choice was 3
    // Create a new game for choice 0
    if(menuChoice1 == 0){

        user_interface->makeNewGame();
	    user_interface->selectDifficulty();

    }

    // Load an existing game here
    else if(menuChoice1 == 1){

        bool loadGameMade;
        loadGameMade = user_interface->makeLoadGame();

        // Make a new game if load game couldn't be done
        if(loadGameMade == false){
            cout << "\nNo existing load file found. Starting New Game!\n" << endl;
            user_interface->makeNewGame();
            user_interface->selectDifficulty();
        }
    }
    // Else exit game
    else{
        cout << "Exiting game!" << endl;
        continueSim = false;
        return 0;
    }

    // Continue running the game here, until the play() returns a false.
    do{
     
        continueSim = user_interface->play();

    }while(continueSim == true);

    // Free memory from user_interface
    free(user_interface);

    return 0;

};
