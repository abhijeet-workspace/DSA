// H-Index II — https://leetcode.com/problems/h-index-ii/
// citations sorted ascending; max h with h papers having >= h citations.
#include <iostream>
#include <vector>

int hIndex(const std::vector<int>& citations) {
    const int n = static_cast<int>(citations.size());
    int lo = 0;
    int hi = n - 1;
    int ans = 0;
    while (lo <= hi) {
        const int mid = lo + (hi - lo) / 2;
        const int h = n - mid;
        if (citations[static_cast<size_t>(mid)] >= h) {
            ans = h;
            hi = mid - 1; // try a larger h (smaller mid)
        } else {
            lo = mid + 1;
        }
    }
    return ans;
}

int main() {
    std::cout << hIndex({0, 1, 3, 5, 6}) << " (expected 3)\n"
              << hIndex({1, 2, 100}) << " (expected 2)\n";
    return 0;
}
