//
// Created by Stuart on 1/21/2021.
//

#include <iostream>
#include <string>
#include <sstream>
#include "menuOptions.hpp"
#include "utilityFunctions.hpp"

/*******************************************************************************************
menuStartup runs when the program begins, asking the user if they would like to simulate
the adventure game or quit.
It takes no parameters and returns an int.
********************************************************************************************/
int menuStartUp()
{

    int retInt = 0;
    string getChoice;

    cout << "Welcome to Project Nashville" << endl;
    cout << "Enter 1: Play a new game" << endl;
    cout << "Enter 2: Load an existing game" << endl;
    cout << "Enter 3: Exit game" << endl;
    cout << ": ";

    std::getline(cin, getChoice);

    const int ONE = 1;
    const int TWO = 2;
    const int THREE = 3;                         //to test against input

    string test = getChoice;                           //string in to test
    int retSize = 0;                                        //int to return
    bool badString = true;                                  //to test string conversion

    while (badString)
    {
        int length = test.length();
        std::stringstream convert(test);

        if ((length == 1) && (convert >> retSize) && !(convert >> test) && ((retSize == ONE || retSize == TWO) || (retSize == THREE)))     //check all parameters
        {
            badString = false;                                   //only end loop if 1,2 or 3 is returned
        }
        else                                                            //loop repeats
        {
            cout << endl;
            cout << "Choice must be one of the following." << endl;
            cout << "Please choose again, selecting '1', '2', or '3':" << endl;
            cout << "Enter 1: Play a new game" << endl;
            cout << "Enter 2: Load an existing game" << endl;
            cout << "Enter 3: Exit game" << endl;
            cout << ": ";
            std::getline(cin, test);
        }
    }
    cout << endl;

    return retSize;
}