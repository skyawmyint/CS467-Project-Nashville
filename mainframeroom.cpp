/******************************************************************
Project Nashville
CS467 - Online Capstone Project
Description: This is the class implementation file for the class mainframeRoom.
******************************************************************/

#include "mainframeroom.hpp"
#include "UI.hpp"
#include <vector>
#include <string>

/******************************************************************************
default constructor
**********************************************************************************/
mainframeRoom::mainframeRoom(class game* current_game) : room(4)
{
    this->game = current_game;
    this->timer_disabled = false;
    this->badge = false;
    setName("MAINFRAME");
    setLongDescription("If NAVIGATION could be considered the mind of the space station, and the CAPTAIN'S CABIN the soul, \n"
                       "then this room, the MAINFRAME, is surely the heart. Normally off limits to all but the most trusted of personnel, \n"
                       "you feel a bit overwhelmed at the vast complexity before you. Panels of switches stretch across the walls. \n"
                       "However your eye is drawn to what looks like a central COMPUTER terminal with a NOTE taped to the corner that appears \n"
                       "to be functional. Behind you lies the dark hall back to CORRIDOR 1.");
    setShortDescription("Panels of switches stretch across the walls. Amidst the sounds of hard drives and servers cooling, \n"
                        "a table on the far side contains a COMPUTER terminal with a NOTE attached.");
    // Add features to the room
    addFeature("COMPUTER", "Looks like you can HACK this computer with the skills you already have!");
    addFeature("NOTE", "Looks like a crew member left a note.");
    
    featureInteraction.insert({ "HACK COMPUTER", 0 });
    featureInteraction.insert({ "HACK THE COMPUTER", 0 });

}
/*********************************************************************************
lookAtFeature - will output a description if a feature is found with the look at action
*************************************************************************************/
void mainframeRoom::lookAtFeature(string featureInputName) {

    // Set variable for found index
    int foundIndex;

    // Search for the feature
    foundIndex = searchFeature(featureInputName);

    // Output the feature description
    // Found the COMPUTER
    if(foundIndex == 0){
        displayFeatureDescription(foundIndex);
    }
        // Found the NOTE
    else if(foundIndex == 1){
        displayFeatureDescription(foundIndex);
        cout << "|---------------------------------------|" << endl;
        cout << "| Who left O2 canisters in front of     |" << endl;
        cout << "| storage? They're blocking the door!   |" << endl;
        cout << "| They're too heavy to move. We might   |" << endl;
        cout << "| have to blast them away!              |" << endl;
        cout << "|---------------------------------------|" << endl;
    }
        // Else this is not recognized
    else{
        cout << "Input not recognized." << endl;
    }

}

/*********************************************************************************
interactRoom - if an interactive action was made for the  mainframe room
*************************************************************************************/
void mainframeRoom::interactRoom(string inputString) {

    // Track the feature action choice
    int featureActionChoice = -1;
    
    // Go through featureInteraction vector and find the associated command
    if(featureInteraction.find(inputString) != featureInteraction.end()) {
        featureActionChoice = featureInteraction[inputString];
    }
    
    // The case where the user wants to "HACK" the computer
    if(featureActionChoice == 0){
        cout << "\nYou boot up the computer.\n"<< endl;
        cout << "|----------------------------------------|" << endl;
        cout << "|  SELF DESTRUCTION ENABLED              |" << endl;
        cout << "|  Enter code to disable: _ _ _ _ _ _ _  |" << endl;
        cout << "|                                        |" << endl;
        cout << "|----------------------------------------|" << endl;
        cout << endl;
        UI* user_interface = new UI();
        vector<string>pass = user_interface->getInput();
        if(pass.size() >= 1 && pass[0] == "0101CAT"){
            game->disableGameTimer();
            cout << "\nSuccess!\n"<< endl;
            cout << "|----------------------------|" << endl;
            cout << "|                            |" << endl;
            cout << "|  SELF DESTRUCTION DISABLED |" << endl;
            cout << "|                            |" << endl;
            cout << "|----------------------------|" << endl;
        }
        free(user_interface);
    }
}

