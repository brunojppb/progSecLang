/*
    PROGRAM: question5.CPP
    Written by Bruno Paulino
    This program calculates the monthly sales tax
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main(){

  int year;
  string month;

  double totalCollected;
  double sales;
  double countySalesTax;
  double stateSalesTax;
  double totalSalesTax;

  cout << "Enter the month: ";
  getline(cin, month);

  cout << "Enter the year: ";
  cin >> year;

  cout << "Enter the total amount collected: ";
  cin >> totalCollected;

  sales = totalCollected / 1.06;
  countySalesTax = sales * 0.02;
  stateSalesTax = sales * 0.04;
  totalSalesTax = countySalesTax + stateSalesTax;

  cout << "Month: " << month << endl;
  cout << "________________________\n";

  cout << "Total Collected: \t$ " << fixed << setprecision(2) << setw(8) << totalCollected << endl;
  cout << "Sales: \t\t\t$ " << fixed << setprecision(2) << setw(8) << sales << endl;
  cout << "County Sales Tax: \t$ " << fixed << setprecision(2) << setw(8) << countySalesTax << endl;
  cout << "State Sales Tax: \t$ " << fixed << setprecision(2) << setw(8) << stateSalesTax << endl;
  cout << "Total Sales Tax: \t$ " << fixed << setprecision(2) << setw(8) << totalSalesTax << endl;

  return 0;
}
