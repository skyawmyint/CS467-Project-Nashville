/******************************************************************
Project Nashville
CS467 - Online Capstone Project
Description: This is the class implementation file for the class corridor2.
******************************************************************/

#include "corridor2.hpp"

/********************************************************************************
default constructor
**********************************************************************************/
corridor2::corridor2()
{

    setName("CORRIDOR 2");
    setLongDescription("You enter a long horizontal corridor heading west. A large window on the north wall overlooks the stars. \n"
                       "Your foot hits something soft. It’s a … person. A man in a silver spacesuit lays face down on the floor \n"
                       "You give him a nudge, but he does not respond. Hey may not be breathing.");
    setShortDescription("You enter a long horizontal corridor heading west. A large window on the north wall overlooks the stars.");

    // Add features to the room
    addFeature("WINDOW","A WINDOW gives an amazing view of the vastness of space if one took the time to LOOK AT it.");
    addFeature("BODY", "A dead BODY lies slumped in the corridor, cold and lifeless!");
}

/*********************************************************************************
lookAtFeature - will output a description if a feature is found with the look at action
*************************************************************************************/
void corridor2::lookAtFeature(string featureInputName) {

    // Set variable for found index
    int foundIndex = -1;

    // Search for the feature
    for(int i = 0; i<feature.size(); i++){
        if(featureInputName == feature[i]){
            foundIndex = i;
        }
    }

    // Output the feature description
    // Found the Window
    if(foundIndex == 0){
        cout << endl << featureDescription[foundIndex] << endl;
    }
    // Found the BODY
    else if(foundIndex == 1){
        cout << endl << featureDescription[foundIndex] << endl;
    }
        // Else this is not recognized
    else{
        cout << "Input not recognized." << endl;
    }

}
