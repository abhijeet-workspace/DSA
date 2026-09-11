// Kth Largest Element in an Array (Quickselect) — https://leetcode.com/problems/kth-largest-element-in-an-array/
// Return the kth largest element (sorted order, not distinct). Average O(N), worst O(N²).
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <utility>
#include <vector>

// Lomuto partition around a random pivot; returns final pivot index.
int partition(std::vector<int>& a, int lo, int hi) {
    const int pidx = lo + std::rand() % (hi - lo + 1);
    std::swap(a[static_cast<size_t>(pidx)], a[static_cast<size_t>(hi)]);
    const int pivot = a[static_cast<size_t>(hi)];
    int i = lo;
    for (int j = lo; j < hi; ++j) {
        if (a[static_cast<size_t>(j)] <= pivot) {
            std::swap(a[static_cast<size_t>(i++)], a[static_cast<size_t>(j)]);
        }
    }
    std::swap(a[static_cast<size_t>(i)], a[static_cast<size_t>(hi)]);
    return i;
}

// Place the element that belongs at index `target` (0-based ascending order).
int quickselect(std::vector<int>& a, int lo, int hi, int target) {
    while (true) {
        const int p = partition(a, lo, hi);
        if (p == target) {
            return a[static_cast<size_t>(p)];
        }
        if (target < p) {
            hi = p - 1;
        } else {
            lo = p + 1;
        }
    }
}

int findKthLargest(std::vector<int> nums, int k) {
    // kth largest ≡ index (n - k) in ascending sorted order
    const int target = static_cast<int>(nums.size()) - k;
    return quickselect(nums, 0, static_cast<int>(nums.size()) - 1, target);
}

int main() {
    std::srand(42);
    std::vector<int> nums = {3, 2, 1, 5, 6, 4};
    const int k = 2;
    std::cout << findKthLargest(nums, k) << " (expected 5)\n";
    return 0;
}
