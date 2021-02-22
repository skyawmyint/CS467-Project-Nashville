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
    // Place all default information
    insertInteractions();

}

/********************************************************************************
constructor
**********************************************************************************/
captainsLodge::captainsLodge(bool inputLoad) : room(10)
{
    // Place all default information
    insertInteractions();
    setRoomID(10);

    // Read from txt file
    string line;
    std::ifstream myfile ("saveCaptainsLodge.txt");
    if (myfile.is_open())
    {
        while ( getline (myfile,line) )
        {
            // For starting items
            if(line == "startingItems"){
                bool endReached = false;
                while(endReached == false){
                    getline (myfile,line);
                    if(line == "END"){
                        endReached = true;
                    }
                    else{
                        addLoadGameEntry(line,0);
                    }
                }
            }
                // For dropped items
            else if(line == "droppedItems"){
                bool endReached = false;
                while(endReached == false){
                    getline (myfile,line);
                    if(line == "END"){
                        endReached = true;
                    }
                    else{
                        addLoadGameEntry(line,1);
                    }
                }
            }
                // Do other flags
            else if(line == "repeatVisit"){
                getline (myfile,line);
                addLoadGameEntry(line, 2);
            }
        }
        myfile.close();
    }

    else{
        cout << "Unable to open file";
    }
}

/*********************************************************************************
insertInteractions() - places all the feature interactions in the object
*************************************************************************************/
void captainsLodge::insertInteractions() {

    setName("CAPTAIN'S LODGE");
    setLongDescription("Clothes and half-filled suitcases are scattered across the floor in what appears to be a\n"
                       "bedroom. It looks like someone left in a hurry. An unmade bed and nightstand sit in the corner. \n"
                       "A FRAMED PHOTO of a tabby cat sits atop the nightstand. Smashed against the wall is an overturned DESK. \n"
                       "CORRIDOR 3 remains the only exit.");
    setShortDescription("You enter what appears to be a bedroom. An unmade bed and nightstand sit in the corner. \n"
                        "A FRAMED PHOTO of a tabby cat sits atop the nightstand. Smashed against the wall is an overturned DESK.");

    // Add features to the room
    addFeature("DESK","The Captain's DESK has been overturned in a frenzy. Is there something trapped underneath?\n"
                      "Maybe you can USE something sharp ON THE DESK to get it out.");
    addFeature("FRAMED PHOTO", "A FRAMED PHOTO of an orange tabby cat on the dresser. You see a small inscription\n"
                               "on the top right of the picture. You may want to READ the FRAMED PHOTO MESSAGE.");

    // Set the interactive actions to the unordered map
    // DESK interaction
    featureInteraction.insert({ "USE SCALPEL", 0 });
    featureInteraction.insert({ "USE SCALPEL ON THE DESK", 0 });
    featureInteraction.insert({ "USE SCALPEL ON DESK", 0 });
    // PET PICTURE interaction
    featureInteraction.insert({ "READ FRAMED PHOTO MESSAGE", 1 });
    featureInteraction.insert({ "READ THE FRAMED PHOTO MESSAGE", 1 });
    featureInteraction.insert({ "READ MESSAGE", 1 });
    featureInteraction.insert({ "READ THE MESSAGE", 1 });

}

/*********************************************************************************
lookAtFeature - will output a description if a feature is found with the look at action
*************************************************************************************/
void captainsLodge::lookAtFeature(string featureInputName) {

    // Set variable for found index
    int foundIndex;

    // Search for the feature
    foundIndex = searchFeature(featureInputName);

    // Output the feature description
    // Found the DESK
    if(foundIndex == 0){
        displayFeatureDescription(foundIndex);
    }
        // Found the PET PICTURE
    else if(foundIndex == 1){
        displayFeatureDescription(foundIndex);
    }
        // Else this is not recognized
    else{
        cout << "Input not recognized." << endl;
    }
}

/*********************************************************************************
interactRoom - if an interactive action was made for the captains lodge room
*************************************************************************************/
void captainsLodge::interactRoom(string inputString) {

    // Track the feature action choice
    int featureActionChoice = -1;

    // Go through featureInteraction vector and find the associated command
    if(featureInteraction.find(inputString) != featureInteraction.end()) {
        featureActionChoice = featureInteraction[inputString];
    }

    // The case where the user wants to "USE SCALPEL"
    if(featureActionChoice == 0 && getCharacter()->searchItem("SCALPEL") == true){

        // If there is still a badge
        if(searchItemStarting("BADGE") == true){

            // Place badge in player's inventory
            getCharacter()->addItem(removeItemStarting("BADGE"));

            // Output story about the badge
            cout << "\nYou see something shiny under the overturned desk. You decide to use the SCALPEL\n"
                    "you have and cut a small part of the desk. This gave it enough room to pry it out!\n"
                    "Taking the object in hand, you see that it's the captain's BADGE!" << endl;
        }
        // Badge has already been taken
        else{
            cout << "\nYou have already pried through the desk! Nothing else can be found here." << endl;
        }
    }

    // Else if there is no scalpel in inventory
    else if(featureActionChoice == 0 && getCharacter()->searchItem("SCALPEL") == false){
        cout << "\nYou do not have the necessary tool to do this!" << endl;
    }

    // Else choose to read the message
    else if(featureActionChoice == 1){

        cout << "\nYou read the inscription:\n"
                "\"My beloved Memphis.\"" << endl;
    }

    // Input not recognized
    else{
        cout << "Input not recognized." << endl;
    }
}

/*********************************************************************************
saveGame - saves to a text file flags and important vectors
*************************************************************************************/
void captainsLodge::saveGame() {

    // Create and open a text file
    std::ofstream MyFile("saveCaptainsLodge.txt");

    // Put flags from the Room parent
    saveInputFile(MyFile);

    // Close the text file
    MyFile.close();

}

/********************************************************************************
destructor
**********************************************************************************/
captainsLodge::~captainsLodge()
{

    featureInteraction.clear();

}