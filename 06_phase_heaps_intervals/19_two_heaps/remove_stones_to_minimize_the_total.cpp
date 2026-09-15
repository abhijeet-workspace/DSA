// Remove Stones to Minimize the Total —
// https://leetcode.com/problems/remove-stones-to-minimize-the-total/ Max-heap: each op replace x
// with floor(x/2), k times; return sum.
#include <iostream>
#include <queue>
#include <vector>

int minStoneSum(std::vector<int>& piles, int k) {
    std::priority_queue<int> maxHeap(piles.begin(), piles.end());
    while (k--) {
        int x = maxHeap.top();
        maxHeap.pop();
        maxHeap.push(x - x / 2); // remove floor(x/2)
    }
    int sum = 0;
    while (!maxHeap.empty()) {
        sum += maxHeap.top();
        maxHeap.pop();
    }
    return sum;
}

int main() {
    std::vector<int> piles = {5, 4, 9};
    std::cout << minStoneSum(piles, 2) << " (expected 12)\n";
    return 0;
}
