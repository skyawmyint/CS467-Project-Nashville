/******************************************************************
Name: Clayton Hewitson
Assignment: Final Project
Date: 12/04/2017
Description: This is the main file for the Final project adventure game,
"Time Immemorial." It handles all the heavy lifting of the game's instantiation,
and all function calls are controlled from here.
******************************************************************/


#include <iostream>
#include <vector>
#include <cstdlib>
#include <memory>
#include <string>
#include "Dungeon.hpp"                                                    //include header file for Dungeon
#include "menuAdventure.hpp"
#include "utilityAdventure.hpp"


using std::cin;
using std::cout;
using std::endl;

using std::string;

int main() 
{
	bool continueSim = true;                                                      //bool for do-while loop.
	const int CHOICE_ONE = 1;                                                     //constant ints for menu compares
	const int CHOICE_TWO = 2;
	const int CHOICE_THREE = 3;

	int playSim = menuStartUp();                                                 //asks user if they wish to run simulation

	do {

		if (playSim == CHOICE_ONE)                                             //Time Immemorial will be played
		{
			cout << endl;
			cout << "Welcome to Time Immorial, a text-based adventure." << endl;
			cout << "Here you have awoken in an unknown space and must attempt" << endl;
			cout << "to determine where you are and how to escape by acquiring items" << endl;
			cout << "to progress from room to room. The theme of the adventure is a meditation" << endl;
			cout << "on Time and Death, so keep that in mind should you get stuck." << endl;
			cout << "Press enter to continue." << endl;
			cin.get();

			string getName;
			cout << "Please enter a name for your adventurer." << endl;
			std::getline(cin, getName);

			Player* player1 = new Player(getName);                              //create new player

			Dungeon timeDungeon(player1);                                        //create dungeon, passing player

			player1 = NULL;

			int playerChoice = 0;                                                //playerChoice for option menus
			int move = 0;                                                         //hold player movement
			int exam = 0;                                                   //specific int for examine option

			cout << endl;

			if (menuChoice("FOR TESTING PURPOSES ONLY: Do you wish to know victory conditions? (y/n)  "))              //if specific victory conditions needed for testing
			{
				cout << "Get to the final room, the FuturePerfect of Time Immemorial, ";
				cout << "with the following items: Flowers, Doll, and Pen";
				cout << endl;
			}

			cout << endl;
			cin.ignore();
			cout << "Please press enter to begin the adventure." << endl;
			cin.get();
			
			cout << "You have awoken in a strange place of unknown origin." << endl;
			cout << "Your head is pounding, and you have no idea how you got here" << endl;
			cout << "or where you are. You have become a figure out of time and space." << endl;
			cout << "You reach for the only light source available, a lit torch in a sconce nearby." << endl;
			cout << endl;
			
			while (timeDungeon.getPosition() != NULL && timeDungeon.getPlayer()->getTorch() > 0 && !timeDungeon.getVictory())              //loop for gameplay, a null, a loss of torch, or victory condition will end game
			{
				cout << "You are in the " << timeDungeon.getPosition()->getName() << endl;                                          //shows current space name, description, and torchLight remaining
				cout << timeDungeon.getPosition()->getDescription() << endl;
				cout << endl;
				cout << "Torchlight remaining: " << timeDungeon.getPlayer()->getTorch() << endl;
				int torchIn = timeDungeon.getPlayer()->getTorch();
				int maxTorchIn = timeDungeon.getPlayer()->getMaxTorch();
				timeDungeon.getPosition()->torchCount(torchIn, maxTorchIn);
				                                                                              
				playerChoice = menuOptions();                                                                                       //menu of possible room actions, examine objects, move, or check backpack

			
				if (playerChoice == CHOICE_ONE)                                                                                          //choice 1 chosen, examine room
				{
					int itemCount = timeDungeon.getPosition()->examine();
					while (exam != itemCount && timeDungeon.getPlayer()->getTorch() > 0 && !timeDungeon.getVictory())
					{
						string itemChoice;
																										//while loop and if statement oterates through room options, only decrementing torch on search
						std::getline(cin, itemChoice);
						exam = checkIntMinMax(itemChoice, itemCount);
						cout << endl;
						if (exam != itemCount)
						{
							timeDungeon.getPosition()->decision(exam, timeDungeon.getTrig(), timeDungeon.getPlayer());
							cout << endl;
							timeDungeon.getPlayer()->decrementTorch();
							cout << "Torchlight remaining: " << timeDungeon.getPlayer()->getTorch() << endl;
							int torchIn = timeDungeon.getPlayer()->getTorch();
							int maxTorchIn = timeDungeon.getPlayer()->getMaxTorch();
							timeDungeon.getPosition()->torchCount(torchIn, maxTorchIn);
							int falseCount = timeDungeon.getPosition()->examine();
						}
					}
			                                                                
					exam = 0;
					cout << endl;
					cout << endl;

					                                                                                                        // if subsequent routes must be unlocked
					if (timeDungeon.getPast() && !timeDungeon.getAdded(1))
					{
						timeDungeon.addSimple();
					}
					if (timeDungeon.getFuture() && !timeDungeon.getAdded(2))
					{
						timeDungeon.addFuture();
					}
					if (timeDungeon.getEnd() && !timeDungeon.getAdded(3))
					{
						timeDungeon.addEnd();
					}
				}
				else if (playerChoice == CHOICE_TWO)                                                                               //enter another Space
				{
					bool acceptableMove = false;                                                                                  //ensure NULL move is not attempted

					do {

						timeDungeon.printSpaces();
						move = menuWhichDirection();                                                                           //choose which direction to move

						if (move == 5)                                                                                         //changed mind on movement
						{
							acceptableMove = true;
						}
						else if (timeDungeon.movePlayer(move) == true)                                                          //move is possible
						{
							acceptableMove = true;
							cout << "You move yourself, cautiously mind you, into the next space." << endl;
							timeDungeon.getPlayer()->decrementTorch();
						}
						else if (timeDungeon.movePlayer(move) == false)                                                       //move is not possible
						{
							cout << "You cannot move where there is no exit. Please look closer." << endl;
							cout << endl;
						}
					
					} while (acceptableMove == false);

					timeDungeon.removePast();                                                                          //remove simple rooms if FutureContinuous reached
					timeDungeon.removePresent();                                                                          //remove FutureContinuous if FuturePerfect reached
					cout << endl;
					cout << endl;
				}
				else if (playerChoice == CHOICE_THREE)                                                                            //inventory backpack, max of three items
				{
					timeDungeon.getPlayer()->useItems();
					cout << endl;
					cout << endl;
				}
				if (timeDungeon.getPlayer()->getTorch() < 1)                                                                             //should your journey end, a dismal fate
				{
					cout << "As your torch slowly sputters to nothing, the pitch darkness of this place envelops you." << endl;
					cout << "Lost in your own head you dream eternal, as strange sounds envelop your senses, turning your lost soul to ash." << endl;
					cout << "This journey has ended..." << endl;
					cout << endl;
				}
				else if (timeDungeon.getVictory())                                                                                                 //you have reached understanding of your grief
				{
					cout << "At least here you were able to say goodbye, even if it were just a dream. Opening your eyes, you awaken..." << endl;
					cout << "This journey has ended..." << endl;
					cout << endl;
				}
			}
			
			int simAgain = menuStartUp2();                                        //ask user if they wish to run simulation again

			if (simAgain == CHOICE_ONE)                                             //if yes, run again
			{
				continueSim;
			}
			else if (simAgain == CHOICE_TWO)                                       //if no, set bool for do-while loop to false
			{
				continueSim = false;
			}
		}
		else if (playSim == CHOICE_TWO)
		{
			continueSim = false;
		}
	
	} while (continueSim == true);
	
	return 0;
}