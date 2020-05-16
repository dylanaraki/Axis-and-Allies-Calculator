#pragma once

using namespace std;

//Struct used which contains data about a specific scenario
struct scenarioData {
	int numHit;
	double prob;
};


//Sets the value of the number of units aiming from 1-4 and returns the total number.
int getUnits(int& one, int& two, int& three, int& four);
//Set the chance of hitting for each unit
void setStrengthArray(double* s, int one, int two, int three, int four, int curr);
//Calculate the probability of each number of hits
void calculateProb(double* s, double* p, int n);
//Calculate the probability of a specific scenario occurring
struct scenarioData calculateScenarioProb(double* s, int n, int scenario);
//Prints the probablities of each being hit
void displayProb(double* p, int n);