// ------------------------------------------------ Owner.cpp ---------------------------------------------------------

// Name and Class: Tim Denisiuk CSS 449
// Code Use: Defines functions for the owner class
// Creation Date: 03/30/2022
// Last Modified: 04/04/2022
// --------------------------------------------------------------------------------------------------------------------

//Purpose: Defines every function in the owner class
//Functionality: Stores a string for the name and a list for the preferences
//Assumptions: None
// -------------------------------------------------------------------------------------------------------------------- 
#include <iostream>
#include <list>
#include "Owner.h"

using namespace std;

//Constructor
//Default constructor for the owner class
//Precondition: None
//Postcondition: creates a string for the name and a list for the preferences
Owner::Owner()
{
	name = "";
	return;
}

//Destructor
//Default destructor for the owner class
//Precondition: None
//Postcondition: None, because there is nothing dynamically allocated
Owner::~Owner()
{
	return;
}

//getName
//Returns the name of the owner
//Precondition: None
//Postcondition: Returns a string of the owner's name
string Owner::getName()
{
	return name;
}

//setName
//set the name of the owner
//Precondition: None
//Postcondition: the name of the owner is set to the string value
void Owner::setName(string inputName)
{
	name = inputName;
	return;
}

//getNextPreference
//Returns the next preference for the owner
//Precondition: None
//Postcondition: returns an int of the owners preference, and prepares for the next preference
int Owner::getNextPreference()
{
	int preferenceValue = preferences.front();
	preferences.pop_front();
	return preferenceValue;
}

//setNextPreference
//sets the next preference for the owner in the list
//Precondition: None
//Postcondition: sets the preference next in line
void Owner::setNextPreference(int inputInt)
{
	preferences.push_back(inputInt);
	return;
}
