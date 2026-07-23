// Sum of Two Integers — https://leetcode.com/problems/sum-of-two-integers/
// XOR = sum without carry; (AND)<<1 = carry; repeat until carry 0.
#include <iostream>

int getSum(int a, int b) {
    while (b != 0) {
        const unsigned carry = static_cast<unsigned>(a & b) << 1;
        a = a ^ b;
        b = static_cast<int>(carry);
    }
    return a;
}

int main() {
    std::cout << getSum(3, 5) << " (expected 8)\n"
              << getSum(-2, 3) << " (expected 1)\n";
    return 0;
}
