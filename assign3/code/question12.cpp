#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){

    int qtd = 0;
    double number;
    double sum = 0;
    ifstream myFile;
    myFile.open("random.txt");

    if(myFile.is_open()){
        while(myFile >> number){
            sum += number;
            qtd++; 
        }

        cout << "The number of numbers in the file is: " << qtd << endl;
        cout << "The sum of all the numbers in the file is: " << sum << endl;
        cout << "The Average of all the numbers is: " << (sum/qtd) << endl;
    }

    return 0;
}