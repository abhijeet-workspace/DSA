// LC264 Ugly Number II — three-pointer merge
#include <algorithm>
#include <iostream>
#include <vector>

int nthUglyNumber(int n) {
    std::vector<int> dp(n);
    dp[0] = 1;
    int i2 = 0, i3 = 0, i5 = 0;
    for (int i = 1; i < n; ++i) {
        long long a = 2LL * dp[i2], b = 3LL * dp[i3], c = 5LL * dp[i5];
        long long nxt = std::min({a, b, c});
        dp[i] = static_cast<int>(nxt);
        if (nxt == a)
            ++i2;
        if (nxt == b)
            ++i3;
        if (nxt == c)
            ++i5;
    }
    return dp[n - 1];
}

int main() {
    std::cout << "nthUglyNumber(10)=" << nthUglyNumber(10) << " (expected 12)\n";
    std::cout << "nthUglyNumber(1)=" << nthUglyNumber(1) << " (expected 1)\n";
    return 0;
}
