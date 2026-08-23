// Peak Index in a Mountain Array — https://leetcode.com/problems/peak-index-in-a-mountain-array/
// Strictly increases then strictly decreases; return the peak index.
#include <iostream>
#include <vector>

int peakIndexInMountainArray(const std::vector<int>& arr) {
    int lo = 0;
    int hi = static_cast<int>(arr.size()) - 1;
    while (lo < hi) {
        const int mid = lo + (hi - lo) / 2;
        if (arr[static_cast<size_t>(mid)] < arr[static_cast<size_t>(mid + 1)]) {
            lo = mid + 1; // still climbing
        } else {
            hi = mid;
        }
    }
    return lo;
}

int main() {
    std::cout << peakIndexInMountainArray({0, 1, 0}) << " (expected 1)\n"
              << peakIndexInMountainArray({0, 2, 1, 0}) << " (expected 1)\n"
              << peakIndexInMountainArray({0, 10, 5, 2}) << " (expected 1)\n";
    return 0;
}
