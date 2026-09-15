// Suffix Array Pattern Search
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

std::vector<int> buildSA(const std::string& s) {
    int n = static_cast<int>(s.size());
    std::vector<int> sa(n), rank(n), tmp(n);
    for (int i = 0; i < n; ++i) {
        sa[i] = i;
        rank[i] = static_cast<unsigned char>(s[i]);
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

bool contains(const std::string& text, const std::string& pat, const std::vector<int>& sa) {
    int n = static_cast<int>(text.size());
    int lo = 0, hi = n;
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        int cmp = text.compare(sa[mid], pat.size(), pat);
        if (cmp < 0)
            lo = mid + 1;
        else
            hi = mid;
    }
    return lo < n && text.compare(sa[lo], pat.size(), pat) == 0;
}

int main() {
    std::string t = "banana";
    auto sa = buildSA(t);
    std::cout << (contains(t, "ana", sa) ? "yes" : "no") << " (expected yes)\n";
    std::cout << (contains(t, "band", sa) ? "yes" : "no") << " (expected no)\n";
    return 0;
}
