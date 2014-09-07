/*
    PROGRAM: question5.CPP
    Written by Bruno Paulino
    This program calculates the average of 5 numbers.
*/

#include <iostream>
using namespace std;

int main(){
    //variables to store the numbers.
    int value1 = 28;
    int value2 = 32;
    int value3 = 37;
    int value4 = 24;
    int value5 = 33;

    //sum of the variables that were declared before.
    int sum = value1 + value2 + value3 + value4 + value5;

    double average = sum / 5.0;

    cout << "QUESTION5: " << endl;
    cout << "Average: " << average << endl;

    return 0;
}
