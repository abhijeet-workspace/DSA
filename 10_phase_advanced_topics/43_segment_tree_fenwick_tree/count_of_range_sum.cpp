// Count of Range Sum — https://leetcode.com/problems/count-of-range-sum/
// Merge-sort on prefix sums counting lower ≤ pre[j]-pre[i] ≤ upper.
#include <iostream>
#include <vector>

int mergeCount(std::vector<long long>& p, std::vector<long long>& tmp, int l, int r, int lower,
               int upper) {
    if (l >= r)
        return 0;
    int m = l + (r - l) / 2;
    int cnt = mergeCount(p, tmp, l, m, lower, upper) + mergeCount(p, tmp, m + 1, r, lower, upper);
    int j1 = m + 1, j2 = m + 1;
    for (int i = l; i <= m; ++i) {
        while (j1 <= r && p[j1] - p[i] < lower)
            ++j1;
        while (j2 <= r && p[j2] - p[i] <= upper)
            ++j2;
        cnt += j2 - j1;
    }
    int i = l, q = m + 1, k = l;
    while (i <= m && q <= r)
        tmp[k++] = (p[i] <= p[q]) ? p[i++] : p[q++];
    while (i <= m)
        tmp[k++] = p[i++];
    while (q <= r)
        tmp[k++] = p[q++];
    for (int t = l; t <= r; ++t)
        p[t] = tmp[t];
    return cnt;
}

int countRangeSum(const std::vector<int>& nums, int lower, int upper) {
    int n = static_cast<int>(nums.size());
    std::vector<long long> pre(n + 1, 0);
    for (int i = 0; i < n; ++i)
        pre[i + 1] = pre[i] + nums[i];
    std::vector<long long> tmp(pre.size());
    return mergeCount(pre, tmp, 0, n, lower, upper);
}

int main() {
    std::cout << countRangeSum({-2, 5, -1}, -2, 2) << " (expected 3)\n";
    return 0;
}
