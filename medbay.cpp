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
    setLongDescription("You see that you are surrounded by white walls that are very bright and clean, the air quite sterile with very little in the room. \n"
                       "The only things that draw your eye are the surgical table that you woke up on with the SCALPEL on it, a metal table in the corner of the room, \n"
                       "a MEDICAL BOX on the far wall, and a door leading to a dark hall, CORRIDOR 1. You also see a COMPUTER on top of the metal table that looks functional.");
    setShortDescription("A surgical table with the SCALPEL lays in the center of the room.  A COMPUTER sits atop of a metal table in the \n"
                        "corner with a MEDICAL BOX next to it.");

    // Toggle the game to say it has been visited already since it is where we begin
    toggleEnteredRoom();

    // Add features to the room
    addFeature("SCALPEL","This item may just be useful to TAKE with you.");
    addFeature("COMPUTER", "Looks like you can HACK this computer with the skills you already have!");
    addFeature("MEDICAL BOX","If only you could OPEN this MEDICAL BOX with some kind of mechanical tool...");

}
/*********************************************************************************
lookAtFeature - will output a description if a feature is found with the look at action
*************************************************************************************/
void medbay::lookAtFeature(string featureInputName) {

    // Set variable for found index
    int foundIndex = -1;

    // Search for the feature
    for(int i = 0; i<feature.size(); i++){
        if(featureInputName == feature[i]){
            foundIndex = i;
        }
    }

    // Output the feature description
    // Found the SCALPEL
    if(foundIndex == 0 && scalpelTaken == false){
        cout << endl << featureDescription[foundIndex] << endl;
    }
    // Found the COMPUTER
    else if(foundIndex == 1){
        cout << endl << featureDescription[foundIndex] << endl;
    }
    // Found the MEDICAL BOX
    else if(foundIndex == 2 && medicalBoxOpened == false){
        cout << endl << featureDescription[foundIndex] << endl;

    }
    // Else this is not recognized
    else{
        cout << "Input not recognized." << endl;
    }

}




