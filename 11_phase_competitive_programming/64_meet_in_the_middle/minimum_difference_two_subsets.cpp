// Minimum difference of two subsets — MITM
#include <algorithm>
#include <iostream>
#include <vector>

void enumSums(const std::vector<int>& a, std::vector<long long>& out) {
    int n = (int)a.size();
    out.resize(1 << n);
    for (int m = 0; m < (1 << n); ++m) {
        long long s = 0;
        for (int i = 0; i < n; ++i)
            if (m & (1 << i))
                s += a[i];
        out[m] = s;
    }
}

long long minDiff(std::vector<int> a) {
    long long total = 0;
    for (int x : a)
        total += x;
    int n = (int)a.size();
    std::vector<int> L(a.begin(), a.begin() + n / 2), R(a.begin() + n / 2, a.end());
    std::vector<long long> sumsL, sumsR;
    enumSums(L, sumsL);
    enumSums(R, sumsR);
    std::sort(sumsR.begin(), sumsR.end());
    long long best = total;
    long long half = total / 2;
    for (long long s : sumsL) {
        long long need = half - s;
        auto it = std::lower_bound(sumsR.begin(), sumsR.end(), need);
        if (it != sumsR.end())
            best = std::min(best, llabs(total - 2 * (s + *it)));
        if (it != sumsR.begin()) {
            --it;
            best = std::min(best, llabs(total - 2 * (s + *it)));
        }
    }
    return best;
}

int main() {
    std::cout << minDiff({1, 6, 11, 5}) << " (expected 1)\n";
    return 0;
}
