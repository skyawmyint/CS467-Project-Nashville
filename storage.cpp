/******************************************************************
Project Nashville
CS467 - Online Capstone Project
Description: This is the class implementation file for the class storage.
******************************************************************/

#include "storage.hpp"

/********************************************************************************
default constructor
**********************************************************************************/
storage::storage() : room(14)
{
    // Place all default information
    insertInteractions();

}

/********************************************************************************
constructor
**********************************************************************************/
storage::storage(bool inputLoad) : room(14)
{
    // Place all default information
    insertInteractions();
    setRoomID(14);

    // Read from txt file
    string line;
    std::ifstream myfile ("saveStorage.txt");
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
void storage::insertInteractions() {

    setName("STORAGE");
    setLongDescription("The shattered wreckage of the destroyed O2 CANISTERS make maneuvering into room a tad difficult, \n"
                       "but why a seemingly ordinary STORAGE room was hidden so thoroughly is anybody's guess. Rows of lockers \n"
                       "line the two walls to the right and left, while straight ahead against the far wall is a fairly large CLOSET. \n"
                       "One small table sits directly to the right, upon which lies a furiously scrawled NOTE. Directly back is the \n"
                       "passage back into LIFE SUPPORT O2.");
    setShortDescription("A seemingly ordinary STORAGE room contains a small table with a scrawled NOTE upon it, \n"
                        "and directly against the far wall a fairly large CLOSET. The only way out is to LIFE SUPPORT O2.");

    // Add features to the room
    addFeature("CLOSET","A closet that you can OPEN stands against the far wall.");
    addFeature("NOTE", "A note that can be READ closely is stickied to a locker.");

    // Set the interactive actions to the unordered map
    // Closet interaction
    featureInteraction.insert({ "OPEN CLOSET", 0 });
    featureInteraction.insert({ "OPEN THE CLOSET", 0 });
    featureInteraction.insert({ "CHECK CLOSET", 0 });
    featureInteraction.insert({ "CHECK THE CLOSET", 0 });
    featureInteraction.insert({ "SEARCH CLOSET", 0 });
    featureInteraction.insert({ "SEARCH THE CLOSET", 0 });
    // Note interaction
    featureInteraction.insert({ "READ THE NOTE", 1 });
    featureInteraction.insert({ "READ NOTE", 1 });
    featureInteraction.insert({ "SKIM NOTE", 1 });
    featureInteraction.insert({ "SKIM THE NOTE", 1 });
}

/*********************************************************************************
lookAtFeature - will output a description if a feature is found with the look at action
*************************************************************************************/
void storage::lookAtFeature(string featureInputName) {

    // Set variable for found index
    int foundIndex;

    // Search for the feature
    foundIndex = searchFeature(featureInputName);

    // Output the feature description
    // Found the CLOSET
    if(foundIndex == 0){
        displayFeatureDescription(foundIndex);
    }
        // Found the NOTE
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
void storage::interactRoom(string inputString) {

    // Track the feature action choice
    int featureActionChoice = -1;

    // Go through featureInteraction vector and find the associated command
    if(featureInteraction.find(inputString) != featureInteraction.end()) {
        featureActionChoice = featureInteraction[inputString];
    }

    // The case where the user wants to "OPEN" the closet. Key is there.
    if(featureActionChoice == 0 && searchItemStarting("KEY") == true){
        cout << "\nYou open the closet and you notice that there is a pilot's jacket hanging. Thinking there\n"
                "must be something useful in there, you dig through the pockets and find a KEY! This may be\n"
                "useful to escape in one of the escape pods!" << endl;
        getCharacter()->addItem(removeItemStarting("KEY"));
    }
    // Case where the user wants to "OPEN" the closet. Key isn't there.
    else if(featureActionChoice == 0 && searchItemStarting("KEY") == false){
        cout << "\nYou open the closet and dig through the contents closer, but find nothing else of use.\n";
    }
    // Case where the user wants to "READ" the NOTE.
    else if(featureActionChoice == 1){
        cout << "\nYou read the following:" << endl;
        cout << "|---------------------------------------|" << endl;
        cout << "| Why is the storage room, which        |" << endl;
        cout << "| everyone needs to use, so difficult   |" << endl;
        cout << "| to find???                            |" << endl;
        cout << "|                                       |" << endl;
        cout << "|---------------------------------------|" << endl;
    }
        // Input not recognized
    else{
        cout << "Input not recognized." << endl;
    }
}

/*********************************************************************************
saveGame - saves to a text file flags and important vectors
*************************************************************************************/
void storage::saveGame() {

    // Create and open a text file
    std::ofstream MyFile("saveStorage.txt");

    // Put flags from the Room parent
    saveInputFile(MyFile);

    // Close the text file
    MyFile.close();

}

/********************************************************************************
destructor
**********************************************************************************/
storage::~storage()
{

    featureInteraction.clear();

}