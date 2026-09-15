// Distinct Echo Substrings — https://leetcode.com/problems/distinct-echo-substrings/
// Rolling hash; echo iff two halves equal; count distinct full hashes.
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

int distinctEchoSubstrings(const std::string& text) {
    const int n = static_cast<int>(text.size());
    const long long MOD = 1000000007LL;
    const long long BASE = 911382323LL;
    std::vector<long long> pw(n + 1, 1), pref(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        pw[i + 1] = pw[i] * BASE % MOD;
        pref[i + 1] = (pref[i] * BASE + (text[i] - 'a' + 1)) % MOD;
    }
    auto get = [&](int l, int r) {  // [l,r)
        return (pref[r] - pref[l] * pw[r - l] % MOD + MOD) % MOD;
    };
    std::unordered_set<long long> seen;
    for (int i = 0; i < n; ++i) {
        for (int len = 1; i + 2 * len <= n; ++len) {
            if (get(i, i + len) == get(i + len, i + 2 * len))
                seen.insert(get(i, i + 2 * len));
        }
    }
    return static_cast<int>(seen.size());
}

int main() {
    std::cout << distinctEchoSubstrings("abcabcabc") << " (expected 3)\n"
              << distinctEchoSubstrings("leetcodeleetcode") << " (expected 2)\n";
    return 0;
}
