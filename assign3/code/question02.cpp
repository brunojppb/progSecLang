/*
    PROGRAM: question02.CPP
    Written by Bruno Paulino
    This program calculates if one date is a magic dates
*/
#include <iostream>
using namespace std;

int main(){

  int day, month, year;

  cout << "Enter the day: ";
  cin >> day;
  cout << "Enter the month: ";
  cin >> month;
  cout << "Enter the year(2 numbers): ";
  cin >> year;

  if((day * month) == year){
    cout << "This date is magic!\n";
  }else{
    cout << "This date is not magic!\n";
  }

  return 0;
}
