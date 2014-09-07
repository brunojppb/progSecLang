/*
    PROGRAM: question6.CPP
    Written by Bruno Paulino
    This program calculates the monthly payments
*/

#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int main(){

  double rate;
  double numberOfPaiments;
  double amountOfLoan;

  cout << "Enter the amount of the loan:";
  cin >> amountOfLoan;
  cout << "Enter the rate: ";
  cin >> rate;
  rate = rate / 100.0;
  cout << "Enter the number of paiments: ";
  cin >> numberOfPaiments;

  double payment = ((rate * pow((1.0 + rate), numberOfPaiments)) / (pow((1.0+rate), numberOfPaiments)-1)) * amountOfLoan;

  cout << "Loan Amount: \t\t\t$ " << fixed << setprecision(2) << setw(8) << amountOfLoan << endl;
  cout << "Monthly Interest Rate: \t\t$ " <<  setw(7) << setprecision(0) << rate*100 << "%\n";
  cout << "Number of Payments: \t\t$ " << setw(8) << numberOfPaiments << endl;
  cout << "Monthly Payment: \t\t$ " << setw(8) << setprecision(2) << payment << endl;
  cout << "Amount Paid back: \t\t$ " << setw(8) << numberOfPaiments*payment << endl;
  cout << "Interest Paid: \t\t\t$ " << setw(8) << (numberOfPaiments*payment)-amountOfLoan << endl;

  return 0;
}
