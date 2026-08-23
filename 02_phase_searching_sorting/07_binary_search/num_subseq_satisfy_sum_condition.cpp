// Number of Subsequences That Satisfy the Given Sum Condition
// https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition/
// Sort; for each left min, binary-search max right with min+max <= target; add 2^(r-l).
#include <algorithm>
#include <iostream>
#include <vector>

int numSubseq(std::vector<int> nums, int target) {
    constexpr int MOD = 1'000'000'007;
    std::sort(nums.begin(), nums.end());
    const int n = static_cast<int>(nums.size());
    std::vector<int> pow2(static_cast<size_t>(n), 1);
    for (int i = 1; i < n; ++i) {
        pow2[static_cast<size_t>(i)] = static_cast<int>((2LL * pow2[static_cast<size_t>(i - 1)]) % MOD);
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (nums[static_cast<size_t>(i)] * 2 > target) {
            break;
        }
        int lo = i;
        int hi = n - 1;
        int best = i;
        while (lo <= hi) {
            const int mid = lo + (hi - lo) / 2;
            if (nums[static_cast<size_t>(i)] + nums[static_cast<size_t>(mid)] <= target) {
                best = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        ans = (ans + pow2[static_cast<size_t>(best - i)]) % MOD;
    }
    return ans;
}

int main() {
    std::cout << numSubseq({3, 5, 6, 7}, 9) << " (expected 4)\n"
              << numSubseq({3, 3, 6, 8}, 10) << " (expected 6)\n";
    return 0;
}
