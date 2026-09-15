// Reverse Pairs — https://leetcode.com/problems/reverse-pairs/
// Merge-sort counting: nums[i] > 2*nums[j] for i < j.
#include <iostream>
#include <vector>

int mergeCount(std::vector<int>& a, std::vector<int>& tmp, int l, int r) {
    if (l >= r)
        return 0;
    int m = l + (r - l) / 2;
    int cnt = mergeCount(a, tmp, l, m) + mergeCount(a, tmp, m + 1, r);
    int j = m + 1;
    for (int i = l; i <= m; ++i) {
        while (j <= r && a[i] > 2LL * a[j])
            ++j;
        cnt += j - (m + 1);
    }
    int i = l, p = m + 1, k = l;
    while (i <= m && p <= r)
        tmp[k++] = (a[i] <= a[p]) ? a[i++] : a[p++];
    while (i <= m)
        tmp[k++] = a[i++];
    while (p <= r)
        tmp[k++] = a[p++];
    for (int t = l; t <= r; ++t)
        a[t] = tmp[t];
    return cnt;
}

int reversePairs(std::vector<int> nums) {
    std::vector<int> tmp(nums.size());
    return mergeCount(nums, tmp, 0, static_cast<int>(nums.size()) - 1);
}

int main() {
    std::cout << reversePairs({1, 3, 2, 3, 1}) << " (expected 2)\n"
              << reversePairs({2, 4, 3, 5, 1}) << " (expected 3)\n";
    return 0;
}
