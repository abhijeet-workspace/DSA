// Reverse Integer — https://leetcode.com/problems/reverse-integer/
// Reverse digits of a 32-bit signed integer; return 0 on overflow.
#include <iostream>
#include <climits>

int reverse(int x) {
    int ans = 0;
    while (x) {
        const int d = x % 10; // pop last digit
        x /= 10;
        if (ans > INT_MAX / 10 || (ans == INT_MAX / 10 && d > 7)) return 0; // overflow +
        if (ans < INT_MIN / 10 || (ans == INT_MIN / 10 && d < -8)) return 0; // overflow -
        ans = ans * 10 + d; // push digit
    }
    return ans;
}

int main() {
    std::cout << reverse(123) << " (expected 321)\n";
    return 0;
}
