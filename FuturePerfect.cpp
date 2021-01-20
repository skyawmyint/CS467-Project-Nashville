/******************************************************************
Name: Clayton Hewitson
Assignment: Final Project
Date: 12/03/2017
Description: This is the class implementation file for the class FuturePerfect.
It it derives from the parent class Space, and is the first room the player
encounters. It has various methods for searching the room based on the specific
environs.
******************************************************************/

#include "FuturePerfect.hpp"                           //header file for FuturePerfect


/********************************************************************************
default constructor
**********************************************************************************/

FuturePerfect::FuturePerfect()
{
	setName("FuturePerfect of Time Immemorial.");                             //set name of location
	setDescription("This room is that of a wake or viewing. \n"
		"Flowers line the walls and are piled atop the floor. Their scent fills the air. \n"
		"There is a guestbook near the door, and at the far side of the room, rests an open casket.");

	victory = false;
	flowers = false;
	guestbook = false;

	//add items to room to examine

	addItem("flowers", "They smell of heaven.");
	addItem("guestbook" ,"There is room for more signatures at the bottom.");
	addItem("casket", "There is someone resting, still inside.");
}

/***************************************************************************************************************************************************
The descision function is called after examine is called in main, allowing the player to further interact with the objects in the Space. Various actions
are taken here depended upon player choice and if certain items are within the Player's possession.
********************************************************************************************************************************************************/

void FuturePerfect::decision(int choiceIn, bool trigger, Player* playIn)
{

	if (choiceIn == 1 && getItem(choiceIn)->getTrigger() == false)                               //check if various conditions met
	{
		cout << getItem(choiceIn)->getDescription() << endl;
		cout << "You don't think anyone would mind if you took some flowers to pay your respects." << endl;
		if (playIn->checkInventory() == true)
		{
			cout << "You put the flowers back. Maybe now is not the time." << endl;
		}
		else
		{
			playIn->addItem("flowers", "They smell of heaven.");
			getItem(choiceIn)->setDescription("There are many more flowers about, but you already have some.");
			getItem(choiceIn)->setTrigger(true);
			flowers = true;												//acquired deathNote
		}
	}
	else if (choiceIn == 1 && getItem(choiceIn)->getTrigger() == true)                               //check if various conditions met
	{
		cout << getItem(choiceIn)->getDescription() << endl;
	}
	else if (choiceIn == 2 && getItem(choiceIn)->getTrigger() == false)
	{
		cout << getItem(choiceIn)->getDescription() << endl;
		if (menuChoice("Do you wish to sign the guestbook? (y/n)   "))
		{
			cout << endl;
			cin.ignore();
			playIn->removeItem(playIn->searchItems("pen"));
			cout << "You sign the guestbook, leaving your pen by its side." << endl;
			getItem(choiceIn)->setDescription("Your signature now rests at the end of the guestbook.");
			getItem(choiceIn)->setTrigger(true);
			guestbook = true;
		}
		else
		{
			cout << endl;
			cin.ignore();
			cout << "You decide now is not the time, but why not?" << endl;
		}
	}
	else if (choiceIn == 2 && getItem(choiceIn)->getTrigger() == true)
	{
		cout << getItem(choiceIn)->getDescription() << endl;
	}
	else if (choiceIn == 3 && getItem(choiceIn)->getTrigger() == false)
	{
		cout << getItem(choiceIn)->getDescription() << endl;
		cout << "With trembling feet you walk towards the open casket and peer inside." << endl;
		cout << "There lays your friend, exactly as she was in the picture in the hall before, pale and stark." << endl;
		cout << "You turn away quickly, it is too much to bear, wiping the tears from your eyes." << endl;
		cout << "You must find a way to pay your respects. Perhaps you already have the tools, perhaps not." << endl;
		getItem(choiceIn)->setDescription("Your best friend lays inside, still but not asleep.");
		getItem(choiceIn)->setTrigger(true);
	}
	else if (choiceIn == 3 && getItem(choiceIn)->getTrigger() == true && (flowers == false || guestbook == false))
	{
		cout << getItem(choiceIn)->getDescription() << endl;
		cout << "You turn away quickly from the casket. Where are all the other mourners?" << endl;
	}
	else if (choiceIn == 3 && getItem(choiceIn)->getTrigger() == true && flowers == true && guestbook == true)
	{
		cout << getItem(choiceIn)->getDescription() << endl;
		cout << "You kneel before the casket, hands held in prayer. A silent muttering is all that escapes your lips." << endl;
		cout << "You feel there is something you could leave for the casket." << endl;

		if (playIn->searchItems("flowers") != -1)
		{
			if (menuChoice("Will you leave the flowers? (y/n)   "))
			{
				cout << endl;
				cin.ignore();
				playIn->removeItem(playIn->searchItems("flowers"));
				cout << endl;
				cout << "You place the flowers gently at the foot of the casket, and return to praying." << endl;
			}
			else
			{
				cout << endl;
				cin.ignore();
				cout << "You rise, returning to your feet." << endl;
			}
		}
		if (playIn->searchItems("flowers") == -1)
		{
			cout << endl;
			cout << "Your best friend lies there, willow-like as if in a dream. Her hands are clasped lightly about her chest." << endl;
			cout << "You feel there is something you can give her now." << endl;
			if (menuChoice("Do you want to use your doll (y/n)   "))
			{
				cout << endl;
				cin.ignore();
				playIn->removeItem(playIn->searchItems("young girl's doll"));
				cout << endl;
				cout << "You place the doll on the chest of your best friend." << endl;
				cout << "For a brief moment the doll stirs, alive again, and snuggles closer." << endl;
				cout << "And then your tears come, streaming down your face, one coming to rest on her cheek." << endl;
				cout << "When the cancer took her, you were just a mere fragment in her life, a backseat to so many other things." << endl;
				cout << endl;
				cout << "What was the start of all this? When did the cogs of fate begin to turn?" << endl;
				cout << "Perhaps it is impossible to grasp that answer now, from deep within the flow of Time" << endl;
				cout << "But, for a certainty, back then, We loved so many, yet hated so much, We hurt others and were hurt ourselves..." << endl;
				cout << "Yet even then we ran like the wind, Whilst our laughter echoed, Under cerulean skies..." << endl;
				victory = true;
			}
			else
			{
				cout << endl;
				cin.ignore();
				cout << "You rise, returning to your feet." << endl;
			}
		}
	}

}

/**************************************************************************************************************
getStatus returns the current bool associated the room, used by the Dungeon class to determine if a certain rooms
functions have been altered or items taken in some way. It takes a bool as an argument and returns nothing.
**************************************************************************************************************/

bool FuturePerfect::getStatus()

{
	return victory;                                                    //returns the lollipop
}
