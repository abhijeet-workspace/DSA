// The Number of Beautiful Subsets — https://leetcode.com/problems/the-number-of-beautiful-subsets/
// Count non-empty subsets where no two elements differ by k.
#include <algorithm>
#include <iostream>
#include <vector>

void dfs(const std::vector<int>& nums, int i, int k, std::vector<int>& freq, int& count) {
    if (i == static_cast<int>(nums.size())) {
        ++count;
        return;
    }
    // skip nums[i]
    dfs(nums, i + 1, k, freq, count);
    const int v = nums[static_cast<size_t>(i)];
    if ((v < k || freq[static_cast<size_t>(v - k)] == 0) &&
        (v + k >= static_cast<int>(freq.size()) || freq[static_cast<size_t>(v + k)] == 0)) {
        ++freq[static_cast<size_t>(v)];
        dfs(nums, i + 1, k, freq, count);
        --freq[static_cast<size_t>(v)];
    }
}

int beautifulSubsets(std::vector<int> nums, int k) {
    std::sort(nums.begin(), nums.end());
    int mx = 0;
    for (int x : nums)
        mx = std::max(mx, x);
    std::vector<int> freq(static_cast<size_t>(mx + 1), 0);
    int count = 0;
    dfs(nums, 0, k, freq, count);
    return count - 1; // exclude empty
}

int main() {
    std::cout << beautifulSubsets({2, 4, 6}, 2) << " (expected 4)\n";
    std::cout << beautifulSubsets({1}, 1) << " (expected 1)\n";
    return 0;
}
