/******************************************************************
Project Nashville
CS467 - Online Capstone Project
Description: This is the class implementation file for the class engineBay.
******************************************************************/

#include "enginebay.hpp"

/********************************************************************************
default constructor
**********************************************************************************/
engineBay::engineBay() : room(3)
{

    setName("ENGINE BAY");
    setLongDescription("Multiple tables covered in scattered parts in various stages of disrepair mark the ENGINE BAY. \n"
                       "Normally a shop filled with the hustle and bustle of ongoing maintenance, the silence present is quite eerie. \n"
                       "In the back corner sits the PRIMER PUMP, needed for restoring power. It appears to be empty at present. \n"
                       "On the floor right at your feet lies a discarded pair of WORKERS' JUMPERS which, alas, are not your size. \n"
                       "Behind you is the route back to CORRIDOR 3.");
    setShortDescription("Multiple tables lay covered with various disassembled engine parts. In the back corner sits a PRIMER PUMP. \n"
                        "At your feet fist a pair of forgotten WORKERS' JUMPERS.");

}
