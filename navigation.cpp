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
    int foundIndex;

    // Search for the feature
    foundIndex = searchFeature(featureInputName);

    // Output the feature description
    // Found the COMMUNICATION
    if(foundIndex == 0){
        displayFeatureDescription(foundIndex);
    }
        // Found the COMPUTER
    else if(foundIndex == 1 && hasPower == true ){
        displayFeatureDescription(foundIndex);
    }
        // Else this is not recognized
    else{
        cout << "Input not recognized." << endl;
    }

}

/*********************************************************************************
flagCheck - used to check if various flags in other rooms have been enabled by the player
*************************************************************************************/
void navigation::flagCheck() {

    //check to see if power already restored, if so just exit
    if (hasPower == false) {
        // Get character pointer from room instantiation
        character *player = this->getCharacter();

        // Check if the two conditions for power being restored have been met
        if (player->getPanel() && player->getPrimer()) {
            hasPower = true;
        }
    }
}

