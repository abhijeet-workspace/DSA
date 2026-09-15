#include <algorithm>
#include <iostream>
#include <vector>
int stoneGameVII(const std::vector<int>& s) {
    int n = s.size();
    std::vector<int> pref(n + 1);
    for (int i = 0; i < n; ++i)
        pref[i + 1] = pref[i] + s[i];
    auto sum = [&](int l, int r) { return pref[r + 1] - pref[l]; };
    std::vector<std::vector<int>> dp(n, std::vector<int>(n));
    for (int len = 2; len <= n; ++len)
        for (int i = 0; i + len - 1 < n; ++i) {
            int j = i + len - 1;
            dp[i][j] = std::max(sum(i + 1, j) - dp[i + 1][j], sum(i, j - 1) - dp[i][j - 1]);
        }
    return dp[0][n - 1];
}
int main() {
    std::cout << "stoneGameVII=" << stoneGameVII({5, 3, 1, 4, 2}) << " (expected 6)\n";
    return 0;
}
