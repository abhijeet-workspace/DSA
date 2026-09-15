// Number of Steps to Reduce a Number to Zero — LC 1342
// Even → /2; odd → -1; count operations until 0.
#include <iostream>

int numberOfSteps(int num) {
    int steps = 0;
    while (num) {
        if (num & 1)
            --num;
        else
            num >>= 1;
        ++steps;
    }
    return steps;
}

int main() {
    std::cout << numberOfSteps(14) << " (expected 6)\n"
              << numberOfSteps(8) << " (expected 4)\n"
              << numberOfSteps(0) << " (expected 0)\n";
    return 0;
}
