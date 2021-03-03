/******************************************************************
Project Nashville
CS467 - Online Capstone Project
Description: This is the class implementation file for the class reactor.
******************************************************************/

#include "reactor.hpp"

/********************************************************************************
default constructor
**********************************************************************************/
reactor::reactor() : room(1)
{
    // Place all default information
    insertInteractions();

}

/********************************************************************************
constructor
**********************************************************************************/
reactor::reactor(bool inputLoad) : room(1)
{
    // Place all default information
    insertInteractions();
    setRoomID(1);

    // Read from txt file
    string line;
    std::ifstream myfile ("saveReactor.txt");
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
            else if(line == "noisyValveOpen"){
                getline (myfile,line);
                this->noisyValveOpen = ToBoolean(line);
            }
        }
        myfile.close();
    }
    else{
        cout << "Unable to open file";
    }

    // Change description based on flag
    if(noisyValveOpen == false){
        // Now update the descriptions to show it is less noisy!
        setLongDescription("This room is more maze than a room with pipes, ducts and catwalks twisting and turning into \n"
                           "the darkness. You see the VALVE that you closed to stop that deafening clanking. However, you still \n"
                           "hear a pinging...this is coming from a crashed SATELLITE on the side of the reactor hull! \n"
                           "Maybe there's something useful if you look closely? CORRIDOR 3 is the only way out.");
        setShortDescription("You see a closed VALVE in this maze of a room with a SATELLITE crashed to the side of \n"
                            "the reactor hull. CORRIDOR 3 is the only way out.");
    }
}

/*********************************************************************************
insertInteractions() - places all the feature interactions in the object
*************************************************************************************/
void reactor::insertInteractions() {

    setName("REACTOR");
    setLongDescription("This room is more maze than a room with pipes, ducts and catwalks twisting and turning into \n"
                       "the darkness. An extremely loud, almost-deafening clanking can be heard coming from an open VALVE deep \n"
                       "within the machine. Your eardrums splitting, it is impossible to discern anything else about this \n"
                       "space while the racket continues. The door back to CORRIDOR 3 at least offers a quiet place to think.");
    setShortDescription("A VALVE that has been the source of a deafening noise rests deep within the heart of this room.\n"
                        "Not much else appears to be of note. CORRIDOR 3 is the only way out.");

    // Add features to the room
    addFeature("VALVE","You may be able to CLOSE or TURN the VALVE  with a tool in order to stop the noise!");
    addFeature("SATELLITE", "You see something attached to the hull of the SATELLITE... \n"
                            "It's a NAV COMM UPDATE MODULE! It may be handy for you to TAKE this!");

    // Set the interactive actions to the unordered map
    // VALVE interaction
    featureInteraction.insert({ "CLOSE VALVE", 0 });
    featureInteraction.insert({ "CLOSE THE VALVE", 0 });
    featureInteraction.insert({ "TURN THE VALVE", 0 });
    featureInteraction.insert({ "TURN VALVE", 0 });
}

/*********************************************************************************
isTakeableFromStarting - will return true if the player can TAKE an item from the
 starting vector.
*************************************************************************************/
bool reactor::isTakeableFromStarting(string inputItemName){

    // The NAV COMM UPDATE MODULE is only takeable when the valve is closed!
    if(inputItemName == "NAV COMM UPDATE MODULE" && searchItemStarting("NAV COMM UPDATE MODULE") == true && this->noisyValveOpen==false){
        return true;
    }
    else{
        return false;
    }
}

/*********************************************************************************
lookAtFeature - will output a description if a feature is found with the look at action
*************************************************************************************/
void reactor::lookAtFeature(string featureInputName) {

    // Set variable for found index
    int foundIndex = -1;

    // Search for the feature
    foundIndex = searchFeature(featureInputName);

    // Output the feature description
    // Found the VALVE
    if(foundIndex == 0 && this->noisyValveOpen == true){
        displayFeatureDescription(foundIndex);
    }
        // VALVE, but not it is closed
    else if(foundIndex == 0 && this->noisyValveOpen == false){
        cout << "\nYou see that the VALVE is now closed. Ahhh, now you can at least hear a little better!" << endl;
    }
        // Found the SATELLITE, NAV COMM UPDATE MODULE not taken
    else if(foundIndex == 1 && searchItemStarting("NAV COMM UPDATE MODULE") == true && this->noisyValveOpen == false){
        displayFeatureDescription(foundIndex);
    }
        // Found the SATELLITE, NAV COMM UPDATE MODULE taken
    else if(foundIndex == 1 && searchItemStarting("NAV COMM UPDATE MODULE") == false && this->noisyValveOpen == false){
        cout << "\nThere doesn't appear to be anything else useful with this SATELLITE." << endl;
    }
        // Else this is not recognized
    else{
        cout << "Input not recognized." << endl;
    }
}

/*********************************************************************************
interactRoom - if an interactive action was made for the Reactor room
*************************************************************************************/
void reactor::interactRoom(string inputString) {

    // Track the feature action choice
    int featureActionChoice = -1;

    // Go through featureInteraction vector and find the associated command
    if(featureInteraction.find(inputString) != featureInteraction.end()) {
        featureActionChoice = featureInteraction[inputString];
    }

    // The case where the user wants to "CLOSE VALVE"
    if(featureActionChoice == 0 && this->noisyValveOpen == true){

        // Check to see if the user has a wrench
        if(getCharacter()->searchItem("WRENCH") == true){
            // Get turn off the valve
            cout <<"\nYou use the WRENCH you have to turn the VALVE. Ahh, now you can hear a little better. With the deafening clanking\n"
                   "sound gone, you hear a pinging...As you look around, you see that it is coming from a crashed SATELLITE on the side\n"
                   "of the reactor hull!! Maybe there's something useful if you look closely?" << endl;
            // Set the valve as closed
            this->noisyValveOpen = false;

            // Now update the descriptions to show it is less noisy!
            setLongDescription("This room is more maze than a room with pipes, ducts and catwalks twisting and turning into the darkness. \n"
                               "You see the VALVE that you closed to stop that deafening clanking. However, you still hear a pinging...this is coming\n"
                               "from a crashed SATELLITE on the side of the reactor hull! Maybe there's something useful if you look closely?\n"
                               "CORRIDOR 3 is the only way out.");
            setShortDescription("You see a closed VALVE in this maze of a room with a SATELLITE crashed to the side of the reactor hull.\n"
                                "CORRIDOR 3 is the only way out.");
        }
        else{
            // The user will need to get a wrench
            cout <<"\nYou realize you don't have the necessary equipment to close the VALVE. If only you could find a tool you could turn\n"
                   "it with..." << endl;
        }
    }
        // Case where the user wants to "CLOSE VALVE", but it's closed already!
    else if(featureActionChoice == 0 && this->noisyValveOpen == false){
        cout << "\nYou can't close the VALVE any further." << endl;
    }
        // Input not recognized
    else{
        cout << "Input not recognized." << endl;
    }
}

/*********************************************************************************
saveGame - saves to a text file flags and important vectors
*************************************************************************************/
void reactor::saveGame() {

    // Create and open a text file
    std::ofstream MyFile("saveReactor.txt");

    // Put flags from the Room parent
    saveInputFile(MyFile);

    // Put flags from this child
    MyFile << "noisyValveOpen\n" << this->noisyValveOpen  << endl;

    // Close the text file
    MyFile.close();

}

/********************************************************************************
destructor
**********************************************************************************/
reactor::~reactor()
{

    featureInteraction.clear();

}