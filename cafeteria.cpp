/******************************************************************
Project Nashville
CS467 - Online Capstone Project
Description: This is the class implementation file for the class cafeteria.
******************************************************************/

#include "cafeteria.hpp"

/********************************************************************************
default constructor
**********************************************************************************/
cafeteria::cafeteria()
{

    setName("CAFETERIA");
    setLongDescription("You enter a large room filled with cafeteria style bench tables. \n"
                       "At the back of the room is a long counter stacked with serving trays filled with half-rotting sandwiches. \n"
                       "Looks like sloppy joes. Yuck.  Smoke plumes from a stove behind the counter. CORRIDOR 3 looms behind.");
    setShortDescription("You enter a large room filled with cafeteria style bench tables. At the back of the room is a long counter \n"
                        "stacked with serving trays of rotting sandwiches. Smoke plumes from a stove behind the counter.");

// Add features to the room
    addFeature("STOVE","At first glance this smoking STOVE seems quite unsafe, oil leaks form the bottom.");
    addFeature("LUNCH LINE", "The LUNCH LINE indicates Sloppy Joe's are apparently a station favorite.");
}

/*********************************************************************************
lookAtFeature - will output a description if a feature is found with the look at action
*************************************************************************************/
void cafeteria::lookAtFeature(string featureInputName) {

    // Set variable for found index
    int foundIndex = -1;

    // Search for the feature
    for(int i = 0; i<feature.size(); i++){
        if(featureInputName == feature[i]){
            foundIndex = i;
        }
    }

    // Output the feature description
    // Found the STOVE
    if(foundIndex == 0){
        cout << endl << featureDescription[foundIndex] << endl;
    }
        // Found the LUNCH LINE
    else if(foundIndex == 1){
        cout << endl << featureDescription[foundIndex] << endl;
    }
        // Else this is not recognized
    else{
        cout << "Input not recognized." << endl;
    }

}