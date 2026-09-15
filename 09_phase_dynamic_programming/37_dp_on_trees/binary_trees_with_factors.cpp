// Binary Trees With Factors — https://leetcode.com/problems/binary-trees-with-factors/
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

int numFactoredBinaryTrees(std::vector<int>& arr) {
    constexpr int MOD = 1'000'000'007;
    std::sort(arr.begin(), arr.end());
    std::unordered_map<int, long long> dp;
    long long ans = 0;
    for (int x : arr) {
        dp[x] = 1;
        for (int y : arr) {
            if (y >= x) break;
            if (x % y == 0) {
                int z = x / y;
                if (dp.count(z)) dp[x] = (dp[x] + dp[y] * dp[z]) % MOD;
            }
        }
        ans = (ans + dp[x]) % MOD;
    }
    return static_cast<int>(ans);
}

int main() {
    std::vector<int> arr{2, 4};
    std::cout << numFactoredBinaryTrees(arr) << " (expected 3)\n";
    return 0;
}
