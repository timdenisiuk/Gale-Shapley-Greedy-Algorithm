// ------------------------------------------------ Program1.cpp ------------------------------------------------------

// Name and Class: Tim Denisiuk CSS 449
// Code Use: Driver for the program
// Creation Date: 03/30/2022
// Last Modified: 04/04/2022
// --------------------------------------------------------------------------------------------------------------------

//Purpose: Driver for the program
//Functionality: Creates the Gale-Shapley class and uses it to performthe algorithm		
//Assumptions:
// -------------------------------------------------------------------------------------------------------------------- 
#include <iostream>
#include <fstream>
#include <list>
#include <queue>
#include "Gale-Shapley.h"
using namespace std;

//main
//Driver for the program
//Precondition: None
//Postconditions: Performs the Gale-Shapley algorithm
int main()
{	
	ifstream infile("program1data.txt");
	GaleShapley gale;
	gale.buildTables(infile);
	gale.performAlgorithm();
	gale.outputResults();
}




