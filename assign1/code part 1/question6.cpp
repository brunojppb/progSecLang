/*
    PROGRAM: question6.CPP
    Written by Bruno Paulino
    This program calculates the employee’s total annual pay.
*/

#include <iostream>
using namespace std;

int main(){
    double payAmount = 1700.0;
    int payPeriods = 26;
    double annualPay = payAmount * payPeriods;

    cout << "QUESTION6: " << endl;
    cout << "Employee's Total Annual Pay: " << annualPay << endl;

    return 0;
}
