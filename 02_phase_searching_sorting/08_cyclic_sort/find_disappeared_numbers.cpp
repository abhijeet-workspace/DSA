// Find All Numbers Disappeared in an Array — LC 448
// Cyclic place value v at index v-1; collect indices where nums[i] != i+1.
#include <iostream>
#include <vector>
#include <utility>

std::vector<int> findDisappearedNumbers(std::vector<int>& nums) {
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
    std::vector<int> missing;
    for (i = 0; i < n; ++i) {
        if (nums[static_cast<size_t>(i)] != i + 1) missing.push_back(i + 1);
    }
    return missing;
}

int main() {
    std::vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};
    for (int x : findDisappearedNumbers(nums)) std::cout << x << " ";
    std::cout << "(expected 5 6)\n";
    return 0;
}
