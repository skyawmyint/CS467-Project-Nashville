/******************************************************************
Name: Clayton Hewitson
Assignment: Final Project
Date: 12/02/2017
Description: This is the class implementation file for the class SimplePast.
It it derives from the parent class Space, and is the first room the player
encounters. It has various methods for searching the room based on the specific
environs.
******************************************************************/

#include "SimplePast.hpp"                           //header file for SimplePast


/********************************************************************************
default constructor
**********************************************************************************/

SimplePast::SimplePast()
{
	setName("SimplePast of Time Immemorial.");                             //set name of location
	setDescription("This room resembles that of a young girl's, a child's. \n"
		"Scattered about are various toys and knicknacks, old clothes, a rocking horse in the corner. \n"
		"The room is lit only by a twirling lamp, casting the shadows of stars about the walls.");

	doll = false;                                         
	dollMoves = false;
	timeContinuous = false;
																	//add items to room to examine

	addItem("the rocking horse", "It remains perfectly still.");
	addItem("twirling lamp", "The shade of the lamp features a constellation unknown to you.");
	addItem("young girl's doll", "This doll looks somewhat familiar, or perhaps not.");
}

/***************************************************************************************************************************************************
The descision function is called after examine is called in main, allowing the player to further interact with the objects in the Space. Various actions
are taken here depended upon player choice and if certain items are within the Player's possession.
********************************************************************************************************************************************************/

void SimplePast::decision(int choiceIn, bool trigger, Player* playIn)
{
	if (choiceIn == 1 && getItem(choiceIn)->getTrigger() == false)                               //check if various conditions met
	{
		cout << getItem(choiceIn)->getDescription() << endl;
	}
	else if (choiceIn == 1 && getItem(choiceIn)->getTrigger() == true)                               //check if various conditions met
	{
		getItem(choiceIn)->setDescription("The rocking horse now sways gently back and forth, to and fro.\nYou half expect it to neigh.");
		cout << getItem(choiceIn)->getDescription() << endl;
	}
	else if (choiceIn == 2 && getItem(choiceIn)->getTrigger() == false)
	{
		cout << getItem(choiceIn)->getDescription() << endl;
		cout << "As you examine the lamp, you barely graze against it. \nIt suddenly goes out, forcing you to light your torch even brighter.\n"
		"From some dark corner of the room you believe you hear movement." << endl;
		getItem(choiceIn)->setDescription("The lamp will not turn back on, no matter how often you plug and unplug it.");
		playIn->addTorch(-2);
		getItem(choiceIn)->setTrigger(true);
	}
	else if (choiceIn == 2 && getItem(choiceIn)->getTrigger() == true)
	{
		cout << getItem(choiceIn)->getDescription() << endl;
	}
	else if (choiceIn == 3 && getItem(choiceIn)->getTrigger() == false && dollMoves == false)
	{
		cout << getItem(choiceIn)->getDescription() << endl;
		cout << "As you reach your hands towards the doll, it suddenly jumps up, coming alive, and scurries about the room!\n"
			"As the doll flees it bangs against the rocking horse." << endl;
		getItem(choiceIn)->setDescription("The doll has vanished!");
		dollMoves = true;
		getItem(1)->setTrigger(true);
	}
	else if (choiceIn == 3 && getItem(choiceIn)->getTrigger() == false && trigger == false && dollMoves == true)
	{
		cout << getItem(choiceIn)->getDescription() << endl;
	}
	else if (choiceIn == 3 && getItem(choiceIn)->getTrigger() == false && trigger == true && dollMoves == true)
	{
		cout << "As you search about for the runaway doll, you get a strange idea..." << endl;
		if (menuChoice("Do you want to use your lollipop? (y/n)   "))
		{
			cout << endl;
			cin.ignore();
			cout << "As you hold the lollipop out, the doll emerges curious from the shadows, and comes ever closer." << endl;
			cout << "You reach forward to take the doll." << endl;

			if (playIn->checkInventory() == true)
			{
				cout << "The doll remains untouched, and quickly scurries away." << endl;
			}
			else
			{
				playIn->addItem("young girl's doll", "This doll looks somewhat familiar, or perhaps not.");
				playIn->removeItem(playIn->searchItems("lollipop"));
				getItem(choiceIn)->setDescription("The doll has vanished!");
				getItem(choiceIn)->setTrigger(true);
				doll = true;																		//acquired doll
				timeContinuous = true;
				cout << endl;
				cout << "In the distance, you hear the chime of a clock toll once." << endl;
			}
		}
		else
		{
			cout << endl;
			cin.ignore();
		}
	}
	else if (choiceIn == 3 && getItem(choiceIn)->getTrigger() == true)                                        //item taken
	{
		cout << getItem(choiceIn)->getDescription() << endl;                                                 //new generic description
	}
}

/**************************************************************************************************************
getStatus returns the current bool associated the room, used by the Dungeon class to determine if a certain rooms
functions have been altered or items taken in some way. It takes a bool as an argument and returns nothing.
**************************************************************************************************************/

bool SimplePast::getStatus()

{
	return doll;                                                    //returns the continuous key
}

/**************************************************************************************************************
getTime returns the current bool associated the room, used by the Dungeon class to determine if a certain rooms
functions have been altered or items taken in some way. It takes a bool as an argument and returns nothing.
In this case it indicates if the SimplePast can be successfully exited
**************************************************************************************************************/

bool SimplePast::getTime()

{
	return timeContinuous;                                                    //returns the bool for exiting SimplePast
}