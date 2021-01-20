/*****************************************************************
Name: Clayton Hewitson
Assignment: Final Project
Date: 12/02/2017
Description: This is the class specification header file that
contains the class declaration for the class SimpleFuture.
It declares all our member variables and member function prototypes.
******************************************************************/




#ifndef SIMPLEFUTURE_HPP                         //include guard to prevent duplicate header file inclusion
#define SIMPLEFUTURE_HPP                         //defines the header file as SIMPLEFUTURE_HPP


#include "Space.hpp"

using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::shared_ptr;
using std::make_shared;

class SimpleFuture : public Space
{
private:
	bool lollipop;                                             //lollipop needed for other room, can be taken
	bool timeContinuous;                                                  //1/3 of determining if clock face will open
	bool timeFuture;                                             //return if door is opened
	bool pen;                                                    //needed for this room
	bool oldWoman;                                              //check if old woman still in room

public:
	SimpleFuture();                                            //constructor
	bool getStatus();                            //returns bool based on if room has been permanently altered
	void decision(int choiceIn, bool trigger, Player* playIn);         //method for player interaction in room
	bool getTime();                                          //returns bool based on if room has been altered
	bool getFuture();                                         //returns bool based on if door at end can be opened
	bool getOldWoman();                                        //returns bool for OldWoman
};
#endif   
