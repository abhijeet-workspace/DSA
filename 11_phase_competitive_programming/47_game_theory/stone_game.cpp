#include <algorithm>
#include <iostream>
#include <vector>

bool stoneGame(const std::vector<int>&) {
    return true;
}

int diff(const std::vector<int>& p) {
    int n = p.size();
    std::vector<std::vector<int>> dp(n, std::vector<int>(n));
    for (int i = 0; i < n; ++i)
        dp[i][i] = p[i];
    for (int len = 2; len <= n; ++len)
        for (int i = 0; i + len - 1 < n; ++i) {
            int j = i + len - 1;
            dp[i][j] = std::max(p[i] - dp[i + 1][j], p[j] - dp[i][j - 1]);
        }
    return dp[0][n - 1];
}

int main() {
    std::vector<int> p = {5, 3, 4, 5};
    std::cout << std::boolalpha << "Alice=" << stoneGame(p) << " (expected true)\n"
              << "diff=" << diff(p) << "\n";
    return 0;
}
