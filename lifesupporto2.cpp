/******************************************************************
Project Nashville
CS467 - Online Capstone Project
Description: This is the class implementation file for the class lifeSupportO2.
******************************************************************/

#include "lifesupporto2.hpp"

/********************************************************************************
default constructor
**********************************************************************************/
lifeSupportO2::lifeSupportO2() : room(12)
{

    setName("LIFE SUPPORT O2");
    setLongDescription("You breathe a sigh of relief that all appears functional in this room, no pun intended. \n"
                       "Rows and Rows of O2 sterilization and life support maintenance terminals cover every square inch. \n"
                       "A quick glance shows that all read-outs are at nominal or slightly above. Tucked next to a stack of \n"
                       "unused yet full O2 CANISTERS sits an EMPTY CONTAINER, ideal for holding any manner of liquid. \n"
                       "While the only nominal exit is back to CORRIDOR 3, something seems off about this room...");
    setShortDescription("Life support and O2 appear to not be in any danger of critical failure, as all machines appear functional. \n"
                        "Next to some unused, but full O2 CANISTERS was resting an EMPTY CONTAINER.");

    // Add features to the room
    addFeature("EMPTY CONTAINER","This item may just be useful to TAKE with you.");
    addFeature("O2 CANISTERS", "These O2 canisters appear to be blocking something behind them...maybe if you can\n"
                               "SHOOT AT the O2 CANISTERS with something...");

    // Set the interactive actions to the unordered map
    // Computer interaction
    featureInteraction.insert({ "SHOOT AT THE O2 CANISTERS", 0 });
    featureInteraction.insert({ "SHOOT THE O2 CANISTERS", 0 });
    featureInteraction.insert({ "SHOOT AT O2 CANISTERS", 0 });
    featureInteraction.insert({ "SHOOT O2 CANISTERS", 0 });

}

/*********************************************************************************
isTakeableFromStarting - will return true if the player can TAKE an item from the
 starting vector.
*************************************************************************************/
bool lifeSupportO2::isTakeableFromStarting(string inputItemName){

    // Taking the empty container, while O2 canisters still there!
    if(inputItemName == "EMPTY CONTAINER" && searchItemStarting("EMPTY CONTAINER") == true && O2CanistersDestroyed == false){
        setLongDescription("You breathe a sigh of relief that all appears functional in this room, no pun intended. \n"
                           "Rows and Rows of O2 sterilization and life support maintenance terminals cover every square inch. \n"
                           "A quick glance shows that all read-outs are at nominal or slightly above. You see a stack of \n"
                           "unused yet full O2 CANISTERS. While the only nominal exit is back to CORRIDOR 3, something \n"
                           "seems off about this room...");
        setShortDescription("Life support and O2 appear to not be in any danger of critical failure, as all machines appear functional. \n"
                            "You see some unused, but full O2 CANISTERS stacked together against the wall.");
        return true;
    }
    // Taking the empty container, while O2 canisters NOT there!
    else if(inputItemName == "EMPTY CONTAINER" && searchItemStarting("EMPTY CONTAINER") == true && O2CanistersDestroyed == true){
        setLongDescription("You breathe a sigh of relief that all appears functional in this room, no pun intended. \n"
                           "Rows and Rows of O2 sterilization and life support maintenance terminals cover every square inch. \n"
                           "A quick glance shows that all read-outs are at nominal or slightly above. You see the remains of the destroyed\n"
                           "O2 CANISTERS which you shot at scattered near an opened entrance to the STORAGE room");
        setShortDescription("Life support and O2 appear to not be in any danger of critical failure, as all machines appear functional. \n"
                            "You see a newly opened entrance to the STORAGE room.");
        return true;
    }
    else{
        return false;
    }
}

/*********************************************************************************
isO2CanistersDestroyed - returns true if the O2 cannisters are destroyed, allowing
 the way into the storage room.
*************************************************************************************/
bool lifeSupportO2::isO2CanistersDestroyed(){

    return this->O2CanistersDestroyed;

}

/*********************************************************************************
lookAtFeature - will output a description if a feature is found with the look at action
*************************************************************************************/
void lifeSupportO2::lookAtFeature(string featureInputName) {

    // Set variable for found index
    int foundIndex;

    // Search for the feature
    foundIndex = searchFeature(featureInputName);

    // Output the feature description
    // Found the EMPTY CONTAINER
    if(foundIndex == 0 && searchItemStarting("EMPTY CONTAINER") == true){
        displayFeatureDescription(foundIndex);
    }
        // Found the O2 canisters
    else if(foundIndex == 1 && O2CanistersDestroyed == false){
        displayFeatureDescription(foundIndex);
    }
    else if(foundIndex == 1 && O2CanistersDestroyed == true){
        cout << endl << "You see the remains of the O2 Canisters you shot out scattered through the floor." << endl;
    }
        // Else this is not recognized
    else{
        cout << "Input not recognized." << endl;
    }
}

/*********************************************************************************
interactRoom - if an interactive action was made for the Medbay room
*************************************************************************************/
void lifeSupportO2::interactRoom(string inputString) {

    // Track the feature action choice
    int featureActionChoice = -1;

    // Go through featureInteraction vector and find the associated command
    if(featureInteraction.find(inputString) != featureInteraction.end()) {
        featureActionChoice = featureInteraction[inputString];
    }

    // The case where the user wants to "SHOOT AT" the O2 Cannisters
    if(featureActionChoice == 0 && isO2CanistersDestroyed()==false){
        // Check if the user has a FLARE GUN
        if(getCharacter()->searchItem("FLARE GUN") == true){

            // Output the story
            cout << "\nYou lift up the FLARE GUN and aim right at the middle of the O2 Canister pile. With one shot, the entire\n"
                    "pile explodes, breaking out in fire. Suddenly, the emergency fire system starts the sprinkler system, putting\n"
                    "out the fire. After the smoke clears, you see an opening...this must be the way to the STORAGE room!" << endl;
            // Set the canister as destroyed
            this->O2CanistersDestroyed = true;

            // Set new descriptions
            if(searchItemStarting("EMPTY CONTAINER") == true){
                setLongDescription("You breathe a sigh of relief that all appears functional in this room, no pun intended. \n"
                                   "Rows and Rows of O2 sterilization and life support maintenance terminals cover every square inch. \n"
                                   "A quick glance shows that all read-outs are at nominal or slightly above. You see an EMPTY CONTAINER\n"
                                   "still intact after the explosion near the entrance to the STORAGE room.");
                setShortDescription("Life support and O2 appear to not be in any danger of critical failure, as all machines appear functional. \n"
                                    "You see an EMPTY CONTAINER right by the entrance to the STORAGE room");
            }
            else{
                setLongDescription("You breathe a sigh of relief that all appears functional in this room, no pun intended. \n"
                                   "Rows and Rows of O2 sterilization and life support maintenance terminals cover every square inch. \n"
                                   "A quick glance shows that all read-outs are at nominal or slightly above. You see the remains of the destroyed\n"
                                   "O2 CANISTERS which you shot at scattered near an opened entrance to the STORAGE room");
                setShortDescription("Life support and O2 appear to not be in any danger of critical failure, as all machines appear functional. \n"
                                    "You see a newly opened entrance to the STORAGE room.");
            }
        }
        // Say that you need the FLARE GUN
        else{
            cout << endl << "You need some sort of gun to be able to do this..." << endl;
        }
    }

    else{
        cout << "Input not recognized." << endl;
    }
}