// Kth Largest Element in an Array — https://leetcode.com/problems/kth-largest-element-in-an-array/
// Return the kth largest element (sorted order, not distinct).
#include <iostream>
#include <queue>
#include <vector>

int findKthLargest(const std::vector<int>& nums, int k) {
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap; // size ≤ k
    for (int num : nums) {
        minHeap.push(num); // candidate among top-k
        if (static_cast<int>(minHeap.size()) > k) {
            minHeap.pop(); // drop smallest of oversized window
        }
    }
    return minHeap.top(); // kth largest sits at root
}

int main() {
    const std::vector<int> nums = {3, 2, 1, 5, 6, 4};
    const int k = 2;
    std::cout << findKthLargest(nums, k) << " (expected 5)\n";
    return 0;
}
