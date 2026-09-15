// LC 327 Count of Range Sum — compressed prefix + Fenwick
// https://leetcode.com/problems/count-of-range-sum/
#include <algorithm>
#include <iostream>
#include <vector>
long long countRangeSum(std::vector<int> nums, int lower, int upper) {
    int n = (int)nums.size();
    std::vector<long long> pref(n + 1, 0);
    for (int i = 0; i < n; ++i)
        pref[i + 1] = pref[i] + nums[i];
    std::vector<long long> vals = pref;
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
        int range(int l, int r) {
            if (l > r)
                return 0;
            return sum(r) - sum(l - 1);
        }
    } bit((int)vals.size());
    long long ans = 0;
    for (int i = 0; i <= n; ++i) {
        long long lo = pref[i] - upper, hi = pref[i] - lower;
        int L = int(std::lower_bound(vals.begin(), vals.end(), lo) - vals.begin()) + 1;
        int R = int(std::upper_bound(vals.begin(), vals.end(), hi) - vals.begin());
        ans += bit.range(L, R);
        bit.add(rank(pref[i]), 1);
    }
    return ans;
}
int main() {
    long long a = countRangeSum({-2, 5, -1}, -2, 2);
    std::cout << "ans=" << a << " expected=3\n" << (a == 3 ? "OK\n" : "FAIL\n");
    return a == 3 ? 0 : 1;
}
