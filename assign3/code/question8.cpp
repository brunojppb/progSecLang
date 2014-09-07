#include <iostream>
using namespace std;

int main(){

  int number;
  int sum = 0;

  cout << "Enter the number: ";
  cin >> number;

  for (int i = 1; i <= number; i++){
    sum += i;
  }

  cout << "The sum of all the integers  from 1 up to " << number << " is ";
  cout << sum << endl;

  return 0;
}
