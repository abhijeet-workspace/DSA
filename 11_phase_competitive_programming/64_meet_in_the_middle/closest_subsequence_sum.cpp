// Closest Subsequence Sum — LC 1755
#include <algorithm>
#include <iostream>
#include <vector>

void enumSums(const std::vector<int>& a, std::vector<long long>& out) {
    int n = (int)a.size();
    out.resize(1 << n);
    for (int mask = 0; mask < (1 << n); ++mask) {
        long long s = 0;
        for (int i = 0; i < n; ++i)
            if (mask & (1 << i))
                s += a[i];
        out[mask] = s;
    }
}

int closestSubsequenceSum(std::vector<int>& nums, int goal) {
    int n = (int)nums.size();
    std::vector<int> L(nums.begin(), nums.begin() + n / 2);
    std::vector<int> R(nums.begin() + n / 2, nums.end());
    std::vector<long long> sumsL, sumsR;
    enumSums(L, sumsL);
    enumSums(R, sumsR);
    std::sort(sumsR.begin(), sumsR.end());
    long long best = llabs(sumsL[0] - goal);
    for (long long s : sumsL) {
        long long need = goal - s;
        auto it = std::lower_bound(sumsR.begin(), sumsR.end(), need);
        if (it != sumsR.end())
            best = std::min(best, llabs(s + *it - goal));
        if (it != sumsR.begin()) {
            --it;
            best = std::min(best, llabs(s + *it - goal));
        }
    }
    return (int)best;
}

int main() {
    std::vector<int> a = {5, 7, 2};
    std::cout << closestSubsequenceSum(a, 6) << " (expected 1)\n";
    return 0;
}
