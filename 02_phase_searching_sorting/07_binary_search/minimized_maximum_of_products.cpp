// Minimized Maximum of Products Distributed to Any Store
// https://leetcode.com/problems/minimized-maximum-of-products-distributed-to-any-store/
// n stores; quantities[i] of product type i must go to distinct stores. Minimize max load of any
// store.
#include <algorithm>
#include <iostream>
#include <vector>

bool canDist(const std::vector<int>& quantities, int n, int cap) {
    long long stores = 0;
    for (int q : quantities) {
        stores += (q + cap - 1LL) / cap;
        if (stores > n) {
            return false;
        }
    }
    return true;
}

int minimizedMaximum(int n, const std::vector<int>& quantities) {
    int lo = 1;
    int hi = *std::max_element(quantities.begin(), quantities.end());
    int ans = hi;
    while (lo <= hi) {
        const int mid = lo + (hi - lo) / 2;
        if (canDist(quantities, n, mid)) {
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    return ans;
}

int main() {
    std::cout << minimizedMaximum(6, {11, 6}) << " (expected 3)\n"
              << minimizedMaximum(7, {15, 10, 10}) << " (expected 5)\n";
    return 0;
}
