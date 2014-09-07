/*
    PROGRAM: question8.CPP
    Written by Bruno Paulino
    This program calculates the subtotal and the total of a customer purchase
*/

#include <iostream>
#include <stdio.h>
using namespace std;

int main(){
    
    double priceItem1 = 12.95;
    double priceItem2 = 24.95;
    double priceItem3 = 6.95;
    double priceItem4 = 14.95;
    double priceItem5 = 3.95;

    double subTotal = priceItem1 + priceItem2 + priceItem3 + priceItem4 + priceItem5;
    double totalTax = subTotal * (6.0 / 100);
    double total = subTotal + totalTax;

    cout << "QUESTION 8: " << endl;
    printf("Subtotal: %.2f\n", subTotal);
    printf("Tax:      %.2f\n", totalTax);
    printf("______________\n");
    printf("Total:    %.2f\n", total);

    return 0;
}
