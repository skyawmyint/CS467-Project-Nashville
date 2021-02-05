/******************************************************************
Project Nashville
CS467 - Online Capstone Project
Description: This is the class implementation file for the class corridor2.
******************************************************************/

#include "corridor2.hpp"

/********************************************************************************
default constructor
**********************************************************************************/
corridor2::corridor2() : room(8)
{

    // Set initial room descriptions
    setName("CORRIDOR 2");
    setLongDescription("You enter a long horizontal corridor with CORRIDOR 1 and 3 on either side. A LARGE WINDOW on the north\n"
                       "wall overlooks the stars. As you walk through the corridor, your foot hits something soft. It’s a ... person.\n"
                       "A MAN in a silver spacesuit lays face down on the floor. You give him a nudge, but he does not respond. He may not be breathing.");
    setShortDescription("You enter a long horizontal corridor with CORRIDOR 1 and 2 on either side. A LARGE WINDOW on the north wall overlooks the stars.\n"
                        "You see an unresponsive MAN on the floor.");


    // Set initial features in the room
    addFeature("LARGE WINDOW","You see a LARGE WINDOW that shows the best view of outer space on the station. You may be able to LOOK OUT it for a better view!");
    addFeature("MAN", "You look closer at the MAN. He is dead...however you see a shiny tool underneath the body. You may be able to PULL or PUSH \n"
                      "the MAN to reveal the tool.");

    // Set initial feature actions in the room
    // LARGE WINDOW interaction
    featureInteraction.insert({ "LOOK OUT LARGE WINDOW", 0 });
    featureInteraction.insert({ "LOOK OUT WINDOW", 0 });
    featureInteraction.insert({ "LOOK OUT THE LARGE WINDOW", 0 });
    featureInteraction.insert({ "VIEW OUT LARGE WINDOW", 0 });
    // MAN interaction
    featureInteraction.insert({ "PULL THE MAN", 1 });
    featureInteraction.insert({ "PULL MAN", 1 });
    featureInteraction.insert({ "PUSH THE MAN", 1 });
    featureInteraction.insert({ "PUSH MAN", 1 });
}

/*********************************************************************************
lookAtFeature - will output a description if a feature is found with the look at action
*************************************************************************************/
void corridor2::lookAtFeature(string featureInputName) {

    // Set variable for found index
    int foundIndex = -1;

    // Search for the feature
    foundIndex = searchFeature(featureInputName);

    // Output the feature description
    // Found the LARGE WINDOW
    if(foundIndex == 0){
        displayFeatureDescription(foundIndex);
    }
        // Found the MAN
    else if(foundIndex == 1 && wrenchTaken == false){
        displayFeatureDescription(foundIndex);
    }
        // Found the MAN without the WRENCH anymore
    else if(foundIndex == 1 && wrenchTaken == true){
        cout << "\nYou see the dead MAN whom you took the WRENCH from on the floor." << endl;
    }
        // Else this is not recognized
    else{
        cout << "Input not recognized." << endl;
    }
}

/*********************************************************************************
interactRoom - if an interactive action was made for the Medbay room
*************************************************************************************/
void corridor2::interactRoom(string inputString) {

    // Track the feature action choice
    int featureActionChoice = -1;

    // Go through featureInteraction vector and find the associated command
    if(featureInteraction.find(inputString) != featureInteraction.end()) {
        featureActionChoice = featureInteraction[inputString];
    }

    // The case where the user wants to "LOOK OUT THE WINDOW"
    if(featureActionChoice == 0){
        cout << "\nYou look out the LARGE WINDOW and see what appears to be a satellite crashed into the side of the station. Looks like it\n"
                "entered part of the REACTOR area...It may be useful to take a visit there!"<< endl;
    }
        // Case where the user wants to PUSH the man
    else if(featureActionChoice == 1 && wrenchTaken == false){

        // Get the WRENCH from the MAN
        cout <<"\nYou use your strength to move the MAN off from the tool. Man! Should have worked out a bit more. You finally use all your\n"
               "might to lift him slightly in order to remove it! You pick up a WRENCH!" << endl;
        getCharacter()->addItem(removeItemStarting("WRENCH"));

        // Set a new long description
        setLongDescription("You enter a long horizontal corridor with CORRIDOR 1 and 3 on either side. A LARGE WINDOW on the north\n"
                           "wall overlooks the stars. As you walk through the corridor, you see the MAN in the silver spacesuit laying\n"
                           "face down on the floor whom you found the WRENCH from.");

        // Set the wrench as taken!
        this->wrenchTaken = true;

    }

        // Case where the user wants to Push the man, but already did and took his wrench.
    else if(featureActionChoice == 1 && wrenchTaken == true){
        cout << "\nYou've already gotten everything you need from this MAN. Let him rest in peace!" << endl;
    }
        // Input not recognized
    else{
        cout << "Input not recognized." << endl;
    }
}

