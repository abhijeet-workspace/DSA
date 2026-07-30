// Remove Element — LC 27
// Write-pointer: copy every non-val forward; return new length.
#include <iostream>
#include <vector>

int removeElement(std::vector<int>& nums, int val) {
    int write = 0;
    for (int x : nums) {
        if (x != val) nums[static_cast<size_t>(write++)] = x;
    }
    return write;
}

int main() {
    std::vector<int> nums = {3, 2, 2, 3};
    int k = removeElement(nums, 3);
    std::cout << "k=" << k << " (expected 2); prefix: ";
    for (int i = 0; i < k; ++i) std::cout << nums[static_cast<size_t>(i)] << " ";
    std::cout << "\n";
    return 0;
}
