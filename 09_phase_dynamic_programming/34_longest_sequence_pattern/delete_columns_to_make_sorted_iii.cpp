// Delete Columns to Make Sorted III — https://leetcode.com/problems/delete-columns-to-make-sorted-iii/
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int minDeletionSize(std::vector<std::string>& strs) {
    const int n = static_cast<int>(strs[0].size());
    const int R = static_cast<int>(strs.size());
    std::vector<int> dp(n, 1);
    int keep = 1;
    for (int j = 0; j < n; ++j) {
        for (int i = 0; i < j; ++i) {
            bool ok = true;
            for (int r = 0; r < R; ++r) {
                if (strs[static_cast<size_t>(r)][static_cast<size_t>(i)] >
                    strs[static_cast<size_t>(r)][static_cast<size_t>(j)]) {
                    ok = false;
                    break;
                }
            }
            if (ok) dp[static_cast<size_t>(j)] =
                        std::max(dp[static_cast<size_t>(j)], dp[static_cast<size_t>(i)] + 1);
        }
        keep = std::max(keep, dp[static_cast<size_t>(j)]);
    }
    return n - keep;
}

int main() {
    std::vector<std::string> strs{"babca", "bbazb"};
    std::cout << minDeletionSize(strs) << " (expected 3)\n";
    return 0;
}
