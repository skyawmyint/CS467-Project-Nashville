/******************************************************************
Project Nashville
CS467 - Online Capstone Project
Description: This is the class implementation file for the class communications.
******************************************************************/

#include "communications.hpp"

/********************************************************************************
default constructor
**********************************************************************************/
communications::communications() : room(9)
{

    setName("COMMUNICATIONS");
    setLongDescription("Ahhh...COMMUNICATIONS. This was your first duty onboard this station, monitoring incoming voice chatter, \n"
                       "in what feels like over a dozen lifetimes ago. Your old COMPUTER TERMINAL sits against the far wall, \n"
                       "untouched but for a thick sheen of dust that sends shivers down your spine. From here it is impossible to tell if \n"
                       "it has any functionality. On the terminal opposite yours, you see a tossed CARD on the table. The only exit \n"
                       "appears to be back out to CORRIDOR 1");
    setShortDescription("A COMPUTER TERMINAL that used to be your own sits against the far wall. Opposite, \n"
                        "a forgotten CARD from a coworker lies discarded. There was a time when you had fond memories of this place.");

    // Add features to the room
    addFeature("CARD","Appears someone recently had themselves a special day. You should READ THE BIRTHDAY MESSAGE for a closer look.");
    addFeature("COMPUTER TERMINAL", "Looks like you can HACK THE COMPUTER TERMINAL with the skills you already have!");

    // Set the interactive actions to the unordered map
    // CARD interactions
    featureInteraction.insert({ "READ THE BIRTHDAY MESSAGE", 0 });
    featureInteraction.insert({ "READ BIRTHDAY MESSAGE", 0 });
    featureInteraction.insert({ "READ CARD", 0 });
    featureInteraction.insert({ "READ THE CARD", 0 });
    // COMPUTER TERMINAL interactions
    featureInteraction.insert({ "HACK THE COMPUTER TERMINAL", 1 });
    featureInteraction.insert({ "HACK COMPUTER TERMINAL", 1 });
    featureInteraction.insert({ "USE THE COMPUTER TERMINAL", 1 });
    featureInteraction.insert({ "USE COMPUTER TERMINAL", 1 });

}

/*********************************************************************************
lookAtFeature - will output a description if a feature is found with the look at action
*************************************************************************************/
void communications::lookAtFeature(string featureInputName) {

    // Set variable for found index
    int foundIndex;

    // Search for the feature
    foundIndex = searchFeature(featureInputName);

    // Output the feature description
    // Found the CARD
    if(foundIndex == 0){
        displayFeatureDescription(foundIndex);
    }

    // Found the COMPUTER TERMINAL, but no power
    else if(foundIndex == 1 && (getCharacter()->getPanel() == false || getCharacter()->getPrimer() == false)){
        cout << "\nYou see that the COMPUTER TERMINAL is shut off. Maybe if you restore the power to it somewhere\n"
                "you can get it running." << endl;
    }

    // Found the COMPUTER, there is power!
    else if(foundIndex == 1 && getCharacter()->getPrimer() == true && getCharacter()->getPanel() == true){
        displayFeatureDescription(foundIndex);
    }
        // Else this is not recognized
    else{
        cout << "Input not recognized." << endl;
    }
}

/*********************************************************************************
interactRoom - if an interactive action was made for the communication room
*************************************************************************************/
void communications::interactRoom(string inputString) {

    // Track the feature action choice
    int featureActionChoice = -1;

    // Go through featureInteraction vector and find the associated command
    if(featureInteraction.find(inputString) != featureInteraction.end()) {
        featureActionChoice = featureInteraction[inputString];
    }

    // The case where the user wants to "READ BIRTHDAY MESSAGE"
    if(featureActionChoice == 0){
        cout << "\nYou see the following message in the card:" << endl;
        cout << "|---------------------------------------|" << endl;
        cout << "| Happy birthday to my favorite crew    |" << endl;
        cout << "| member John!                          |" << endl;
        cout << "|                                       |" << endl;
        cout << "| You share the same birthday as my     |" << endl;
        cout << "| favorite holiday, Christmas! Today    |" << endl;
        cout << "| is the day to celebrate!!             |" << endl;
        cout << "|                                       |" << endl;
        cout << "|                      - The Captain    |" << endl;
        cout << "|---------------------------------------|" << endl;
    }

    // Else if power is restored and the choice is computer terminal and astronaut hasn't been hailed
    else if(featureActionChoice == 1 && getCharacter()->getPrimer() == true && getCharacter()->getPanel() == true && this->astronautHailed == false){

        // Show backstory of the station here! Also set astronaut as being hailed
        this->astronautHailed = true;
        cout << "\nHello...can...anyone...me? \n"
                "This is Major Sanderson. \n"
                "If someone can hear me. \n"
                "Project Nashville has been compromised. \n"
                "I barely managed to escape. \n"
                "But there should be one pod still remaining. \n"
                "Need...key and...nav...\n"
                "Repeat, the station....compromised. \n"
                "Self-destruct has been activated... \n"
                "Good luck....god speed."<< endl;
    }

    // Else if the power is restored and the astronaut has already been hailed
    else if(featureActionChoice == 1 && getCharacter()->getPrimer() == true && getCharacter()->getPanel() == true && this->astronautHailed == true){
        cout << "\nYou already got the information you needed from this COMPUTER TERMINAL!" << endl;
    }

    // Else if the power is not restored and the choice is computer terminal
    else if(featureActionChoice == 1 && (getCharacter()->getPanel() == false || getCharacter()->getPrimer() == false)){
        cout << "\nThe COMPUTER TERMINAL is not working. Need to restore power to it somehow!" << endl;
    }

    // Input not recognized
    else{
        cout << "Input not recognized." << endl;
    }
}

