// Top K Frequent Elements — https://leetcode.com/problems/top-k-frequent-elements/
// Return the k most frequent numbers in nums (any order).
#include <iostream>
#include <queue>
#include <unordered_map>
#include <utility>
#include <vector>

std::vector<int> topKFrequent(const std::vector<int>& nums, int k) {
    std::unordered_map<int, int> freq;
    for (int num : nums) {
        ++freq[num]; // count occurrences
    }
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
                        std::greater<std::pair<int, int>>>
        minHeap; // {frequency, value}, size ≤ k
    for (const auto& entry : freq) {
        minHeap.push({entry.second, entry.first});
        if (static_cast<int>(minHeap.size()) > k) {
            minHeap.pop(); // drop least frequent of oversized window
        }
    }
    std::vector<int> result;
    while (!minHeap.empty()) {
        result.push_back(minHeap.top().second);
        minHeap.pop();
    }
    return result;
}

int main() {
    const std::vector<int> nums = {1, 1, 1, 2, 2, 3, 4, 4, 4, 4};
    const auto res = topKFrequent(nums, 2);
    std::cout << "top-2:";
    for (int x : res) {
        std::cout << " " << x;
    }
    std::cout << " (expected 4 and 1)\n";
    return 0;
}
