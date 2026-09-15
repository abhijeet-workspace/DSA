// Delete Operation for Two Strings —
// https://leetcode.com/problems/delete-operation-for-two-strings/ Min deletions = m + n -
// 2*LCS(word1, word2).
#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

static int lcsLen(std::string a, std::string b) {
    if (a.size() < b.size())
        std::swap(a, b);
    const int m = static_cast<int>(a.size());
    const int n = static_cast<int>(b.size());
    std::vector<int> prev(static_cast<size_t>(n) + 1, 0);
    std::vector<int> curr(static_cast<size_t>(n) + 1, 0);
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (a[static_cast<size_t>(i - 1)] == b[static_cast<size_t>(j - 1)]) {
                curr[static_cast<size_t>(j)] = 1 + prev[static_cast<size_t>(j - 1)];
            } else {
                curr[static_cast<size_t>(j)] =
                    std::max(prev[static_cast<size_t>(j)], curr[static_cast<size_t>(j - 1)]);
            }
        }
        prev.swap(curr);
        std::fill(curr.begin(), curr.end(), 0);
    }
    return prev[static_cast<size_t>(n)];
}

int minDistance(const std::string& word1, const std::string& word2) {
    const int m = static_cast<int>(word1.size());
    const int n = static_cast<int>(word2.size());
    return m + n - 2 * lcsLen(word1, word2); // keep LCS, delete the rest
}

int main() {
    std::cout << minDistance("sea", "eat") << " (expected 2)\n"
              << minDistance("leetcode", "etco") << " (expected 4)\n";
    return 0;
}
