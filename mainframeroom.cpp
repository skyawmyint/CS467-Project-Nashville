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
    // Add features to the room
    addFeature("COMPUTER", "Looks like you can HACK this computer with the skills you already have!");
    addFeature("NOTE", "Could contain some useful information if LOOKED AT.");

}
/*********************************************************************************
lookAtFeature - will output a description if a feature is found with the look at action
*************************************************************************************/
void mainframeRoom::lookAtFeature(string featureInputName) {

    // Set variable for found index
    int foundIndex = -1;

    // Search for the feature
    for(int i = 0; i<feature.size(); i++){
        if(featureInputName == feature[i]){
            foundIndex = i;
        }
    }

    // Output the feature description
    // Found the COMPUTER
    if(foundIndex == 0){
        cout << endl << featureDescription[foundIndex] << endl;
    }
        // Found the NOTE
    else if(foundIndex == 1){
        cout << endl << featureDescription[foundIndex] << endl;
    }
        // Else this is not recognized
    else{
        cout << "Input not recognized." << endl;
    }

}

