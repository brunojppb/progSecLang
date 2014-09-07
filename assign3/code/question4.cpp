#include <iostream>
using namespace std;

int main(){

  double beginningBalance, checkCharges, totalCharges;
  int numberOfChecks;

  cout << "Enter the Beginning Balance: ";
  cin >> beginningBalance;

  if(beginningBalance < 0){
    cout << "ALERT!: Your account is Overdraw!\n";
  }

  cout << "Enter the number of Checks: ";
  cin >> numberOfChecks;

  if(numberOfChecks < 0){
    cout << "you must enter a value greater then 0\n";
  }else{

      if(numberOfChecks >= 60){
        checkCharges = 0.04 * numberOfChecks;
      }
      else if(numberOfChecks >= 40){
        checkCharges = 0.06 * numberOfChecks;
      }
      else if(numberOfChecks >= 20){
        checkCharges = 0.08 * numberOfChecks;
      }else{
        checkCharges = 0.10 * numberOfChecks;
      }

      if(beginningBalance < 400){
        totalCharges = 10 + checkCharges + 15;
      }else{
        totalCharges = 10 + checkCharges;
      }

      cout << "Bank's Service fees: \n";
      cout << "=========================\n";
      cout << "Bank Charges: \t\t $ 10.00\n";
      cout << "Check fees: \t\t $ " << checkCharges << endl;
      if(beginningBalance < 400){
        cout << "ballance below $400: \t $ 15.00\n";
      }
      cout << "Total: \t\t\t $ " << totalCharges << endl;


  }
  return 0;






















}
