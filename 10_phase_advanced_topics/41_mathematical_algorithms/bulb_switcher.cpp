// Bulb Switcher — https://leetcode.com/problems/bulb-switcher/
// On bulbs = perfect squares ≤ n = floor(sqrt(n)).
#include <iostream>

int bulbSwitch(int n) {
    if (n < 2)
        return n;
    long r = n;
    while (r > n / r)
        r = (r + n / r) / 2;
    return static_cast<int>(r);
}

int main() {
    std::cout << bulbSwitch(3) << " (expected 1)\n"
              << bulbSwitch(4) << " (expected 2)\n"
              << bulbSwitch(1) << " (expected 1)\n";
    return 0;
}
