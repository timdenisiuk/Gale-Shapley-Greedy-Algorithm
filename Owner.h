// ------------------------------------------------ Owner.h -----------------------------------------------------------

// Name and Class: Tim Denisiuk CSS 449
// Code Use: Used to stores the names and the preference list of each owner as well as functions to access them
// Creation Date: 03/30/2022
// Last Modified: 04/04/2022
// --------------------------------------------------------------------------------------------------------------------

//Purpose: Owner class stores the names and preference list of each owner of the text file
//		   Getter and setter methods are used to access the data for the class
//Functionality: Stores a string for the name and a list for the preferences
//Assumptions: None
// -------------------------------------------------------------------------------------------------------------------- 
#pragma once
#include <iostream>
#include <list>

using namespace std;

class Owner
{
public:
	//Constructor
	//Default constructor for the owner class
	//Precondition: None
	//Postcondition: creates a string for the name and a list for the preferences
	Owner();

	//Destructor
	//Default destructor for the owner class
	//Precondition: None
	//Postcondition: None, because there is nothing dynamically allocated
	~Owner();

	//getName
	//Returns the name of the owner
	//Precondition: None
	//Postcondition: Returns a string of the owner's name
	string getName();

	//setName
	//set the name of the owner
	//Precondition: None
	//Postcondition: the name of the owner is set to the string value
	void setName(string);

	//getNextPreference
	//Returns the next preference for the owner
	//Precondition: None
	//Postcondition: returns an int of the owners preference, and prepares for the next preference
	int getNextPreference();

	//setNextPreference
	//sets the next preference for the owner in the list
	//Precondition: None
	//Postcondition: sets the preference next in line
	void setNextPreference(int);

private:
	string name;				//string that stores the name of the owner
	list<int> preferences;		//list that stores the preference ranking of the owner


};