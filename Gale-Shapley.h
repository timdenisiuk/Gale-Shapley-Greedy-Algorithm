// ------------------------------------------------ Gale-Shapley.h ----------------------------------------------------

// Name and Class: Tim Denisiuk CSS 449
// Code Use: Used to store all public functions and private data types for the algoritm
// Creation Date: 03/30/2022
// Last Modified: 04/04/2022
// --------------------------------------------------------------------------------------------------------------------

//Purpose: GaleShapley class stores all data it needs from the text file to perform the algorithm
//Functionality: Stores vectors for all data within the text file and uses those vectors to perform each function
//				 Same class can be used with multiple text file inputs
//Assumptions: The assumption is made that all text file input is formatted the same way
//			   The assumption is made that each input is a valid input, and there are the same number of owners as pets
// -------------------------------------------------------------------------------------------------------------------- 
#pragma once
#include <iostream>
#include <queue>
#include <vector>
#include "Owner.h"
#include "Pet.h"

using namespace std;


class GaleShapley
{
public:
	//Constructor:
	//Default Constructor for the GaleShapley class
	//Preconditions: Node
	//Postconditions: Initializes empty vectors for each table
	GaleShapley();

	//Destructor:
	//Default destructor for the GaleShapley class
	//Preconditions: None
	//Postconditions: None, because there are no dynamically allocated data types in the class
	~GaleShapley();

	//buildTables:
	//Initializing function that creates all required tables based on text file input
	//Preconditions: None
	//Postconditions: Sets all tables to have the values required for the algorithm
	void buildTables(ifstream&);

	//performAlgorithm:
	//Performs the Gale-Shapley algorithm running in O(n^2) time
	//Precondition: buildTables must have been called earlier to store all required data
	//Postcondition: Sets the pairing tables so it pairs each owner to each pet
	void performAlgorithm();

	//OutputResuilts:
	//Outputs a formatted version of the match tables
	//Precondition: performAlgorithm must be called so tables can be set
	//Postcondition: Outputs the pairing of each owner to each pet
	void outputResults();

private:
	int size;							//size of all vectors
	vector<int> ownerMatch;				//vector that stores each owner's pet match
	vector<int> petMatch;				//vector that stores each pet's owner match
	vector<Owner>ownerObjectArray;		//vector that stores all owner objects
	vector<Pet> petObjectArray;			//vector that stores all pet objects
	queue<int> unmatchedOwner;			//queue that stores unmatched owners
};