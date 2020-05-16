#include <iostream>
#include <cmath>
#include "Calculator-Functions.h"

int getUnits(int& one, int& two, int& three, int& four) {
    cout << "Number @1: ";
    cin >> one;
    cout << "Number @2: ";
    cin >> two;
    cout << "Number @3: ";
    cin >> three;
    cout << "Number @4: ";
    cin >> four;
    return one + two + three + four;
}

void setStrengthArray(double* s, int one, int two, int three, int four, int curr) {
    int i, n;
    double val;
    switch (curr) {
    case 1:
        i = 0;
        n = one;
        val = 1.0/6.0;
        break;
    case 2:
        i = one;
        n = one + two; 
        val = 2.0/6.0;
        break;
    case 3:
        i = one+two;
        n = one + two + three;
        val = 3.0/6.0;
        break;
    case 4:
        i = one+two+three;
        n = one + two + three + four;
        val = 4.0/6.0;
        break;
    }
    for (; i < n; i++) {
        s[i] = val;
    }
    if (curr < 4) {
        setStrengthArray(s, one, two, three, four, curr + 1);
    }
    return;
}

void calculateProb(double* s, double* p, int n) {
    //Number of possible scenarios, a n-digit binary number where each unit misses (0) or hits (1)
    int scenarios = 1 << n;
    for (int i = 0; i < scenarios; i++) {
        struct scenarioData data = calculateScenarioProb(s,n,i);
        p[data.numHit] += data.prob;
    }
    return;
}

struct scenarioData calculateScenarioProb(double* s, int n, int scenario) {
    int numHit = 0;
    double prob = 1;
    for (int i = 0; i < n; i++) {
        if (!(scenario % 2)) {
            prob *= (1.0 - s[i]);
        }
        else {
            prob *= s[i];
            numHit++;
        }
        scenario /= 2;
    }
    scenarioData toReturn;
    toReturn.numHit = numHit;
    toReturn.prob = prob;
    return toReturn;
}


void displayProb(double* p, int n) {
    for (int i = 0; i <= n; i++) {
        cout << "Probability of " << i;
        if (i == 1) {
            cout << " hit: ";
        }
        else {
            cout << " hits: ";
        }
        cout << p[i] << endl;
    }
    return;
}