/******************************************************************
Project Nashville
CS467 - Online Capstone Project
Description: This is the class implementation file for the class lifeSupportO2.
******************************************************************/

#include "lifesupporto2.hpp"

/********************************************************************************
default constructor
**********************************************************************************/
lifeSupportO2::lifeSupportO2() : room(12)
{

    setName("LIFE SUPPORT O2");
    setLongDescription("You breathe a sigh of relief that all appears functional in this room, no pun intended. \n"
                       "Rows and Rows of O2 sterilization and life support maintenance terminals cover every square inch. \n"
                       "A quick glance shows that all read-outs are at nominal or slightly above. Tucked next to a stack of \n"
                       "unused yet full O2 CANISTERS sits an EMPTY CONTAINER, ideal for holding any manner of liquid. \n"
                       "While the only nominal exit is back to CORRIDOR 3, something seems off about this room...");
    setShortDescription("Life support and O2 appear to not be in any danger of critical failure, as all machines appear functional. \n"
                        "Next to some unused but full O2 CANISTERS was resting an EMPTY CONTAINER.");

// Add features to the room
    addFeature("EMPTY CONTAINER","This item may just be useful to TAKE with you.");
    addFeature("O2 CANISTERS", "These O2 canisters appear to be blocking something behind them...");

}
/*********************************************************************************
lookAtFeature - will output a description if a feature is found with the look at action
*************************************************************************************/
void lifeSupportO2::lookAtFeature(string featureInputName) {

    // Set variable for found index
    int foundIndex = -1;

    // Search for the feature
    for(int i = 0; i<feature.size(); i++){
        if(featureInputName == feature[i]){
            foundIndex = i;
        }
    }

    // Output the feature description
    // Found the EMPTY CONTAINER
    if(foundIndex == 0 && emptyContainerTaken == false){
        cout << endl << featureDescription[foundIndex] << endl;
    }
        // Found the O2 canisters
    else if(foundIndex == 1){
        cout << endl << featureDescription[foundIndex] << endl;
    }
        // Else this is not recognized
    else{
        cout << "Input not recognized." << endl;
    }

}
