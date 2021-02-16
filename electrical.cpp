/******************************************************************
Project Nashville
CS467 - Online Capstone Project
Description: This is the class implementation file for the class electrical.
******************************************************************/

#include "electrical.hpp"

/********************************************************************************
default constructor
**********************************************************************************/
electrical::electrical() : room(11)
{
    setName("ELECTRICAL");
    setLongDescription("There is the smell of burning ozone accompanied with a sizzling sound that makes your eardrums ring \n"
                       "as you enter ELECTRICAL. Against the far wall a shattered ELECTRICAL PANEL emits wave after wave of dangerous sparks, \n"
                       "being quite dangerous to approach and causing the lights to flicker. In the corner however, safely out of range of \n"
                       "the PANEL, sits a COMPUTER on a desk that somehow seems to have power...you can always go back to CORRIDOR 1.");
    setShortDescription("A shattered ELECTRICAL PANEL hums on the far side of the room. \n"
                        "In a tiny corner across the way a COMPUTER sits alone and lonely.");


// Add features to the room
    addFeature("COMMUNICATION","This appears to be some internal correspondence that can be LOOKED AT.");
    addFeature("PANEL", "If only you had some way to repair this by handling it safely!");
}

/*********************************************************************************
lookAtFeature - will output a description if a feature is found with the look at action
*************************************************************************************/
void electrical::lookAtFeature(string featureInputName) {

    // Set variable for found index
    int foundIndex;

    // Search for the feature
    foundIndex = searchFeature(featureInputName);

    // Output the feature description
    // Found the COMMUNICATION
    if(foundIndex == 0){
        displayFeatureDescription(foundIndex);
    }
    // Found the PANEL
    else if(foundIndex == 1){
        displayFeatureDescription(foundIndex);
    }
        // Else this is not recognized
    else{
        cout << "Input not recognized." << endl;
    }

}

/*********************************************************************************
flagSet - used to set various flags on the player character as they interact from room to room
*************************************************************************************/
void electrical::flagSet() {

    //check to see if panel is repaired, if not just exit
    if (electricalPanelRepaired) {
        // Get character pointer from room instantiation
        character *player = this->getCharacter();

        // Check if the this flag has already been passed to the player, if not, do so
        if (!player->getPanel()) {
            player->setPanel(electricalPanelRepaired);
        }
    }
}
