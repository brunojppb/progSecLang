/*
    PROGRAM: question7.CPP
    Written by Bruno Paulino
    This program calculates the ocean levels after 5, 7 and 10 years
*/

#include <iostream>
using namespace std;

int main(){
    double averagePerYear = 1.5;
    
    double millimitersAfter5Years = averagePerYear * 5;
    double millimitersAfter7Years = averagePerYear * 7;
    double millimitersAfter10Years = averagePerYear * 10;

    cout << "QUESTION 7: " << endl;
    cout << "The number of millimiters after 5 years: " << millimitersAfter5Years << endl;
    cout << "The number of millimiters after 7 years: " << millimitersAfter7Years << endl;
    cout << "The number of millimiters after 10 years: " << millimitersAfter10Years << endl;

    return 0;
}
