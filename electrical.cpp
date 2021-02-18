/******************************************************************
Project Nashville
CS467 - Online Capstone Project
Description: This is the class implementation file for the class electrical.
******************************************************************/

#include "electrical.hpp"

/********************************************************************************
default constructor
**********************************************************************************/
electrical::electrical() : room(11)
{
    setName("ELECTRICAL");
    setLongDescription("There is the smell of burning ozone accompanied with a sizzling sound that makes your eardrums ring \n"
                       "as you enter ELECTRICAL. Against the far wall a shattered ELECTRICAL PANEL emits wave after wave of dangerous sparks, \n"
                       "being quite dangerous to approach and causing the lights to flicker. In the corner however, safely out of range of \n"
                       "the panel, sits a COMPUTER on a desk that somehow seems to have power...you can always go back to CORRIDOR 1.");
    setShortDescription("A shattered ELECTRICAL PANEL hums on the far side of the room. In a tiny corner across the way \n"
                        "a COMPUTER sits alone and lonely.");

    // Add features to the room
    addFeature("COMPUTER","There appears to be some kind of EMAIL on the screen that you can READ.");
    addFeature("ELECTRICAL PANEL", "You could probably REPAIR this if you had some sort of PPE to handle it!");

    // Set the interactive actions to the unordered map
    // COMPUTER
    featureInteraction.insert({ "READ EMAIL", 0 });
    featureInteraction.insert({ "OPEN EMAIL", 0 });
    featureInteraction.insert({ "READ THE EMAIL", 0 });
    featureInteraction.insert({ "OPEN THE EMAIL", 0 });
    // ELECTRICAL PANEL
    featureInteraction.insert({ "REPAIR ELECTRICAL PANEL", 1 });
    featureInteraction.insert({ "REPAIR THE ELECTRICAL PANEL", 1 });
    featureInteraction.insert({ "FIX ELECTRICAL PANEL", 1 });
    featureInteraction.insert({ "FIX THE ELECTRICAL PANEL", 1 });

}

/*********************************************************************************
lookAtFeature - will output a description if a feature is found with the look at action
*************************************************************************************/
void electrical::lookAtFeature(string featureInputName) {

    // Set variable for found index
    int foundIndex;

    // Search for the feature
    foundIndex = searchFeature(featureInputName);

    // Output the feature description
    // Found the COMPUTER
    if(foundIndex == 0){
        displayFeatureDescription(foundIndex);
    }
    // Found the ELECTRICAL PANEL
    else if(foundIndex == 1){
        displayFeatureDescription(foundIndex);
    }
        // Else this is not recognized
    else{
        cout << "Input not recognized." << endl;
    }
}

/*********************************************************************************
interactRoom - if an interactive action was made for the electrical room
*************************************************************************************/
void electrical::interactRoom(string inputString) {

    // Track the feature action choice
    int featureActionChoice = -1;

    // Go through featureInteraction vector and find the associated command
    if(featureInteraction.find(inputString) != featureInteraction.end()) {
        featureActionChoice = featureInteraction[inputString];
    }

    // The case where the user wants to "READ EMAIL"
    if(featureActionChoice == 0){

        cout <<"\nYou go towards the computer and read the following email:" << endl;
        cout << "|-------------------------------------------|" << endl;
        cout << "| I need help in the CAFETERIA!!            |" << endl;
        cout << "| I see sparks coming from the stove!!      |" << endl;
        cout << "| This could be dangerous with the leaky    |" << endl;
        cout << "| oil. I need one of you electrical guys    |" << endl;
        cout << "| to come right away!                       |" << endl;
        cout << "|                                           |" << endl;
        cout << "|                     - Chef Ramsay         |" << endl;
        cout << "|-------------------------------------------|" << endl;
    }

    // The case where the user repairs the electrical panel
    else if(featureActionChoice == 1 && getCharacter()->getPanel() == false){

        // If player has the WORK GLOVES
        if(getCharacter()->searchItem("WORK GLOVES") == true){

            // Set the panel repaired flag as true now
            getCharacter()->setPanel(true);

            // Output story of repairing the electrical panel
            cout << "\nYou grab the WORK GLOVES you have on you and put them on your hands. Now's the time to put all your\n"
                    "handiness skills to the test. Connecting random wires to sockets, flipping switches, and pulling on\n"
                    "random stuff seems to be your strategy... You've done the best you could. Maybe it worked??"<< endl;

            // If pump primer was already fixed, output that power is restored now!
            if(getCharacter()->getPrimer() == true){
                cout << "\nYou suddenly hear the noise of something turning on outside the corridor. Ah yes! You've restored the\n"
                        "main power to the entire station! Maybe there are things around the station that you can use now!" << endl;
            }
        }
            // If player does not have the WORK GLOVES
        else{
            cout << "\nYou need some kind PPE to work on this safely!" << endl;
        }
    }

    else if(featureActionChoice == 1 && getCharacter()->getPanel() == true) {
        cout << "\nThough the ELECTRICAL PANEL still emits dangerous sparks, you've already repaired it to the best of\n"
                "your ability." << endl;
    }

    // Input not recognized
    else{
        cout << "Input not recognized." << endl;
    }
}
