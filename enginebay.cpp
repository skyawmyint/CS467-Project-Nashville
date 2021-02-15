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

// Add features to the room
    addFeature("PUMP PRIMER","If this PUMP PRIMER was filled with fuel, perhaps power could be restored.");
    addFeature("WORKERS' JUMPERS", "A discarded pair of WORKERS' JUMPERS. Perhaps the pockets could be OPENED.");
}

/*********************************************************************************
lookAtFeature - will output a description if a feature is found with the look at action
*************************************************************************************/
void engineBay::lookAtFeature(string featureInputName) {

    // Set variable for found index
    int foundIndex;

    // Search for the feature
    foundIndex = searchFeature(featureInputName);

    // Output the feature description
    // Found the PUMP PRIMER
    if(foundIndex == 0){
        displayFeatureDescription(foundIndex);
    }
        // Found the WORKERS' JUMPERS
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
void engineBay::flagSet() {

    //check to see if pump if full, if not just exit
    if (pumpPrimerFull) {
        // Get character pointer from room instantiation
        character *player = this->getCharacter();

        // Check if the this flag has already been passed to the player, if not, do so
        if (!player->getPrimer()) {
            player->setPrimer(pumpPrimerFull);
        }
    }
}