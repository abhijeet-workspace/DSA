// Merge Sorted Array — https://leetcode.com/problems/merge-sorted-array/
// Merge nums2 into nums1's trailing capacity by filling from the back.
#include <iostream>
#include <vector>

void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
    int i = m - 1, j = n - 1, k = m + n - 1;
    while (i >= 0 && j >= 0) {
        if (nums1[static_cast<size_t>(i)] > nums2[static_cast<size_t>(j)]) {
            nums1[static_cast<size_t>(k--)] = nums1[static_cast<size_t>(i--)];
        } else {
            nums1[static_cast<size_t>(k--)] = nums2[static_cast<size_t>(j--)];
        }
    }
    while (j >= 0) {
        nums1[static_cast<size_t>(k--)] = nums2[static_cast<size_t>(j--)]; // leftover nums2
    }
}

int main() {
    std::vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    std::vector<int> nums2 = {2, 5, 6};
    merge(nums1, 3, nums2, 3);
    for (size_t i = 0; i < nums1.size(); ++i) {
        std::cout << nums1[i] << (i + 1 < nums1.size() ? " " : "");
    }
    std::cout << " (expected 1 2 2 3 5 6)\n";
    return 0;
}
