/*************************************************************
Name: Clayton Hewitson
Assignment: Final Project
Date: 12/02/2017
Description: This is the prototype header file for the function
utilityAdventure.cpp. It's a helper file for intput validation
****************************************************************/


#ifndef UTILITYADVENTURE_HPP            
#define UTILITYADVENTURE_HPP

#include <string>

using std::string;

int checkIntMinMax(string testIntIn, int MaxIn, int MinIn = 1);
int checkSelection2(string selectIn);
int checkSelection3(string selectIn);
int checkSelection3a(string selectIn);
int checkSelection5(string selectIn);


#endif  

