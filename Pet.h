// ------------------------------------------------ Pet.h -------------------------------------------------------------

// Name and Class: Tim Denisiuk CSS 449
// Code Use: Used to store pet names and pet preferences
// Creation Date: 03/30/2022
// Last Modified: 04/04/2022
// --------------------------------------------------------------------------------------------------------------------

//Purpose: Pet class stores all data for each pet as well as functions to access them
//Functionality: stores vectors of each preference and ranking so it can be performs in O(1) time			
//Assumptions:
// -------------------------------------------------------------------------------------------------------------------- 
#pragma once
#include <iostream>
#include <vector>

using namespace std;

class Pet
{
public:
	//Constructor
	//Default constructor for pet class
	//Preconditions: None
	//Postconditions: creates empty vectors for preferences
	Pet();

	//Destructor
	//Default destructor for pet class
	//Preconditions: None
	//Postcondition: None, because nothing is dynamically allocated
	~Pet();

	//getName
	//Returns the name of the pet object
	//Preconditions: None
	//Postconditions: returns a string that is the name of the pet
	string getName();

	//setName
	//Sets the name for the pet object
	//Precondition: None
	//Postcondition: sets the name to the string parameter
	void setName(string);

	//setSize
	//Sets the size of both the int and the vectors
	//Precondition: None
	//Postcondition: sets the size of both vectors and value of size int
	void setSize(int);

	//getRank
	//Gets the value of the rank from the index of the int
	//Precondition: None
	//Postcondition: returns the ranking value of the int index
	int getRank(int);

	//setRank
	//Sets the ranking table for each pet
	//Precondition: setPref must have been called earlier during initialization to set preference table
	//Postcondition: Sets the table for the ranking
	void setRank();

	//setPref
	//Sets the preference table for each pet, using index and value as parameters
	//Precondition: None
	//Postcondition: Sets the index of the preference table to the value
	void setPref(int, int);

private:
	int size;				//size of both vectors
	string name;			//string of name for the pet
	vector<int> petPref;	//vector of the preferences for the pet
	vector<int> petRank;	//vector of the rankings for the pet

};