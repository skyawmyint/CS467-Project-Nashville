/******************************************************************
Project Nashville
CS467 - Online Capstone Project
Description: This is the class implementation file for the class captainsLodge.
******************************************************************/

#include "captainslodge.hpp"

/********************************************************************************
default constructor
**********************************************************************************/
captainsLodge::captainsLodge() : room(10)
{
    setName("CAPTAIN'S LODGE");
    setLongDescription("You enter what appears to be a bedroom. Clothes and half-filled suitcases are scattered \n"
                       "across the floor. Looks like someone left in a hurry. An unmade bed and nightstand sit in the corner. \n"
                       "A framed photo of a tabby cat sits atop the nightstand. Smashed against the wall is an overturned desk. \n"
                       "CORRIDOR 3 remains the only exit");
    setShortDescription("You enter what appears to be a bedroom. An unmade bed and nightstand sit in the corner. \n"
                        "A framed photo of a tabby cat sits atop the nightstand. Smashed against the wall is an overturned desk.");

// Add features to the room
    addFeature("DESK","The Captain's desk has been overturned in a frenzy. Is there something trapped underneath?");
    addFeature("PET PICTURE", "A PET PICTURE of an orange tabby cat can be LOOKED AT on the dresser.");
}

/*********************************************************************************
lookAtFeature - will output a description if a feature is found with the look at action
*************************************************************************************/
void captainsLodge::lookAtFeature(string featureInputName) {

    // Set variable for found index
    int foundIndex = -1;

    // Search for the feature
    for(int i = 0; i<feature.size(); i++){
        if(featureInputName == feature[i]){
            foundIndex = i;
        }
    }

    // Output the feature description
    // Found the DESK
    if(foundIndex == 0){
        cout << endl << featureDescription[foundIndex] << endl;
    }
        // Found the PET PICTURE
    else if(foundIndex == 1){
        cout << endl << featureDescription[foundIndex] << endl;
    }
        // Else this is not recognized
    else{
        cout << "Input not recognized." << endl;
    }

}
