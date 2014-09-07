/*
    PROGRAM: question2.CPP
    Written by Bruno Paulino
    This program calculates how much money the East Coast sales division generates. 
    We know that the sales division generates 62% of the total sales.
*/

#include <iostream>
#include <stdio.h>
using namespace std;

int main(){
    //variables to store the integer numbers.
    double totalAmountOfTheYear = 4600000;

    //calculates the division amount
    double eastCoastSalesDivisionAmount = totalAmountOfTheYear * (62.0 / 100.0);

    cout << "QUESTION 2: " << endl;
    //using printf function to format the output number
    printf("East Coast Sales Division will generate: %.2f Dollars\n", eastCoastSalesDivisionAmount);

    return 0;
}
