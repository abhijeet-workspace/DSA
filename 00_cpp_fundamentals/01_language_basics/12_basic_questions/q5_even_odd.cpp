// Q5 Even or Odd — basic practice
// Classify an integer using modulo 2.
#include <iostream>

int main() {
    int num = 0;
    std::cout << "Input a number to find is even or odd " << std::endl;
    std::cin >> num;

    if (num % 2 == 0) { // even when remainder is 0
        std::cout << num << " is even number " << std::endl;
    } else {
        std::cout << num << " is odd number " << std::endl;
    }
    return 0;
}
