/******************************************************************
Project Nashville
CS467 - Online Capstone Project
Description: This is the class implementation file for the class navigation.
******************************************************************/

#include "navigation.hpp"

/********************************************************************************
default constructor
**********************************************************************************/
navigation::navigation() : room(13)
{

    setName("NAVIGATION");
    setLongDescription("The uncharted vistas of space can be seen stretching to event horizon outside of NAVIGATION's viewport. \n"
                       "Still takes your breath away. The room however has suffered worse than most, it appears several of the terminals \n"
                       "have been smashed and there are signs of a scuffle. The captain's COMPUTER however, situated at the main command chair, \n"
                       "may still have some functionality. The exit leads back to CORRIDOR 1");
    setShortDescription("The captains' COMPUTER terminal sits across from his now empty leather chair and seems to be the \n"
                        "only piece of equipment possible of functioning. This room has seen much the worse for wear.");

    // Add features to the room
    addFeature("COMMUNICATION","This appears to be some internal correspondence that can be LOOKED AT.");
    addFeature("COMPUTER", "Looks like you can HACK this computer with the skills you already have!");
}

/*********************************************************************************
lookAtFeature - will output a description if a feature is found with the look at action
*************************************************************************************/
void navigation::lookAtFeature(string featureInputName) {

    // Set variable for found index
    int foundIndex = -1;

    // Search for the feature
    for(int i = 0; i<feature.size(); i++){
        if(featureInputName == feature[i]){
            foundIndex = i;
        }
    }

    // Output the feature description
    // Found the COMMUNICATION
    if(foundIndex == 0){
        cout << endl << featureDescription[foundIndex] << endl;
    }
        // Found the COMPUTER
    else if(foundIndex == 1 && hasPower == true ){
        cout << endl << featureDescription[foundIndex] << endl;
    }
        // Else this is not recognized
    else{
        cout << "Input not recognized." << endl;
    }

}

