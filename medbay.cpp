/******************************************************************
Project Nashville
CS467 - Online Capstone Project
Description: This is the class implementation file for the class medbay.
******************************************************************/

#include "medbay.hpp"

/********************************************************************************
default constructor
**********************************************************************************/
medbay::medbay()
{

    // Set name and descriptions
    setName("MEDBAY");
    setLongDescription("You see that you are surrounded by white walls that are very bright and clean, the air quite sterile with little in the room. \n"
                       "The only things that draw your eye are the surgical table that you woke up on with the SCALPEL on it, \n"
                       "a metal table in the corner of the room,, a MEDICAL BOX on the far wall, and a door leading to a dark hall, CORRIDOR 1. \n"
                       "You also see a COMPUTER on top of the metal table that looks functional.");
    setShortDescription("A surgical table with the SCALPEL lays in the center of the room.  A COMPUTER sits atop of a metal table in the \n"
                        "corner with a MEDICAL BOX next to it.");

    // Toggle the game to say it has been visited already since it is where we begin
    toggleEnteredRoom();

    // Add features to the room
    addFeature("SCALPEL","This item may just be useful to TAKE with you.");
    addFeature("COMPUTER", "Looks like you can HACK this computer with the skills you already have!");
    addFeature("MEDICAL BOX","If only you could OPEN this MEDICAL BOX with some kind of mechanical tool...");

    // Set the interactive actions to the unordered map
    // Computer interaction
    featureInteraction.insert({ "HACK COMPUTER", 0 });
    featureInteraction.insert({ "HACK THE COMPUTER", 0 });
    featureInteraction.insert({ "USE COMPUTER", 0 });
    featureInteraction.insert({ "USE THE COMPUTER", 0 });
    // Medical box interaction
    featureInteraction.insert({ "OPEN MEDICAL BOX", 1 });
    featureInteraction.insert({ "OPEN THE MEDICAL BOX", 1 });
    featureInteraction.insert({ "USE WRENCH ON MEDICAL BOX", 1 });
    featureInteraction.insert({ "USE WRENCH ON THE MEDICAL BOX", 1 });

}

/*********************************************************************************
isTakeableFromStarting - will return true if the player can TAKE an item from the
 starting vector.
*************************************************************************************/
bool medbay::isTakeableFromStarting(string inputItemName){

    // Only the SCALPEL can be TAKE from the starting vector for this room
    if(inputItemName == "SCALPEL" && searchItemStarting("SCALPEL") == true){
        // The item will have been taken at this point, remove scalpel from long/short description.
        setLongDescription("You see that you are surrounded by white walls that are very bright and clean, the air quite sterile with little in the room. \n"
                           "The only things that draw your eye are the empty surgical table that you woke up on, a metal table in the corner of the room, \n"
                           "a MEDICAL BOX on the far wall, and a door leading to a dark hall, CORRIDOR 1. You also see a COMPUTER on top of the metal table that looks functional.");
        setShortDescription("A surgical table lays in the center of the room.  A COMPUTER sits atop of a metal table in the corner with a MEDICAL BOX next to it.");

        return true;
    }
    else{
        return false;
    }
}

/*********************************************************************************
lookAtFeature - will output a description if a feature is found with the look at action
*************************************************************************************/
void medbay::lookAtFeature(string featureInputName) {

    // Set variable for found index
    int foundIndex = -1;

    // Search for the feature
    for(int i = 0; i<feature.size(); i++){
        if(featureInputName == feature[i]){
            foundIndex = i;
        }
    }

    // Output the feature description
    // Found the SCALPEL
    if(foundIndex == 0 && searchItemStarting("SCALPEL") == true){
        cout << endl << featureDescription[foundIndex] << endl;
    }
    // Found the COMPUTER
    else if(foundIndex == 1){
        cout << endl << featureDescription[foundIndex] << endl;
    }
    // Found the MEDICAL BOX
    else if(foundIndex == 2 && medicalBoxOpened == false){
        cout << endl << featureDescription[foundIndex] << endl;
    }
    // Found the MEDICAL BOX, but OPENED now...
    else if(foundIndex == 2 && medicalBoxOpened == true){
        cout << "\nYou look at an opened MEDICAL BOX which you got a FLARE GUN from. It is now empty." << endl;
    }
    // Else this is not recognized
    else{
        cout << "Input not recognized." << endl;
    }

}

/*********************************************************************************
interactRoom - if an interactive action was made for the Medbay room
*************************************************************************************/
void medbay::interactRoom(string inputString) {

    // Track the feature action choice
    int featureActionChoice = -1;

    // Go through featureInteraction vector and find the associated command
    if(featureInteraction.find(inputString) != featureInteraction.end()) {
        featureActionChoice = featureInteraction[inputString];
    }

    // The case where the user wants to "HACK" the computer
    if(featureActionChoice == 0){
        cout << "\nYou go to the corner metal table thinking this COMPUTER might be useful somehow! Using the advanced computer skills you have,\n"
                "you hack into the COMPUTER in order have analysis on all life-forms on the station. The search comes up with one life-form present...\n"
                "You're the only one left on the station!" << endl;
    }
    // Case where the user wants to "OPEN" the medical box
    else if(featureActionChoice == 1 && medicalBoxOpened == false){

        // Check to see if the user has a wrench
        if(getCharacter()->searchItem("WRENCH") == true){

            // Get the flare gun from the medical box
            cout <<"\nYou use the wrench to pry open a corner of the MEDICAL BOX. In it, you find a FLARE GUN! Wow! This could probably be\n"
                   "useful somewhere." << endl;
            getCharacter()->addItem(removeItemStarting("FLARE GUN"));
            // Set the medical box as opened.
            this->medicalBoxOpened = true;
        }
        else{
            // The user will need to get a wrench
            cout <<"\nYou realize you don't have the necessary equipment to open the MEDICAL BOX. If only you could find something to pry\n"
                   "open the corner of it with..." << endl;
        }
    }
    // Case where the user wants to "OPEN" the medical box, but it has already been open.
    else if(featureActionChoice == 1 && medicalBoxOpened == true){
        cout << "\nYou have already opened this MEDICAL BOX!" << endl;
    }
    // Input not recognized
    else{
        cout << "Input not recognized." << endl;
    }
}

