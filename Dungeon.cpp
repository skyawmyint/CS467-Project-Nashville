/******************************************************************
Name: Clayton Hewitson
Assignment: Final Project
Date: 12/01/2017
Description: This is the class implementation file for the class Dungeon.
It has private variables, pointers to Space objects, to hold each of the rooms
in the dungeon as well as a pointer for the player's current position. A player
object also exists for the current game. There are various methods to move
and track the player's crawl through the dungeon, and the constructor instantiates
the dungeon into being. It has various get and set methods.
******************************************************************/

#include "Dungeon.hpp"                           //header file for Space




/********************************************************************************
default constructor, builds the dungeon by linking nodes.
**********************************************************************************/

Dungeon::Dungeon(Player* pIn)                                             //pass player character
{
	simplePast = new SimplePast;                                      //create every room in dungeon off of heap
	simplePresent = new SimplePresent;
	simpleFuture = new SimpleFuture;                                      
    futureContinuous = new FutureContinuous;                                      
	futurePerfect = new FuturePerfect;                                      
	foyer = new Foyer;

	timePast = false;                                                //set all bools to false
	timePresent = false;
	timeFuture = false;

	simplePast->setTop(foyer);                                       //build dungeon
	simplePast->setRight(simplePresent);
	simplePast->setBottom(simpleFuture);

	simplePresent->setTop(foyer);
	simplePresent->setLeft(simplePast);
	simplePresent->setBottom(simpleFuture);

	simpleFuture->setTop(foyer);
	simpleFuture->setLeft(simplePast);
	simpleFuture->setRight(simplePresent);                                 


	setPlayer(pIn);                                                  //create the player
	setPosition(foyer);                                           //set starting location, simplePast

	
}


/*********************************************************************************
setPosition sets the position of the player's current location, it takes a pointer to a Space
as a parameter and returns nothing
*************************************************************************************/

void Dungeon::setPosition(Space* spaceIn)
{
	position = spaceIn;
}

/*********************************************************************************
getPosition returns the pointer of the player's current location, it takes nothing as a parameter and returns
a pointer to a Space
*************************************************************************************/

Space* Dungeon::getPosition() const
{
	return position;
}


/*********************************************************************************
setPlayer sets the Player pointer in the Dungeon class, theVagrant, to a passed player Pointer from main.
It takes a pointer to a Player as a parameter and returns nothing
*************************************************************************************/

void Dungeon::setPlayer(Player* playerIn)
{
	theVagrant = playerIn;
}

/*********************************************************************************
getPlayer returns the pointer to the class player Pointer, theVagrant. it takes nothing as a parameter and returns
a pointer to a player
*************************************************************************************/

Player* Dungeon::getPlayer() const
{
	return theVagrant;
}

/****************************************************************************************
movePlayer takes an int as an argument from a previous menu choice of whether the player
wishes to move north, south, east, or west from the current room. The player moves in the
appropriate direction by modifying the value of the Space pointer movement or does not move
at all if the direction indicated returns a NULL pointer. This function returns a bool.
*****************************************************************************************/

bool Dungeon::movePlayer(int directionIn)
{


	switch (directionIn)                                                    //direction number indicating north, south, east, or west
	{
	case 1: if (getPosition()->getTop() == NULL)                                 //if player wishes to move north
	{
		return false;                                                           //cannot move north, return room specific rejection
	}
			else                                                                //movement possible, return rome specific movement
			{
				setPosition(getPosition()->getTop());
				return true;
			}
			break;
	case 2: if (getPosition()->getBottom() == NULL)                                 //repeat
	{
		return false;                                                          
	}
			else                                                                
			{
				setPosition(getPosition()->getBottom());
				return true;
			}
			break;
	case 3: if (getPosition()->getRight() == NULL)                                 //repeat
	{
		return false;
	}
			else
			{
				setPosition(getPosition()->getRight());
				return true;
			}
			break;
	case 4: if (getPosition()->getLeft() == NULL)                                 //repeat
	{
		return false;
	}
			else
			{
				setPosition(getPosition()->getLeft());
				return true;
			}
			break;
	default: return false;
	}
	
}

/******************************************************************************************
printSpaces prints all the rooms adjacent to the player in the current dungeon, it takes no
parameters and returns nothing
*******************************************************************************************/

void Dungeon::printSpaces()
{
	if (getPosition()->getBottom() == NULL && getPosition()->getTop() == NULL && getPosition()->getLeft() == NULL && getPosition()->getRight() == NULL)
	{
		cout << "There appears to be no exit from this room." << endl;
		cout << endl;
	}

	if (getPosition()->getTop() != NULL)
	{
		cout << "To the north of you: " << getPosition()->getTop()->getDescription() << endl;
		cout << endl;
	}
	if (getPosition()->getBottom() != NULL)
	{
		cout << "To the south of you: " << getPosition()->getBottom()->getDescription() << endl;
		cout << endl;
	}
	if (getPosition()->getRight() != NULL)
	{
		cout << "To the east of you: " << getPosition()->getRight()->getDescription() << endl;
		cout << endl;
	}
	if (getPosition()->getLeft() != NULL)
	{
		cout << "To the west of you: " << getPosition()->getLeft()->getDescription() << endl;
		cout << endl;
	}
}

/**************************************************************************************************
getTrig is a bool function that tests certain conditions dependent upon Player actions in various different room,
and thus determines what further options of movement and actions are possible for the player in their given location.
It returns a bool and accepts no arguments
*****************************************************************************************************/

