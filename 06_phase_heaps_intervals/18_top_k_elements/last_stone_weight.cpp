// Last Stone Weight — https://leetcode.com/problems/last-stone-weight/
// Smash heaviest stones until ≤1 remains; return its weight (or 0).
#include <iostream>
#include <queue>
#include <vector>

int lastStoneWeight(std::vector<int>& stones) {
    std::priority_queue<int> pq(stones.begin(), stones.end()); // max-heap of weights
    while (pq.size() > 1) {
        const int a = pq.top();
        pq.pop(); // heaviest
        const int b = pq.top();
        pq.pop(); // second heaviest
        if (a != b) {
            pq.push(a - b); // leftover stone
        }
    }
    return pq.empty() ? 0 : pq.top();
}

int main() {
    std::vector<int> stones = {2, 7, 4, 1, 8, 1};
    std::cout << lastStoneWeight(stones) << " (expected 1)\n";
    return 0;
}
