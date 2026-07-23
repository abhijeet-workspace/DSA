// Randomized Quickselect — k-th order statistic
// Random pivot; expected O(N); related to LC 215.
#include <cassert>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <utility>
#include <vector>

int partition(std::vector<int>& a, int lo, int hi) {
    const int pidx = lo + std::rand() % (hi - lo + 1);
    std::swap(a[static_cast<size_t>(pidx)], a[static_cast<size_t>(hi)]);
    const int pivot = a[static_cast<size_t>(hi)];
    int i = lo;
    for (int j = lo; j < hi; ++j) {
        if (a[static_cast<size_t>(j)] <= pivot) {
            std::swap(a[static_cast<size_t>(i++)], a[static_cast<size_t>(j)]);
        }
    }
    std::swap(a[static_cast<size_t>(i)], a[static_cast<size_t>(hi)]);
    return i;
}

int quickselect(std::vector<int>& a, int lo, int hi, int k) {
    while (true) {
        const int p = partition(a, lo, hi);
        if (p == k) {
            return a[static_cast<size_t>(p)];
        }
        if (k < p) {
            hi = p - 1;
        } else {
            lo = p + 1;
        }
    }
}

int main() {
    std::srand(42);
    std::vector<int> a{7, 2, 1, 6, 8, 5};
    const int k = 2; // 0-based: 3rd smallest
    const int ans = quickselect(a, 0, static_cast<int>(a.size()) - 1, k);
    std::cout << "kth=" << ans << " (expected 5)\n";
    assert(ans == 5);
    return 0;
}
