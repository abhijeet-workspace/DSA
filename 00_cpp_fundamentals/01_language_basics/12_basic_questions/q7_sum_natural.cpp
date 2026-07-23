// Q7 Sum of Natural Numbers — basic practice
// Compare loop, recursion, and closed-form sum 1..N.
#include <iostream>

void sumOfNaturalNumbersByLoop(int limit);
int sumOfNaturalNumbersByRecursion(int limit);
void sumOfNaturalNumbersByFormula(int limit);

int main() {
    std::cout << "Sum of Natural Numbers" << std::endl;
    int limit = 0;
    std::cout << "Enter the limit: ";
    std::cin >> limit;

    sumOfNaturalNumbersByLoop(limit);
    std::cout << "Using Recursion: " << sumOfNaturalNumbersByRecursion(limit)
              << std::endl;
    sumOfNaturalNumbersByFormula(limit);
    return 0;
}

void sumOfNaturalNumbersByLoop(int limit) {
    int sum = 0;
    for (int i = 1; i <= limit; i++) { // accumulate 1..limit
        sum += i;
    }
    std::cout << "Sum of first " << limit << " natural numbers is: " << sum
              << std::endl;
}

int sumOfNaturalNumbersByRecursion(int limit) {
    if (limit <= 1) { // base: 0 or 1
        return limit < 0 ? 0 : limit;
    }
    return limit + sumOfNaturalNumbersByRecursion(limit - 1); // peel last term
}

void sumOfNaturalNumbersByFormula(int limit) {
    int sum = (limit * (limit + 1)) / 2; // Gauss formula
    std::cout << "Sum of first " << limit << " natural numbers is: " << sum
              << std::endl;
}
