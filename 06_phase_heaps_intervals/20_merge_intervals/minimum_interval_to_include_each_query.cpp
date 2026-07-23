// Minimum Interval to Include Each Query —
// https://leetcode.com/problems/minimum-interval-to-include-each-query/
// For each query, smallest interval length covering it (−1 if none).
#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

std::vector<int> minInterval(std::vector<std::vector<int>> intervals,
                             std::vector<int> queries) {
    std::sort(intervals.begin(), intervals.end()); // by left
    std::vector<std::pair<int, int>> q;            // {value, index}
    for (int i = 0; i < static_cast<int>(queries.size()); ++i) {
        q.push_back({queries[static_cast<size_t>(i)], i});
    }
    std::sort(q.begin(), q.end());
    // min-heap of {length, right}
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
                        std::greater<>>
        pq;
    std::vector<int> ans(queries.size(), -1);
    int i = 0;
    for (const auto& [x, idx] : q) {
        while (i < static_cast<int>(intervals.size()) &&
               intervals[static_cast<size_t>(i)][0] <= x) {
            const int L = intervals[static_cast<size_t>(i)][0];
            const int R = intervals[static_cast<size_t>(i)][1];
            pq.push({R - L + 1, R});
            ++i;
        }
        while (!pq.empty() && pq.top().second < x) { // expired
            pq.pop();
        }
        if (!pq.empty()) {
            ans[static_cast<size_t>(idx)] = pq.top().first;
        }
    }
    return ans;
}

int main() {
    auto a = minInterval({{1, 4}, {2, 4}, {3, 6}, {4, 4}}, {2, 3, 4, 5});
    for (int x : a) {
        std::cout << x << " ";
    }
    std::cout << "(expected 3 3 1 4)\n";
    return 0;
}
