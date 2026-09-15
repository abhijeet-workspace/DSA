// Maximum Length of Repeated Subarray —
// https://leetcode.com/problems/maximum-length-of-repeated-subarray/
#include <algorithm>
#include <iostream>
#include <vector>

int findLength(std::vector<int>& nums1, std::vector<int>& nums2) {
    const int n = static_cast<int>(nums1.size()), m = static_cast<int>(nums2.size());
    std::vector<int> dp(m + 1, 0);
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = m; j >= 1; --j) {
            if (nums1[static_cast<size_t>(i - 1)] == nums2[static_cast<size_t>(j - 1)]) {
                dp[static_cast<size_t>(j)] = dp[static_cast<size_t>(j - 1)] + 1;
                ans = std::max(ans, dp[static_cast<size_t>(j)]);
            } else {
                dp[static_cast<size_t>(j)] = 0;
            }
        }
    }
    return ans;
}

int main() {
    std::vector<int> a{1, 2, 3, 2, 1}, b{3, 2, 1, 4, 7};
    std::cout << findLength(a, b) << " (expected 3)\n";
    return 0;
}
