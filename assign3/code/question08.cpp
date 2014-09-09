/*
    PROGRAM: question08.CPP
    Written by Bruno Paulino
    This program a sum of numbers starting by 1 until the number provided
*/

#include <iostream>
using namespace std;

int main(){

  int number;
  int sum = 0;

  cout << "Enter the number: ";
  cin >> number;
  if(number > 0){
      for (int i = 1; i <= number; i++){
        sum += i;
      }

      cout << "The sum of all the integers  from 1 up to " << number << " is ";
      cout << sum << endl;
  }
  else{
    cout << "You must enter a number greater then 0\n";
  }

  return 0;
}
