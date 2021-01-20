/*****************************************************************
Name: Clayton Hewitson
Assignment: Final Project
Date: 12/04/2017
Description: This is the class specification header file that
contains the class declaration for the class FuturePerfect.
It declares all our member variables and member function prototypes.
******************************************************************/




#ifndef FUTUREPERFECT_HPP                         //include guard to prevent duplicate header file inclusion
#define FUTUREPERFECT_HPP                         //defines the header file as FuturePerfect_HPP


#include "Space.hpp"

using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::shared_ptr;
using std::make_shared;

class FuturePerfect : public Space
{
private:
	bool victory;
	bool guestbook;
	bool flowers;

public:
	FuturePerfect();                                            //constructor
	bool getStatus();                                                  //bool for victory achieved
	void decision(int choiceIn, bool trigger, Player* playIn);         //method for player interaction in room
};
#endif   

