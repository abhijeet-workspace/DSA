// Move Zeroes — LC 283
// Stable partition: write non-zeros forward, then fill remaining with 0.
#include <iostream>
#include <vector>

void moveZeroes(std::vector<int>& nums) {
    int write = 0;
    for (int x : nums) {
        if (x != 0) nums[static_cast<size_t>(write++)] = x;
    }
    while (write < static_cast<int>(nums.size())) nums[static_cast<size_t>(write++)] = 0;
}

int main() {
    std::vector<int> nums = {0, 1, 0, 3, 12};
    moveZeroes(nums);
    for (int x : nums) std::cout << x << " ";
    std::cout << "\n"; // expected 1 3 12 0 0
    return 0;
}
