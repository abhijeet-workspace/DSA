// Arithmetic Basics — C++ fundamentals
// Abs, min/max, average, sum of naturals (loop vs formula).
#include <iostream>

int absVal(int x) {
    return x < 0 ? -x : x;
}

int minOf(int a, int b) {
    return a < b ? a : b;
}

int maxOf(int a, int b) {
    return a > b ? a : b;
}

double average(const int* a, int n) {
    if (n <= 0) {
        return 0.0;
    }
    long long sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += a[i];
    }
    return static_cast<double>(sum) / n;
}

long long sumNaturalLoop(int n) {
    long long s = 0;
    for (int i = 1; i <= n; ++i) {
        s += i;
    }
    return s;
}

long long sumNaturalFormula(int n) {
    return static_cast<long long>(n) * (n + 1) / 2;
}

int main() {
    std::cout << "abs(-7) = " << absVal(-7) << " (expected 7)\n";
    std::cout << "min(3,9) = " << minOf(3, 9) << " (expected 3)\n";
    std::cout << "max(3,9) = " << maxOf(3, 9) << " (expected 9)\n";

    int arr[] = {2, 4, 6};
    std::cout << "avg = " << average(arr, 3) << " (expected 4)\n";

    std::cout << "sum 1..5 loop = " << sumNaturalLoop(5) << " (expected 15)\n";
    std::cout << "sum 1..5 formula = " << sumNaturalFormula(5) << " (expected 15)\n";
    return 0;
}
