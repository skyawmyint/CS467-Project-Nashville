/******************************************************************
Name: Clayton Hewitson
Assignment: Final Project
Date: 12/02/2017
Description: This is the class implementation file for the class SimpleFuture.
It it derives from the parent class Space, and is the first room the player
encounters. It has various methods for searching the room based on the specific
environs.
******************************************************************/

#include "SimpleFuture.hpp"                           //header file for SimpleFuture


/********************************************************************************
default constructor
**********************************************************************************/

SimpleFuture::SimpleFuture()
{
	setName("SimpleFuture of Time Immemorial.");                             //set name of location
	setDescription("This room is that of an old woman, yet still tidy and prim. \n"
		"The environs smell of mothballs however, and the wood in the floors and walls creaks and moans. \n"
		"In the corner sits an old woman in a rocking chair, gently moving back and forth.");

	lollipop = false;
	pen = false;
	timeContinuous = false;
	timeFuture = false;
	oldWoman = true;

	//add items to room to examine

	addItem("door", "At the far end is a locked door, marked with a Triskelion symbol.");
	addItem("pen", "Not much to say about this, it works.");
	addItem("old woman", "She looks like someone you know.");
}

/***************************************************************************************************************************************************
The descision function is called after examine is called in main, allowing the player to further interact with the objects in the Space. Various actions
are taken here depended upon player choice and if certain items are within the Player's possession.
********************************************************************************************************************************************************/

