// Suffix Array + Kasai LCP — CP classic
// Build SA via prefix doubling; LCP via Kasai in O(N).
#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

std::vector<int> buildSA(const std::string& s) {
    const int n = static_cast<int>(s.size());
    std::vector<int> sa(static_cast<size_t>(n));
    std::iota(sa.begin(), sa.end(), 0);
    std::vector<int> rank(static_cast<size_t>(n)), tmp(static_cast<size_t>(n));
    for (int i = 0; i < n; ++i) {
        rank[static_cast<size_t>(i)] = static_cast<unsigned char>(s[static_cast<size_t>(i)]);
    }
    for (int k = 1; k < n; k <<= 1) {
        auto cmp = [&](int i, int j) {
            if (rank[static_cast<size_t>(i)] != rank[static_cast<size_t>(j)]) {
                return rank[static_cast<size_t>(i)] < rank[static_cast<size_t>(j)];
            }
            const int ri = i + k < n ? rank[static_cast<size_t>(i + k)] : -1;
            const int rj = j + k < n ? rank[static_cast<size_t>(j + k)] : -1;
            return ri < rj;
        };
        std::sort(sa.begin(), sa.end(), cmp);
        tmp[static_cast<size_t>(sa[0])] = 0;
        for (int i = 1; i < n; ++i) {
            tmp[static_cast<size_t>(sa[static_cast<size_t>(i)])] =
                tmp[static_cast<size_t>(sa[static_cast<size_t>(i - 1)])] +
                (cmp(sa[static_cast<size_t>(i - 1)], sa[static_cast<size_t>(i)]) ? 1 : 0);
        }
        rank.swap(tmp);
        if (rank[static_cast<size_t>(sa[static_cast<size_t>(n - 1)])] == n - 1) {
            break;
        }
    }
    return sa;
}

std::vector<int> buildLCP(const std::string& s, const std::vector<int>& sa) {
    const int n = static_cast<int>(s.size());
    std::vector<int> inv(static_cast<size_t>(n)), lcp(static_cast<size_t>(n), 0);
    for (int i = 0; i < n; ++i) {
        inv[static_cast<size_t>(sa[static_cast<size_t>(i)])] = i;
    }
    int k = 0;
    for (int i = 0; i < n; ++i) {
        if (inv[static_cast<size_t>(i)] == n - 1) {
            k = 0;
            continue;
        }
        const int j = sa[static_cast<size_t>(inv[static_cast<size_t>(i)] + 1)];
        while (i + k < n && j + k < n &&
               s[static_cast<size_t>(i + k)] == s[static_cast<size_t>(j + k)]) {
            ++k;
        }
        lcp[static_cast<size_t>(inv[static_cast<size_t>(i)])] = k;
        if (k) {
            --k; // Kasai: next suffix shares at least k-1
        }
    }
    return lcp;
}

int main() {
    const std::string s = "banana";
    const auto sa = buildSA(s);
    const auto lcp = buildLCP(s, sa);
    std::cout << "SA:";
    for (int i : sa) {
        std::cout << " " << i;
    }
    std::cout << "\nLCP:";
    for (int x : lcp) {
        std::cout << " " << x;
    }
    std::cout << "\nfirst_suffix=" << s.substr(static_cast<size_t>(sa[0]))
              << " (expected a)\n";
    return 0;
}
