/******************************************************************
Project Nashville
CS467 - Online Capstone Project
Description: This is the class implementation file for the class escapePodRoom.
******************************************************************/

#include "escapepodroom.hpp"

/********************************************************************************
default constructor
**********************************************************************************/
escapePodRoom::escapePodRoom() : room(0)
{

    setName("ESCAPE POD ROOM");
    setLongDescription("The room is barren and stark, necessary except with the vain hope that it would never have to be used. This ESCAPE POD \n"
                       "ROOM should have had at least a half-dozen pods primed and ready for jump in case of emergency, \n"
                       "yet only one ESCAPE POD remains, its soft lights gently humming. Against a side wall is a metal table with a small \n"
                       "NOTEPAD atop. A door behind leads to the dark hall of CORRIDOR 1.");
    setShortDescription("One gently whirring ESCAPE POD lays primed in the far corner. A small NOTEPAD sits atop of a metal table against the side wall");


    // Add features to the room
    addFeature("ESCAPE POD","This item is the key to your salvation, if only...");
    addFeature("NOTEPAD", "If LOOKED AT this may give instructions to operate the escape pod.");

}
/*********************************************************************************
lookAtFeature - will output a description if a feature is found with the look at action
*************************************************************************************/
void escapePodRoom::lookAtFeature(string featureInputName) {

    // Set variable for found index
    int foundIndex;

    // Search for the feature
    foundIndex = searchFeature(featureInputName);

    // Output the feature description
    // Found the ESCAPE POD
    if(foundIndex == 0){
        displayFeatureDescription(foundIndex);
    }
        // Found the NOTEPAD
    else if(foundIndex == 1){
        displayFeatureDescription(foundIndex);
    }
        // Else this is not recognized
    else{
        cout << "Input not recognized." << endl;
    }

}
