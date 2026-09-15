// Maximum Product After K Increments — https://leetcode.com/problems/maximum-product-after-k-increments/
// Always increment the current minimum (min-heap) for k steps.
#include <iostream>
#include <queue>
#include <vector>

int maximumProduct(std::vector<int>& nums, int k) {
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap(nums.begin(), nums.end());
    while (k--) {
        int x = minHeap.top();
        minHeap.pop();
        minHeap.push(x + 1);
    }
    const int MOD = 1'000'000'007;
    long long prod = 1;
    while (!minHeap.empty()) {
        prod = (prod * minHeap.top()) % MOD;
        minHeap.pop();
    }
    return static_cast<int>(prod);
}

int main() {
    std::vector<int> nums = {0, 4};
    std::cout << maximumProduct(nums, 5) << " (expected 20)\n";
    return 0;
}
