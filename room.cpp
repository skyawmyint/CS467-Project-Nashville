/******************************************************************
Project Nashville
CS467 - Online Capstone Project
Description: This is the class implementation file for the class room.
******************************************************************/

#include "room.hpp"

/********************************************************************************
default constructor
**********************************************************************************/
room::room()
{

}
/********************************************************************************
set room id with constructor
**********************************************************************************/
room::room(int id)
{
   this->room_id = id;
}
/********************************************************************************
setCharacter - sets the character pointer
**********************************************************************************/
void room::setCharacter(character* inputCharacter)
{

    this->playerPointer = inputCharacter;

}

/********************************************************************************
getCharacter - returns the character pointer
**********************************************************************************/
character* room::getCharacter()
{

    return this->playerPointer;

}

/*********************************************************************************
setName sets the name of the room it takes a string as a parameter and returns nothing
*************************************************************************************/
void room::setName(string nameIn)
{
    this->roomName = nameIn;
}

/*********************************************************************************
getName returns the name of the current room object, it takes nothing as a parameter and returns
a string;
*************************************************************************************/
string room::getName() const
{
    return this->roomName;
}

/*********************************************************************************
setLongDescription sets the description of the current room object, it takes a string as a parameter and returns nothing
*************************************************************************************/
void room::setLongDescription(string scriptIn)
{
    this->longDescription = scriptIn;
}

/*********************************************************************************
getDescription returns the description of the current room object, it takes nothing as a parameter and returns
a string;
*************************************************************************************/
string room::getLongDescription() const
{
    return this->longDescription;
}

/*********************************************************************************
setShortDescription sets the description of the current room object, it takes a string as a parameter and returns nothing
*************************************************************************************/
void room::setShortDescription(string scriptIn)
{
    this->shortDescription = scriptIn;
}

/*********************************************************************************
getShortDescription returns the description of the current room object, it takes nothing as a parameter and returns
a string;
*************************************************************************************/
string room::getShortDescription() const
{
    return this->shortDescription;
}

/*********************************************************************************************
setConnectedRooms takes a room* pointer input and sets it in the connectedRooms vector to keep
 a list of connected rooms.
*********************************************************************************************/
void room::setConnectedRooms(room* inputRoom)
{
    this->connectedRooms.push_back(inputRoom);

}

/*********************************************************************************************
isConnectedRoom takes in a string room name input and checks if it is one of the connected
 rooms in the connectedRooms vector. Returns true if it is, false if it is not.
*********************************************************************************************/
bool room::isConnectedRoom(string inputRoomName)
{
    // Create a flag to see if it is a connected room
    bool connectedRoomFlag = false;

    // Go through each index in the array
    for(int i = 0; i<connectedRooms.size(); i++){

        // Compare the room name with the input string room name
        if(connectedRooms[i]->getName() == inputRoomName){
            connectedRoomFlag = true;
        }
    }

    return connectedRoomFlag;
}

/*********************************************************************************************
isRepeatVisit returns the bool of if it is the first time someone has entered the room
*********************************************************************************************/
bool room::isRepeatVisit()
{
    return this->repeatVisit;
}

/*********************************************************************************************
toggleEnteredRoom sets the repeatVisit to TRUE if the room has been already visited
*********************************************************************************************/
void room::toggleEnteredRoom()
{
    this->repeatVisit = true;
}

/*********************************************************************************
addItemStarting adds an item to the starting vector of items in a room
*************************************************************************************/
void room::addItemStarting(item *inputItem)
{

    this->startingItems.push_back(inputItem);

}

/*********************************************************************************
searchItemStarting searches if an Item is in a starting room item. Returns bool
*************************************************************************************/
bool room::searchItemStarting(string inputItemName){

    bool itemExist = false;

    for (int i = 0; i < startingItems.size(); i++)
    {
        if (inputItemName == startingItems[i]->getName())
        {
            itemExist = true;
        }
    }
    return itemExist;
}

