/*
    PROGRAM: question2.CPP
    Written by Bruno Paulino
    This program calculates the amount of income generated from tickets sales
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main(){

  double classASeatPrice = 15;
  double classBSeatPrice = 12;
  double classCSeatPrice =  9;

  double classASeatsSold;
  double classBSeatsSold;
  double classCSeatsSold;

  cout << "Enter how many Class A seats were sold: ";
  cin >> classASeatsSold;
  cout << "Enter how many Class B seats were sold: ";
  cin >> classBSeatsSold;
  cout << "Enter how many Class C seats were sold: ";
  cin >> classCSeatsSold;

  double totalAmount =  (classASeatPrice * classASeatsSold) +
                        (classBSeatPrice * classBSeatsSold) +
                        (classCSeatPrice * classCSeatsSold);

  cout << "The total amout is: $" << fixed << setprecision(2) << totalAmount << endl;

  return 0;
}
