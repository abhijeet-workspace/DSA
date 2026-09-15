// Find the Kth Smallest Sum of a Matrix With Sorted Rows —
// https://leetcode.com/problems/find-the-kth-smallest-sum-of-a-matrix-with-sorted-rows/ Iteratively
// k-way merge row selections with a min-heap of partial sums.
#include <iostream>
#include <queue>
#include <set>
#include <vector>

int kthSmallest(std::vector<std::vector<int>>& mat, int k) {
    std::vector<int> prev = {0};
    for (const auto& row : mat) {
        std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
        for (int s : prev) {
            for (int x : row)
                pq.push(s + x);
        }
        prev.clear();
        while (!pq.empty() && static_cast<int>(prev.size()) < k) {
            prev.push_back(pq.top());
            pq.pop();
        }
    }
    return prev[static_cast<size_t>(k - 1)];
}

int main() {
    std::vector<std::vector<int>> mat = {{1, 3, 11}, {2, 4, 6}};
    std::cout << kthSmallest(mat, 5) << " (expected 7)\n";
    return 0;
}
