// Set Mismatch — https://leetcode.com/problems/set-mismatch/
// Place v at v-1; slot with wrong value → duplicate = nums[i], missing = i+1.
#include <iostream>
#include <utility>
#include <vector>

std::vector<int> findErrorNums(std::vector<int>& nums) {
    const int n = static_cast<int>(nums.size());
    int i = 0;
    while (i < n) {
        const int correct = nums[static_cast<size_t>(i)] - 1;
        if (nums[static_cast<size_t>(i)] != nums[static_cast<size_t>(correct)]) {
            std::swap(nums[static_cast<size_t>(i)], nums[static_cast<size_t>(correct)]);
        } else {
            ++i;
        }
    }
    for (i = 0; i < n; ++i) {
        if (nums[static_cast<size_t>(i)] != i + 1) {
            return {nums[static_cast<size_t>(i)], i + 1};
        }
    }
    return {};
}

int main() {
    std::vector<int> a = {1, 2, 2, 4};
    std::vector<int> b = {1, 1};
    auto r1 = findErrorNums(a);
    auto r2 = findErrorNums(b);
    std::cout << r1[0] << ' ' << r1[1] << " (expected 2 3)\n"
              << r2[0] << ' ' << r2[1] << " (expected 1 2)\n";
    return 0;
}
