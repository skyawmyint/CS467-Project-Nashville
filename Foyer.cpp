/******************************************************************
Name: Clayton Hewitson
Assignment: Final Project
Date: 12/02/2017
Description: This is the class implementation file for the class Foyer.
It it derives from the parent class Space, and is the first room the player
encounters. It has various methods for searching the room based on the specific
environs.
******************************************************************/

#include "Foyer.hpp"                           //header file for Foyer


/********************************************************************************
default constructor
**********************************************************************************/

Foyer::Foyer()
{
	setName("Foyer of Time Immemorial.");                             //set name of location
	setDescription("This dusty foyer where you have awoken looks as if \n"
		"it has not been occupied in some time. The smell of an ancient tomb hangs in the air. \n"
		"Were it not for the timing of an old grandfather clock the silence would be defeaning. \n"
		"As far as you can tell, there are no visible exits from this room.");

	continuousKey = false;                                          //the key is well hidden indeed
	timePast = false;

	//add items to room to examine

	addItem("the grandfather clock", "You notice the second hand runs backward, the hour hand is stuck, \nand the minute hand runs forward");
	addItem("ancient book", "Is that an Ouroboros symbol on the cover?");
	addItem("photograph of your best friend", "This photo of your best friend depicts her younger than you ever knew her, \na child. She holds a small doll. What is this doing here?");
}

/***************************************************************************************************************************************************
The descision function is called after examine is called in main, allowing the player to further interact with the objects in the Space. Various actions
are taken here depended upon player choice and if certain items are within the Player's possession.
********************************************************************************************************************************************************/

void Foyer::decision(int choiceIn, bool trigger, Player* playIn)
{
	if (choiceIn == 1 && getItem(choiceIn)->getTrigger() == false && trigger == false)                               //check if various conditions met
	{
		cout << getItem(choiceIn)->getDescription() << endl;                                                       //generic description
	}
	else if (choiceIn == 1 && getItem(choiceIn)->getTrigger() == false && trigger == true)                           //actions taken
	{
		getItem(choiceIn)->setDescription("All hands now point to the witching hour of midnight, or is noon? \nRegardless the clock face swings open, "
			"revealing a key with the symbol of the Triskelion upon it.");
		cout << getItem(choiceIn)->getDescription() << endl;
		cout << endl;
		cout << "You reach forward to take the key." << endl;

		if (playIn->checkInventory() == true)
		{
			cout << "The key remains untouched, shadows dancing upon it." << endl;
			cout << "The clock face closes again with a soft click, but does not lock." << endl;
		}
		else
		{
			playIn->addItem("Triskelion Key", "This appears to be the Key to the Door of Continuous");
			cout << "The clock face closes again with a soft click, locking." << endl;
			getItem(choiceIn)->setDescription("All hands now point to the witching hour of midnight, or is noon?");
			getItem(choiceIn)->setTrigger(true);
			continuousKey = true;
		}
	}
	else if (choiceIn == 1 && getItem(choiceIn)->getTrigger() == true)                                        //item taken
	{
		cout << getItem(choiceIn)->getDescription() << endl;                                                 //new generic description
	}
	else if (choiceIn == 2 && getItem(choiceIn)->getTrigger() == false)                                        //opens path forward
	{
		cout << getItem(choiceIn)->getDescription() << endl;
		cout << "You open the ancient book, all of it's pages are empty save one. It reads:" << endl;
		cout << "When time appears to run both forward and back, it is simpler to remember you are then at a standstill." << endl;
		cout << "The walls before you begin to shift and shimmer, and three exits appear where there were none before." << endl;
		cout << "You return the book to it's previous resting place." << endl;
		getItem(choiceIn)->setTrigger(true);
		timePast = true;
	}
	else if (choiceIn == 2 && getItem(choiceIn)->getTrigger() == true)
	{
		cout << getItem(choiceIn)->getDescription() << endl;
		cout << "You open the ancient book, all of it's pages are empty save one. It reads:" << endl;
		cout << "When time appears to run both forward and back, it is simpler to remember you are then at a standstill." << endl;
		cout << "You return the book to it's previous resting place." << endl;
	}
	else if (choiceIn == 3 && getItem(choiceIn)->getTrigger() == false)
	{
		cout << getItem(choiceIn)->getDescription() << endl;
		cout << "As you gaze at the photo, the image of your best friend slowly fades away, leaving nothing." << endl;
		getItem(choiceIn)->setDescription("There is nothing now but an empty photograph");
		getItem(choiceIn)->setTrigger(true);
	}
	else if (choiceIn == 3 && getItem(choiceIn)->getTrigger() == true)
	{
		cout << getItem(choiceIn)->getDescription() << endl;
	}
}

/**************************************************************************************************************
getStatus returns the current bool associated the room, used by the Dungeon class to determine if a certain rooms
functions have been altered or items taken in some way. It takes a bool as an argument and returns nothing.
**************************************************************************************************************/

bool Foyer::getStatus()

{
	return continuousKey;                                                    //returns the continuous key
}

/**************************************************************************************************************
getTime returns the current bool associated the room, used by the Dungeon class to determine if a certain rooms
functions have been altered or items taken in some way. It takes a bool as an argument and returns nothing.
In this case it indicates if the foyer can be successfully exited
**************************************************************************************************************/

bool Foyer::getTime()

{
	return timePast;                                                    //returns the bool for exiting foyer
}