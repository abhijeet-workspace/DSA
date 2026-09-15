// Kth Largest Element in an Array (Max Heap) —
// https://leetcode.com/problems/kth-largest-element-in-an-array/ Return the kth largest element
// (sorted order, not distinct).
#include <iostream>
#include <queue>
#include <vector>

int findKthLargest(const std::vector<int>& nums, int k) {
    std::priority_queue<int> maxHeap(nums.begin(), nums.end()); // all N in max-heap
    for (int i = 0; i < k - 1; ++i) {
        maxHeap.pop(); // discard larger than the kth
    }
    return maxHeap.top(); // kth largest now at root
}

int main() {
    const std::vector<int> nums = {3, 2, 1, 5, 6, 4};
    const int k = 2;
    std::cout << findKthLargest(nums, k) << " (expected 5)\n";
    return 0;
}
