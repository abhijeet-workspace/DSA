// Valid Perfect Square — https://leetcode.com/problems/valid-perfect-square/
// Return whether num is a perfect square without using sqrt.
#include <iostream>

bool isPerfectSquare(int num) {
    int lo = 1;
    int hi = num;
    while (lo <= hi) {
        const int mid = lo + (hi - lo) / 2;
        const long long sq = 1LL * mid * mid;
        if (sq == num) {
            return true;
        }
        if (sq < num) {
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    return false;
}

int main() {
    std::cout << std::boolalpha << isPerfectSquare(16) << " (expected true)\n"
              << isPerfectSquare(14) << " (expected false)\n";
    return 0;
}
