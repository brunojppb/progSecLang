/*
    PROGRAM: question10.CPP
    Written by Bruno Paulino
    This program calculates the long-distance carrier charges for telefones calls
*/

#include <iostream>
using namespace std;

int main(){


  const double RATE_PER_MINUTE_MORNING = 0.12;
  const double RATE_PER_MINUTE_DUTY_HOURS = 0.55;
  const double RATE_PER_MINUTE_NIGHT = 0.35;
  float startTime;
  float totalCharge;
  int minutesOfTheCall;
  float minutes;

  cout << "Enter the starting time: ";
  cin >> startTime;

  minutes = startTime - static_cast<int>(startTime);

  if((startTime >= 0 && startTime <= 23) && (minutes >= 0.0 && minutes <= 0.59)){

    cout << "Enter the number of minutes of the call: ";
    cin >> minutesOfTheCall;

    if(minutesOfTheCall > 0){

      if(startTime > 19){
        totalCharge = minutesOfTheCall * RATE_PER_MINUTE_NIGHT;
      }
      else if(startTime >= 7){
        totalCharge = minutesOfTheCall * RATE_PER_MINUTE_DUTY_HOURS;
      }
      else{
        totalCharge = minutesOfTheCall * RATE_PER_MINUTE_MORNING;
      }

      cout << "Total Charges: \t$ " << totalCharge << endl;

    }
    else{
      cout << "You must enter a number of minutes greater then 0\n";
    }

  }else{
    cout << "You must enter a valid hour and minute\n";
  }

  return 0;
}