/*********************************************************************************
removeItemStarting removes an item from a rooms starting item vector.
*************************************************************************************/
item* room::removeItemStarting(string inputItemName){

    item* tempItemPointer;

    for (int i = 0; i < startingItems.size(); i++)
    {
        if (inputItemName == startingItems[i]->getName())
        {

            tempItemPointer = startingItems[i];
            this->startingItems.erase(startingItems.begin() + i);
            break;

        }

    }
    return tempItemPointer;
};

/*********************************************************************************
addItemDropped adds an item to the dropped vector of items in a room
*************************************************************************************/
void room::addItemDropped(item *inputItem)
{

    this->droppedItems.push_back(inputItem);

}

/*********************************************************************************
searchItemDropped searches if an Item is a dropped room item. Returns bool
*************************************************************************************/
bool room::searchItemDropped(string inputItemName){

    bool itemExist = false;

    for (int i = 0; i < droppedItems.size(); i++)
    {
        if (inputItemName == droppedItems[i]->getName())
        {
            itemExist = true;
        }
    }
    return itemExist;
}

/*********************************************************************************
removeItemDropped removes an item from a rooms dropped item vector.
*************************************************************************************/
item* room::removeItemDropped(string inputItemName){

    item* tempItemPointer;

    for (int i = 0; i < droppedItems.size(); i++)
    {
        if (inputItemName == droppedItems[i]->getName())
        {

            tempItemPointer = droppedItems[i];
            this->droppedItems.erase(droppedItems.begin() + i);
            break;

        }

    }
    return tempItemPointer;
};

/*********************************************************************************
listItemDropped outputs all the items that have been dropped in the room.
*************************************************************************************/
void room::listItemDropped() {

    // Output what you see on the ground
    if(droppedItems.size() != 0){
        cout << "\nYou see the following items on the ground: ";
    }

    // Lists all the items in the droppedItems vector
    for(int i = 0; i < droppedItems.size(); i++){

        if(i != droppedItems.size()-1){
            cout << droppedItems[i]->getName() << ", ";
        }
        else{
            cout << droppedItems[i]->getName() << ".";
        }
    }
}

/*********************************************************************************
itemIndexDrop - returns the index if an item was found in the room's dropped items
*************************************************************************************/
int room::itemIndexDrop(string inputItemName){

    int itemIndex = -1;

    for (int i = 0; i < droppedItems.size(); i++)
    {
        if (inputItemName == droppedItems[i]->getName())
        {
            itemIndex = i;
        }
    }
    return itemIndex;

}

/*********************************************************************************
displayItemDropDescription - displays the item description at the the drop index
*************************************************************************************/
void room::displayItemDropDescription(int index) {

    // Index cannot be greater than the inventory size or negative
    if(index<droppedItems.size() && (index > -1)){
        cout << droppedItems[index]->getDescription() << endl;
    }
}

/*********************************************************************************
addFeature adds a feature name and description for the look at action in the
 vector
*************************************************************************************/
void room::addFeature(string inputName, string inputDescription) {

    this->feature.push_back(inputName);
    this->featureDescription.push_back(inputDescription);

}

/*********************************************************************************
searchFeature searched for a feature and returns the index if it exists. Returns -1 if
 no index is found
*************************************************************************************/
int room::searchFeature(string inputName) {

    // Set variable for found index
    int foundIndex = -1;

    // Search for the feature
    for(int i = 0; i<feature.size(); i++){
        if(inputName == feature[i]){
            foundIndex = i;
        }
    }

    return foundIndex;

}

/*********************************************************************************
displayFeatureDescription - displays the feature description at a given index
*************************************************************************************/
void room::displayFeatureDescription(int indexInput) {

    cout << endl << this->featureDescription[indexInput] << endl;

}


/*********************************************************************************
isTakeableFromStarting returns true if the item in the starting room is takeable
 from the starting vector outright. Otherwise returns false.
*************************************************************************************/
bool room::isTakeableFromStarting(string inputItemName){

    return false;

}

/*********************************************************************************
lookAtFeature - will output a description if a feature is found with the look at action
*************************************************************************************/
void room::lookAtFeature(string inputFeature) {

}

