// Q6 Multiplication Table — basic practice
// Print number * i for i = 1..limit.
#include <iostream>

void multiplicationTable(int number, int limit) {
    for (int i = 1; i <= limit; i++) { // one line per multiplier
        std::cout << number << " * " << i << " = " << number * i << std::endl;
    }
}

int main() {
    int num = 0;
    int limit = 0;
    std::cout << "Enter a number: ";
    std::cin >> num;
    std::cout << "Enter a limit: ";
    std::cin >> limit;
    multiplicationTable(num, limit);
    return 0;
}
