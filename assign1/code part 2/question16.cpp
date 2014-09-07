/*
    PROGRAM: question16.CPP
    Written by Bruno Paulino
    This program calculates the number of customers that purchase energy drink
*/

#include <iostream>
using namespace std;

int main(){

  int numberOfCustomers = 12467;
  double oneOrMoreDrinksPercentage = 0.14;
  double flavoredDrinkPercentage = 0.64;

  cout << "One or more energy drink per week: " << numberOfCustomers * oneOrMoreDrinksPercentage << endl;
  cout << "Prefer citrus flavored:            " << (numberOfCustomers * oneOrMoreDrinksPercentage) * flavoredDrinkPercentage << endl;

  return 0;
}
