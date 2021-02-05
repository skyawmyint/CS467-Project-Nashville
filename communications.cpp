/******************************************************************
Project Nashville
CS467 - Online Capstone Project
Description: This is the class implementation file for the class communications.
******************************************************************/

#include "communications.hpp"

/********************************************************************************
default constructor
**********************************************************************************/
communications::communications() : room(9)
{

    setName("COMMUNICATIONS");
    setLongDescription("Ahhh...COMMUNICATIONS. This was your first duty onboard this station, monitoring incoming voice chatter, \n"
                       "in what feels like over a dozen lifetimes ago. Your old COMPUTER terminal sits against the far wall, \n"
                       "untouched but for a thick sheen of dust that sends shivers down your spine. From here it is impossible to tell if \n"
                       "it has any functionality. On the terminal opposite yours, a BIRTHDAY message from a co-worker lies scrawled on a tossed card. \n"
                       "The only exit appears to be back out to CORRIDOR 1");
    setShortDescription("A COMPUTER terminal that used to be your own sits against the far wall. Opposite, \n"
                        "a forgotten BIRTHDAY message from a coworker lies discarded. There was a time when you had fond memories of this place.");

    // Add features to the room
    addFeature("BIRTHDAY MESSAGE","Appears someone recently had themselves a special day..");
    addFeature("COMPUTER", "Looks like you can HACK this computer with the skills you already have!");
}

/*********************************************************************************
lookAtFeature - will output a description if a feature is found with the look at action
*************************************************************************************/
void communications::lookAtFeature(string featureInputName) {

    // Set variable for found index
    int foundIndex;

    // Search for the feature
    foundIndex = searchFeature(featureInputName);

    // Output the feature description
    // Found the BIRTHDAY MESSAGE
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
