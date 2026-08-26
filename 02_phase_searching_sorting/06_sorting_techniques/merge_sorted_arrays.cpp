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

static void printVec(const std::vector<int>& v, const char* expected) {
    for (size_t i = 0; i < v.size(); ++i) {
        std::cout << v[i] << (i + 1 < v.size() ? " " : "");
    }
    std::cout << " (expected " << expected << ")\n";
}

int main() {
    std::vector<int> a = {1, 2, 3, 0, 0, 0};
    std::vector<int> b = {2, 5, 6};
    merge(a, 3, b, 3);
    printVec(a, "1 2 2 3 5 6");

    std::vector<int> c = {0};
    std::vector<int> d = {1};
    merge(c, 0, d, 1); // m = 0
    printVec(c, "1");

    std::vector<int> e = {1};
    std::vector<int> f;
    merge(e, 1, f, 0); // n = 0
    printVec(e, "1");
    return 0;
}
