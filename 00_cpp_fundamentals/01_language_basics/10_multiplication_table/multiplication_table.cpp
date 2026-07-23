// Multiplication Table — C++ basics
// Print number * i for i = 1..limit from user input.
#include <iostream>

void multiplicationTable(int number, int limit) {
    for (int i = 1; i <= limit; i++) { // one row per multiplier
        std::cout << number << " * " << i << " = " << number * i << std::endl;
    }
}

int main() {
    std::cout << "Enter the number to print the multiplication table :- ";
    int number = 0;
    std::cin >> number; // base number

    std::cout << "\nEnter the limit till which you want to print the multiplication table :- ";
    int limit = 0;
    std::cin >> limit; // upper multiplier

    multiplicationTable(number, limit);
    return 0;
}
