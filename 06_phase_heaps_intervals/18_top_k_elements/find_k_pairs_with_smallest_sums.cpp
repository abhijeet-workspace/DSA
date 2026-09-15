// Find K Pairs with Smallest Sums — https://leetcode.com/problems/find-k-pairs-with-smallest-sums/
// Min-heap of (sum,i,j); expand i+1 for fixed j to avoid duplicates.
#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

std::vector<std::vector<int>> kSmallestPairs(const std::vector<int>& nums1,
                                             const std::vector<int>& nums2, int k) {
    std::vector<std::vector<int>> result;
    if (nums1.empty() || nums2.empty() || k <= 0) {
        return result;
    }
    using T = std::tuple<int, int, int>; // sum, i, j
    std::priority_queue<T, std::vector<T>, std::greater<T>> min_heap;
    const int m = static_cast<int>(nums1.size());
    const int n = static_cast<int>(nums2.size());
    for (int j = 0; j < std::min(k, n); ++j) {
        min_heap.push({nums1[0] + nums2[static_cast<size_t>(j)], 0, j});
    }
    while (k-- > 0 && !min_heap.empty()) {
        auto [sum, i, j] = min_heap.top();
        min_heap.pop();
        (void)sum;
        result.push_back({nums1[static_cast<size_t>(i)], nums2[static_cast<size_t>(j)]});
        if (i + 1 < m) {
            min_heap.push(
                {nums1[static_cast<size_t>(i + 1)] + nums2[static_cast<size_t>(j)], i + 1, j});
        }
    }
    return result;
}

int main() {
    const auto pairs = kSmallestPairs({1, 7, 11}, {2, 4, 6}, 3);
    std::cout << "pairs:";
    for (const auto& p : pairs) {
        std::cout << " [" << p[0] << "," << p[1] << "]";
    }
    std::cout << " (expected [1,2] [1,4] [1,6])\n";

    const auto pairs2 = kSmallestPairs({1, 1, 2}, {1, 2, 3}, 2);
    std::cout << "pairs:";
    for (const auto& p : pairs2) {
        std::cout << " [" << p[0] << "," << p[1] << "]";
    }
    std::cout << " (expected [1,1] [1,1])\n";
    return 0;
}
