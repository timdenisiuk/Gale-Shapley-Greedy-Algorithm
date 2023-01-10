// ------------------------------------------------ Pet.cpp -----------------------------------------------------------

// Name and Class: Tim Denisiuk CSS 449
// Code Use: Used to define functions in pet class
// Creation Date: 03/30/2022
// Last Modified: 04/04/2022
// --------------------------------------------------------------------------------------------------------------------

//Purpose: Defines all functions for the pet class
//Functionality: stores vectors of each preference and ranking so it can be performs in O(1) time			
//Assumptions:
// -------------------------------------------------------------------------------------------------------------------- 

#pragma once
#include <iostream>
#include "Pet.h"
using namespace std;

//Constructor
//Default constructor for pet class
//Preconditions: None
//Postconditions: creates empty vectors for preferences
Pet::Pet()
{
	name = "";
}

//Destructor
//Default destructor for pet class
//Preconditions: None
//Postcondition: None, because nothing is dynamically allocated
Pet::~Pet()
{
}

//getName
//Returns the name of the pet object
//Preconditions: None
//Postconditions: returns a string that is the name of the pet
string Pet::getName()
{
	return name;
}

//setName
//Sets the name for the pet object
//Precondition: None
//Postcondition: sets the name to the string parameter
void Pet::setName(string inputName)
{
	name = inputName;
}

//setSize
//Sets the size of both the int and the vectors
//Precondition: None
//Postcondition: sets the size of both vectors and value of size int
void Pet::setSize(int inputSize)
{
	size = inputSize;
	petPref.resize(inputSize);
	petRank.resize(inputSize);
}

//getRank
//Gets the value of the rank from the index of the int
//Precondition: None
//Postcondition: returns the ranking value of the int index
int Pet::getRank(int index)
{
	return petRank[index];
}

//setRank
//Sets the ranking table for each pet
//Precondition: setPref must have been called earlier during initialization to set preference table
//Postcondition: Sets the table for the ranking
void Pet::setRank()
{
	for (int i = 0; i < size; i++)
	{
		petRank[petPref[i]] = i;
	}
}

//setPref
//Sets the preference table for each pet, using index and value as parameters
//Precondition: None
//Postcondition: Sets the index of the preference table to the value
void Pet::setPref(int index, int value)
{
	petPref[index] = value;
}