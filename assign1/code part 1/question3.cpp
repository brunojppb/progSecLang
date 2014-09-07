/*
    PROGRAM: question3.CPP
    Written by Bruno Paulino
    This program calculates total sales tax on a $52 purchase
*/

#include <iostream>
using namespace std;

int main(){
    //variables to store each tax value.
    double stateSalesTax = 4;
    double countySalesTax = 2;
    double totalSales = 52;

    //calculates the total sales tax
    double totalSalesTax = totalSales * ((stateSalesTax + countySalesTax) / 100);

    cout << "QUESTION 3: " << endl;
    cout << "Total Sales Tax: " << totalSalesTax << endl;

    return 0;
}
