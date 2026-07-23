// Remove Duplicates from Sorted Array — LC 26
// Slow/fast: write next unique at ++slow when nums[fast] differs.
#include <iostream>
#include <vector>

int removeDuplicates(std::vector<int>& nums) {
    if (nums.empty()) return 0;
    int slow = 0;
    for (int fast = 1; fast < static_cast<int>(nums.size()); ++fast) {
        if (nums[static_cast<size_t>(fast)] != nums[static_cast<size_t>(slow)]) {
            ++slow;
            nums[static_cast<size_t>(slow)] = nums[static_cast<size_t>(fast)];
        }
    }
    return slow + 1;
}

int main() {
    std::vector<int> nums = {1, 1, 2, 2, 3};
    int k = removeDuplicates(nums);
    std::cout << "Unique count: " << k << " (expected 3)\nModified: ";
    for (int i = 0; i < k; ++i) std::cout << nums[static_cast<size_t>(i)] << " ";
    std::cout << "\n";
    return 0;
}
