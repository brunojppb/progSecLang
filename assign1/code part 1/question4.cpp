/*
    PROGRAM: question4.CPP
    Written by Bruno Paulino
    This program calculates the restaurant bill
*/

#include <iostream>
#include <stdio.h>
using namespace std;

int main(){

    double tipPercentage = 15.0 / 100;
    double taxPercentage = 6.75 / 100;
    double mealCharge = 44.5;

    double totalTax = mealCharge * taxPercentage;
    double totalTip = (mealCharge + totalTax) * tipPercentage;

    double totalBill = mealCharge + totalTax + totalTip;

    cout << "QUESTION4: " << endl;
    printf("Meal Cost: %.2f\n", mealCharge);
    printf("Total Tax: %.2f\n", totalTax);
    printf("Total Tip: %.2f\n", totalTip);
    printf("Total Bill: %.2f\n", totalBill);

    return 0;
}
