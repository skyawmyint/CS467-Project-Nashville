/*****************************************************************
Name: Clayton Hewitson
Assignment: Final Project
Date: 11/30/2017
Description: This is the class specification header file that
contains the class declaration for the class DUNGEON.
It declares all our member variables and member function prototypes.
******************************************************************/




#ifndef DUNEGON_HPP                         //include guard to prevent duplicate header file inclusion
#define DUNEGON_HPP                         //defines the header file as DUNGEON_HPP

#include <stddef.h>
#include <iostream>
#include <string>
#include <vector>
#include <memory>

#include "Space.hpp"
#include "Player.hpp"
#include "Foyer.hpp"
#include "SimplePast.hpp"
#include "SimplePresent.hpp"
#include "SimpleFuture.hpp"
#include "FutureContinuous.hpp"
#include "FuturePerfect.hpp"


using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::shared_ptr;
using std::make_shared;

class Dungeon
{
private:
	Space* position;                                     //pointer to current player position;
	Player* theVagrant;                                    //player characer in building

	Space* simplePast;                                      //pointer to simplePast space
	Space* simplePresent;                                      //pointer to simplePresent space
	Space* simpleFuture;                                      //pointer to simpleFuture space
	Space* futureContinuous;                                      //pointer to futureContinous space
	Space* futurePerfect;                                      //pointer to futurePerfect space
	Space* foyer;                                                //pointer to foyer space

	bool timePast;                                                //bools to test various structural damages to time Space
	bool timePresent;
	bool timeFuture;

public:
	Dungeon(Player* pIn);                                        //constructor
	void setPosition(Space* spaceIn);                           //set current and starting position of Player
	Space* getPosition() const;                                    //get the current position of Player in the building
	void setPlayer(Player* playerIn);                             //set the current player passed from main into dungeon
	Player* getPlayer() const;                                   //return the current player character from the dungeon
	bool movePlayer(int directionIn);                            //moves the player in the corresponding direction of not NULL
	void printSpaces();                                          //prints all the rooms adjacent to the player
	bool getTrig();                                              //keeps track of various changes added to Spaces
	bool getPast();                                              //keeps track of whether foyer doors have been opened
	void addSimple();                                             //connects the foyer to the other rooms
	bool getFuture();                                              //keeps track of whether future locked door has been opened
	void addFuture();                                              //opens locked door beyond SimpleFuture Room
	bool getEnd();                                                  //keeps track of whether final area has been unlocked
	void addEnd();                                                   //allows entry to final area
	void removePast();                                              //removes the past once simpleFuture door has been walked through
	void removePresent();                                            //removes the past once continuousFuture door walked through
	bool getAdded(const int& i);                                    //tracks what has been added to Dungeon
	bool getVictory();                                              //tracks if victory achieved
	~Dungeon();                                               //destructor
};
#endif       

