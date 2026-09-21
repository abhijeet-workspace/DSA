// Recursion — C++ basics
// Factorial and Fibonacci with explicit base cases; compare to an iterative sum.
#include <iostream>

long long factorial(int n) {
    if (n <= 1) { // base case
        return 1;
    }
    return n * factorial(n - 1); // recursive case
}

long long fib(int n) {
    if (n <= 1) {
        return n; // fib(0)=0, fib(1)=1
    }
    return fib(n - 1) + fib(n - 2); // exponential naive form — teaching only
}

long long sumTo(int n) { // iterative contrast
    long long s = 0;
    for (int i = 1; i <= n; ++i) {
        s += i;
    }
    return s;
}

int main() {
    std::cout << "factorial(5)=" << factorial(5) << '\n'; // 120
    std::cout << "fib(6)=" << fib(6) << '\n';           // 8
    std::cout << "sumTo(5)=" << sumTo(5) << '\n';       // 15
    return 0;
}