/*********************************************************************************
lookAtFeature - will output a description if a feature is found with the look at action
*************************************************************************************/
void room::lookAtFeature(string inputFeature, int inputTime) {

}

/*********************************************************************************
interactRoom - works with the room to do a specific interactive action
*************************************************************************************/
void room::interactRoom(string inputString) {

}

/*********************************************************************************
interactRoom - works with the room to do a specific interactive action
*************************************************************************************/
int room::interactRoom(string inputString, bool inputMap) {

    return 0;

}

/*********************************************************************************
isO2CanistersDestroyed - for the entrance into the storage room.
*************************************************************************************/
bool room::isO2CanistersDestroyed(){

    return false;

}

/*********************************************************************************
setRoomID - sets the room ID number
 *************************************************************************************/
void room::setRoomID(int inputNum){

    this->room_id = inputNum;

}

/*********************************************************************************
getRoomId - returns room id
 *************************************************************************************/
int room::getRoomId(){
   return this->room_id;
}

/*********************************************************************************
saveGame() - virtual function to save room flags
 *************************************************************************************/
void room::saveGame(){

}

/*********************************************************************************
saveInputFile - takes in an input file txt and places flags in it
 *************************************************************************************/
void room::saveInputFile(std::ofstream &inputFile){

    // Save the starting
    // If starting is not empty
    if(startingItems.size() != 0){
        inputFile << "startingItems\n";
        for(int i = 0; i < startingItems.size(); i++){
            inputFile << startingItems[i]->getName() << endl;
        }
    }
    else{
        inputFile << "empty startingItems" << endl;
    }
    inputFile << "END" << endl;

    // Save droppedItems
    if(droppedItems.size() != 0){
        inputFile << "droppedItems\n";
        for(int i = 0; i < droppedItems.size(); i++){
            inputFile << droppedItems[i]->getName() << endl;
        }
    }
    else{
        inputFile << "empty droppedItems" << endl;
    }
    inputFile << "END" << endl;

    // Other flags
    inputFile << "repeatVisit\n" << this->repeatVisit  << endl;

}

/*********************************************************************************
addLoadGameEntry() - virtual function to load room flags specifically
 *************************************************************************************/
