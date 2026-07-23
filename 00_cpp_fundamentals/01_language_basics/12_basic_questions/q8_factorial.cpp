// Q8 Factorial — basic practice
// Compute n! with recursion and with an iterative loop.
#include <iostream>

unsigned long long factorialRecursive(int n);
unsigned long long factorialLoop(int n);

int main() {
    std::cout << "Factorial of a Number using Recursion" << std::endl;
    int num = 0;
    std::cout << "Enter a non-negative number: ";
    std::cin >> num;

    if (num < 0) {
        std::cout << "Factorial is not defined for negative numbers." << std::endl;
        return 0;
    }

    std::cout << "Factorial of " << num << " is: " << factorialRecursive(num)
              << std::endl;
    std::cout << "Factorial of a Number using Loop" << std::endl;
    std::cout << "Factorial of " << num << " is: " << factorialLoop(num)
              << std::endl;
    return 0;
}

unsigned long long factorialRecursive(int n) {
    if (n == 0 || n == 1) { // 0! = 1! = 1
        return 1;
    }
    return static_cast<unsigned long long>(n) * factorialRecursive(n - 1);
}

unsigned long long factorialLoop(int n) {
    unsigned long long fact = 1;
    for (int i = 2; i <= n; ++i) { // multiply 2..n
        fact *= static_cast<unsigned long long>(i);
    }
    return fact;
}
