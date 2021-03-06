/******************************************************************
Project Nashville
CS467 - Online Capstone Project
Description: This is the class implementation file for the class medbay.
******************************************************************/

#include "medbay.hpp"

/********************************************************************************
default constructor
**********************************************************************************/
medbay::medbay() : room(2)
{
    // Place all default information
    insertInteractions();

}

/********************************************************************************
constructor
**********************************************************************************/
medbay::medbay(bool inputLoad) : room(2)
{
    // Place all default information
    insertInteractions();
    setRoomID(2);

    // Read from txt file
    string line;
    std::ifstream myfile ("saveMedbay.txt");
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

    // Edit description based on flag
    if(searchItemStarting("SCALPEL") == false){
        // The item will have been taken at this point, remove scalpel from long/short description.
        setLongDescription("You see that you are surrounded by white walls that are very bright and clean, the air \n"
                           "quite sterile with little in the room. The only things that draw your eye are the empty surgical \n"
                           "table that you woke up on, a metal table in the corner of the room, a MEDICAL BOX on the far \n"
                           "wall, and a door leading to a dark hall, CORRIDOR 1. You also see a COMPUTER on top of the \n"
                           "metal table that looks functional.");
        setShortDescription("A surgical table lays in the center of the room. A COMPUTER sits atop of a metal table \n"
                            "in the corner with a MEDICAL BOX next to it. There is a door leading to CORRIDOR 1.");
    }
}

/*********************************************************************************
insertInteractions() - places all the feature interactions in the object
*************************************************************************************/
void medbay::insertInteractions() {

    // Set name and descriptions
    setName("MEDBAY");
    setLongDescription("You see that you are surrounded by white walls that are very bright and clean, the air quite \n"
                       "sterile with little in the room. The only things that draw your eye are the surgical table that you \n"
                       " woke up on with the SCALPEL on it, a metal table in the corner of the room, a MEDICAL BOX on the \n"
                       "far wall, and a door leading to a dark hall, CORRIDOR 1. You also see a COMPUTER on top of the metal \n"
                       "table that looks functional.");
    setShortDescription("A surgical table with the SCALPEL lays in the center of the room. A COMPUTER sits atop of \n"
                        "a metal table in the corner with a MEDICAL BOX next to it. There is a door leading to CORRIDOR 1.");

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
        setLongDescription("You see that you are surrounded by white walls that are very bright and clean, the air quite \n"
                           "sterile with little in the room. The only things that draw your eye are the empty surgical table that you \n"
                           "woke up on, a metal table in the corner of the room,  a MEDICAL BOX on the far wall, and a door leading to \n"
                           "a dark hall, CORRIDOR 1. You also see a COMPUTER on top of the metal table that looks functional.");
        setShortDescription("A surgical table lays in the center of the room. A COMPUTER sits atop of a metal table in the corner \n"
                            "with a MEDICAL BOX next to it. There is a door leading to CORRIDOR 1.");

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
    int foundIndex;

    // Search for the feature
    foundIndex = searchFeature(featureInputName);

    // Output the feature description
    // Found the SCALPEL
    if(foundIndex == 0 && searchItemStarting("SCALPEL") == true){
        displayFeatureDescription(foundIndex);
    }
    // Found the COMPUTER
    else if(foundIndex == 1){
        displayFeatureDescription(foundIndex);
    }
    // Found the MEDICAL BOX
    else if(foundIndex == 2 && searchItemStarting("FLARE GUN") == true){
        displayFeatureDescription(foundIndex);
    }
    // Found the MEDICAL BOX, but OPENED now...
    else if(foundIndex == 2 && searchItemStarting("FLARE GUN") == false){
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
    else if(featureActionChoice == 1 && searchItemStarting("FLARE GUN") == true){

        // Check to see if the user has a wrench
        if(getCharacter()->searchItem("WRENCH") == true){

            // Get the flare gun from the medical box
            cout <<"\nYou use the wrench to pry open a corner of the MEDICAL BOX. In it, you find a FLARE GUN! Wow! This could probably be\n"
                   "useful somewhere." << endl;
            getCharacter()->addItem(removeItemStarting("FLARE GUN"));
        }
        else{
            // The user will need to get a wrench
            cout <<"\nYou realize you don't have the necessary equipment to open the MEDICAL BOX. If only you could find something to pry\n"
                   "open the corner of it with..." << endl;
        }
    }
    // Case where the user wants to "OPEN" the medical box, but it has already been open.
    else if(featureActionChoice == 1 && searchItemStarting("FLARE GUN") == false){
        cout << "\nYou have already opened this MEDICAL BOX!" << endl;
    }
    // Input not recognized
    else{
        cout << "Input not recognized." << endl;
    }
}

/*********************************************************************************
saveGame - saves to a text file flags and important vectors
*************************************************************************************/
void medbay::saveGame() {

    // Create and open a text file
    std::ofstream MyFile("saveMedbay.txt");

    // Put flags from the Room parent
    saveInputFile(MyFile);

    // Close the text file
    MyFile.close();

}

/********************************************************************************
destructor
**********************************************************************************/
medbay::~medbay()
{

    featureInteraction.clear();

}