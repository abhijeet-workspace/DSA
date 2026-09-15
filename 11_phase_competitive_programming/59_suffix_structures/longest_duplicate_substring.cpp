// Longest Duplicate Substring — LeetCode 1044
// Binary search length + Rabin–Karp (pedagogy vs SA in md).
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

int search(const std::string& s, int len, std::string& out) {
    if (len == 0)
        return 0;
    const long long MOD = 1000000007;
    const long long BASE = 911382323;
    int n = static_cast<int>(s.size());
    long long h = 0, powB = 1;
    for (int i = 0; i < len; ++i) {
        h = (h * BASE + s[i]) % MOD;
        if (i)
            powB = powB * BASE % MOD;
    }
    std::unordered_map<long long, std::vector<int>> pos;
    pos[h].push_back(0);
    for (int i = len; i < n; ++i) {
        h = (h - s[i - len] * powB % MOD + MOD) % MOD;
        h = (h * BASE + s[i]) % MOD;
        int start = i - len + 1;
        auto it = pos.find(h);
        if (it != pos.end()) {
            for (int p : it->second)
                if (s.compare(p, len, s, start, len) == 0) {
                    out = s.substr(start, len);
                    return start;
                }
        }
        pos[h].push_back(start);
    }
    return -1;
}

std::string longestDupSubstring(const std::string& s) {
    int lo = 0, hi = static_cast<int>(s.size());
    std::string best;
    while (lo < hi) {
        int mid = (lo + hi + 1) / 2;
        std::string cand;
        if (search(s, mid, cand) >= 0) {
            best = cand;
            lo = mid;
        } else
            hi = mid - 1;
    }
    return best;
}

int main() {
    std::cout << longestDupSubstring("banana") << " (expected ana)\n";
    return 0;
}
