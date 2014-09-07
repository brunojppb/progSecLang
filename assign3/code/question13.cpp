#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){

    int year = 1900;
    int number;
    ifstream myFile;
    myFile.open("people.dat");

    if(myFile.is_open()){
        cout << "PRAIRIEVILLE POPULATION GROWTH\n";
        cout << "(each * represents 1,000 people)\n";
        while(myFile >> number){
            cout << year << " " << "(" << number << ") ";
            for(int i = 0; i < (number/1000); i++){
                cout << "*";
            }
            if((number % 1000) != 0){
                if((number % 1000) > 500){
                  cout << "*";
                }
            }
            cout << "\n";
            year += 20;
        }
    }

    return 0;
}
