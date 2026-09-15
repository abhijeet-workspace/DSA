// Kth Smallest Element in a Sorted Matrix — https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/
// Min-heap frontier starting at each row's first column (k-way merge).
#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

int kthSmallest(std::vector<std::vector<int>>& matrix, int k) {
    using T = std::tuple<int, int, int>;
    std::priority_queue<T, std::vector<T>, std::greater<T>> pq;
    const int n = static_cast<int>(matrix.size());
    for (int r = 0; r < std::min(n, k); ++r) {
        pq.push({matrix[static_cast<size_t>(r)][0], r, 0});
    }
    int ans = 0;
    while (k--) {
        auto [val, r, c] = pq.top();
        pq.pop();
        ans = val;
        if (c + 1 < n) pq.push({matrix[static_cast<size_t>(r)][static_cast<size_t>(c + 1)], r, c + 1});
    }
    return ans;
}

int main() {
    std::vector<std::vector<int>> m = {{1, 5, 9}, {10, 11, 13}, {12, 13, 15}};
    std::cout << kthSmallest(m, 8) << " (expected 13)\n";
    return 0;
}
