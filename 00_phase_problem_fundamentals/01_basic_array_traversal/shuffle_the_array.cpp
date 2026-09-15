// Shuffle the Array — LC 1470
// Interleave nums[0..n) with nums[n..2n).
#include <iostream>
#include <vector>

std::vector<int> shuffle(const std::vector<int>& nums, int n) {
    std::vector<int> ans(static_cast<size_t>(2 * n));
    for (int i = 0; i < n; ++i) {
        ans[static_cast<size_t>(2 * i)] = nums[static_cast<size_t>(i)];
        ans[static_cast<size_t>(2 * i + 1)] = nums[static_cast<size_t>(n + i)];
    }
    return ans;
}

int main() {
    for (int x : shuffle({2, 5, 1, 3, 4, 7}, 3))
        std::cout << x << " ";
    std::cout << "(expected 2 3 5 4 1 7)\n";
    return 0;
}
