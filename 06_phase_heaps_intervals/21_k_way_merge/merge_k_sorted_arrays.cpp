// Merge K Sorted Arrays — interview classic (k-way merge pattern)
// Min-heap of {val, arrayIdx, elemIdx}; flatten into one sorted vector.
#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

std::vector<int> mergeKSortedArrays(const std::vector<std::vector<int>>& arrays) {
    using T = std::tuple<int, int, int>;
    std::priority_queue<T, std::vector<T>, std::greater<T>> pq;
    for (int i = 0; i < static_cast<int>(arrays.size()); ++i) {
        if (!arrays[static_cast<size_t>(i)].empty()) {
            pq.push({arrays[static_cast<size_t>(i)][0], i, 0});
        }
    }
    std::vector<int> out;
    while (!pq.empty()) {
        auto [val, i, j] = pq.top();
        pq.pop();
        out.push_back(val);
        if (j + 1 < static_cast<int>(arrays[static_cast<size_t>(i)].size())) {
            pq.push({arrays[static_cast<size_t>(i)][static_cast<size_t>(j + 1)], i, j + 1});
        }
    }
    return out;
}

int main() {
    auto r = mergeKSortedArrays({{1, 4, 7}, {2, 5, 8}, {3, 6, 9}});
    for (int x : r)
        std::cout << x << " ";
    std::cout << "(expected 1 2 3 4 5 6 7 8 9)\n";
    return 0;
}
