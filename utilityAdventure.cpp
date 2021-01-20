/*************************************************************
Name: Clayton Hewitson
Assignment: Final Project
Date: 12/02/2017
Description: This is the function definition for the function utility.
It is a list of helper functions with a wide variety of input validation
uses to be used in this and future labs and projects.
****************************************************************/

#include "utilityAdventure.hpp"
#include <iostream>
#include <string>
#include <sstream>

using std::cin;
using std::cout;
using std::endl;

using std::string;


/*************************************************************************************
checkIntMinMax is a utility function that checks a. if the user input is an int and
b. if said int is greater than than or equal to a certain min and less than or equal to a certain max.
If either of these conditions fails, the function asks the user to input again.
It takes one strings and two ints for test input, the min and max, and returns an int.
If just one int is passed, it sets one as the max, and the function sets a default paramater min of zero.
****************************************************************************************/


int checkIntMinMax(string testIntIn, int maxIn, int minIn)
{
	int max = maxIn;                                   //max and min to test against
	int min = minIn;

	string intTest = testIntIn;                             //string in to test
	int retInt = 0;                                        //int to return
	bool badString = true;                                  //to test string conversion



	while (badString)
	{
		std::stringstream convert(intTest);

		if ((convert >> retInt) && !(convert >> intTest) && (retInt >= min) && (retInt <= max))          //check all parameters
		{
			badString = false;                                       //only end loop if int is returned
		}
		else                                                            //loop repeats
		{
			cout << endl;
			cout << "Choice must be one of the available option numbers." << endl;
			cout << "to total number of times or quit." << endl;
			cout << "Please choose again:" << endl;
			std::getline(cin, intTest);
			cout << endl;
		}
	}

	return retInt;
}

/********************************************************************************
checkSelection2 is a utility funtion that checks if a user input matches certain
predetermined choice selections, and asks the user to reenter their selection if
it does not. It returns an int and takes a string.
*******************************************************************************/


int checkSelection2(string selectIn)
{

	const int ONE = 1;
	const int TWO = 2;                      //to test against input

	string test = selectIn;                           //string in to test
	int retSize = 0;                                        //int to return
	bool badString = true;                                  //to test string conversion


	while (badString)
	{
		int length = test.length();
		std::stringstream convert(test);

		if ((length == 1) && (convert >> retSize) && !(convert >> test) && (retSize == ONE) || (retSize == TWO))     //check all parameters
		{
			badString = false;                                   //only end loop if 1, is returned
		}
		else                                                            //loop repeats
		{
			cout << endl;
			cout << "Choice must be one of the following for starting or quitting Time Immemorial. " << endl;
			cout << "Please choose again, selecting '1' or '2':" << endl;
			cout << "1. Start Time Immemorial" << endl;
			cout << "2. Quit" << endl;
			std::getline(cin, test);
		}
	}

	return retSize;
}


/********************************************************************************
checkSelection3 is a utility funtion that checks if a user input matches certain
predetermined choice selections, and asks the user to reenter their selection if
it does not. It returns an int and takes a string.
*******************************************************************************/


int checkSelection3(string selectIn)
{

	const int ONE = 1;
	const int TWO = 2;
	const int THREE = 3;                         //to test against input

	string test = selectIn;                           //string in to test
	int retSize = 0;                                        //int to return
	bool badString = true;                                  //to test string conversion


	while (badString)
	{
		int length = test.length();
		std::stringstream convert(test);

		if ((length == 1) && (convert >> retSize) && !(convert >> test) && ((retSize == ONE || retSize == TWO) || (retSize == THREE)))     //check all parameters
		{
			badString = false;                                   //only end loop if 1,2 or 3 is returned
		}
		else                                                            //loop repeats
		{
			cout << endl;
			cout << "Choice must be one of the following." << endl;
			cout << "Please choose again, selecting '1', '2', or '3':" << endl;
			cout << "Whose name do you wish to write within the Death Note?" << endl;
			cout << "1. Your name" << endl;
			cout << "2. The old woman's." << endl;
			cout << "3. No thanks, this is getting weird." << endl;
			std::getline(cin, test);
		}
	}

	return retSize;
}

/********************************************************************************
checkSelection3a is a utility funtion that checks if a user input matches certain
predetermined choice selections, and asks the user to reenter their selection if
it does not. It returns an int and takes a string.
*******************************************************************************/


int checkSelection3a(string selectIn)
{

	const int ONE = 1;
	const int TWO = 2;
	const int THREE = 3;                         //to test against input

	string test = selectIn;                           //string in to test
	int retSize = 0;                                        //int to return
	bool badString = true;                                  //to test string conversion


	while (badString)
	{
		int length = test.length();
		std::stringstream convert(test);

		if ((length == 1) && (convert >> retSize) && !(convert >> test) && ((retSize == ONE || retSize == TWO) || (retSize == THREE)))     //check all parameters
		{
			badString = false;                                   //only end loop if 1,2 or 3 is returned
		}
		else                                                            //loop repeats
		{
			cout << endl;
			cout << "Choice must be one of the following." << endl;
			cout << "Please choose again, selecting '1', '2', or '3':" << endl;
			cout << "What do you wish to do in this location?" << endl;
			cout << "1. Examine Space" << endl;
			cout << "2. Move to new location" << endl;
			cout << "3. Inventory backpack" << endl;
			std::getline(cin, test);
		}
	}

	return retSize;
}

/********************************************************************************
checkSelection5 is a utility funtion that checks if a user input matches certain
predetermined choice selections, and asks the user to reenter their selection if
it does not. It returns an int and takes a string. It used for setting the user
chosen direction.
*******************************************************************************/


int checkSelection5(string selectIn)
{

	const int ONE = 1;
	const int TWO = 2;
	const int THREE = 3;                         //to test against input
	const int FOUR = 4;
	const int FIVE = 5;

	string test = selectIn;                           //string in to test
	int retSize = 0;                                        //int to return
	bool badString = true;                                  //to test string conversion


	while (badString)
	{
		int length = test.length();
		std::stringstream convert(test);

		if ((length == 1) && (convert >> retSize) && !(convert >> test) && (((((retSize == ONE || retSize == TWO) || (retSize == THREE))) || (retSize == FOUR) || (retSize == FIVE))))     //check all parameters
		{
			badString = false;                                   //only end loop if 1,2 or 3 is returned
		}
		else                                                            //loop repeats
		{
			cout << endl;
			cout << "Choice must be one of the following for movement. " << endl;
			cout << "Please choose again, selecting '1', '2', '3', '4', or '5':" << endl;
			cout << "1. north" << endl;
			cout << "2. south" << endl;
			cout << "3. east" << endl;
			cout << "4. west" << endl;
			cout << "5. Nah, I'm good where I'm at." << endl;
			std::getline(cin, test);
		}
	}

	return retSize;
}