// The K Weakest Rows in a Matrix — https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/
// Rank rows by soldier count then index; return first k via max-heap of size k.
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

std::vector<int> kWeakestRows(const std::vector<std::vector<int>>& mat, int k) {
    // max-heap of {soldiers, rowIndex}; keep only k weakest
    using Pair = std::pair<int, int>;
    std::priority_queue<Pair> pq;
    const int m = static_cast<int>(mat.size());
    for (int i = 0; i < m; ++i) {
        int soldiers = 0;
        for (int v : mat[static_cast<size_t>(i)]) {
            if (v == 1) {
                ++soldiers;
            } else {
                break; // row is sorted 1s then 0s
            }
        }
        pq.emplace(soldiers, i);
        if (static_cast<int>(pq.size()) > k) {
            pq.pop();
        }
    }
    std::vector<int> ans(static_cast<size_t>(k));
    for (int i = k - 1; i >= 0; --i) {
        ans[static_cast<size_t>(i)] = pq.top().second;
        pq.pop();
    }
    return ans;
}

int main() {
    const std::vector<std::vector<int>> mat = {
        {1, 1, 0, 0, 0}, {1, 1, 1, 1, 0}, {1, 0, 0, 0, 0}, {1, 1, 0, 0, 0}, {1, 1, 1, 1, 1},
    };
    const auto ans = kWeakestRows(mat, 3);
    for (size_t i = 0; i < ans.size(); ++i) {
        if (i) {
            std::cout << ' ';
        }
        std::cout << ans[i];
    }
    std::cout << " (expected 2 0 3)\n";
    return 0;
}
