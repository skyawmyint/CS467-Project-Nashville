/******************************************************************
Project Nashville
CS467 - Online Capstone Project
Description: This is the class implementation file for the class escapePodRoom.
******************************************************************/

#include "escapepodroom.hpp"

/********************************************************************************
default constructor
**********************************************************************************/
escapePodRoom::escapePodRoom()
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
    int foundIndex = -1;

    // Search for the feature
    for(int i = 0; i<feature.size(); i++){
        if(featureInputName == feature[i]){
            foundIndex = i;
        }
    }

    // Output the feature description
    // Found the ESCAPE POD
    if(foundIndex == 0){
        cout << endl << featureDescription[foundIndex] << endl;
    }
        // Found the NOTEPAD
    else if(foundIndex == 1){
        cout << endl << featureDescription[foundIndex] << endl;
    }
        // Else this is not recognized
    else{
        cout << "Input not recognized." << endl;
    }

}