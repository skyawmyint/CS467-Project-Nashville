/******************************************************************
Project Nashville
CS467 - Online Capstone Project
Description: This is the class implementation file for the class medbay.
******************************************************************/

#include "medbay.hpp"

/********************************************************************************
default constructor
**********************************************************************************/
medbay::medbay()
{

    // Set name and descriptions
    setName("MEDBAY");
    setLongDescription("You see that you are surrounded by white walls that are very bright and clean. The walls feel empty with very little in the room. \n"
                       "The only things in the room that you see are the surgical table that you woke up on with a SCALPEL on it, a metal table in the corner of the room, \n"
                       "and a door leading to a dark hall, CORRIDOR 1. You also see a COMPUTER on top of the metal table that looks functional.");
    setShortDescription("A surgical table with a SCALPEL lays in the center of the room.  A COMPUTER sits atop of a metal table in the\n"
                        "corner with a MEDICAL BOX next to it.");

    // Toggle the game to say it has been visited already since it is where we begin
    toggleEnteredRoom();

}
