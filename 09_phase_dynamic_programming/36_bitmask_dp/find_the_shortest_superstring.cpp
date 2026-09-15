// Find the Shortest Superstring — https://leetcode.com/problems/find-the-shortest-superstring/
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

std::string shortestSuperstring(std::vector<std::string>& words) {
    const int n = static_cast<int>(words.size());
    std::vector<std::vector<int>> overlap(n, std::vector<int>(n, 0));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) if (i != j) {
            const auto& a = words[static_cast<size_t>(i)];
            const auto& b = words[static_cast<size_t>(j)];
            for (int k = static_cast<int>(std::min(a.size(), b.size())); k > 0; --k) {
                if (a.substr(a.size() - k) == b.substr(0, k)) {
                    overlap[static_cast<size_t>(i)][static_cast<size_t>(j)] = k;
                    break;
                }
            }
        }
    const int N = 1 << n;
    std::vector<std::vector<std::string>> dp(N, std::vector<std::string>(n));
    for (int i = 0; i < n; ++i) dp[1 << i][static_cast<size_t>(i)] = words[static_cast<size_t>(i)];
    for (int mask = 0; mask < N; ++mask) {
        for (int i = 0; i < n; ++i) {
            if (!(mask & (1 << i)) || dp[static_cast<size_t>(mask)][static_cast<size_t>(i)].empty()) continue;
            for (int j = 0; j < n; ++j) {
                if (mask & (1 << j)) continue;
                const int nmask = mask | (1 << j);
                std::string cand = dp[static_cast<size_t>(mask)][static_cast<size_t>(i)] +
                                   words[static_cast<size_t>(j)].substr(
                                       static_cast<size_t>(overlap[static_cast<size_t>(i)][static_cast<size_t>(j)]));
                auto& cur = dp[static_cast<size_t>(nmask)][static_cast<size_t>(j)];
                if (cur.empty() || cand.size() < cur.size()) cur = cand;
            }
        }
    }
    std::string ans;
    for (int i = 0; i < n; ++i) {
        const auto& s = dp[static_cast<size_t>(N - 1)][static_cast<size_t>(i)];
        if (!s.empty() && (ans.empty() || s.size() < ans.size())) ans = s;
    }
    return ans;
}

int main() {
    std::vector<std::string> words{"catg", "ctaagt", "gcta", "ttca", "atgcatc"};
    std::cout << shortestSuperstring(words).size() << " (expected 16)\n";
    return 0;
}
