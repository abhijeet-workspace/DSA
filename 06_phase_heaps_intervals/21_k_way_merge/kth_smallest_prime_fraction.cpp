// K-th Smallest Prime Fraction — https://leetcode.com/problems/k-th-smallest-prime-fraction/
// Min-heap of fractions arr[i]/arr[j] with j advancing (k-way style).
#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

std::vector<int> kthSmallestPrimeFraction(std::vector<int>& arr, int k) {
    using T = std::tuple<double, int, int>; // value, i, j
    std::priority_queue<T, std::vector<T>, std::greater<T>> pq;
    const int n = static_cast<int>(arr.size());
    for (int i = 0; i < n - 1; ++i) {
        pq.push({static_cast<double>(arr[static_cast<size_t>(i)]) / arr[static_cast<size_t>(n - 1)], i, n - 1});
    }
    while (--k > 0) {
        auto [val, i, j] = pq.top();
        pq.pop();
        (void)val;
        if (j - 1 > i) {
            pq.push({static_cast<double>(arr[static_cast<size_t>(i)]) / arr[static_cast<size_t>(j - 1)], i, j - 1});
        }
    }
    auto [val, i, j] = pq.top();
    (void)val;
    return {arr[static_cast<size_t>(i)], arr[static_cast<size_t>(j)]};
}

int main() {
    std::vector<int> arr = {1, 2, 3, 5};
    auto r = kthSmallestPrimeFraction(arr, 3);
    std::cout << r[0] << "/" << r[1] << " (expected 1/5)\n";
    return 0;
}
