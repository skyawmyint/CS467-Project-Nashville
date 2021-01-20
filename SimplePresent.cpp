/******************************************************************
Name: Clayton Hewitson
Assignment: Final Project
Date: 12/02/2017
Description: This is the class implementation file for the class SimplePresent.
It it derives from the parent class Space, and is the first room the player
encounters. It has various methods for searching the room based on the specific
environs.
******************************************************************/

#include "SimplePresent.hpp"                           //header file for SimplePresent


/********************************************************************************
default constructor
**********************************************************************************/

SimplePresent::SimplePresent()
{
	setName("SimplePresent of Time Immemorial.");                             //set name of location
	setDescription("This room is that of a college or post-graduate student. \n"
		"The environs are tidy and neat, with a small table, and impressive shelf of numerous books. \n"
		"A low fire burns in a fireplace against the far wall, but your torch lights most of the room.");

	deathNote = false;
	timeContinuous = false;
	
	//add items to room to examine

	addItem("fireplace", "It burns low, casting little light, but hot.");
	addItem("Death Note", "It contains many strange rules and instructions for causing the deaths of others. One page left.");
	addItem("elegant note", "The handwriting on this note is exquisite.");
}

/***************************************************************************************************************************************************
The descision function is called after examine is called in main, allowing the player to further interact with the objects in the Space. Various actions
are taken here depended upon player choice and if certain items are within the Player's possession.
********************************************************************************************************************************************************/

void SimplePresent::decision(int choiceIn, bool trigger, Player* playIn)
{
	if ((playIn->getTorch() <= playIn->getMaxTorch() * .40) && !timeContinuous)                                      //if torch dim enough
	{
		cout << "The fire in the fireplace goes out with a whoosh." << endl;
		cout << "The room is so dim now you almost can't see your hand in front of your face, yet in the distance a clock chimes once. " << endl;
		cout << endl;
		getItem(1)->setTrigger(true);                                                                         //unlock time continuous, fire goes out
		getItem(1)->setDescription("The fire place has gone out, leaving just a trail of smoke.");
		timeContinuous = true;
	}
	if (choiceIn == 1 && getItem(choiceIn)->getTrigger() == false)                               //check if various conditions met
	{
		cout << getItem(choiceIn)->getDescription() << endl;
		cout << "Given the opportunity, you decide to relight your torch." << endl;
		cout << "The room brightens considerably." << endl;
		playIn->addTorch(3);
	}
	else if (choiceIn == 1 && getItem(choiceIn)->getTrigger() == true)                               //check if various conditions met
	{
		cout << getItem(choiceIn)->getDescription() << endl;
	}
	else if (choiceIn == 2 && getItem(choiceIn)->getTrigger() == false)
	{
		cout << getItem(choiceIn)->getDescription() << endl;
		cout << "This book of occult curses may be useful in this strange place. You decide to take it." << endl;
		if (playIn->checkInventory() == true)
		{
			cout << "You decide to come back later for the Death Note." << endl;
		}
		else
		{
			playIn->addItem("Death Note", "It contains many strange rules and instructions for causing the deaths of others. One page left.");
			getItem(choiceIn)->setDescription("Where is the Death Note? That's right, you took it.");
			getItem(choiceIn)->setTrigger(true);
			deathNote = true;												//acquired deathNote
		}
	}
	else if (choiceIn == 2 && getItem(choiceIn)->getTrigger() == true)
	{
		cout << getItem(choiceIn)->getDescription() << endl;
	}
	else if (choiceIn == 3 && getItem(choiceIn)->getTrigger() == false)                                        
	{
		cout << getItem(choiceIn)->getDescription() << endl;
		cout << "You read, and the words chill you. It reads:" << endl;
		cout << "'Why do I sit here, having just received this terrible news? I should be cherishing every moment" << endl;
		cout << "Yet I sit lost in reverie, what foolishness. Memories fade. And future? I no longer have one" << endl;
		cout << "Our eyes lie. The truth of the present is cloaked in darkness.'" << endl;
		cout << "You return the letter back to the table." << endl;
		getItem(choiceIn)->setDescription("The note's words make you feel very strange, melancholy.");
		getItem(choiceIn)->setTrigger(true);
	}
	else if (choiceIn == 3 && getItem(choiceIn)->getTrigger() == true)
	{
		cout << getItem(choiceIn)->getDescription() << endl;
		cout << "It reads:" << endl;
		cout << "'Why do I sit here, having just received this terrible news? I should be cherishing every moment" << endl;
		cout << "Yet I sit lost in reverie, what foolishness. Memories fade. And future? I no longer have one" << endl;
		cout << "Our eyes lie. The truth of the present is cloaked in darkness.'" << endl;
		cout << "You return the letter back to the table." << endl;
	}
}

/**************************************************************************************************************
getStatus returns the current bool associated the room, used by the Dungeon class to determine if a certain rooms
functions have been altered or items taken in some way. It takes a bool as an argument and returns nothing.
**************************************************************************************************************/

bool SimplePresent::getStatus()

{
	return deathNote;                                                    //returns the continuous key
}

/**************************************************************************************************************
getTime returns the current bool associated the room, used by the Dungeon class to determine if a certain rooms
functions have been altered or items taken in some way. It takes a bool as an argument and returns nothing.
In this case it indicates if the SimplePresent can be successfully exited
**************************************************************************************************************/

bool SimplePresent::getTime()

{
	return timeContinuous;                                                    //returns the bool for exiting SimplePresent
}