void SimpleFuture::decision(int choiceIn, bool trigger, Player* playIn)
{
	
	if (choiceIn == 1 && getItem(choiceIn)->getTrigger() == false && oldWoman == true)                               //check if various conditions met
	{
		cout << getItem(choiceIn)->getDescription() << endl;
		cout << "You try to jimmy the door handle, no avail, it will not budge." << endl;
	}
	else if (choiceIn == 1 && getItem(choiceIn)->getTrigger() == false && oldWoman == false && trigger == false)                               //check if various conditions met
	{
		cout << getItem(choiceIn)->getDescription() << endl;
		cout << "You try to jimmy the door handle, no avail, it will not budge." << endl;
	}
	else if (choiceIn == 1 && getItem(choiceIn)->getTrigger() == false && oldWoman == false && trigger == true)                               //check if various conditions met
	{
		cout << getItem(choiceIn)->getDescription() << endl;
		cout << "You insert the Triskelion Key into the door." << endl;
		cout << "The key turns, and the door opens, revealing a dark corridor beyond." << endl;
		playIn->removeItem(playIn->searchItems("Triskelion Key"));
		getItem(choiceIn)->setTrigger(true);
		getItem(choiceIn)->setDescription("The door is open, revealing a dark chasm into what lies beyond...");
		timeFuture = true;
	}
	else if (choiceIn == 1 && getItem(choiceIn)->getTrigger() == true)                               //check if various conditions met
	{
		cout << getItem(choiceIn)->getDescription() << endl;
	}
	else if (choiceIn == 2 && getItem(choiceIn)->getTrigger() == false)
	{
		cout << getItem(choiceIn)->getDescription() << endl;
		cout << "Now if only I had something to write on...." << endl;
		if (playIn->searchItems("Death Note") != -1)
		{
			cout << "Having the Death Note, you decide to reach for the pen." << endl;

			if (playIn->checkInventory() == true)
			{
				cout << "You place the pen back on the table." << endl;
			}
			else
			{
				playIn->addItem("pen", "Not much to say about this, it works.");
				getItem(choiceIn)->setDescription("The pen has been taken.");
				getItem(choiceIn)->setTrigger(true);
				pen = true;												//acquired pen
			}
		}
	}
	else if (choiceIn == 2 && getItem(choiceIn)->getTrigger() == true)
	{
		cout << getItem(choiceIn)->getDescription() << endl;
	}
	else if (choiceIn == 3 && getItem(choiceIn)->getTrigger() == false && trigger == false)                                   //converse with the old woman
	{
		cout << getItem(choiceIn)->getDescription() << endl;
		cout << "The old woman opens her eyes, watery and hovering. She speaks:" << endl;
		cout << "'Why must you young people be so loud? Can't you see I'm just a crazy old lady trying to sleep.'" << endl;

		if (menuChoice("Do I know you? (y/n)   "))
		{
			cout << endl;
			cin.ignore();
			cout << "'Have you brought me anything for the pain then dear? It hurts, it hurts so much.'" << endl;
			cout << "'Here, a little extra light for your way, so you can find the end of mine.'" << endl;
			cout << "The old woman produces matches from a pocket, and relights your torch." << endl;
			cout << "The old woman's eyes close, and she falls back to sleep with a hiss." << endl;
			playIn->addTorch(1);
		}
		else
		{
			cout << endl;
			cin.ignore();
			cout << "'Then why are you accosting me? Police! Police!'" << endl;
			cout << "The old woman flails at you, knocking off the top of your torch!" << endl;
			cout << "The old woman's eyes close, and she falls back to sleep with a hiss." << endl;
			playIn->addTorch(-2);
		}
	}
	else if (choiceIn == 3 && getItem(choiceIn)->getTrigger() == false && trigger == true && pen == false)
	{
		cout << getItem(choiceIn)->getDescription() << endl;
		cout << "The old woman opens her eyes, watery and hovering. She speaks:" << endl;
		cout << "'Why must you young people be so loud? Can't you see I'm just a crazy old lady trying to sleep.'" << endl;

		if (menuChoice("Do I know you? (y/n)   "))
		{
			cout << endl;
			cin.ignore();
			cout << "'Have you brought me anything for the pain then dear? It hurts, it hurts so much.'" << endl;
			cout << "As you gaze at the old woman's pain, you get a strange idea..." << endl;
			
			if (menuChoice("Do you want to use your Death Note? (y/n)   "))
			{
				cout << endl;
				cin.ignore();
				cout << "The old woman smiles, then speaks" << endl;
				cout << "'That's nice dear, but you have nothing to write with.'" << endl;
				cout << "'Here, a little extra light for your way, so you can find the end of mine'" << endl;
				cout << "The old woman produces matches from a pocket, and relights your torch." << endl;
				cout << "The old woman's eyes close, and she falls back to sleep with a hiss." << endl;
				playIn->addTorch(1);
			}
			else
			{
				cout << endl;
				cin.ignore();
				cout << "The old woman frowns, then speaks" << endl;
				cout << "'Don't tease an old woman so. I can feel the disease in my bones, my lungs, everywhere.'" << endl;
				cout << "'Here, a little extra light for your way, so you can find the end of mine.'" << endl;
				cout << "The old woman produces matches from a pocket, and relights your torch." << endl;
				cout << "The old woman's eyes close, and she falls back to sleep with a hiss." << endl;
				playIn->addTorch(1);
			}
		}
		else
		{
			cout << endl;
			cin.ignore();
			cout << "'Then why are you accosting me? Police! Police!'" << endl;
			cout << "The old woman flails at you, knocking off the top of your torch!" << endl;
			cout << "The old woman's eyes close, and she falls back to sleep with a hiss." << endl;
			playIn->addTorch(-2);
		}
	}
	else if (choiceIn == 3 && getItem(choiceIn)->getTrigger() == false && trigger == true && pen == true)
	{
		cout << getItem(choiceIn)->getDescription() << endl;
		cout << "The old woman opens her eyes, watery and hovering. She speaks:" << endl;
		cout << "'Why must you young people be so loud? Can't you see I'm just a crazy old lady trying to sleep.'" << endl;

		if (menuChoice("Do I know you? (y/n)   "))
		{
			cout << endl;
			cin.ignore();
			cout << "'Have you brought me anything for the pain then dear? It hurts, it hurts so much.'" << endl;
			cout << "As you gaze at the old woman's pain, you get a strange idea..." << endl;

			if (menuChoice("Do you want to use your Death Note? (y/n)   "))
			{
				cout << endl;
				cin.ignore();
				cout << "The old woman smiles, then speaks" << endl;
				cout << "'That's nice dear, but are you sure?'" << endl;
				cout << "'In life I never reached such an old age as this, but you know that, you were there.'" << endl;
				cout << "'It was always your dream to die young, and mine to be the crazy old lady on the porch.'" << endl;
				cout << "'Look at us now. But it hurts " << playIn->getName() << ", it hurts in my bones, my lungs, everywhere.'" << endl;
				cout << "'But I don't want to be selfish. You can spare yourself this sorrow. Forget about me.'" << endl;
				cout << "'Use the Death Note on yourself and leave this place.'" << endl;
				cout << "The old woman smiles" << endl;
				cout << endl;
				int myChoice = menuDeathNote();

				if (myChoice == 1)
				{
					cout << "You write your name, " << playIn->getName() << ", in the Death Note." << endl;
					cout << "The woman smiles sadly at you, but with a touch of envy." << endl;
					cout << "After 40 seconds you feel your heart seize up, your eyes go dim, and you collapse to the floor." << endl;
					playIn->addTorch(playIn->getMaxTorch() * -1);
				}
				else if (myChoice == 2)
				{
					cout << "You write the old woman's name in the Death Note." << endl;
					cout << "Somehow, when you put pen to page, you knew her full name as if born to you." << endl;
					cout << "A secret name, a private joke." << endl;
					cout << "The old woman smiles." << endl;
					cout << "'Thank you' she whispers" << endl;
					cout << "'Such a nice young person, so considerate, here, have a sucker.'" << endl;
					cout << "Her eyes close for the final time." << endl;
					playIn->addItem("lollipop", "The sort of thing a very young child would love.");
					cout << "The Death Note, having no more pages, you discard." << endl;
					playIn->removeItem(playIn->searchItems("Death Note"));
					getItem(choiceIn)->setDescription("The old woman looks like she is asleep...");
					getItem(choiceIn)->setTrigger(true);
					oldWoman = false;																		//oldWoman is no mpre
					timeContinuous = true;
					lollipop = true;
					cout << endl;
					cout << "In the distance, you hear the chime of a clock toll once." << endl;
				}
				else if (myChoice == 3)
				{
					cout << "The old woman frowns, then speaks" << endl;
					cout << "'Don't tease an old woman so. I can feel the disease in my bones, my lungs, everywhere.'" << endl;
					cout << "The old woman's eyes close, and she falls back to sleep with a hiss." << endl;
				}
			}
			else
			{
				cout << endl;
				cin.ignore();
				cout << "The old woman frowns, then speaks" << endl;
				cout << "'Don't tease an old woman so. I can feel the disease in my bones, my lungs, everywhere.'" << endl;
				cout << "'Here, a little extra light for your way, so you can find the end of mine.'" << endl;
				cout << "The old woman produces matches from a pocket, and relights your torch." << endl;
				cout << "The old woman's eyes close, and she falls back to sleep with a hiss." << endl;
				playIn->addTorch(1);
			}
		}
		else
		{
			cout << endl;
			cin.ignore();
			cout << "'Then why are you accosting me? Police! Police!'" << endl;
			cout << "The old woman flails at you, knocking off the top of your torch!" << endl;
			cout << "The old woman's eyes close, and she falls back to sleep with a hiss." << endl;
			playIn->addTorch(-2);
		}
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

bool SimpleFuture::getStatus()

{
	return lollipop;                                                    //returns the lollipop
}

/**************************************************************************************************************
getTime returns the current bool associated the room, used by the Dungeon class to determine if a certain rooms
functions have been altered or items taken in some way. It takes a bool as an argument and returns nothing.
In this case it indicates if the SimpleFuture can be successfully exited
**************************************************************************************************************/

bool SimpleFuture::getTime()

{
	return timeContinuous;                                                   
}

/**************************************************************************************************************
getFuturereturns the current bool associated the room, used by the Dungeon class to determine if a certain rooms
functions have been altered or items taken in some way. It takes a bool as an argument and returns nothing.
In this case it indicates if the SimpleFuture can be successfully exited
**************************************************************************************************************/

bool SimpleFuture::getFuture()

{
	return timeFuture;                                                    //returns the bool for exiting SimpleFuture
}

/**************************************************************************************************************
getOldWoman the current bool associated the room, used by the Dungeon class to determine if a certain rooms
functions have been altered or items taken in some way. It takes a bool as an argument and returns nothing.
In this case it indicates if the SimpleFuture can be successfully exited
**************************************************************************************************************/

bool SimpleFuture::getOldWoman()

{
	return oldWoman;                                                    
}