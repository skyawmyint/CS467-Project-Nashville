/******************************************************************
Name: Clayton Hewitson
Assignment: Final Project
Date: 11/24/2017
Description: This is the class implementation file for the class Space.
It has only three variables, all private, a Space pointer to the right Space,
a pointer to the left Space, a pointer to the space above and a pointer to the space below.
It has get and set methods for all of these variables.
******************************************************************/

#include "Space.hpp"                           //header file for Space




/********************************************************************************
default constructor
**********************************************************************************/

Space::Space()
{
	right = NULL;
	left = NULL;
	top = NULL;
	bottom = NULL;

}


/*********************************************************************************
setright sets the pointer to the right Space object, it takes a pointer to a Space
as a parameter and returns nothing
*************************************************************************************/

void Space::setRight(Space* rightSpace)
{
	right = rightSpace;
}

/*********************************************************************************
getright returns the pointer to the right Space object, it takes nothing as a parameter and returns
a pointer to a Space
*************************************************************************************/

Space* Space::getRight() const
{
	return right;
}


/*********************************************************************************
setleft sets the pointer to the left Space object, it takes a pointer to a Space
as a parameter and returns nothing
*************************************************************************************/

void Space::setLeft(Space* leftSpace)
{
	left = leftSpace;
}

/*********************************************************************************
getleft returns the pointer to the left Space object, it takes nothing as a parameter and returns
a pointer to a Space
*************************************************************************************/

Space* Space::getLeft() const
{
	return left;
}


/*********************************************************************************
setTop sets the pointer to the top Space object, it takes a pointer to a Space
as a parameter and returns nothing
*************************************************************************************/

void Space::setTop(Space* topSpace)
{
	top = topSpace;
}

/*********************************************************************************
getTop returns the pointer to the top Space object, it takes nothing as a parameter and returns
a pointer to a Space
*************************************************************************************/

Space* Space::getTop() const
{
	return top;
}


/*********************************************************************************
setBottom sets the pointer to the bottom Space object, it takes a pointer to a Space
as a parameter and returns nothing
*************************************************************************************/

void Space::setBottom(Space* bottomSpace)
{
	bottom = bottomSpace;
}

/*********************************************************************************
getBottom returns the pointer to the bottom Space object, it takes nothing as a parameter and returns
a pointer to a Space
*************************************************************************************/

Space* Space::getBottom() const
{
	return bottom;
}

/*********************************************************************************
setName sets the name of the current Space object, it takes a string as a parameter and returns nothing
*************************************************************************************/

void Space::setName(string nameIn)
{
	name = nameIn;
}

/*********************************************************************************
getName returns the name of the current Space object, it takes nothing as a parameter and returns
a string;
*************************************************************************************/

string Space::getName() const
{
	return name;
}

/*********************************************************************************
setDescription sets the description of the current Space object, it takes a string as a parameter and returns nothing
*************************************************************************************/

void Space::setDescription(string scriptIn)
{
	description = scriptIn;
}

/*********************************************************************************
getDescription returns the description of the current Space object, it takes nothing as a parameter and returns
a string;
*************************************************************************************/

string Space::getDescription() const
{
	return description;
}

/***************************************************************************************
torchCount takes an int as a parameter which is the player's current remaining amount of 
torchlight. Based upon how much remains, special messages may be relayed to the player. In
specific rooms other events may occur...
****************************************************************************************/

void Space::torchCount(int torchIn, int maxTorchIn)
{
	if (torchIn <= maxTorchIn && torchIn > maxTorchIn * .75)
	{
		cout << "Your torch burns brightly, illuminating the entire room clearly." << endl;
		cout << endl;
	}
	else if (torchIn <= maxTorchIn * .75 && torchIn > maxTorchIn * .50)
	{
		cout << "Your torch dims just a touch, casting strange shadows about the walls." << endl;
		cout << endl;
	}
	else if (torchIn <= maxTorchIn * .50 && torchIn > maxTorchIn * .25)
	{
		cout << "Your torch's light has waned considerably, everything beyond a few feet is obscured." << endl;
		cout << endl;
	}
	else if (torchIn <= maxTorchIn * .25 && torchIn > maxTorchIn * .05)
	{
		cout << "Your torch sputters and sparks, and for a terrifying moment almost goes completely out." << endl;
		cout << endl;
	}
	else if (torchIn <= maxTorchIn * .05 && torchIn > 0)
	{
		cout << "Your torch clings feebly to life, soon it will go completely out." << endl;
		cout << "You will then be in great danger of being eaten by a grue." << endl;
		cout << endl;
	}
}



/*************************************************************************************
getItem returns a shared_ptr to an item that can be taken in the Space object and added to the player's inventory
from the vector items, based upon a player choice from a menu selection. This value is then
passed to the items vector, and the appropriate item is returned. It takes an int as a parameter;
***********************************************************************************/

shared_ptr<Item> Space::getItem(int numIn)
{
	int vectorChoice = numIn;
	vectorChoice--;

	shared_ptr<Item> tempItem = items[vectorChoice];

	return tempItem;
}

/*********************************************************************************************
addItem adds a new item shared pointer into the vector items, thus instantiating a
new item object off of the heap. It takes two parameters, all needed to construct a new item pointer.
It then uses emplace_back to place the pointer into the vector. It returns nothing.
*********************************************************************************************/

void Space::addItem(string nameIn, string descriptionIn)
{
	items.emplace_back(make_shared<Item>(nameIn, descriptionIn));
}


/***********************************************************************************************
examine provides an interface for the player to examine the items in the current Space, and determine
what, if any of them, can be taken. It take no parameters and returns an int, accessing the items
in the current space from the Spaces item vector,
*************************************************************************************************/

int Space::examine() 
{
	int count = 0;
	cout << "Of the various items strewn about, some could bear closer inspection." << endl;
	cout << "Which item would you like to examine further?" << endl;
	for (count = 0; count < items.size(); count++)
	{
		cout << count + 1 << ". Examine " << items[count]->getName() << endl;
	}
	count++;
	cout << count << ". Stop examining the room." << endl;

	return count;
}


/**********************************************************************************************
getStatus is a bool that returns true or false bases upon if a room has been permantely altered
(i.e. item taken, etc.) It takes no paramaters and returns a bool. The bool is originally set to false
**************************************************************************************************/

bool Space::getStatus() 
{
	return false;
}

/**********************************************************************************************
getTime is a bool that returns true or false bases upon if a room has been permantely altered
(i.e. item taken, etc.) It takes no paramaters and returns a bool. The bool is originally set to false
**************************************************************************************************/

bool Space::getTime()
{
	return false;
}

/**********************************************************************************************
getFuture is a bool that returns true or false bases upon if a room has been permantely altered
(i.e. item taken, etc.) It takes no paramaters and returns a bool. The bool is originally set to false
**************************************************************************************************/

bool Space::getFuture()
{
	return false;
}

/**********************************************************************************************
getOldWoman is a bool that returns true or false bases upon if a room has been permantely altered
(i.e. item taken, etc.) It takes no paramaters and returns a bool. The bool is originally set to false
**************************************************************************************************/

bool Space::getOldWoman()
{
	return false;
}


/********************************************************************************
destructor
**********************************************************************************/

Space::~Space()
{
	right = NULL;
	left = NULL;
	top = NULL;
	bottom = NULL;

}