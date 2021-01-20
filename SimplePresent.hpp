/*****************************************************************
Name: Clayton Hewitson
Assignment: Final Project
Date: 12/02/2017
Description: This is the class specification header file that
contains the class declaration for the class SimplePresent.
It declares all our member variables and member function prototypes.
******************************************************************/




#ifndef SIMPLEPRESENT_HPP                         //include guard to prevent duplicate header file inclusion
#define SIMPLEPRESENT_HPP                         //defines the header file as SIMPLEPRESENT_HPP


#include "Space.hpp"

using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::shared_ptr;
using std::make_shared;

class SimplePresent : public Space
{
private:
	bool deathNote;                                             //deathNote needed for other room, can be taken
	bool timeContinuous;                                                  //1/3 of determining if clock face will open

public:
	SimplePresent();                                            //constructor
	bool getStatus();                            //returns bool based on if room has been permanently altered
	void decision(int choiceIn, bool trigger, Player* playIn);         //method for player interaction in room
	bool getTime();                                          //returns bool based on if room has been altered
};
#endif   
