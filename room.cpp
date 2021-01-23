/******************************************************************
Project Nashville
CS467 - Online Capstone Project
Description: This is the class implementation file for the class room.
******************************************************************/

#include "room.hpp"

/********************************************************************************
default constructor
**********************************************************************************/
room::room()
{


}

/*********************************************************************************
setName sets the name of the room it takes a string as a parameter and returns nothing
*************************************************************************************/
void room::setName(string nameIn)
{
    roomName = nameIn;
}

/*********************************************************************************
getName returns the name of the current room object, it takes nothing as a parameter and returns
a string;
*************************************************************************************/
string room::getName() const
{
    return roomName;
}

/*********************************************************************************
setLongDescription sets the description of the current room object, it takes a string as a parameter and returns nothing
*************************************************************************************/
void room::setLongDescription(string scriptIn)
{
    longDescription = scriptIn;
}

/*********************************************************************************
getDescription returns the description of the current room object, it takes nothing as a parameter and returns
a string;
*************************************************************************************/
string room::getLongDescription() const
{
    return longDescription;
}

/*********************************************************************************
setShortDescription sets the description of the current room object, it takes a string as a parameter and returns nothing
*************************************************************************************/
void room::setShortDescription(string scriptIn)
{
    shortDescription = scriptIn;
}

/*********************************************************************************
getShortDescription returns the description of the current room object, it takes nothing as a parameter and returns
a string;
*************************************************************************************/
string room::getShortDescription() const
{
    return shortDescription;
}

/*********************************************************************************************
setConnectedRooms takes a room* pointer input and sets it in the connectedRooms vector to keep
 a list of connected rooms.
*********************************************************************************************/
void room::setConnectedRooms(room* inputRoom)
{
    connectedRooms.push_back(inputRoom);
    numConnectedRooms++;

}

/*********************************************************************************************
isConnectedRoom takes in a string room name input and checks if it is one of the connected
 rooms in the connectedRooms vector. Returns true if it is, false if it is not.
*********************************************************************************************/
bool room::isConnectedRoom(string inputRoomName)
{
    // Create a flag to see if it is a connected room
    bool connectedRoomFlag = false;

    // Go through each index in the array
    for(int i = 0; i<numConnectedRooms; i++){

        // Compare the room name with the input string room name
        if(connectedRooms[i]->getName() == inputRoomName){
            connectedRoomFlag = true;
        }
    }

    return connectedRoomFlag;
}

/*********************************************************************************************
isRepeatVisit returns the bool of if it is the first time someone has entered the room
*********************************************************************************************/
bool room::isRepeatVisit()
{
    return repeatVisit;
}

/*********************************************************************************************
toggleEnteredRoom sets the repeatVisit to TRUE if the room has been already visited
*********************************************************************************************/
void room::toggleEnteredRoom()
{
    repeatVisit = true;
}







/********************************************************************************
destructor
**********************************************************************************/
room::~room()
{



}