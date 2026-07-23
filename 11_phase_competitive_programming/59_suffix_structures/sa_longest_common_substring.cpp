// LCS of two strings via SA+LCP — CP classic
// Concatenate A+# +B; max LCP across different sides.
#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

std::vector<int> buildSA(const std::string& s) {
    const int n = static_cast<int>(s.size());
    std::vector<int> sa(static_cast<size_t>(n)), rank(static_cast<size_t>(n)),
        tmp(static_cast<size_t>(n));
    std::iota(sa.begin(), sa.end(), 0);
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

int lcsLen(const std::string& A, const std::string& B) {
    const std::string s = A + "#" + B + "$";
    const int n = static_cast<int>(s.size());
    const int mid = static_cast<int>(A.size());
    const auto sa = buildSA(s);
    std::vector<int> inv(static_cast<size_t>(n)), lcp(static_cast<size_t>(n), 0);
    for (int i = 0; i < n; ++i) {
        inv[static_cast<size_t>(sa[static_cast<size_t>(i)])] = i;
    }
    int k = 0, best = 0;
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
        const bool diff = (i < mid) != (j < mid); // different original strings
        if (diff) {
            best = std::max(best, k);
        }
        if (k) {
            --k;
        }
    }
    return best;
}

int main() {
    std::cout << lcsLen("abac", "bacc") << " (expected 3)\n";
    return 0;
}
