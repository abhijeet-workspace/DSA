// Build Array from Permutation — LC 1920
// ans[i] = nums[nums[i]] for a 0-indexed permutation.
#include <iostream>
#include <vector>

std::vector<int> buildArray(const std::vector<int>& nums) {
    const int n = static_cast<int>(nums.size());
    std::vector<int> ans(static_cast<size_t>(n));
    for (int i = 0; i < n; ++i) {
        ans[static_cast<size_t>(i)] = nums[static_cast<size_t>(nums[static_cast<size_t>(i)])];
    }
    return ans;
}

int main() {
    for (int x : buildArray({0, 2, 1, 5, 3, 4}))
        std::cout << x << " ";
    std::cout << "(expected 0 1 2 4 5 3)\n";
    return 0;
}
