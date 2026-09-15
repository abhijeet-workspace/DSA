// Subsets (bitmask teaching) — https://leetcode.com/problems/subsets/
// Generate the power set using integer bitmasks 0..(1<<n)-1.
#include <iostream>
#include <vector>

std::vector<std::vector<int>> subsets(const std::vector<int>& nums) {
    const int n = static_cast<int>(nums.size());
    std::vector<std::vector<int>> result;
    result.reserve(1u << n);
    for (int mask = 0; mask < (1 << n); ++mask) {
        std::vector<int> cur;
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i))
                cur.push_back(nums[static_cast<size_t>(i)]);
        }
        result.push_back(std::move(cur));
    }
    return result;
}

int main() {
    const auto r = subsets({1, 2, 3});
    std::cout << "count=" << r.size() << " (expected 8)\n";
    return 0;
}
