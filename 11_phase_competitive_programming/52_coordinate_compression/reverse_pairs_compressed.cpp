// LC 493 Reverse Pairs — compress + Fenwick
// https://leetcode.com/problems/reverse-pairs/
#include <algorithm>
#include <iostream>
#include <vector>
int reversePairs(std::vector<int> nums) {
    int n = (int)nums.size();
    std::vector<long long> vals;
    for (int x : nums) {
        vals.push_back(x);
        vals.push_back(2LL * x);
    }
    std::sort(vals.begin(), vals.end());
    vals.erase(std::unique(vals.begin(), vals.end()), vals.end());
    auto rank = [&](long long x) {
        return int(std::lower_bound(vals.begin(), vals.end(), x) - vals.begin()) + 1;
    };
    struct BIT {
        int n;
        std::vector<int> b;
        BIT(int n) : n(n), b(n + 1, 0) {}
        void add(int i, int v) {
            for (; i <= n; i += i & -i)
                b[i] += v;
        }
        int sum(int i) {
            int s = 0;
            for (; i > 0; i -= i & -i)
                s += b[i];
            return s;
        }
    } bit((int)vals.size());
    int ans = 0;
    for (int i = n - 1; i >= 0; --i) {
        int lo = 1, hi = (int)vals.size(), best = 0;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (vals[mid - 1] * 2 < nums[i]) {
                best = mid;
                lo = mid + 1;
            } else
                hi = mid - 1;
        }
        ans += bit.sum(best);
        bit.add(rank(nums[i]), 1);
    }
    return ans;
}
int main() {
    int a = reversePairs({1, 3, 2, 3, 1}), b = reversePairs({2, 4, 3, 5, 1});
    std::cout << "a=" << a << " b=" << b << "\n" << ((a == 2 && b == 3) ? "OK\n" : "FAIL\n");
    return (a == 2 && b == 3) ? 0 : 1;
}
