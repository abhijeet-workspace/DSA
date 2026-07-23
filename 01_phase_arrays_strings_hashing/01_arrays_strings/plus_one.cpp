// Plus One — https://leetcode.com/problems/plus-one/
// Digits of a non-negative integer; add one and return the digit array.
#include <iostream>
#include <vector>

std::vector<int> plusOne(std::vector<int> digits) {
    for (int i = static_cast<int>(digits.size()) - 1; i >= 0; --i) {
        if (digits[static_cast<size_t>(i)] < 9) {
            ++digits[static_cast<size_t>(i)]; // no carry
            return digits;
        }
        digits[static_cast<size_t>(i)] = 0; // 9 -> 0, carry left
    }
    digits.insert(digits.begin(), 1); // all 9s: grow length
    return digits;
}

int main() {
    for (int x : plusOne({1, 2, 9})) std::cout << x;
    std::cout << " (expected 130)\n";
    return 0;
}
