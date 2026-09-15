// Split Array With Same Average — LC 805 (DP by size)
#include <iostream>
#include <unordered_set>
#include <vector>

bool splitArraySameAverage(std::vector<int> nums) {
    int n = (int)nums.size();
    if (n == 1)
        return false;
    int S = 0;
    for (int x : nums)
        S += x;
    std::vector<std::unordered_set<int>> dp(n / 2 + 1);
    dp[0].insert(0);
    for (int x : nums) {
        for (int k = n / 2; k >= 1; --k) {
            for (int s : dp[k - 1])
                dp[k].insert(s + x);
        }
    }
    for (int k = 1; k <= n / 2; ++k) {
        if ((S * k) % n)
            continue;
        int need = (S * k) / n;
        if (dp[k].count(need))
            return true;
    }
    return false;
}

int main() {
    std::cout << std::boolalpha << splitArraySameAverage({1, 2, 3, 4, 5, 6, 7, 8})
              << " (expected true)\n";
    return 0;
}
