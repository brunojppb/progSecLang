#include <iostream>
#include <string>

int main() {
    std::string input = "a b c 4 e 9879";//I added some more extra characters to prove my point.
    std::string numbers = "0123456789";
    std::size_t found = input.find_first_of(numbers.c_str());

    while (found != std::string::npos) {
        std::cout << found << std::endl;
        found = input.find_first_of(numbers.c_str(), found+1);
    }

    return 0;
}