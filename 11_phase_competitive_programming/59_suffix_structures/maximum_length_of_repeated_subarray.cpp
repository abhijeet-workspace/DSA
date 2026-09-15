// Maximum Length of Repeated Subarray — LeetCode 718
#include <algorithm>
#include <iostream>
#include <vector>

int findLength(const std::vector<int>& A, const std::vector<int>& B) {
    int n = static_cast<int>(A.size()), m = static_cast<int>(B.size());
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1, 0));
    int best = 0;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (A[i - 1] == B[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                best = std::max(best, dp[i][j]);
            }
    return best;
}

int main() {
    std::cout << findLength({1, 2, 3, 2, 1}, {3, 2, 1, 4, 7}) << " (expected 3)\n";
    return 0;
}
