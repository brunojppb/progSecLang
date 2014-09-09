/*
    PROGRAM: question12.CPP
    Written by Bruno Paulino
    This program calculates:
     1- the number of numbers in the file
     2- The sum of all the numbers in the file
     3 - The average of all the numbers in the file

*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){

    int quantity = 0;
    double number;
    double sum = 0;
    ifstream myFile;
    myFile.open("random.txt");

    if(myFile.is_open()){
        while(myFile >> number){
            sum += number;
            quantity++;
        }

        cout << "The number of numbers in the file is: " << quantity << endl;
        cout << "The sum of all the numbers in the file is: " << sum << endl;
        cout << "The Average of all the numbers is: " << (sum/quantity) << endl;
    }

    return 0;
}
