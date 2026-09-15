// Longest Duplicate Substring — https://leetcode.com/problems/longest-duplicate-substring/
// Binary search length + rolling hash; verify on collisions.
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

std::string longestDupSubstring(const std::string& s) {
    const int n = static_cast<int>(s.size());
    const long long MOD = 1000000007LL;
    const long long BASE = 911382323LL;
    std::vector<long long> pw(n + 1, 1), pref(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        pw[i + 1] = pw[i] * BASE % MOD;
        pref[i + 1] = (pref[i] * BASE + (s[i] - 'a' + 1)) % MOD;
    }
    auto get = [&](int l, int r) { return (pref[r] - pref[l] * pw[r - l] % MOD + MOD) % MOD; };
    auto check = [&](int len) -> int {
        if (len == 0)
            return 0;
        std::unordered_map<long long, std::vector<int>> pos;
        for (int i = 0; i + len <= n; ++i) {
            long long h = get(i, i + len);
            auto it = pos.find(h);
            if (it != pos.end()) {
                for (int j : it->second)
                    if (s.compare(j, len, s, i, len) == 0)
                        return i;
            }
            pos[h].push_back(i);
        }
        return -1;
    };
    int lo = 1, hi = n - 1, bestPos = -1, bestLen = 0;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        int p = check(mid);
        if (p >= 0) {
            bestLen = mid;
            bestPos = p;
            lo = mid + 1;
        } else
            hi = mid - 1;
    }
    return bestPos < 0 ? "" : s.substr(bestPos, bestLen);
}

int main() {
    std::cout << longestDupSubstring("banana") << " (expected ana)\n"
              << longestDupSubstring("abcd") << " (expected empty)\n";
    return 0;
}
