/*
    PROGRAM: question3.CPP
    Written by Bruno Paulino
    This program calculates the sine, cosine and tangent of the angle
*/

#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int main(){

  double angleInRadians;

  cout << "Enter the angle in radians: ";
  cin >> angleInRadians;

  cout << "Sine: " << fixed << setprecision(4) << sin(angleInRadians) << endl;
  cout << "Cosine: " << cos(angleInRadians) << endl;
  cout << "Tangent: " << tan(angleInRadians) << endl;


  return 0;
}
