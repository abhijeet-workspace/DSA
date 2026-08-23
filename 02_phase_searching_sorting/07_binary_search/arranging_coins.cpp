// Arranging Coins — https://leetcode.com/problems/arranging-coins/
// Complete rows 1+2+...+k = k(k+1)/2 <= n; max such k via binary search.
#include <iostream>

int arrangeCoins(int n) {
    int lo = 0;
    int hi = n;
    int ans = 0;
    while (lo <= hi) {
        const int mid = lo + (hi - lo) / 2;
        const long long need = 1LL * mid * (mid + 1) / 2;
        if (need <= n) {
            ans = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    return ans;
}

int main() {
    std::cout << arrangeCoins(5) << " (expected 2)\n"
              << arrangeCoins(8) << " (expected 3)\n";
    return 0;
}
