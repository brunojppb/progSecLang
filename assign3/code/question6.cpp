#include <iostream>
using namespace std;

int main(){

    const double CARBON_DIOXIDE_SPEED = 258;
    const double AIR_SPEED = 331.5;
    const double HELIUM_SPEED = 972;
    const double HYDROGEN_SPEED = 1270;

    int option, seconds;
    double distance = 0;

    cout << "Select one gas(enter a number): \n";
    cout << "1 - Carbon Dioxide\n";
    cout << "2 - Air\n";
    cout << "3 - Helium\n";
    cout << "4 - Hydrogen\n";

    cin >> option;
    if(option >= 1 && option <= 4){

      cout << "Enter the number of seconds: ";
      cin >> seconds;
      if(seconds >= 0 && seconds <= 30){

        switch(option){

          case 1:
            distance = CARBON_DIOXIDE_SPEED * seconds;
            break;

          case 2:
            distance = AIR_SPEED * seconds;
            break;

          case 3:
            distance = HELIUM_SPEED * seconds;
            break;

          case 4:
            distance = HYDROGEN_SPEED * seconds;
            break;

          default:
            break;
        }

        cout << "Distance: " << distance << " Meter(s)\n";

      }
      else{
        cout << "You must enter seconds between 0 and 30\n";
      }

    }
    else{
      cout << "Wrong Option.\n";
    }

    return 0;

}
