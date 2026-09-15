// LC 315 Count of Smaller Numbers After Self
// https://leetcode.com/problems/count-of-smaller-numbers-after-self/
#include <algorithm>
#include <iostream>
#include <vector>
std::vector<int> countSmaller(std::vector<int> nums) {
    std::vector<int> vals = nums;
    std::sort(vals.begin(), vals.end());
    vals.erase(std::unique(vals.begin(), vals.end()), vals.end());
    auto rank = [&](int x) {
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
    int n = (int)nums.size();
    std::vector<int> ans(n);
    for (int i = n - 1; i >= 0; --i) {
        int r = rank(nums[i]);
        ans[i] = bit.sum(r - 1);
        bit.add(r, 1);
    }
    return ans;
}
int main() {
    auto a = countSmaller({5, 2, 6, 1});
    const std::vector<int> exp = {2, 1, 1, 0};
    bool ok = a == exp;
    std::cout << "ans:";
    for (int x : a)
        std::cout << " " << x;
    std::cout << "\n" << (ok ? "OK\n" : "FAIL\n");
    return ok ? 0 : 1;
}
