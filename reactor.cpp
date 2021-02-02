/******************************************************************
Project Nashville
CS467 - Online Capstone Project
Description: This is the class implementation file for the class reactor.
******************************************************************/

#include "reactor.hpp"

/********************************************************************************
default constructor
**********************************************************************************/
reactor::reactor()
{

    setName("REACTOR");
    setLongDescription("The REACTOR is more maze than room with pipes, ducts and catwalks twisting and turning into the darkness. \n"
                       "An extremely loud, almost-deafening clanking can be heard coming from an open VALVE deep within the machine. \n"
                       "Your eardrums splitting, it is impossible to discern anything else about this space while the racket continues. \n"
                       "The door back to CORRIDOR 3 at least offers a quiet place to think.");
    setShortDescription("A VALVE that has been the source of a deafening noise rests deep within the heart of this room. \n"
                        "Not much else appears to be of note.");

// Add features to the room
    addFeature("VALVE", "If only there was some way to close this valve. You can't even think!");
    addFeature("SATELLITE", "Now that the noise has ceased, the ping of a lonely satellite can be heard...");

}
/*********************************************************************************
lookAtFeature - will output a description if a feature is found with the look at action
*************************************************************************************/
void reactor::lookAtFeature(string featureInputName) {

    // Set variable for found index
    int foundIndex = -1;

    // Search for the feature
    for(int i = 0; i<feature.size(); i++){
        if(featureInputName == feature[i]){
            foundIndex = i;
        }
    }

    // Output the feature description
    // Found the VALVE
    if(foundIndex == 0){
        cout << endl << featureDescription[foundIndex] << endl;
    }
        // Found the SATELLITE
    else if(foundIndex == 1 && noisyValveOpen == false ){
        cout << endl << featureDescription[foundIndex] << endl;
    }
        // Else this is not recognized
    else{
        cout << "Input not recognized." << endl;
    }

}