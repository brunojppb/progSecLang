#include <iostream>
using namespace std;

int main(){

  const double CALORIES_PER_MINUTE = 3.9;

  for (int i = 10; i <= 25; i+= 5){
    cout << "Calories burned after " << i << " minutes: ";
    cout << i * CALORIES_PER_MINUTE << endl;
  }

  return 0;
}
