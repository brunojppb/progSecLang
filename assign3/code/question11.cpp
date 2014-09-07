#include <iostream>
using namespace std;

int main(){

  double sales1, sales2, sales3, sales4, sales5;

  cout << "Enter today’s sales for store 1: ";
  cin >> sales1;
  cout << "Enter today’s sales for store 2: ";
  cin >> sales2;
  cout << "Enter today’s sales for store 3: ";
  cin >> sales3;
  cout << "Enter today’s sales for store 4: ";
  cin >> sales4;
  cout << "Enter today’s sales for store 5: ";
  cin >> sales5;

  cout << "SALES BAR CHART:\n";
  cout << "(Each * = $100)\n";

  cout << "Store 1: ";
  for(int i = 0; i < (sales1/100); i++){
    cout << "*";
  }
  cout << "\nStore 2: ";
  for(int i = 0; i < (sales2/100); i++){
    cout << "*";
  }
  cout << "\nStore 3: ";
  for(int i = 0; i < (sales3/100); i++){
    cout << "*";
  }
  cout << "\nStore 4: ";
  for(int i = 0; i < (sales4/100); i++){
    cout << "*";
  }
  cout << "\nStore 5: ";
  for(int i = 0; i < (sales5/100); i++){
    cout << "*";
  }
  cout << endl;

  return 0;
}
