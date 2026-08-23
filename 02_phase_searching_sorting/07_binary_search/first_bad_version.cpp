// First Bad Version — https://leetcode.com/problems/first-bad-version/
// Versions [1, n]; all versions after the first bad are bad. Minimize isBadVersion calls.
#include <iostream>

static int g_first_bad = 0;

bool isBadVersion(int version) {
    return version >= g_first_bad;
}

int firstBadVersion(int n) {
    int lo = 1;
    int hi = n;
    while (lo < hi) {
        const int mid = lo + (hi - lo) / 2;
        if (isBadVersion(mid)) {
            hi = mid; // first bad in [lo, mid]
        } else {
            lo = mid + 1;
        }
    }
    return lo;
}

int main() {
    g_first_bad = 4;
    std::cout << firstBadVersion(5) << " (expected 4)\n";
    g_first_bad = 1;
    std::cout << firstBadVersion(1) << " (expected 1)\n";
    return 0;
}
