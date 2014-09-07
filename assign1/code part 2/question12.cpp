/*
    PROGRAM: question12.CPP
    Written by Bruno Paulino
    This program calculates how many acres is equivalent to square feet
*/

#include <iostream>
using namespace std;

int main(){

    double acreInSquareFeet = 43560;
    double squareFeetLand = 389767;

    cout << "QUESTION12:" << endl;
    cout << "A tract of a land with " << squareFeetLand << " square feet is equivalent to: "
                                    << squareFeetLand/acreInSquareFeet << " acres" << endl;

    return 0;
}
