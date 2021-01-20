/*************************************************************
Name: Clayton Hewitson
Assignment: Final Project
Date: 12/02/2017
Description: This is the prototype header file for the function
menuAdventure.cpp. It's a helper file for all menu selection options
****************************************************************/


#ifndef MENUADVENTURE_HPP            
#define MENUADVENTURE_HPP

#include <string>
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

using std::string;

bool menuChoice(string display);
int menuDeathNote();
int menuStartUp();
int menuStartUp2();
int menuOptions();
int menuWhichDirection();

#endif  
