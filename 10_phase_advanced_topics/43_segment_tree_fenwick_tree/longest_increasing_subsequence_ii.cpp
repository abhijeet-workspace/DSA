// Longest Increasing Subsequence II —
// https://leetcode.com/problems/longest-increasing-subsequence-ii/ Segtree range-max on value
// domain; dp[x] = 1 + max on [x-k, x).
#include <algorithm>
#include <iostream>
#include <vector>

struct SegMax {
    int n;
    std::vector<int> t;
    explicit SegMax(int n) : n(n), t(4 * n + 4, 0) {}
    void update(int node, int s, int e, int idx, int val) {
        if (s == e) {
            t[node] = std::max(t[node], val);
            return;
        }
        int m = (s + e) / 2;
        if (idx <= m)
            update(2 * node, s, m, idx, val);
        else
            update(2 * node + 1, m + 1, e, idx, val);
        t[node] = std::max(t[2 * node], t[2 * node + 1]);
    }
    int query(int node, int s, int e, int l, int r) {
        if (r < s || e < l || l > r)
            return 0;
        if (l <= s && e <= r)
            return t[node];
        int m = (s + e) / 2;
        return std::max(query(2 * node, s, m, l, r), query(2 * node + 1, m + 1, e, l, r));
    }
    void update(int idx, int val) { update(1, 1, n, idx, val); }
    int query(int l, int r) { return query(1, 1, n, l, r); }
};

int lengthOfLIS(const std::vector<int>& nums, int k) {
    int mx = 0;
    for (int x : nums)
        mx = std::max(mx, x);
    SegMax seg(mx);
    int ans = 0;
    for (int x : nums) {
        int lo = std::max(1, x - k);
        int best = 1 + seg.query(lo, x - 1);
        seg.update(x, best);
        ans = std::max(ans, best);
    }
    return ans;
}

int main() {
    std::cout << lengthOfLIS({4, 2, 1, 4, 3, 4, 5, 8, 15}, 3) << " (expected 5)\n"
              << lengthOfLIS({7, 4, 5, 1, 8, 12, 4, 7}, 5) << " (expected 4)\n";
    return 0;
}
