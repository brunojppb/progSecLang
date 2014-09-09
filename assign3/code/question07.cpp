/*
    PROGRAM: question07.CPP
    Written by Bruno Paulino
    This program creates a geometry calculator
    and computes:
     1- the area of the Circle
     2- the area of the Rectangle
     3- the area of the triangle
*/

#include <iostream>
#include <math.h>
using namespace std;

int main(){

    int option = 10;
    double PI = 3.14159;;
    double radius, rectangleLength, rectangleWidth, triangleBase, triangleHeight;

    do{
        cout << "Geometry  Calculator:\n";
        cout << "1. Calculate the area of the Circle\n";
        cout << "2. Calculate the area of the Rectangle\n";
        cout << "3. Calculate the area of the Triangle\n";
        cout << "4. Quit\n";
        cout << "Enter your choice(1-4)\n";
        cin >> option;

        if(option < 1 || option > 4){
            cout << "Wrong Option!\n";
            break;
        }
        else{
            switch(option){
                case 1:
                    cout << "Enter the radius of the circle:\n";
                    cin >> radius;
                    if(radius < 0)
                      cout << "Invalid Radius!\n";
                    else
                      cout << "The area of the circle is: " << (PI * pow(radius, 2)) << endl;
                    break;

                case 2:
                    cout << "Enter the length of the Rectangle:\n";
                    cin >> rectangleLength;
                    if (rectangleLength < 0)
                      cout << "Invalid Rectangle Length!\n";
                    else{
                        cout << "Enter the width of the Rectangle:\n";
                        cin >> rectangleWidth;
                        if(rectangleWidth < 0)
                          cout << "Invalid Rectangle Width!\n";
                        else
                          cout << "The area of the Rectangle is: " << (rectangleLength * rectangleWidth) << endl;
                    }

                    break;

                case 3:
                    cout << "Enter the length of the Triangle's base:\n";
                    cin >> triangleBase;
                    if(triangleBase < 0)
                      cout << "Invalid Triangle Base\n";
                    else{
                      cout << "Enter the length of the Triangle's height:\n";
                      cin >> triangleHeight;
                      if(triangleHeight < 0)
                        cout << "Invalid Triangle Base\n";
                      else
                        cout << "The area of the Triangle is: " << (triangleBase * triangleHeight) * 0.5 << endl;
                    }
                    break;

                default:
                    break;
            }
        }

    }while(option != 4);

    cout << "Thank you!\n";

    return 0;
}
