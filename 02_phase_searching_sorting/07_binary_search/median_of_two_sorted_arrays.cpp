// Median of Two Sorted Arrays — https://leetcode.com/problems/median-of-two-sorted-arrays/
// Binary-partition the shorter array so left/right halves balance.
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

double findMedianSortedArrays(std::vector<int>& a, std::vector<int>& b) {
    if (a.size() > b.size()) {
        return findMedianSortedArrays(b, a); // ensure a is shorter
    }
    const int m = static_cast<int>(a.size());
    const int n = static_cast<int>(b.size());
    int lo = 0;
    int hi = m;
    const int half = (m + n + 1) / 2;
    while (lo <= hi) {
        const int i = (lo + hi) / 2;
        const int j = half - i;
        const int aL = i ? a[static_cast<size_t>(i - 1)] : INT_MIN;
        const int aR = i < m ? a[static_cast<size_t>(i)] : INT_MAX;
        const int bL = j ? b[static_cast<size_t>(j - 1)] : INT_MIN;
        const int bR = j < n ? b[static_cast<size_t>(j)] : INT_MAX;
        if (aL <= bR && bL <= aR) {
            if ((m + n) % 2) {
                return static_cast<double>(std::max(aL, bL));
            }
            return (std::max(aL, bL) + std::min(aR, bR)) / 2.0;
        }
        if (aL > bR) {
            hi = i - 1;
        } else {
            lo = i + 1;
        }
    }
    return 0.0;
}

int main() {
    std::vector<int> a = {1, 3};
    std::vector<int> b = {2};
    std::cout << findMedianSortedArrays(a, b) << " (expected 2)\n";
    return 0;
}