bool Dungeon::getTrig()
{
	if (getPosition()->getName() == "Foyer of Time Immemorial.")
	{
		if (simplePast->getTime() == true && simplePresent->getTime() == true && simpleFuture->getTime() == true)
		{
			return true;                                                      //if all tasks completed, get key from foyer
		}
	}
	else if (getPosition()->getName() == "SimpleFuture of Time Immemorial.")
	{
		if (simplePast->getTime() == true && simplePresent->getTime() == true && simpleFuture->getTime() == true)
		{
			return foyer->getStatus();                                                      //if all tasks completed, door can be opened in simpleFuture
		}
		else if (getPosition()->getOldWoman() == false)
		{
			return false;
		}
		else
		{
			return simplePresent->getStatus();                                             //if not, search for deathNote
		}
	}
	else if (getPosition()->getName() == "SimplePast of Time Immemorial.")                  //used to test if lollipop has been required
	{
		return simpleFuture->getStatus();
	}

	return false;
}

/**************************************************************************************************
getPast is a bool function that tests certain conditions dependent upon Player actions in various different room,
and thus determines what further options of movement and actions are possible for the player in their given location.
It returns a bool and accepts no arguments. Here it determines if the foyer doors can be opened.
*****************************************************************************************************/

bool Dungeon::getPast()
{
	return foyer->getTime();
}

/*************************************************************************************************
void addSimple connects the foyer, the starting area, to the three areas of simple time provided
the ancient book has been read. It takes no parameters and returns nothing 
************************************************************************************************/

void Dungeon::addSimple()
{

	foyer->setBottom(simpleFuture);                                //connect foyer to other areas                                 
	foyer->setLeft(simplePast);
	foyer->setRight(simplePresent);

	timePast = true;
}


/**************************************************************************************************
getFuture is a bool function that tests certain conditions dependent upon Player actions in various different room,
and thus determines what further options of movement and actions are possible for the player in their given location.
It returns a bool and accepts no arguments. Here it determines if the foyer doors can be opened.
*****************************************************************************************************/

bool Dungeon::getFuture()
{
	return simpleFuture->getFuture();
}

/*************************************************************************************************
void addFuture opens the door in the simpleFuture room, allowing further passage to new lands beyond.
It takes no parameters and returns nothing
************************************************************************************************/

void Dungeon::addFuture()
{

	simpleFuture->setBottom(futureContinuous);                                //connect simple Future to other areas                             
	timePresent = true;
}


/**************************************************************************************************
getEnd is a bool function that tests certain conditions dependent upon Player actions in various different room,
and thus determines what further options of movement and actions are possible for the player in their given location.
It returns a bool and accepts no arguments. Here it determines if the foyer doors can be opened.
*****************************************************************************************************/

bool Dungeon::getEnd()
{
	return futureContinuous->getFuture();
}


/*************************************************************************************************
void addEnd opens the door in the contintuousFuture room, allowing further passage to new lands beyond.
It takes no parameters and returns nothing
************************************************************************************************/

void Dungeon::addEnd()
{

	futureContinuous->setBottom(futurePerfect);                                //connect continuousFuture to other areas                             
	timeFuture = true;
}



/******************************************************************************************************
removePast removes all preceeding rooms once the door at the far end of simple future is walked through,
it takes no parameters and returns nothing.
****************************************************************************************************/

void Dungeon::removePast() 
{
	if (position->getName() == "FutureContinuous of Time Immemorial.") 
	{
		cout << "As you walk through the now unlocked door, you feel a whoosh of air,\n"
			"and a small click behind you.\n"
			"Turning around you see the path you have come from has now vanished, \n"
			"replaced by a solid gray wall." << endl;
		simpleFuture->setBottom(NULL);
		futureContinuous->setTop(NULL);
	}
}


/******************************************************************************************************
removePresent removes all preceeding rooms once the door at the far end of future continuous is walked through,
it takes no parameters and returns nothing.
****************************************************************************************************/

void Dungeon::removePresent()
{
	if (position->getName() == "FuturePerfect of Time Immemorial.")
	{
		cout << "As you walk through the now unlocked door, you feel a whoosh of air,\n"
			"and a small click behind you.\n"
			"Turning around you see the path you have come from has now vanished, \n"
			"replaced by a solid gray wall." << endl;
		futureContinuous->setBottom(NULL);
		futurePerfect->setTop(NULL);
	}
}

/***************************************************************************************************
void getAdded runs a check to determine if the foyer doors have been opened, and if the way past simpleFuture
has been made clear as well as they way to the end. It takes a constant int as a parameter and returns a bool for use in main
***************************************************************************************************/

bool Dungeon::getAdded(const int &i)
{
	if (i == 1)
		return timePast;
	else if (1 == 2)
	{
		return timePresent;
	}
	else
	{
		return timeFuture;
	}
}

/************************************************************************************************************
getVictory simply returns the getStats of the final room, FuturePerfect. If all events have been accomplished
successfully in the room of futurPerfect, the victory condition will return true and the journey will end.
*********************************************************************************************************/

bool Dungeon::getVictory()
{
	return futurePerfect->getStatus();
}


/********************************************************************************
destructor
**********************************************************************************/

Dungeon::~Dungeon()
{
	delete simplePast;                                    //clear every room off of heap
	simplePast = NULL;
	
	delete simplePresent;                                   
	simplePresent = NULL;

	delete simpleFuture;
	simpleFuture = NULL;

	delete futureContinuous;
	futureContinuous = NULL;

	delete futurePerfect;
	futurePerfect = NULL;

	delete foyer;
	foyer = NULL;

	delete theVagrant;                               //delete player and player position
	theVagrant = NULL;

	position = NULL;

}