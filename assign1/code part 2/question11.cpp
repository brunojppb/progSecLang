/*
    PROGRAM: question11.CPP
    Written by Bruno Paulino
    This program calculates the distance the car can travel on one tank of gas in town
    and on the highway
*/

#include <iostream>
using namespace std;

int main(){
    
    double gallons = 20;
    double townAverages = 21.5;
    double highwayAverages = 26.8;

    cout << "QUESTION11:" << endl;
    cout << "Distance the car can travel one tank: " << endl;
    cout << "In Town:    " << gallons * townAverages << " miles." << endl;
    cout << "On highway: " << gallons * highwayAverages << " miles." << endl;

    return 0;
}
