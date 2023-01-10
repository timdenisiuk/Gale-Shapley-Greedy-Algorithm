// ------------------------------------------------ Gale-Shapley.cpp --------------------------------------------------

// Name and Class: Tim Denisiuk CSS 449
// Code Use: Defines each function for the Gale-Shapley class
// Creation Date: 03/30/2022
// Last Modified: 04/04/2022
// --------------------------------------------------------------------------------------------------------------------

//Purpose: Defines all functions for the Gale-Shapley class
//Functionality: Constructs all tables, sets values for all tables, perform algorithms based on tables
//				 and output the results of the algorithm
//Assumptions: The assumption is made that all text file input is formatted the same way
//			   The assumption is made that each input is a valid input, and there are the same number of owners as pets
// -------------------------------------------------------------------------------------------------------------------- 

#include <iostream>
#include <fstream>
#include "Gale-Shapley.h"
#include "Owner.h"
#include "Pet.h"
using namespace std;

//Constructor:
//Default Constructor for the GaleShapley class
//Preconditions: Node
//Postconditions: Initializes empty vectors for each table
GaleShapley::GaleShapley()
{
	size = 0;
	return;
}

//Destructor:
//Default destructor for the GaleShapley class
//Preconditions: None
//Postconditions: None, because there are no dynamically allocated data types in the class
GaleShapley::~GaleShapley()
{
	return;
}

//buildTables:
//Initializing function that creates all required tables based on text file input
//Preconditions: None
//Postconditions: Sets all tables to have the values required for the algorithm
void GaleShapley::buildTables(ifstream& infile)
{
	int preference;
	string tempName;
	if (!infile)													//fail-safe for a bad file
	{
		cout << "File not found / couldn't be opened" << endl;
		return;
	}

	infile >> size;

	ownerMatch.resize(size);										//program crashes if empty vectors are not resized beforehand
	petMatch.resize(size);
	for (int i = 0; i < size; i++)									//sets the match table to -1 for unmatched owners/pets
	{
		ownerMatch[i] = -1;
		petMatch[i] = -1;
	}

	ownerObjectArray.resize(size);
	petObjectArray.resize(size);


	for (int i = 0; i < size; i++)									//sets the name of each owner object
	{
		infile >> tempName;
		ownerObjectArray[i].setName(tempName);
	}


	for (int i = 0; i < size; i++)									//sets the preference list for each owner object
	{
		for (int j = 0; j < size; j++)
		{
			infile >> preference;
			preference--;											//to match zero-based vectors
			ownerObjectArray[i].setNextPreference(preference);
		}
	}
	

	for (int i = 0; i < size; i++)									//sets the name of each pet object
	{
		infile >> tempName;
		petObjectArray[i].setName(tempName);
	}


	for (int i = 0; i < size; i++)									//sets the preference vector of each pet object
	{
		petObjectArray[i].setSize(size);							//vector needs to be resized to avoid crashing
		for (int j = 0; j < size; j++)
		{
			infile >> preference;
			preference--;											//uses zero-based vector
			petObjectArray[i].setPref(j, preference);
		}
	}


	for (int i = 0; i < size; i++)									//sets ranking vector after preference vector to be O(1) time
	{
		petObjectArray[i].setRank();
	}


	for (int i = 0; i < size; i++)									//sets list of unmatched owners to keep track of who is still unmatched
	{
		unmatchedOwner.push(i);
	}

}

//performAlgorithm:
//Performs the Gale-Shapley algorithm running in O(n^2) time
//Precondition: buildTables must have been called earlier to store all required data
//Postcondition: Sets the pairing tables so it pairs each owner to each pet
void GaleShapley::performAlgorithm()
{
	int owner, ownerPetPreference, prevOwner;
	
	while (unmatchedOwner.size() != 0)																//performs algorithm so long as there is an unmatched owner
	{
		owner = unmatchedOwner.front();
		unmatchedOwner.pop();


		ownerPetPreference = ownerObjectArray[owner].getNextPreference();


		if (petMatch[ownerPetPreference] < 0)														//adds matching is match value is less than 0 (-1)
		{
			ownerMatch[owner] = ownerPetPreference;
			petMatch[ownerPetPreference] = owner;
		}


		else if (petObjectArray[ownerPetPreference].getRank(petMatch[ownerPetPreference]) >			//if current owner rank is higher than new owner rank, swaps owners and puts old owner into unmatched list
			petObjectArray[ownerPetPreference].getRank(owner))
		{
			prevOwner = petMatch[ownerPetPreference];
			ownerMatch[owner] = ownerPetPreference;
			petMatch[ownerPetPreference] = owner;
			unmatchedOwner.push(prevOwner);
			ownerMatch[prevOwner] = -1;
		}


		else																					    //swap can't happen, pushes current owner back to unmatched list
			unmatchedOwner.push(owner);
	}
}

//OutputResuilts:
//Outputs a formatted version of the match tables
//Precondition: performAlgorithm must be called so tables can be set
//Postcondition: Outputs the pairing of each owner to each pet
void GaleShapley::outputResults()
{
	for (int i = 0; i < size; i++)
	{
		cout << ownerObjectArray[i].getName() << " / " << petObjectArray[ownerMatch[i]].getName() << "" "" << endl;
	}
}