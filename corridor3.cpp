/******************************************************************
Project Nashville
CS467 - Online Capstone Project
Description: This is the class implementation file for the class corridor3.
******************************************************************/

#include "corridor3.hpp"

/********************************************************************************
default constructor
**********************************************************************************/
corridor3::corridor3()
{

    setName("CORRIDOR 3");
    setLongDescription("You enter yet another long vertical corridor. There are five doors along the east wall. \n"
                       "A large screen spans across the east wall displaying a map. \n"
                       "It’s almost a perfect mirror image of the first corridor entered. Why is there one less door? Mmm...");
    setShortDescription("You enter a vertical long corridor. There are five doors along the east wall. \n"
                        "A large screen spans across the east wall displaying a map.");

    // Add features to the room
    addFeature("MAP","This map appears to be able to be LOOKED AT, giving a layout of the station.");
}

/*********************************************************************************
lookAtFeature - will output a description if a feature is found with the look at action
*************************************************************************************/
void corridor3::lookAtFeature(string featureInputName) {

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