void room::addLoadGameEntry(string inputString, int doType){

    // Add to starting vector
    if(doType == 0){
        if(inputString == "KEY"){
            item* keyItem = new item();
            keyItem->setName("KEY");
            keyItem->setDescription("This KEY can be used to escape in the ESCAPE POD.");
            addItemStarting(keyItem);
        }
        else if(inputString == "BADGE"){
            item* badgeItem = new item();
            badgeItem->setName("BADGE");
            badgeItem->setDescription("This BADGE allows access to open the MAINFRAME ROOM.");
            addItemStarting(badgeItem);
        }
        else if(inputString == "SCALPEL"){
            item* scalpelItem = new item();
            scalpelItem->setName("SCALPEL");
            scalpelItem->setDescription("This is a handy SCALPEL that can be used in multiple objects to cut and pry.");
            addItemStarting(scalpelItem);
        }
        else if(inputString == "WORK GLOVES"){
            item* workGlovesItem = new item();
            workGlovesItem->setName("WORK GLOVES");
            workGlovesItem->setDescription("These WORK GLOVES can be handy in working with dangerous electrical objects.");
            addItemStarting(workGlovesItem);
        }
        else if(inputString == "NAV COMM UPDATE MODULE"){
            item* navCommUpdateModuleItem = new item();
            navCommUpdateModuleItem->setName("NAV COMM UPDATE MODULE");
            navCommUpdateModuleItem->setDescription("The NAV COMM UPDATE MODULE can be used on a computer to allow a safe route on an escape pod.");
            addItemStarting(navCommUpdateModuleItem);
        }
        else if(inputString == "EMPTY CONTAINER"){
            item* emptyContainerItem = new item();
            emptyContainerItem->setName("EMPTY CONTAINER");
            emptyContainerItem->setDescription("This EMPTY CONTAINER can be filled with something.");
            addItemStarting(emptyContainerItem);
        }
        else if(inputString == "WRENCH"){
            item* wrenchItem = new item();
            wrenchItem->setName("WRENCH");
            wrenchItem->setDescription("This WRENCH can be used to turn valves or bolts.");
            addItemStarting(wrenchItem);
        }
        else if(inputString == "FLARE GUN"){
            item* flareGunItem = new item();
            flareGunItem->setName("FLARE GUN");
            flareGunItem->setDescription("This FLARE GUN can probably be used to ignite something with O2.");
            addItemStarting(flareGunItem);
        }
    }
    // Add to dropped items
    else if(doType == 1){
        if(inputString == "KEY"){
            item* keyItem = new item();
            keyItem->setName("KEY");
            keyItem->setDescription("This KEY can be used to escape in the ESCAPE POD.");
            addItemDropped(keyItem);
        }
        else if(inputString == "BADGE"){
            item* badgeItem = new item();
            badgeItem->setName("BADGE");
            badgeItem->setDescription("This BADGE allows access to open the MAINFRAME ROOM.");
            addItemDropped(badgeItem);
        }
        else if(inputString == "SCALPEL"){
            item* scalpelItem = new item();
            scalpelItem->setName("SCALPEL");
            scalpelItem->setDescription("This is a handy SCALPEL that can be used in multiple objects to cut and pry.");
            addItemDropped(scalpelItem);
        }
        else if(inputString == "WORK GLOVES"){
            item* workGlovesItem = new item();
            workGlovesItem->setName("WORK GLOVES");
            workGlovesItem->setDescription("These WORK GLOVES can be handy in working with dangerous electrical objects.");
            addItemDropped(workGlovesItem);
        }
        else if(inputString == "NAV COMM UPDATE MODULE"){
            item* navCommUpdateModuleItem = new item();
            navCommUpdateModuleItem->setName("NAV COMM UPDATE MODULE");
            navCommUpdateModuleItem->setDescription("The NAV COMM UPDATE MODULE can be used on a computer to allow a safe route on an escape pod.");
            addItemDropped(navCommUpdateModuleItem);
        }
        else if(inputString == "EMPTY CONTAINER"){
            item* emptyContainerItem = new item();
            emptyContainerItem->setName("EMPTY CONTAINER");
            emptyContainerItem->setDescription("This EMPTY CONTAINER can be filled with something.");
            addItemDropped(emptyContainerItem);
        }
        else if(inputString == "FILLED CONTAINER") {
            item *emptyContainerItem = new item();
            emptyContainerItem->setName("FILLED CONTAINER");
            emptyContainerItem->setDescription("A container filled up with oil.");
            addItemDropped(emptyContainerItem);
        }
        else if(inputString == "WRENCH"){
            item* wrenchItem = new item();
            wrenchItem->setName("WRENCH");
            wrenchItem->setDescription("This WRENCH can be used to turn valves or bolts.");
            addItemDropped(wrenchItem);
        }
        else if(inputString == "FLARE GUN"){
            item* flareGunItem = new item();
            flareGunItem->setName("FLARE GUN");
            flareGunItem->setDescription("This FLARE GUN can probably be used to ignite something with O2.");
            addItemDropped(flareGunItem);
        }
    }
    // repeatVisit flag
    else if(doType == 2){
        this->repeatVisit = ToBoolean(inputString);
    }
}

/********************************************************************************
destructor
**********************************************************************************/
room::~room()
{

    // Free all the starting items
    item* tempItemPointer;
    int startingSize = startingItems.size();

    for (int i = 0; i < startingSize; i++)
    {
        tempItemPointer = startingItems[startingSize-1-i];
        startingItems.pop_back();
        free(tempItemPointer);
    }

    // Free all the dropped items
    int droppedSize = droppedItems.size();

    for (int i = 0; i < droppedSize; i++)
    {
        tempItemPointer = droppedItems[droppedSize-1-i];
        droppedItems.pop_back();
        free(tempItemPointer);
    }

    // Clear connected rooms
    connectedRooms.clear();

    // Clear features
    feature.clear();
    featureDescription.clear();

}
