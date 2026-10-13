// Kth Largest Element in an Array (Quickselect) —
// https://leetcode.com/problems/kth-largest-element-in-an-array/ Return the kth largest element
// (sorted order, not distinct). Average O(N), worst O(N²).
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <utility>
#include <vector>

// Three-way (Dutch-flag) partition around a random pivot.
// Returns inclusive [eqLo, eqHi]: values < pivot | == pivot | > pivot.
// Equals must be a band, not one side of a 2-way split — a run of duplicates
// otherwise shrinks the window by one index per pass (O(N²), TLE).
std::pair<int, int> partition(std::vector<int>& a, int lo, int hi) {
    const int pidx = lo + std::rand() % (hi - lo + 1);
    const int pivot = a[static_cast<size_t>(pidx)];
    int lt = lo;
    int i = lo;
    int gt = hi;
    while (i <= gt) {
        const int v = a[static_cast<size_t>(i)];
        if (v < pivot) {
            std::swap(a[static_cast<size_t>(lt++)], a[static_cast<size_t>(i++)]);
        } else if (v > pivot) {
            std::swap(a[static_cast<size_t>(i)], a[static_cast<size_t>(gt--)]);
        } else {
            ++i;
        }
    }
    return {lt, gt};
}

// Place the element that belongs at index `target` (0-based ascending order).
int quickselect(std::vector<int>& a, int lo, int hi, int target) {
    while (lo <= hi) {
        const auto [eqLo, eqHi] = partition(a, lo, hi);
        if (target >= eqLo && target <= eqHi) {
            return a[static_cast<size_t>(target)];
        }
        if (target < eqLo) {
            hi = eqLo - 1;
        } else {
            lo = eqHi + 1;
        }
    }
    return a[static_cast<size_t>(target)];
}

int findKthLargest(std::vector<int> nums, int k) {
    // kth largest ≡ index (n - k) in ascending sorted order
    const int target = static_cast<int>(nums.size()) - k;
    return quickselect(nums, 0, static_cast<int>(nums.size()) - 1, target);
}

int main() {
    std::srand(42);
    std::vector<int> nums = {3, 2, 1, 5, 6, 4};
    std::cout << findKthLargest(nums, 2) << " (expected 5)\n";

    // Same shape as the TLE case: a few outliers, then a long run of duplicates.
    std::vector<int> dups(100000, 1);
    dups[1] = 2;
    dups[2] = 3;
    dups[3] = 4;
    dups[4] = 5;
    dups[dups.size() - 5] = -5;
    dups[dups.size() - 4] = -4;
    dups[dups.size() - 3] = -3;
    dups[dups.size() - 2] = -2;
    dups[dups.size() - 1] = -1;
    std::cout << findKthLargest(dups, 1) << " (expected 5)\n";
    std::cout << findKthLargest(dups, 5) << " (expected 1)\n";
    std::cout << findKthLargest(dups, static_cast<int>(dups.size())) << " (expected -5)\n";
    return 0;
}
