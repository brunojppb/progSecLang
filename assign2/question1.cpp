/*
    PROGRAM: question1.CPP
    Written by Bruno Paulino
    This program calculates the mileage Per Gallon
*/

#include <iostream>
using namespace std;

int main(){

  int gallons;
  double mileage;

  cout << "Enter the number of gallons of gas the car can hold: ";
  cin >> gallons;
  cout << "Enter the number of miles it can be driven on a full tank: ";
  cin >> mileage;

  double mileagePerGallon = mileage/gallons;

  cout << "The mileage per gallon is: " << mileagePerGallon << endl;

  return 0;
}
