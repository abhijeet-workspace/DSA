// First Missing Positive — LC 41
// Place each value v in [1,n] at index v-1; then scan for first index i with nums[i] != i+1.
#include <algorithm>
#include <iostream>
#include <vector>

int firstMissingPositive(std::vector<int>& nums) {
    const int n = static_cast<int>(nums.size());
    for (int i = 0; i < n; ++i) {
        while (nums[static_cast<size_t>(i)] >= 1 && nums[static_cast<size_t>(i)] <= n &&
               nums[static_cast<size_t>(nums[static_cast<size_t>(i)] - 1)] !=
                   nums[static_cast<size_t>(i)]) {
            std::swap(nums[static_cast<size_t>(i)],
                      nums[static_cast<size_t>(nums[static_cast<size_t>(i)] - 1)]);
        }
    }
    for (int i = 0; i < n; ++i) {
        if (nums[static_cast<size_t>(i)] != i + 1)
            return i + 1;
    }
    return n + 1;
}

int main() {
    std::vector<int> a{3, 4, -1, 1};
    std::cout << firstMissingPositive(a) << " (expected 2)\n";
    std::vector<int> b{1, 2, 0};
    std::cout << firstMissingPositive(b) << " (expected 3)\n";
    return 0;
}
