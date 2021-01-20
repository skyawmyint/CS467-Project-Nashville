/*****************************************************************
Name: Clayton Hewitson
Assignment: Final Project
Date: 12/04/2017
Description: This is the class specification header file that
contains the class declaration for the class FutureContinuous.
It declares all our member variables and member function prototypes.
******************************************************************/




#ifndef FUTURECONTINUOUS_HPP                         //include guard to prevent duplicate header file inclusion
#define FUTURECONTINUOUS_HPP                         //defines the header file as FutureContinuous_HPP


#include "Space.hpp"

using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::shared_ptr;
using std::make_shared;

class FutureContinuous : public Space
{
private:
	bool timeFuture;                                                  //determine if doors to next area open
	int paintingCount;                                                //ensure all paintings viewed

public:
	FutureContinuous();                                            //constructor
	void decision(int choiceIn, bool trigger, Player* playIn);         //method for player interaction in room
	bool getFuture();                                          //returns bool based on if room has been altered
};
#endif   
