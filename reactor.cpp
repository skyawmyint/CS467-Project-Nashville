/******************************************************************
Project Nashville
CS467 - Online Capstone Project
Description: This is the class implementation file for the class reactor.
******************************************************************/

#include "reactor.hpp"

/********************************************************************************
default constructor
**********************************************************************************/
reactor::reactor() : room(1)
{

    setName("REACTOR");
    setLongDescription("The REACTOR is more maze than room with pipes, ducts and catwalks twisting and turning into the darkness. \n"
                       "An extremely loud, almost-deafening clanking can be heard coming from an open VALVE deep within the machine. \n"
                       "Your eardrums splitting, it is impossible to discern anything else about this space while the racket continues. \n"
                       "The door back to CORRIDOR 3 at least offers a quiet place to think.");
    setShortDescription("A VALVE that has been the source of a deafening noise rests deep within the heart of this room. \n"
                        "Not much else appears to be of note.");

}
