#include <algorithm>
#include <climits>
#include <iostream>
#include <string>
#include <vector>

std::string stoneGameIII(const std::vector<int>& a) {
    int n = a.size();
    std::vector<int> dp(n + 1);
    for (int i = n - 1; i >= 0; --i) {
        int best = INT_MIN, sum = 0;
        for (int k = 1; k <= 3 && i + k - 1 < n; ++k) {
            sum += a[i + k - 1];
            best = std::max(best, sum - dp[i + k]);
        }
        dp[i] = best;
    }
    if (dp[0] > 0)
        return "Alice";
    if (dp[0] < 0)
        return "Bob";
    return "Tie";
}

int main() {
    std::cout << stoneGameIII({1, 2, 3, 7}) << " (expected Bob)\n"
              << stoneGameIII({1, 2, 3, -9}) << " (expected Alice)\n";
    return 0;
}
