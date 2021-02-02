/******************************************************************
Project Nashville
CS467 - Online Capstone Project
Description: This is the class implementation file for the class corridor1.
******************************************************************/

#include "corridor1.hpp"

/********************************************************************************
default constructor
**********************************************************************************/
corridor1::corridor1()
{

    setName("CORRIDOR 1");
    setLongDescription("Bright overhead lights flicker on illuminating a long corridor. Including the room you just exited there are six doors \n"
                       "along one wall. A large screen spans across the other wall displaying a map. You hear a rumbling sound. \n"
                       "Suddenly the room shakes and you stumble fighting for balance. You feel a sinking sensation of doom...");
    setShortDescription("You enter a long vertical corridor. There are six doors along the west wall. \n"
                        "A large screen spans across the west wall displaying a map.");

    // Add features to the room
    addFeature("MAP","This map appears to be able to be LOOKED AT, giving a layout of the station.");
}

/*********************************************************************************
lookAtFeature - will output a description if a feature is found with the look at action
*************************************************************************************/
void corridor1::lookAtFeature(string featureInputName) {

    // Set variable for found index
    int foundIndex = -1;

    // Search for the feature
    for(int i = 0; i<feature.size(); i++){
        if(featureInputName == feature[i]){
            foundIndex = i;
        }
    }

    // Output the feature description
    // Found the MAP
    if(foundIndex == 0){
        cout << endl << featureDescription[foundIndex] << endl;
    }
        // Else this is not recognized
    else{
        cout << "Input not recognized." << endl;
    }

}