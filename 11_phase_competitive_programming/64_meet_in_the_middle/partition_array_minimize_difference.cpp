// Partition Array Minimize Difference — LC 2035
#include <algorithm>
#include <iostream>
#include <vector>

std::vector<std::vector<int>> sizedSums(const std::vector<int>& a) {
    int n = (int)a.size();
    std::vector<std::vector<int>> res(n + 1);
    for (int mask = 0; mask < (1 << n); ++mask) {
        int s = 0, c = 0;
        for (int i = 0; i < n; ++i)
            if (mask & (1 << i)) {
                s += a[i];
                ++c;
            }
        res[c].push_back(s);
    }
    for (auto& v : res)
        std::sort(v.begin(), v.end());
    return res;
}

int minimumDifference(std::vector<int>& nums) {
    int n2 = (int)nums.size(), n = n2 / 2;
    long long total = 0;
    for (int x : nums)
        total += x;
    std::vector<int> A(nums.begin(), nums.begin() + n);
    std::vector<int> B(nums.begin() + n, nums.end());
    auto LA = sizedSums(A), LB = sizedSums(B);
    long long best = llabs(total);
    for (int k = 0; k <= n; ++k) {
        for (int sA : LA[k]) {
            long long need = total / 2 - sA;
            auto& v = LB[n - k];
            auto it = std::lower_bound(v.begin(), v.end(), (int)need);
            if (it != v.end())
                best = std::min(best, llabs(total - 2LL * (sA + *it)));
            if (it != v.begin()) {
                --it;
                best = std::min(best, llabs(total - 2LL * (sA + *it)));
            }
        }
    }
    return (int)best;
}

int main() {
    std::vector<int> a = {3, 9, 7, 3};
    std::cout << minimumDifference(a) << " (expected 2)\n";
    return 0;
}
