/******************************************************************
Project Nashville
CS467 - Online Capstone Project
Description: This is the class implementation file for the class navigation.
******************************************************************/

#include "navigation.hpp"

/********************************************************************************
default constructor
**********************************************************************************/
navigation::navigation() : room(13)
{
    setName("NAVIGATION");
    setLongDescription("The uncharted vistas of space can be seen stretching to event horizon outside of NAVIGATION's viewport. \n"
                       "Still takes your breath away. The room however has suffered worse than most, it appears several of the terminals \n"
                       "have been smashed and there are signs of a scuffle. The captain's COMPUTER however, situated at the main command chair, \n"
                       "may still have some functionality. There appears to be some sort of blinking light coming from a MESSAGE RECORDER\n"
                       "next to the COMPUTER as well. The exit leads back to CORRIDOR 1");
    setShortDescription("The captains' COMPUTER terminal sits across from his now empty leather chair with a MESSAGE RECORDER next to it.\n"
                        "These seem to be the only piece of equipment possible of functioning. This room has seen much the worse for wear.");

    // Add features to the room
    addFeature("MESSAGE RECORDER","You see a blinking red light going off on the MESSAGE RECORDER. Maybe you can PLAY THE MESSAGE\n"
                                  "and see if it's anything important.");
    addFeature("COMPUTER", "Maybe you can HACK this COMPUTER with the skills you already have!");

    // Set the interactive actions to the unordered map
    // Message recorder
    featureInteraction.insert({ "PLAY MESSAGE RECORDER", 0 });
    featureInteraction.insert({ "PLAY THE MESSAGE RECORDER", 0 });
    featureInteraction.insert({ "PLAY MESSAGE", 0 });
    featureInteraction.insert({ "PLAY THE MESSAGE", 0 });
    featureInteraction.insert({ "LISTEN TO MESSAGE RECORDER", 0 });
    featureInteraction.insert({ "LISTEN TO THE MESSAGE RECORDER", 0 });
    featureInteraction.insert({ "LISTEN TO MESSAGE", 0 });
    featureInteraction.insert({ "LISTEN TO THE MESSAGE", 0 });
    // Hacking computer
    featureInteraction.insert({ "HACK COMPUTER", 1 });
    featureInteraction.insert({ "HACK THE COMPUTER", 1 });
    featureInteraction.insert({ "USE COMPUTER", 1 });
    featureInteraction.insert({ "USE THE COMPUTER", 1 });
    // Unlock captain's lodge
    featureInteraction.insert({ "UNLOCK CAPTAIN'S LODGE", 2 });
    featureInteraction.insert({ "UNLOCK THE CAPTAIN'S LODGE", 2 });
    // Upload nav comm module
    featureInteraction.insert({ "UPLOAD NAV COMM UPDATE MODULE", 3 });
    featureInteraction.insert({ "UPLOAD THE NAV COMM UPDATE MODULE", 3 });

}

/*********************************************************************************
lookAtFeature - will output a description if a feature is found with the look at action
*************************************************************************************/
void navigation::lookAtFeature(string featureInputName) {

    // Set variable for found index
    int foundIndex;

    // Search for the feature
    foundIndex = searchFeature(featureInputName);

    // Output the feature description
    // Found the MESSAGE RECORDER
    if(foundIndex == 0){
        displayFeatureDescription(foundIndex);
    }
    // Found the COMPUTER
    else if(foundIndex == 1){
        displayFeatureDescription(foundIndex);
    }
        // Else this is not recognized
    else{
        cout << "Input not recognized." << endl;
    }

}

/*********************************************************************************
interactRoom - if an interactive action was made for the navigation room
*************************************************************************************/
void navigation::interactRoom(string inputString) {

    // Track the feature action choice
    int featureActionChoice = -1;

    // Go through featureInteraction vector and find the associated command
    if(featureInteraction.find(inputString) != featureInteraction.end()) {
        featureActionChoice = featureInteraction[inputString];
    }

    // The case where the user wants to "PLAY MESSAGE"
    if(featureActionChoice == 0){
        cout << "\nYou click the play button on the MESSAGE RECORDER and hear the following:\n"
                "\"Hello? Navigation Officer Tom, this is the captain speaking! When you get this message we need to discuss\n"
                "changing the passcode to the mainframe computer. We've been using the same one FOREVER!! Maybe something dumb\n"
                "like my favorite crew member's birthday with my dear pet's name? HAHA!\"" << endl;
    }

    // If the player wants to do anything with the computer, but there is no power
    else if((featureActionChoice == 1 || featureActionChoice == 2 || featureActionChoice == 3) && (getCharacter()->getPanel() == false || getCharacter()->getPrimer() == false)){
        cout << "\nUnfortunately, the COMPUTER has no power to it. Maybe you can get it working by restoring power somewhere." << endl;
    }

    // Power restored and the player wants to hack computer
    else if(featureActionChoice == 1 && getCharacter()->getPrimer() == true && getCharacter()->getPanel() == true){

        cout << "\nYou hack into the computer looking for any sort of information. Reading through all the text, you\n"
                "gather that you can UNLOCK THE CAPTAIN'S LODGE here to gain entry there. You also see that you can\n"
                "even UPLOAD a NAV COMM UPDATE MODULE to have safe passage on an escape pod." << endl;
    }

    // Unlock captain's lodge option
    else if(featureActionChoice == 2 && getCharacter()->getPrimer() == true && getCharacter()->getPanel() == true){

        if(getCharacter()->getCaptainDoor() == false){
            // Unlock and show output
            getCharacter()->setCaptainDoor();
            cout << "\nYou enter in the computer to unlock the captain's lodge. You see a success screen following the\n"
                    "input. Maybe you should go check that room out!" << endl;
        }
        else{
            cout << "\nYou've already unlocked the door!" << endl;
        }
    }

    // Upload nav comm update module
    else if(featureActionChoice == 3 && getCharacter()->getPrimer() == true && getCharacter()->getPanel() == true) {

        // When it hasn't been uploaded yet
        if(getCharacter()->getNavigation() == false){

            // If the character has the nav comm update module
            if(getCharacter()->searchItem("NAV COMM UPDATE MODULE") == true){
                getCharacter()->setNavigation();
                // Remove the nav comm update module from inventory
                free(getCharacter()->removeItem("NAV COMM UPDATE MODULE"));
                cout << "You take the NAV COMM UPDATE MODULE from your inventory and place it in the computer to upload.\n"
                        "You see the screen confirming that it has been successfully uploaded. The escape pod can now get\n"
                        "a safe location!" << endl;
            }
            // The character does not have
            else{
                cout << "\nYou do not have the necessary item to do this!" << endl;
            }
        }
        // It has already been uploaded
        else{
            cout << "\nYou've already uploaded a navigation module to the computer!" << endl;
        }
    }

    // Input not recognized
    else{
        cout << "Input not recognized." << endl;
    }
}

/*********************************************************************************
saveGame - saves to a text file flags and important vectors
*************************************************************************************/
void navigation::saveGame() {

    // Create and open a text file
    std::ofstream MyFile("saveNavigation.txt");

    // Put flags from the Room parent
    saveInputFile(MyFile);

    // Close the text file
    MyFile.close();

}

/********************************************************************************
destructor
**********************************************************************************/
navigation::~navigation()
{

    featureInteraction.clear();

}