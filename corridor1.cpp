/******************************************************************
Project Nashville
CS467 - Online Capstone Project
Description: This is the class implementation file for the class corridor1.
******************************************************************/

#include "corridor1.hpp"

/********************************************************************************
default constructor
**********************************************************************************/
corridor1::corridor1() : room(6)
{

    // Place all default information
    insertInteractions();

}

/********************************************************************************
constructor
**********************************************************************************/
corridor1::corridor1(bool inputLoad) : room(6)
{
    // Place all default information
    insertInteractions();
    setRoomID(6);

    // Read from txt file
    string line;
    std::ifstream myfile ("saveCorridor1.txt");
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
            else if(line == "statueBroken"){
                getline (myfile,line);
                this->statueBroken = ToBoolean(line);
            }
        }
        myfile.close();
    }

    else{
        cout << "Unable to open file";
    }

    // Change description if statue is broken
    // If not broken
    if(statueBroken == true){
        setLongDescription("Bright overhead lights flicker on, illuminating a long corridor. You see another long corridor headed east, which\n"
                           "you remember as CORRIDOR 2. There are six doors along the west wall labelled from north to south as follows:\n"
                           "ESCAPE POD ROOM, MEDBAY, MAINFRAME, COMMUNICATIONS, ELECTRICAL, AND NAVIGATION. A large screen spans across \n"
                           "the other wall displaying an INTERACTIVE MAP. On the corner of the south wall, you see remains of a broken STATUE. \n"
                           "Suddenly, you hear a rumbling. The room shakes and you stumble fighting for balance.\n"
                           "You feel a sinking sensation of doom...");
        setShortDescription("You see another long corridor headed east, called CORRIDOR 2. There are six doors along the west wall: \n"
                            "ESCAPE POD ROOM, MEDBAY, MAINFRAME, COMMUNICATIONS, ELECTRICAL, and NAVIGATION. A large screen spans across \n"
                            "the east wall displaying an INTERACTIVE MAP. There are remains of a broken STATUE on the corner of the south wall.");
    }
}

/*********************************************************************************
insertInteractions() - places all the feature interactions in the object
*************************************************************************************/
void corridor1::insertInteractions() {

    setName("CORRIDOR 1");

    setLongDescription("Bright overhead lights flicker on, illuminating a long corridor. You see another long corridor headed east, which\n"
                       "you remember as CORRIDOR 2. There are six doors along the west wall labelled from north to south as follows:\n"
                       "ESCAPE POD ROOM, MEDBAY, MAINFRAME, COMMUNICATIONS, ELECTRICAL, AND NAVIGATION. A large screen spans across \n"
                       "the other wall displaying an INTERACTIVE MAP. On the corner of the south wall, you see the STATUE of a person. \n"
                       "Suddenly, you hear a rumbling. The room shakes and you stumble fighting for balance.\n"
                       "You feel a sinking sensation of doom...");
    setShortDescription("You see another long corridor headed east, called CORRIDOR 2. There are six doors along the west wall: \n"
                        "ESCAPE POD ROOM, MEDBAY, MAINFRAME, COMMUNICATIONS, ELECTRICAL, and NAVIGATION. A large screen spans across \n"
                        "the east wall displaying an INTERACTIVE MAP. There is a STATUE on the corner of the south wall.");

    // Set initial features in the room
    addFeature("INTERACTIVE MAP","You see a map with with the layout of the entire space station. It may be useful to UPLOAD the\n"
                                 "INTERACTIVE MAP to the handy tablet you have on you.");
    addFeature("STATUE", "You're not sure how this will be useful in you escaping. What will happen if you TOUCH or KICK it?");

    // Set initial feature actions in the room
    // INTERACTIVE MAP interaction
    featureInteraction.insert({ "UPLOAD INTERACTIVE MAP", 0 });
    featureInteraction.insert({ "UPLOAD THE INTERACTIVE MAP", 0 });
    featureInteraction.insert({ "UPLOAD MAP", 0 });
    featureInteraction.insert({ "UPLOAD THE MAP", 0 });
    // TOUCH STATUE interaction
    featureInteraction.insert({ "TOUCH STATUE", 1 });
    featureInteraction.insert({ "TOUCH THE STATUE", 1 });
    featureInteraction.insert({ "FEEL STATUE", 1 });
    featureInteraction.insert({ "FEEL THE STATUE", 1 });
    // KICK STATUE interaction
    featureInteraction.insert({ "KICK STATUE", 2 });
    featureInteraction.insert({ "KICK THE STATUE", 2 });
    featureInteraction.insert({ "PUSH STATUE", 2 });
    featureInteraction.insert({ "PUSH THE STATUE", 2 });
    featureInteraction.insert({ "DESTROY STATUE", 2 });
    featureInteraction.insert({ "DESTROY THE STATUE", 2 });

}

