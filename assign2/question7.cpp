/*
    PROGRAM: question7.CPP
    Written by Bruno Paulino
    This program calculates how many pizzas we need to buy
*/

#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int main(){

  int pizzasNeeded;
  double numberOfPeople;
  double inches;
  double sliceArea = 14.125; //square inches

  cout << "Enter how many people will be in the party: ";
  cin >> numberOfPeople;

  cout << "Enter the diameter of the pizzas to be ordered: ";
  cin >> inches;

  double pizzaArea = M_PI * pow((inches/2.0), 2);
  int numberOfSlicesPerPizza = pizzaArea / sliceArea;
  int slicesNeeded = numberOfPeople * 4;

  if(slicesNeeded % numberOfSlicesPerPizza == 0){
    pizzasNeeded = slicesNeeded / numberOfSlicesPerPizza;
  }else{
    pizzasNeeded = (slicesNeeded / numberOfSlicesPerPizza) + 1;
  }

  cout << numberOfPeople << " people will eat " << slicesNeeded << " slices of pizza." << endl;
  cout << "One pizza with " << inches << " inches will be splited in " << numberOfSlicesPerPizza << " slices." << endl;
  cout << "You need to purchase " << pizzasNeeded << " Pizzas." << endl;

  return 0;
}
