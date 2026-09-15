// Suffix Array O(N log^2 N) — prefix doubling
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

std::vector<int> suffixArrayNlog2(const std::string& s) {
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

int main() {
    auto sa = suffixArrayNlog2("banana");
    std::cout << "sa:";
    for (int x : sa)
        std::cout << " " << x;
    std::cout << " (expected 5 3 1 0 4 2)\n";
    return 0;
}
