/*
    PROGRAM: question13.CPP
    Written by Bruno Paulino
    This program calculates the selling price of a circuit board
*/

#include <iostream>
using namespace std;

int main(){

    double profit = 0.4;
    double circuitCost = 12.67;

    cout << "QUESTION13:" << endl;
    cout << "A circuit that costs:      $" << circuitCost << endl;
    cout << "The selling price will be: $" << circuitCost + (circuitCost * profit) << endl;

    return 0;
}
