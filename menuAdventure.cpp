/*************************************************************
Name: Clayton Hewitson
Assignment: Final Project
Date: 12/02/2017
Description: This is the function definition for the function menuAdventure.
It is a list of menu functions to be used in this and future labs and projects.
****************************************************************/


#include "menuAdventure.hpp"
#include "utilityAdventure.hpp"
#include <iostream>
#include <string>
#include <sstream>


using std::cin;
using std::cout;
using std::endl;

using std::string;



/**********************************************************************************************
menuChoice simply takes a passed string to display as a question, and then prompts the user for a yes or
no answer. Any answer besides a "Y" or "y" or "yes" or "yes" will cause the bool to return false.
If any of the proceeding are chosen it will return true. The bool responses are used to determine
further program executions.
***********************************************************************************************/

bool menuChoice(string display)
{
	string choice;

	cout << display;
	cin >> choice;

	if (choice == "y" || choice == "Y" || choice == "yes" || choice == "Yes")
	{
		return true;
	}
	else
	{
		return false;
	}
}


/*******************************************************************************************
menuStartup runs when the program begins, asking the user if they would like to simulate
the adventure game or quit.
It takes no parameters and returns an int.
********************************************************************************************/

int menuStartUp()
{
	int retInt = 0;
	string getChoice;

	cout << "Hello, welcome to Time Immemorial, a text-based adventure game." << endl;
	cout << "Please choose one of the following options by entering the corresponding number." << endl;
	cout << "1. Start Time Immemorial" << endl;
	cout << "2. Quit" << endl;
	std::getline(cin, getChoice);
	retInt = checkSelection2(getChoice);
	cout << endl;

	return retInt;
}

/*******************************************************************************************
menuStartup2 runs when the program ends, asking the user if they would like to simulate
Time Immemorial or quit.
It takes no parameters and returns an int.
********************************************************************************************/

int menuStartUp2()
{
	int retInt = 0;
	string getChoice;

	cout << "Would you like to explore Time Immemorial again?" << endl;
	cout << "Please choose one of the following options by entering the corresponding number." << endl;
	cout << "1. Start Time Immemorial." << endl;
	cout << "2. Quit" << endl;
	std::getline(cin, getChoice);
	retInt = checkSelection2(getChoice);
	cout << endl;

	return retInt;
}

/****************************************************************************
menuOptions is a menu function that asks the user which option they wish to run from a 
choice of three whenever they are in a room. Examine, move, or check backpack.
After the choice is verifed and checked, it is then returned.
It takes no paramaters and returns an int.
*******************************************************************************/

int menuOptions()
{
	int retDirect = 0;
	string inDirect;

	cout << "What do you wish to do in this location?" << endl;
	cout << "1. Examine Space" << endl;
	cout << "2. Move to new location" << endl;
	cout << "3. Inventory backpack" << endl;
	std::getline(cin, inDirect);
	retDirect = checkSelection3a(inDirect);
	cout << endl;

	return retDirect;
}

/****************************************************************************
menuDeathNote is a menu function that asks the user whom they would like to use the Death Note on.
After the choice is verifed and checked, it is then returned.
It takes no paramaters and returns an int.
*******************************************************************************/

int menuDeathNote()
{
	int retDirect = 0;
	string inDirect;

	cout << "Whose name do you wish to write within the Death Note?" << endl;
	cout << "1. Your name" << endl;
	cout << "2. The old woman's." << endl;
	cout << "3. No thanks, this is getting weird." << endl;
	std::getline(cin, inDirect);
	retDirect = checkSelection3(inDirect);
	cout << endl;

	return retDirect;
}

/****************************************************************************
menuWhichDirection is a menu function that asks the user which specific direction they
would wish to travel. After the choice is verifed and checked,
it is then returned. It takes no paramaters and returns an int. This function is only
called if the user chooses to position the ant personally, instead of a fixed or random
position.
*******************************************************************************/

int menuWhichDirection()
{
	int retDirect = 0;
	string inDirect;

	cout << "Please choose one of the following directions to move." << endl;
	cout << "1. north" << endl;
	cout << "2. south" << endl;
	cout << "3. east" << endl;
	cout << "4. west" << endl;
	cout << "5. Nah, I'm good where I'm at." << endl;
	std::getline(cin, inDirect);
	retDirect = checkSelection5(inDirect);
	cout << endl;

	return retDirect;
}