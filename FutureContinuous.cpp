/******************************************************************
Name: Clayton Hewitson
Assignment: Final Project
Date: 12/03/2017
Description: This is the class implementation file for the class FutureContinuous.
It it derives from the parent class Space, and is the first room the player
encounters. It has various methods for searching the room based on the specific
environs.
******************************************************************/

#include "FutureContinuous.hpp"                           //header file for FutureContinuous


/********************************************************************************
default constructor
**********************************************************************************/

FutureContinuous::FutureContinuous()
{
	setName("FutureContinuous of Time Immemorial.");                             //set name of location
	setDescription("This room is a long hallway that seems to stretch to no end. \n"
		"Paintings line the sides of both walls, figures half hidden in the fading shadows. \n"
		"A single torch burns in a socket about halfway down the hall.");

	timeFuture = false;
	paintingCount = 0;

	//add items to room to examine

	addItem("Painting of Girl", "This painting is of a young girl in a pretty dress, holding a doll.");
	addItem("Painting of Woman", "It's the same woman as the photograph from the foyer. She's beautiful.");
	addItem("Painting of Old Woman", "It is a painting of the old woman from the previous room, radiant though and smiling.");
	addItem("Painting of Deceased Woman", "It is a painting of a deceased middle-aged woman, pale, gaunt, and striking.");
	addItem("Torch in Sconce", "It burns feebly, but you can probably swap torches with it.");
}

/***************************************************************************************************************************************************
The descision function is called after examine is called in main, allowing the player to further interact with the objects in the Space. Various actions
are taken here depended upon player choice and if certain items are within the Player's possession.
********************************************************************************************************************************************************/

void FutureContinuous::decision(int choiceIn, bool trigger, Player* playIn)
{
	cout << paintingCount << endl;
	if (paintingCount == 3 && !timeFuture)                                      //if all paintings looked at
	{
		cout << "You hear the gentle tingle of faraway laughter. " << endl;
		cout << "Suddenly you can make out the end of the hall. An open door awaits." << endl;
		cout << endl;
		timeFuture = true;
	}
	if (choiceIn == 1 && getItem(choiceIn)->getTrigger() == false)                               //check if various conditions met
	{
		cout << getItem(choiceIn)->getDescription() << endl;
		cout << "The girl looks so alive and filled with joy. Her eyes sparkle." << endl;
		cout << "You never knew her during this time. Only, much, much later did you meet." << endl;
		cout << "But she would tell you stories of her childhood, in the west." << endl;
		getItem(choiceIn)->setDescription("This painting is of a young girl in a pretty dress, holding a familiar doll.");
		getItem(choiceIn)->setTrigger(true);
		paintingCount++;
	}
	else if (choiceIn == 1 && getItem(choiceIn)->getTrigger() == true)                               //check if various conditions met
	{
		cout << getItem(choiceIn)->getDescription() << endl;
	}
	else if (choiceIn == 2 && getItem(choiceIn)->getTrigger() == false)
	{
		cout << getItem(choiceIn)->getDescription() << endl;
		cout << "Ah yes, this is when you knew her. The woman in the painting is dressed in frontier woman's dress." << endl;
		cout << "It was in college when you met, before the sickness. Her hair was the rays of the sun caught." << endl;
		cout << "Her eyes were the skies reflected. The dress, the dress is from a play she was in of the West." << endl;
		getItem(choiceIn)->setDescription("It's the same woman as the photograph from the foyer. She's hunating.");
		getItem(choiceIn)->setTrigger(true);
		paintingCount++;
	}
	else if (choiceIn == 2 && getItem(choiceIn)->getTrigger() == true)
	{
		cout << getItem(choiceIn)->getDescription() << endl;
	}
	else if (choiceIn == 3 && getItem(choiceIn)->getTrigger() == false)
	{
		cout << getItem(choiceIn)->getDescription() << endl;
		cout << "Why do I recognize this old woman now, and not before only minutes ago?" << endl;
		cout << "Because she never saw this joy of the grace of old age, not for her, never her." << endl;
		cout << "Her name was written in the Death Note before you were born, as is yours." << endl; 
		getItem(choiceIn)->setDescription("It is a painting of the old woman from the previous room. It is difficult to meet her gaze.");
		getItem(choiceIn)->setTrigger(true);
		paintingCount++;
	}
	else if (choiceIn == 3 && getItem(choiceIn)->getTrigger() == true)
	{
		cout << getItem(choiceIn)->getDescription() << endl;
	}
	else if (choiceIn == 4 && getItem(choiceIn)->getTrigger() == false)
	{
		cout << getItem(choiceIn)->getDescription() << endl;
		cout << "You never went to her funeral." << endl;
		cout << "True, your setpdad had injured himself the day before, a ready-made excuse." << endl;
		cout << "But that wasn't the whole truth now was it?" << endl;
		getItem(choiceIn)->setDescription("It is a painting of a deceased middle-aged woman, pale, gaunt, and striking. A tear rests on her cheek.");
		getItem(choiceIn)->setTrigger(true);
		paintingCount++;
	}
	else if (choiceIn == 4 && getItem(choiceIn)->getTrigger() == true)
	{
		cout << getItem(choiceIn)->getDescription() << endl;
	}
	if (choiceIn == 5 && getItem(choiceIn)->getTrigger() == false)                               //check if various conditions met
	{
		cout << getItem(choiceIn)->getDescription() << endl;
		cout << "Given the opportunity, you decide to do so." << endl;
		cout << "It's not much, but better than what you had." << endl;
		getItem(choiceIn)->setDescription("You have taken the torch from the wall.");
		getItem(choiceIn)->setTrigger(true);
		playIn->addTorch(15);
	}
	else if (choiceIn == 5 && getItem(choiceIn)->getTrigger() == true)                               //check if various conditions met
	{
		cout << getItem(choiceIn)->getDescription() << endl;
	}
}


/**************************************************************************************************************
getFuturereturns the current bool associated the room, used by the Dungeon class to determine if a certain rooms
functions have been altered or items taken in some way. It takes a bool as an argument and returns nothing.
In this case it indicates if the SimpleFuture can be successfully exited
**************************************************************************************************************/

bool FutureContinuous::getFuture()

{
	return timeFuture;                                                    //returns the bool for exiting FutureContinuous
}