//
// Created by Stuart on 1/20/2021.
//

#include <iostream>
#include <vector>
#include <cstdlib>
#include <memory>
#include <string>

#include "character.hpp"
#include "item.hpp"
#include "room.hpp"
#include "game.hpp"
#include "UI.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;


int main(){

    bool continueSim = true; //bool for do-while loop.

    game* currentGame;

    // Acquire whether to play New Game, Load Game, or Exit Game
    int menuChoice1 = menuStartUp();

    // Exit game if choice was 3
    // Create a new game for choice 1
    if(menuChoice1 == 0){

        // Set new game stats here!
        currentGame = new game();

        // Since it will be new game, output description of first room
        currentGame->currentRoomDescription();

    }

    // Load an existing game here
    else if(menuChoice1 == 1){

        cout << "Load game has not been implemented yet. Sorry!" << endl;
        continueSim = false;
        return 0;

    }
    // Else exit game
    else{
        cout << "Exiting game!" << endl;
        continueSim = false;
        return 0;
    }

    // Run the game here!
    do{

        // Get input from  the user
        string getInput;
        cout << ": ";
        std::getline(cin, getInput);

        // Write something here to parse all the words in the string. Maybe into an array?

        // TEMP CODE HERE JUST TO SEE IF MOVEMENT IS WORKING. Just type the room name. All CAPS
        currentGame->moveRooms(getInput);

        // Write something to exit game
        if(getInput == "EXIT GAME"){
            continueSim = false;
        }

    }while(continueSim == true);


    return 0;

};
