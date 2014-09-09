/*
    PROGRAM: question03.CPP
    Written by Bruno Paulino
    This program calculates how many hours/minutes/seconds according to the input
*/
#include <iostream>
using namespace std;

int main(){

  int seconds;

  cout << "Enter the number of seconds: ";
  cin >> seconds;

  if(seconds < 0){
    cout << "You must enter a number greater then 0\n";
  }
  else{
    if(seconds >= 86400){
      cout << "The number of days in " << seconds << " is: ";
      cout << (seconds / 86400.0) << endl;
    }
    else if(seconds >= 3600){
      cout << "The number of hours in " << seconds << " is: ";
      cout << (seconds / 3600.0) << endl;
    }
    else{
      cout << "The number of minutes in " << seconds << " is: ";
      cout << (seconds / 60.0) << endl;
    }
  }
  return 0;
}
