// Sort Colors / Dutch National Flag — https://leetcode.com/problems/sort-colors/
// Sort array of 0s, 1s, 2s in-place in one pass.
#include <iostream>
#include <vector>
#include <utility>

void sortColors(std::vector<int>& nums) {
    int low = 0; // next slot for 0
    int mid = 0; // current scan
    int high = static_cast<int>(nums.size()) - 1; // next slot for 2
    while (mid <= high) {
        if (nums[static_cast<size_t>(mid)] == 0) {
            std::swap(nums[static_cast<size_t>(low)], nums[static_cast<size_t>(mid)]);
            ++low;
            ++mid;
        } else if (nums[static_cast<size_t>(mid)] == 1) {
            ++mid; // already in middle band
        } else {
            std::swap(nums[static_cast<size_t>(mid)], nums[static_cast<size_t>(high)]);
            --high; // do not advance mid; swapped value unread
        }
    }
}

int main() {
    std::vector<int> nums = {2, 0, 2, 1, 1, 0};
    std::cout << "Original: ";
    for (int x : nums) std::cout << x << " ";
    std::cout << "\n";
    sortColors(nums);
    std::cout << "Sorted: ";
    for (int x : nums) std::cout << x << " ";
    std::cout << "\n"; // expected 0 0 1 1 2 2
    return 0;
}
