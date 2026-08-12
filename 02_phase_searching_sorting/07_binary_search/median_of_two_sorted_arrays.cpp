// Median of Two Sorted Arrays — https://leetcode.com/problems/median-of-two-sorted-arrays/
// Brute: merge + sort. Optimal: binary-partition the shorter array.
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

// --- Brute: merge both arrays, sort, then pick median — O((m+n) log(m+n)) ---
std::vector<int> mergeTwoSortVector(const std::vector<int>& nums1,
                                    const std::vector<int>& nums2) {
    std::vector<int> merged;
    merged.reserve(nums1.size() + nums2.size());
    merged.insert(merged.end(), nums1.begin(), nums1.end());
    merged.insert(merged.end(), nums2.begin(), nums2.end());
    std::sort(merged.begin(), merged.end());
    return merged;
}

double findMedianSortedArraysBrute(const std::vector<int>& nums1,
                                   const std::vector<int>& nums2) {
    const std::vector<int> sorted = mergeTwoSortVector(nums1, nums2);
    const int n = static_cast<int>(sorted.size());
    if (n % 2 == 0) {
        return (sorted[n / 2] + sorted[(n / 2) - 1]) / 2.0;
    }
    return static_cast<double>(sorted[n / 2]);
}

// --- Optimal: binary-partition shorter array — O(log(min(m,n))) ---
double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
    if (nums1.size() > nums2.size()) {
        return findMedianSortedArrays(nums2, nums1);
    }
    const int m = static_cast<int>(nums1.size());
    const int n = static_cast<int>(nums2.size());
    int low = 0;
    int high = m;
    const int half = (m + n + 1) / 2;
    while (low <= high) {
        const int partition1 = (low + high) / 2;
        const int partition2 = half - partition1;
        const int maxLeft1 = partition1 ? nums1[static_cast<size_t>(partition1 - 1)] : INT_MIN;
        const int minRight1 = partition1 < m ? nums1[static_cast<size_t>(partition1)] : INT_MAX;
        const int maxLeft2 = partition2 ? nums2[static_cast<size_t>(partition2 - 1)] : INT_MIN;
        const int minRight2 = partition2 < n ? nums2[static_cast<size_t>(partition2)] : INT_MAX;
        if (maxLeft1 <= minRight2 && maxLeft2 <= minRight1) {
            if ((m + n) % 2) {
                return static_cast<double>(std::max(maxLeft1, maxLeft2));
            }
            return (std::max(maxLeft1, maxLeft2) + std::min(minRight1, minRight2)) / 2.0;
        }
        if (maxLeft1 > minRight2) {
            high = partition1 - 1;
        } else {
            low = partition1 + 1;
        }
    }
    return 0.0;
}

int main() {
    std::vector<int> nums1 = {1, 3};
    std::vector<int> nums2 = {2};
    std::cout << "brute:   " << findMedianSortedArraysBrute(nums1, nums2)
              << " (expected 2)\n";
    std::cout << "optimal: " << findMedianSortedArrays(nums1, nums2)
              << " (expected 2)\n";
    return 0;
}
