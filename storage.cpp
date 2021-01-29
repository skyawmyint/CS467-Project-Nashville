/******************************************************************
Project Nashville
CS467 - Online Capstone Project
Description: This is the class implementation file for the class storage.
******************************************************************/

#include "storage.hpp"

/********************************************************************************
default constructor
**********************************************************************************/
storage::storage() : room(14)
{

    setName("STORAGE");
    setLongDescription("The shattered wreckage of the destroyed O2 CANISTERS make maneuvering into room a tad difficult, \n"
                       "but why a seemingly ordinary STORAGE room was hidden so thoroughly is anybody's guess. Rows of lockers \n"
                       "line the two walls to the right and left, while straight ahead against the far wall is a fairly large CLOSET. \n"
                       "One small table sits directly to the right, upon which lies a furiously scrawled NOTE. \n"
                       "Directly back is the passage back into LIFE SUPPORT O2.");
    setShortDescription("A seemingly ordinary STORAGE room contains a small table with a scrawled NOTE upon it, \n"
                        "and directly against the far wall a fairly large CLOSET.");

}
