/*************************************************************

****************************************************************/

#include "utilityFunctions.hpp"
#include <iostream>
#include <string>
#include <sstream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

bool ToBoolean(string value)
{

    if(value == "0"){
        return false;
    }
    else{
        return true;
    }

}