#include "Calculator-Functions.h"
#include <iostream>

using namespace std;

int main() {
	//Get the number of units and what they're aiming at.
	int one, two, three, four;
	int total = getUnits(one, two, three, four);

	//Set an array which will contain each unit's strength value (as an int)
	double* strength = new double[total];
	setStrengthArray(strength,one,two,three,four,1);

	//Set an array for the probablities of the number of hits from 0-total
	double* prob = new double[total + 1]();
	calculateProb(strength,prob,total);

	//Print probabilities
	displayProb(prob,total);

	//Free any memory.
	delete[] strength;
	strength = NULL;
	delete[] prob;
	prob = NULL;
}