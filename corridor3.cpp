/******************************************************************
Project Nashville
CS467 - Online Capstone Project
Description: This is the class implementation file for the class corridor3.
******************************************************************/

#include "corridor3.hpp"

/********************************************************************************
default constructor
**********************************************************************************/
corridor3::corridor3() : room(7)
{

    setName("CORRIDOR 3");
    setLongDescription("You enter yet another long vertical corridor. There are five doors along the east wall. \n"
                       "A large screen spans across the east wall displaying a map. \n"
                       "It’s almost a perfect mirror image of the first corridor entered. Why is there one less door? Mmm...");
    setShortDescription("You enter a vertical long corridor. There are five doors along the east wall. \n"
                        "A large screen spans across the east wall displaying a map.");

    // Set initial features in the room
    addFeature("INTERACTIVE MAP","You see a map with with the layout of the entire space station. It may be useful to UPLOAD the\n"
                                 "INTERACTIVE MAP the handy tablet you have on you.");
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
    // KICK STATUE interaction
    featureInteraction.insert({ "KICK STATUE", 2 });
    featureInteraction.insert({ "KICK THE STATUE", 2 });

}


/*********************************************************************************
lookAtFeature - will output a description if a feature is found with the look at action
*************************************************************************************/
void corridor3::lookAtFeature(string featureInputName) {


}

/*********************************************************************************
interactRoom - if an interactive action was made for the Medbay room
*************************************************************************************/
int corridor3::interactRoom(string inputString, bool inputMap) {



}