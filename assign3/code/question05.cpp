/*
    PROGRAM: question05.CPP
    Written by Bruno Paulino
    This program creates a spectral analysis
*/
#include <iostream>
using namespace std;

int main(){

    double wavelength;

    cout << "Enter the wavelength: ";
    cin >> wavelength;

    if(wavelength >= 1.0e-2){
      cout << "Radio Waves\n";
    }
    else if(wavelength >= 1.0e-3){
      cout << "Microwaves\n";
    }
    else if(wavelength >= 7.0e-7){
      cout << "Infrared\n";
    }
    else if(wavelength >= 4.0e-7){
      cout << "Visible Light\n";
    }
    else if(wavelength >= 1.0e-8){
      cout << "Ultraviolet\n";
    }
    else if(wavelength >= 1.0e-11){
      cout << "X Rays\n";
    }
    else{
      cout << "Gamma Rays\n";
    }

    return 0;

}
