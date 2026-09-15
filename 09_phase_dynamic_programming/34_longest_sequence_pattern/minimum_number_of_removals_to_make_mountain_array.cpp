// Minimum Number of Removals to Make Mountain Array — https://leetcode.com/problems/minimum-number-of-removals-to-make-mountain-array/
#include <algorithm>
#include <iostream>
#include <vector>

int minimumMountainRemovals(std::vector<int>& nums) {
    const int n = static_cast<int>(nums.size());
    std::vector<int> lis(n, 1), lds(n, 1);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < i; ++j)
            if (nums[static_cast<size_t>(j)] < nums[static_cast<size_t>(i)])
                lis[static_cast<size_t>(i)] =
                    std::max(lis[static_cast<size_t>(i)], lis[static_cast<size_t>(j)] + 1);
    for (int i = n - 1; i >= 0; --i)
        for (int j = n - 1; j > i; --j)
            if (nums[static_cast<size_t>(j)] < nums[static_cast<size_t>(i)])
                lds[static_cast<size_t>(i)] =
                    std::max(lds[static_cast<size_t>(i)], lds[static_cast<size_t>(j)] + 1);
    int best = 0;
    for (int i = 0; i < n; ++i)
        if (lis[static_cast<size_t>(i)] >= 2 && lds[static_cast<size_t>(i)] >= 2)
            best = std::max(best, lis[static_cast<size_t>(i)] + lds[static_cast<size_t>(i)] - 1);
    return n - best;
}

int main() {
    std::vector<int> a{1, 3, 1}, b{2, 1, 1, 5, 6, 2, 3, 1};
    std::cout << minimumMountainRemovals(a) << " (expected 0)\n";
    std::cout << minimumMountainRemovals(b) << " (expected 3)\n";
    return 0;
}
