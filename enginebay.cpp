/******************************************************************
Project Nashville
CS467 - Online Capstone Project
Description: This is the class implementation file for the class engineBay.
******************************************************************/

#include "enginebay.hpp"

/********************************************************************************
default constructor
**********************************************************************************/
engineBay::engineBay() : room(3)
{

    setName("ENGINE BAY");
    setLongDescription("Multiple tables covered in scattered parts in various stages of disrepair mark the ENGINE BAY. \n"
                       "Normally a shop filled with the hustle and bustle of ongoing maintenance, the silence present is quite eerie. \n"
                       "In the back corner sits the PUMP PRIMER, needed for restoring power. On the floor right at your feet lies \n"
                       "a discarded pair of WORKER'S JUMPERS which, alas, are not your size. Behind you is the route back to CORRIDOR 3.");
    setShortDescription("Multiple tables lay covered with various disassembled engine parts. In the back corner sits a PUMP PRIMER. \n"
                        "At your feet lies a pair of forgotten WORKERS' JUMPERS.");

    // Add features to the room
    addFeature("PUMP PRIMER","If you FILL the PUMP PRIMER with fuel, perhaps power could be restored.");
    addFeature("WORKER'S JUMPERS", "A discarded pair of WORKER'S JUMPERS. Perhaps you could OPEN THE POCKETS OF THE WORKER'S JUMPERS\n"
                                   "to see if there is something useful!");

    // Set the interactive actions to the unordered map
    // PUMP PRIMER
    featureInteraction.insert({ "FILL PUMP PRIMER", 0 });
    featureInteraction.insert({ "FILL THE PUMP PRIMER", 0 });
    // WORKERS' JUMPERS
    featureInteraction.insert({ "OPEN THE POCKETS OF THE WORKER'S JUMPERS", 1 });
    featureInteraction.insert({ "OPEN POCKETS OF THE WORKER'S JUMPERS", 1 });
    featureInteraction.insert({ "OPEN THE POCKETS OF WORKER'S JUMPERS", 1 });
    featureInteraction.insert({ "OPEN POCKETS OF WORKER'S JUMPERS", 1 });
    featureInteraction.insert({ "OPEN POCKETS", 1 });
    featureInteraction.insert({ "OPEN THE POCKETS", 1 });

}

/*********************************************************************************
lookAtFeature - will output a description if a feature is found with the look at action
*************************************************************************************/
void engineBay::lookAtFeature(string featureInputName) {

    // Set variable for found index
    int foundIndex;

    // Search for the feature
    foundIndex = searchFeature(featureInputName);

    // Output the feature description
    // Found the PUMP PRIMER
    if(foundIndex == 0 && getCharacter()->getPrimer() == false){
        displayFeatureDescription(foundIndex);
    }
    else if(foundIndex == 0 && getCharacter()->getPrimer() == true){
        cout << "\nYou see that the PUMP PRIMER is operating with the fuel you've added to it." << endl;
    }
        // Found the WORKERS' JUMPERS
    else if(foundIndex == 1){
        displayFeatureDescription(foundIndex);
    }
        // Else this is not recognized
    else{
        cout << "Input not recognized." << endl;
    }
}

/*********************************************************************************
interactRoom - if an interactive action was made for the engine bay room
*************************************************************************************/
void engineBay::interactRoom(string inputString) {

    // Track the feature action choice
    int featureActionChoice = -1;

    // Go through featureInteraction vector and find the associated command
    if(featureInteraction.find(inputString) != featureInteraction.end()) {
        featureActionChoice = featureInteraction[inputString];
    }

    // The case where the user wants to "FILL THE PUMP PRIMER"
    if(featureActionChoice == 0 && getCharacter()->getPrimer() == false){

        // If player has the FILLED CONTAINER
        if(getCharacter()->searchItem("FILLED CONTAINER") == true){

            // Set the Pump Primer flag as true now
            getCharacter()->setPrimer(true);

            // Output story of putting in gas
            cout << "\nYou lift up the container of oil you've collected to fill up the PUMP PRIMER. You empty your container and\n"
                    "discard the empty container. You yank on the handle of the pump and hear the noise of the pump working!" << endl;

            // If electrical panel was already fixed, output that power is restored now!
            if(getCharacter()->getPanel() == true){
                cout << "\nYou see the lights flicker. After a couple seconds, the room turns brighter. Ah yes! You've restored\n"
                        "power to the entire station! Maybe there are things around the station that you can use now!" << endl;
            }

            // Delete the FILLED CONTAINER from the players' inventory
            free(getCharacter()->removeItem("FILLED CONTAINER"));

        }
        // If player does not have the FILLED CONTAINER
        else{
            cout << "\nYou need some kind of container of fuel in order to do this!" << endl;
        }
    }
    // The case where the pump primer is filled!
    else if(featureActionChoice == 0 && getCharacter()->getPrimer() == true){
        cout << "\nThe pump primer is operating with the fuel you've already added to it." << endl;
    }

    // The case where the player wants to open pockets
    else if(featureActionChoice == 1){

        // If pockets are not opened
        if(this->jumpersOpened == false){
            // Now say as opened
            this->jumpersOpened = true;
            // Place the workers gloves in character's inventory
            cout <<"\nYou pick up the discarded worker's jumpers on the floor. You see that it has some big pockets on it and\n"
                   "decide to look through them. On the right waist pocket, you feel something... You grab it and take it out.\n"
                   "It's a pair of WORK GLOVES! You take this along with you, thinking it can come in handy!"<< endl;
            getCharacter()->addItem(removeItemStarting("WORK GLOVES"));
        }

        // If pockets are opened already
        else{
            cout << "\nYou've already looked through the pockets!" << endl;
        }
    }

    // Invalid
    else{
        cout << "Input not recognized." << endl;
    }
}

/*********************************************************************************
saveGame - saves to a text file flags and important vectors
*************************************************************************************/
void engineBay::saveGame() {

    // Create and open a text file
    std::ofstream MyFile("saveEngineBay.txt");

    // Put flags from the Room parent
    saveInputFile(MyFile);

    // Put flags from this child
    MyFile << "jumpersOpened \n" << this->jumpersOpened  << endl;

    // Close the text file
    MyFile.close();

}

/********************************************************************************
destructor
**********************************************************************************/
engineBay::~engineBay()
{

    featureInteraction.clear();

}