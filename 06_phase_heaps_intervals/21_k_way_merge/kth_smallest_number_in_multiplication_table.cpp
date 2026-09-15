// Kth Smallest Number in Multiplication Table — https://leetcode.com/problems/kth-smallest-number-in-multiplication-table/
// Binary search on value; count how many cells <= mid (row-wise).
#include <algorithm>
#include <iostream>

int findKthNumber(int m, int n, int k) {
    int lo = 1, hi = m * n;
    auto countLE = [&](int x) {
        int cnt = 0;
        for (int i = 1; i <= m; ++i) cnt += std::min(n, x / i);
        return cnt;
    };
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (countLE(mid) >= k) hi = mid;
        else lo = mid + 1;
    }
    return lo;
}

int main() {
    std::cout << findKthNumber(3, 3, 5) << " (expected 3)\n";
    return 0;
}
