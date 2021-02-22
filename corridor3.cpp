/******************************************************************
Project Nashville
CS467 - Online Capstone Project
Description: This is the class implementation file for the class corridor3.
******************************************************************/

#include "corridor3.hpp"

/********************************************************************************
default constructor
**********************************************************************************/
corridor3::corridor3(game* currentGame) : room(7) {

    this->currentGame = currentGame;
    // Place all default information
    insertInteractions();

}

/********************************************************************************
constructor
**********************************************************************************/
corridor3::corridor3(bool inputLoad, game* currentGame) : room(7)
{
    // Place all default information
    this->currentGame = currentGame;
    insertInteractions();
    setRoomID(7);

    // Read from txt file
    string line;
    std::ifstream myfile ("saveCorridor3.txt");
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
            else if(line == "paintingDestroyed"){
                getline (myfile,line);
                this->paintingDestroyed = ToBoolean(line);
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
void corridor3::insertInteractions() {

    setName("CORRIDOR 3");
    setLongDescription("You see that it is a long vertical corridor. There are five doors along the east wall. \n"
                       "It’s almost a perfect mirror image of the first corridor entered. Why is there one less door though?\n"
                       "A large CLOCK spans across the northwestern wall counting down. You also see a large PAINTING on the\n"
                       "southwestern wall.");
    setShortDescription("There are five doors along the east wall. A large CLOCK spans across the northwestern wall\n"
                        "and a large PAINTING spans across the southwestern wall.");


    // Set initial features in the room
    addFeature("CLOCK","You see a large clock.");
    addFeature("PAINTING", "You see an image of a large man in front of a space station being constructed...\n"
                           "Could this be the greedy president of this project? I wish I would just DESTROY this PAINTING!");

    // Set initial feature actions in the room
    featureInteraction.insert({ "LOOK AT THE CLOCK", 0});
    featureInteraction.insert({ "LOOK AT CLOCK", 0});

    // DESTROY interaction
    featureInteraction.insert({ "DESTROY PAINTING", 1});
    featureInteraction.insert({ "DESTROY THIS PAINTING", 1});
    featureInteraction.insert({ "DESTROY THE PAINTING", 1});

}

/*********************************************************************************
lookAtFeature - will output a description if a feature is found with the look at action
*************************************************************************************/
void corridor3::lookAtFeature(string featureInputName, int inputTime) {

    // Set variable for found index
    int foundIndex;

    // Search for the feature
    foundIndex = searchFeature(featureInputName);

    // Output the feature description
    // Found the CLOCK
    if(foundIndex == 0){
        cout << "\nTime until self-destruction: ";
	    currentGame->printTime();
    }
        // Found the PAINTING
    else if(foundIndex == 1 && paintingDestroyed == false){
        displayFeatureDescription(foundIndex);
    }
        // Found the PAINTING, but destroyed now
    else if(foundIndex == 1 && paintingDestroyed == true){
        cout << "\nYou see the painting with the head of man ripped out...You really hated this man!" << endl;
    }
        // Else this is not recognized
    else{
        cout << "Input not recognized." << endl;
    }
}

/*********************************************************************************
interactRoom - if an interactive action was made for the this room
*************************************************************************************/
void corridor3::interactRoom(string inputString) {

    // Track the feature action choice
    int featureActionChoice = -1;

    // Go through featureInteraction vector and find the associated command
    if(featureInteraction.find(inputString) != featureInteraction.end()) {
        featureActionChoice = featureInteraction[inputString];
    }

    // The case where the user wants to "DESTROY PAINTING"
    if(featureActionChoice == 1){
        // If not destroyed
        if(paintingDestroyed == false){
            cout << "\nThe rage inside of you builds up looking at the face in the painting. Suddenly, you grip at the\n"
                    "canvas and rip apart the face from the rest of the image." << endl;
            this->paintingDestroyed = true;
        }
            // If destroyed
        else{
            cout << "\nYou've destroyed this painting far enough!" << endl;
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
void corridor3::saveGame() {

    // Create and open a text file
    std::ofstream MyFile("saveCorridor3.txt");

    // Put flags from the Room parent
    saveInputFile(MyFile);

    // Put flags from this child
    MyFile << "paintingDestroyed\n" << this->paintingDestroyed  << endl;

    // Close the text file
    MyFile.close();

}

/********************************************************************************
destructor
**********************************************************************************/
corridor3::~corridor3()
{

    featureInteraction.clear();

}