/*********************************************************************************
lookAtFeature - will output a description if a feature is found with the look at action
*************************************************************************************/
void corridor1::lookAtFeature(string featureInputName) {

    // Set variable for found index
    int foundIndex;

    // Search for the feature
    foundIndex = searchFeature(featureInputName);

    // Output the feature description
    // Found the INTERACTIVE MAP
    if(foundIndex == 0){
        displayFeatureDescription(foundIndex);
    }
        // Found the STATUE
    else if(foundIndex == 1 && statueBroken == false){
        displayFeatureDescription(foundIndex);
    }
        // FOUND the STATUE, but broken now
    else if(foundIndex == 1 && statueBroken == true){
        cout << "\nBreaking the statue seemed to do nothing..." << endl;
    }
        // Else this is not recognized
    else{
        cout << "Input not recognized." << endl;
    }
}

/*********************************************************************************
interactRoom - if an interactive action was made for this room
*************************************************************************************/
int corridor1::interactRoom(string inputString, bool inputMap) {

    // Track the feature action choice
    int featureActionChoice = -1;

    // Go through featureInteraction vector and find the associated command
    if(featureInteraction.find(inputString) != featureInteraction.end()) {
        featureActionChoice = featureInteraction[inputString];
    }

    // The case where the user wants to "UPLOAD INTERACTIVE MAP"
    if(featureActionChoice == 0 && inputMap == false){
        cout << "\nYou upload a map of the space station into your tablet. You now have access to the MAP command!" << endl;
        return 1; // Return 1 to make the map in game!

    }
    // The case where the map is already uploaded!
    else if(featureActionChoice == 0 && inputMap == true){
        cout << "\nYou already uploaded the map!" << endl;
    }
    // Case user touches the statue
    else if(featureActionChoice == 1){

        // If not broken
        if(statueBroken == false) {
            cout << "\nYou touch the statue of the man. You suddenly remember this statue was the captain of this station." << endl;
        }
        // If broken
        else{
            cout << "\nYou touch the broken remains of the statue. You never liked this man anyways..." << endl;
        }
    }
    // Case where the user kicks the statue
    else if(featureActionChoice == 2){

        // If not broken
        if(statueBroken == false){
            cout << "\nThe statue falls to the ground, shattering to many broken pieces!" << endl;
            setLongDescription("Bright overhead lights flicker on, illuminating a long corridor. You see another long corridor headed east, which\n"
                               "you remember as CORRIDOR 2. There are six doors along the west wall labelled from north to south as follows: ESCAPE POD ROOM,\n"
                               "MEDBAY, MAINFRAME, COMMUNICATIONS, ELECTRICAL, AND NAVIGATION. A large screen spans across the other wall displaying an \n"
                               "INTERACTIVE MAP. On the corner of the south wall, you see remains of a broken STATUE. Suddenly, you hear a rumbling. The room\n"
                               "shakes and you stumble fighting for balance. You feel a sinking sensation of doom...");
            setShortDescription("You see another long corridor headed east, called CORRIDOR 2. There are six doors along the west wall: ESCAPE POD ROOM,\n"
                                "MEDBAY, MAINFRAME, COMMUNICATIONS, ELECTRICAL, and NAVIGATION. A large screen spans across the east wall displaying an\n"
                                "INTERACTIVE MAP. There are remains of a broken STATUE on the corner of the south wall.");
            this->statueBroken = true;
        }
        // If broken
        else{
            cout << "\nCan't break this statue any further!" << endl;
        }
    }
        // Input not recognized

    else{
        cout << "Input not recognized." << endl;
    }

    return 0;

}

/*********************************************************************************
saveGame - saves to a text file flags and important vectors
*************************************************************************************/
void corridor1::saveGame() {

    // Create and open a text file
    std::ofstream MyFile("saveCorridor1.txt");

    // Put flags from the Room parent
    saveInputFile(MyFile);

    // Put flags from this child
    MyFile << "statueBroken\n" << this->statueBroken  << endl;

    // Close the text file
    MyFile.close();

}

/********************************************************************************
destructor
**********************************************************************************/
corridor1::~corridor1()
{

    featureInteraction.clear();

}