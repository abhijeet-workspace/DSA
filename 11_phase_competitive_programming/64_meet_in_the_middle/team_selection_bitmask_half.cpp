// Team selection — exactly k items, max sum <= budget (MITM)
#include <algorithm>
#include <iostream>
#include <vector>

std::vector<std::vector<long long>> sized(const std::vector<long long>& a) {
    int n = (int)a.size();
    std::vector<std::vector<long long>> res(n + 1);
    for (int m = 0; m < (1 << n); ++m) {
        long long s = 0;
        int c = 0;
        for (int i = 0; i < n; ++i)
            if (m & (1 << i)) {
                s += a[i];
                ++c;
            }
        res[c].push_back(s);
    }
    for (auto& v : res)
        std::sort(v.begin(), v.end());
    return res;
}

long long bestTeam(std::vector<long long> a, int k, long long budget) {
    int n = (int)a.size();
    if (k < 0 || k > n)
        return -1;
    std::vector<long long> L(a.begin(), a.begin() + n / 2), R(a.begin() + n / 2, a.end());
    auto SL = sized(L), SR = sized(R);
    long long ans = -1;
    for (int c = 0; c <= k; ++c) {
        if (c > (int)L.size() || k - c > (int)R.size())
            continue;
        for (long long sL : SL[c]) {
            if (sL > budget)
                continue;
            long long rem = budget - sL;
            auto& v = SR[k - c];
            auto it = std::upper_bound(v.begin(), v.end(), rem);
            if (it == v.begin())
                continue;
            --it;
            ans = std::max(ans, sL + *it);
        }
    }
    return ans;
}

int main() {
    std::cout << bestTeam({6, 3, 2, 5}, 2, 8) << " (expected 8)\n";
    return 0;
}
