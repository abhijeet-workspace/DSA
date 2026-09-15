// Longest Common Subpath — LeetCode 1923
// Binary search + multi-string rolling hash (SA alternative noted).
#include <iostream>
#include <unordered_set>
#include <vector>

bool ok(int len, const std::vector<std::vector<int>>& paths) {
    if (len == 0)
        return true;
    const long long MOD = 1000000009;
    const long long BASE = 911382323;
    std::unordered_set<long long> inter;
    bool first = true;
    for (const auto& p : paths) {
        if (static_cast<int>(p.size()) < len)
            return false;
        long long h = 0, powB = 1;
        for (int i = 0; i < len; ++i) {
            h = (h * BASE + p[i] + 1) % MOD;
            if (i)
                powB = powB * BASE % MOD;
        }
        std::unordered_set<long long> cur;
        cur.insert(h);
        for (int i = len; i < static_cast<int>(p.size()); ++i) {
            h = (h - (p[i - len] + 1) * powB % MOD + MOD) % MOD;
            h = (h * BASE + p[i] + 1) % MOD;
            cur.insert(h);
        }
        if (first) {
            inter = std::move(cur);
            first = false;
        } else {
            std::unordered_set<long long> nxt;
            for (long long x : cur)
                if (inter.count(x))
                    nxt.insert(x);
            inter.swap(nxt);
        }
        if (inter.empty())
            return false;
    }
    return !inter.empty();
}

int longestCommonSubpath(int /*n*/, const std::vector<std::vector<int>>& paths) {
    int lo = 0, hi = static_cast<int>(paths[0].size());
    for (const auto& p : paths)
        hi = std::min(hi, static_cast<int>(p.size()));
    while (lo < hi) {
        int mid = (lo + hi + 1) / 2;
        if (ok(mid, paths))
            lo = mid;
        else
            hi = mid - 1;
    }
    return lo;
}

int main() {
    std::cout << longestCommonSubpath(5, {{0, 1, 2, 3, 4}, {2, 3, 4}, {4, 0, 1, 2, 3}})
              << " (expected 2)\n";
    return 0;
}
