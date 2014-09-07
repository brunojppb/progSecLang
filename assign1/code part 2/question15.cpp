/*
    PROGRAM: question15.CPP
    Written by Bruno Paulino
    This program calculates how much money Kathryn spent with 600 shares of stock
*/

#include <iostream>
using namespace std;

int main(){

    int amountOfStock = 600;
    double pricePerShare = 21.77;
    double commissionPercentage = 0.02;
    double totalPaid = pricePerShare * amountOfStock;

    cout << "Question15:" << endl;
    cout << "The amount paid for the stock alone: (without the commission): $" << totalPaid << endl;
    cout << "The amount of the commision:                                   $" << totalPaid * commissionPercentage << endl;
    cout << "The total amount paid (for the stock plus the commission):     $" << totalPaid + (totalPaid * commissionPercentage) << endl;

    return 0;
}
