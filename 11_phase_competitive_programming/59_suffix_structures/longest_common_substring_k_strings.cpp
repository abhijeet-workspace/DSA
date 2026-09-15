// Longest Common Substring of K Strings — teaching via DP on 2, note for k
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int lcs2(const std::string& a, const std::string& b) {
    int n = static_cast<int>(a.size()), m = static_cast<int>(b.size());
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1, 0));
    int best = 0;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                best = std::max(best, dp[i][j]);
            }
    return best;
}

// For k strings: generalized SA of s1+#1+s2+#2+... and scan LCP windows covering all ids.
int lcs3(const std::string& a, const std::string& b, const std::string& c) {
    return std::min(
        {lcs2(a, b), lcs2(b, c), lcs2(a, c)}); // WRONG in general — demo only when LCSubstring
                                               // equals pairwise mins (not always!)
}

int main() {
    // Correct pairwise for 2 strings:
    std::cout << lcs2("abcdef", "zbcdf") << " (expected 3)\n"; // bcd
    // Teaching note: for true k-string LCS use SA method; pairwise min is NOT correct.
    // Counterexample sketch omitted; we only verify 2-string lab I/O.
    std::cout << lcs2("aaa", "aaaa") << " (expected 3)\n";
    return 0;
}
