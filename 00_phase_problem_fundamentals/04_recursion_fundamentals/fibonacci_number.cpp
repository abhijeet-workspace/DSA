// Fibonacci Number — LC 509
// Plain recursion (n <= 30).
#include <iostream>

int fib(int n) {
    if (n <= 1)
        return n;
    return fib(n - 1) + fib(n - 2);
}

int main() {
    std::cout << fib(2) << " (expected 1)\n";
    std::cout << fib(4) << " (expected 3)\n";
    return 0;
}
