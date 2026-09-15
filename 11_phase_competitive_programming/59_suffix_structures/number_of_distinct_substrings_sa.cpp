// Number of Distinct Substrings via SA+LCP
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

std::vector<int> buildSA(const std::string& s) {
    int n = static_cast<int>(s.size());
    std::vector<int> sa(n), rank(n), tmp(n);
    for (int i = 0; i < n; ++i) {
        sa[i] = i;
        rank[i] = s[i];
    }
    for (int k = 1; k < n; k *= 2) {
        auto cmp = [&](int i, int j) {
            if (rank[i] != rank[j])
                return rank[i] < rank[j];
            int ri = i + k < n ? rank[i + k] : -1;
            int rj = j + k < n ? rank[j + k] : -1;
            return ri < rj;
        };
        std::sort(sa.begin(), sa.end(), cmp);
        tmp[sa[0]] = 0;
        for (int i = 1; i < n; ++i)
            tmp[sa[i]] = tmp[sa[i - 1]] + (cmp(sa[i - 1], sa[i]) ? 1 : 0);
        rank.swap(tmp);
        if (rank[sa[n - 1]] == n - 1)
            break;
    }
    return sa;
}

std::vector<int> buildLCP(const std::string& s, const std::vector<int>& sa) {
    int n = static_cast<int>(s.size());
    std::vector<int> inv(n), lcp(n);
    for (int i = 0; i < n; ++i)
        inv[sa[i]] = i;
    int k = 0;
    for (int i = 0; i < n; ++i) {
        if (inv[i] == n - 1) {
            k = 0;
            continue;
        }
        int j = sa[inv[i] + 1];
        while (i + k < n && j + k < n && s[i + k] == s[j + k])
            ++k;
        lcp[inv[i]] = k;
        if (k)
            --k;
    }
    return lcp;
}

long long distinctSubstrings(const std::string& s) {
    int n = static_cast<int>(s.size());
    auto sa = buildSA(s);
    auto lcp = buildLCP(s, sa);
    long long sumL = 0;
    for (int i = 0; i + 1 < n; ++i)
        sumL += lcp[i];
    return 1LL * n * (n + 1) / 2 - sumL;
}

int main() {
    std::cout << distinctSubstrings("aba") << " (expected 5)\n"; // a,b,ab,ba,aba
    std::cout << distinctSubstrings("aaa") << " (expected 3)\n";
    return 0;
}
