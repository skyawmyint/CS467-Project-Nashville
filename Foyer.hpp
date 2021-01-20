/*****************************************************************
Name: Clayton Hewitson
Assignment: Final Project
Date: 12/02/2017
Description: This is the class specification header file that
contains the class declaration for the class FOYER.
It declares all our member variables and member function prototypes.
******************************************************************/




#ifndef FOYER_HPP                         //include guard to prevent duplicate header file inclusion
#define FOYER_HPP                         //defines the header file as FOYER_HPP


#include "Space.hpp"

using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::shared_ptr;
using std::make_shared;

class Foyer : public Space
{
private:
	bool continuousKey;                                             //key for the next area, hidden
	bool timePast;                                                  //opens foyer doors if book has been read

public:
	Foyer();                                            //constructor
	bool getStatus();                            //returns bool based on if room has been permanently altered
	void decision(int choiceIn, bool trigger, Player* playIn);         //method for player interaction in room
	bool getTime();                                          //returns bool based on if room has been altered
};
#endif       

