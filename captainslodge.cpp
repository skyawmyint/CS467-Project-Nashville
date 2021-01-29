/******************************************************************
Project Nashville
CS467 - Online Capstone Project
Description: This is the class implementation file for the class captainsLodge.
******************************************************************/

#include "captainslodge.hpp"

/********************************************************************************
default constructor
**********************************************************************************/
captainsLodge::captainsLodge() : room(10)
{
    setName("CAPTAIN'S LODGE");
    setLongDescription("You enter what appears to be a bedroom. Clothes and half-filled suitcases are scattered \n"
                       "across the floor. Looks like someone left in a hurry. An unmade bed and nightstand sit in the corner. \n"
                       "A framed photo of a tabby cat sits atop the nightstand. Smashed against the wall is an overturned desk. \n"
                       "CORRIDOR 3 remains the only exit");
    setShortDescription("You enter what appears to be a bedroom. An unmade bed and nightstand sit in the corner. \n"
                        "A framed photo of a tabby cat sits atop the nightstand. Smashed against the wall is an overturned desk.");

}
