/******************************************************************
Project Nashville
CS467 - Online Capstone Project
Description: This is the class implementation file for the class escapePodRoom.
******************************************************************/

#include "escapepodroom.hpp"
#include "UI.hpp"
#include <vector>
#include <string>

/********************************************************************************
default constructor
**********************************************************************************/
escapePodRoom::escapePodRoom(class game* current_game) : room(0)
{

    this->myGame = current_game;

    setName("ESCAPE POD ROOM");
    setLongDescription("The room is barren and stark, necessary except with the vain hope that it would never have to be used. This ESCAPE POD \n"
                       "ROOM should have had at least a half-dozen pods primed and ready for jump in case of emergency, \n"
                       "yet only one ESCAPE POD remains, its soft lights gently humming. Against a side wall is a metal table with a small \n"
                       "NOTEPAD atop. A door behind leads back to the dark hall of CORRIDOR 1.");
    setShortDescription("One gently whirring ESCAPE POD lays primed in the far corner. A small NOTEPAD sits atop of a metal table against the side wall");

    // Add features to the room
    addFeature("ESCAPE POD","This is the key to your salvation, if only you knew how to get it working! Then you can ENTER it");
    addFeature("NOTEPAD", "If READ, this may give instructions to operate the escape pod.");

    // Set the interactive actions to the unordered map
    // Escape Pod interaction
    featureInteraction.insert({ "ENTER ESCAPE POD", 0 });
    featureInteraction.insert({ "ENTER THE ESCAPE POD", 0 });
    featureInteraction.insert({ "USE ESCAPE POD", 0 });
    featureInteraction.insert({ "USE THE ESCAPE POD", 0 });
    // Notepad interaction
    featureInteraction.insert({ "READ NOTEPAD", 1 });
    featureInteraction.insert({ "READ THE NOTEPAD", 1 });

}
/*********************************************************************************
lookAtFeature - will output a description if a feature is found with the look at action
*************************************************************************************/
void escapePodRoom::lookAtFeature(string featureInputName) {

    // Set variable for found index
    int foundIndex;

    // Search for the feature
    foundIndex = searchFeature(featureInputName);

    // Output the feature description
    // Found the ESCAPE POD
    if(foundIndex == 0){
        displayFeatureDescription(foundIndex);
    }
        // Found the NOTEPAD
    else if(foundIndex == 1){
        displayFeatureDescription(foundIndex);
    }
        // Else this is not recognized
    else{
        cout << "Input not recognized." << endl;
    }
}

/*********************************************************************************
interactRoom - if an interactive action was made for the  mainframe room
*************************************************************************************/
void escapePodRoom::interactRoom(string inputString) {

    // Track the feature action choice
    int featureActionChoice = -1;

    // Go through featureInteraction vector and find the associated command
    if(featureInteraction.find(inputString) != featureInteraction.end()) {
        featureActionChoice = featureInteraction[inputString];
    }

    // The case where the user wants to "ENTER" the escape pod, and able to
    if(featureActionChoice == 0 && getCharacter()->searchItem("KEY") == true && getCharacter()->getNavigation() == true){
        // Set so the flag is escape
        myGame->setEscape();

        // If you can make some kind of end game story here!
        cout <<"\nYou enter the escape pod and escape!" << endl;

    }
    // "ENTER" escape pod, but do not have the necessary stuff
    else if(featureActionChoice == 0){
        if(getCharacter()->searchItem("KEY") == false && getCharacter()->getNavigation() == true){
            cout <<"\nYou need to find some sort of item to start the ESCAPE POD with!" << endl;
        }
        else if(getCharacter()->searchItem("KEY") == true && getCharacter()->getNavigation() == false){
            cout <<"\nYou have the KEY, but need to upload directions somewhere or you will be lost in space!" << endl;
        }
        else{
            cout <<"\nYou do not have the necessary stuff to safely use the ESCAPE POD!" << endl;
        }
    }
    // Else the user READs the notepad
    else if(featureActionChoice == 1){
        cout <<"\nYou pick up the NOTEPAD and read the following:" << endl;
        cout << "|----------------------------|" << endl;
        cout << "|  ESCAPE POD CHECKLIST      |" << endl;
        cout << "|  ~~~~~~~~~~~~~~~~~~~~      |" << endl;
        cout << "|  - KEY                     |" << endl;
        cout << "|  - Coordinates uploaded    |" << endl;
        cout << "|    in NAVIGATION room's    |" << endl;
        cout << "|    COMPUTER TERMINAL       |" << endl;
        cout << "|                            |" << endl;
        cout << "|           - The Captain    |" << endl;
        cout << "|----------------------------|" << endl;
    }
    // Input not recognized
    else{
        cout << "Input not recognized." << endl;
    }
}

/********************************************************************************
destructor
**********************************************************************************/
escapePodRoom::~escapePodRoom()
{

    featureInteraction.clear();

}