/******************************************************************
Project Nashville
CS467 - Online Capstone Project
Description: This is the class implementation file for the class mainframeRoom.
******************************************************************/

#include "mainframeroom.hpp"

/********************************************************************************
default constructor
**********************************************************************************/
mainframeRoom::mainframeRoom() : room(4)
{
    setName("MAINFRAME ROOM");
    setLongDescription("If NAVIGATION could be considered the mind of the space station, and the CAPTAIN'S CABIN the soul, \n"
                       "then this room, the MAINFRAME, is surely the heart. Normally off limits to all but the most trusted of personnel, \n"
                       "you feel a bit overwhelmed at the vast complexity before you. Panels of switches stretch across the walls. \n"
                       "However your eye is drawn to what looks like a central COMPUTER terminal with a NOTE taped to the corner that appears \n"
                       "to be functional. Behind you lies the dark hall back to CORRIDOR 1.");
    setShortDescription("Panels of switches stretch across the walls. Amidst the sounds of hard drives and servers cooling, \n"
                        "a table on the far side contains a COMPUTER terminal with a NOTE attached.");
}
