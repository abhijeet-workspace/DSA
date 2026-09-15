// Knapsack MITM for small n, large W
#include <algorithm>
#include <iostream>
#include <vector>

struct P {
    long long w, v;
};

std::vector<P> enumWV(const std::vector<long long>& w, const std::vector<long long>& v) {
    int n = (int)w.size();
    std::vector<P> out(1 << n);
    for (int m = 0; m < (1 << n); ++m) {
        long long sw = 0, sv = 0;
        for (int i = 0; i < n; ++i)
            if (m & (1 << i)) {
                sw += w[i];
                sv += v[i];
            }
        out[m] = {sw, sv};
    }
    return out;
}

long long knapsackMITM(std::vector<long long> w, std::vector<long long> v, long long W) {
    int n = (int)w.size();
    std::vector<long long> wL(w.begin(), w.begin() + n / 2), wR(w.begin() + n / 2, w.end());
    std::vector<long long> vL(v.begin(), v.begin() + n / 2), vR(v.begin() + n / 2, v.end());
    auto L = enumWV(wL, vL), R = enumWV(wR, vR);
    std::sort(L.begin(), L.end(), [](auto& a, auto& b) { return a.w < b.w; });
    std::vector<long long> best(L.size());
    long long cur = 0;
    for (size_t i = 0; i < L.size(); ++i) {
        cur = std::max(cur, L[i].v);
        best[i] = cur;
    }
    long long ans = 0;
    for (auto& p : R) {
        if (p.w > W)
            continue;
        long long rem = W - p.w;
        auto it = std::upper_bound(L.begin(), L.end(), rem,
                                   [](long long x, const P& q) { return x < q.w; });
        long long add = 0;
        if (it != L.begin())
            add = best[(it - L.begin()) - 1];
        ans = std::max(ans, p.v + add);
    }
    return ans;
}

int main() {
    std::cout << knapsackMITM({2, 3, 4}, {3, 4, 5}, 5) << " (expected 7)\n";
    return 0;
}
