/******************************************************************
Project Nashville
CS467 - Online Capstone Project
Description: This is the class implementation file for the class cafeteria.
******************************************************************/

#include "cafeteria.hpp"

/********************************************************************************
default constructor
**********************************************************************************/
cafeteria::cafeteria() : room(5)
{

    setName("CAFETERIA");
    setLongDescription("You see a large room filled with cafeteria style bench tables. At the back of the room is\n"
                       "a long counter stacked with serving trays filled with half-rotting sandwiches. Looks like SLOPPY JOES.\n"
                       "Yuck.  Smoke plumes from a STOVE behind the counter. CORRIDOR 3 looms behind.");
    setShortDescription("You enter a large room filled with cafeteria style bench tables. At the back of the room is a long counter \n"
                        "stacked with serving trays of rotting SLOPPY JOES. Smoke plumes from a STOVE behind the counter.");

    // Add features to the room
    addFeature("STOVE","At first glance this smoking STOVE seems quite unsafe, oil leaks form the bottom.\n"
                       "Maybe you can PLACE a container UNDER the STOVE to use the oil somewhere?");
    addFeature("SLOPPY JOES", "The SLOPPY JOES are apparently a station favorite. What if you EAT one?");

    // Set the interactive actions to the unordered map
    // Stove interaction
    featureInteraction.insert({ "PLACE EMPTY CONTAINER UNDER STOVE", 0 });
    featureInteraction.insert({ "PLACE EMPTY CONTAINER UNDER THE STOVE", 0 });
    featureInteraction.insert({ "PLACE THE EMPTY CONTAINER UNDER STOVE", 0 });
    featureInteraction.insert({ "PLACE THE EMPTY CONTAINER UNDER THE STOVE", 0 });
    featureInteraction.insert({ "FILL THE EMPTY CONTAINER", 0 });
    featureInteraction.insert({ "FILL EMPTY CONTAINER", 0 });
    // Sloppy Joes interaction
    featureInteraction.insert({ "EAT SLOPPY JOES", 1 });
    featureInteraction.insert({ "EAT THE SLOPPY JOES", 1 });
    featureInteraction.insert({ "GRAB SLOPPY JOES", 1 });
    featureInteraction.insert({ "GRAB THE SLOPPY JOES", 1 });

}

/*********************************************************************************
lookAtFeature - will output a description if a feature is found with the look at action
*************************************************************************************/
void cafeteria::lookAtFeature(string featureInputName) {

    // Set variable for found index
    int foundIndex = -1;

    // Search for the feature
    foundIndex = searchFeature(featureInputName);

    // Output the feature description
    // Found the STOVE
    if(foundIndex == 0){
        displayFeatureDescription(foundIndex);
    }
        // Found the SLOPPY JOES
    else if(foundIndex == 1){
        displayFeatureDescription(foundIndex);
    }
        // Else this is not recognized
    else{
        cout << "Input not recognized." << endl;
    }
}

/*********************************************************************************
interactRoom - if an interactive action was made for the room
*************************************************************************************/
void cafeteria::interactRoom(string inputString) {

    // Track the feature action choice
    int featureActionChoice = -1;

    // Go through featureInteraction vector and find the associated command
    if(featureInteraction.find(inputString) != featureInteraction.end()) {
        featureActionChoice = featureInteraction[inputString];
    }

    // The case where the user wants to "FILL" the empty container
    if(featureActionChoice == 0 && getCharacter()->searchItem("EMPTY CONTAINER") == true && containerFilled == false){
        cout << "\nThinking the oil could be of use somewhere, you place the EMPTY CONTAINER under the STOVE.\n"
                "You fill up the container and take it with you!" << endl;
        // Change item into a filled container
        getCharacter()->returnItem(getCharacter()->itemIndex("EMPTY CONTAINER"))->setName("FILLED CONTAINER");
        getCharacter()->returnItem(getCharacter()->itemIndex("FILLED CONTAINER"))->setDescription("A container filled up with oil, you can probably EMPTY it somewhere!");
        this->containerFilled = true;
    }
    // Case where the user wants to "EAT" the sloppy joes
    else if(featureActionChoice == 1) {
        cout << "\nYou seriously can't be thinking of eating the rotting SLOPPY JOES!!" << endl;
    }
        // Input not recognized
    else{
        cout << "Input not recognized." << endl;
    }
}