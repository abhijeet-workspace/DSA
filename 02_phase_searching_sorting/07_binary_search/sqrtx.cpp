// Sqrt(x) — https://leetcode.com/problems/sqrtx/
// Integer square root: largest y with y*y <= x.
#include <iostream>

int mySqrt(int x) {
    if (x < 2) {
        return x;
    }
    int lo = 1;
    int hi = x / 2;
    int ans = 1;
    while (lo <= hi) {
        const int mid = lo + (hi - lo) / 2;
        const long long sq = 1LL * mid * mid;
        if (sq == x) {
            return mid;
        }
        if (sq < x) {
            ans = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    return ans;
}

int main() {
    std::cout << mySqrt(4) << " (expected 2)\n" << mySqrt(8) << " (expected 2)\n";
    return 0;
}
