// Number of Ways to Form a Target String Given a Dictionary —
// https://leetcode.com/problems/number-of-ways-to-form-a-target-string-given-a-dictionary/
#include <iostream>
#include <string>
#include <vector>

int numWays(std::vector<std::string>& words, std::string target) {
    constexpr int MOD = 1'000'000'007;
    const int C = static_cast<int>(words[0].size());
    const int T = static_cast<int>(target.size());
    std::vector<std::vector<int>> freq(C, std::vector<int>(26, 0));
    for (const auto& w : words)
        for (int c = 0; c < C; ++c)
            freq[static_cast<size_t>(c)][static_cast<size_t>(w[static_cast<size_t>(c)] - 'a')]++;
    std::vector<long long> dp(T + 1, 0);
    dp[0] = 1;
    for (int c = 0; c < C; ++c) {
        for (int j = T - 1; j >= 0; --j) {
            const int ch = target[static_cast<size_t>(j)] - 'a';
            dp[static_cast<size_t>(j + 1)] =
                (dp[static_cast<size_t>(j + 1)] +
                 dp[static_cast<size_t>(j)] *
                     freq[static_cast<size_t>(c)][static_cast<size_t>(ch)]) %
                MOD;
        }
    }
    return static_cast<int>(dp[static_cast<size_t>(T)]);
}

int main() {
    std::vector<std::string> words{"acca", "bbbb", "caca"};
    std::cout << numWays(words, "aba") << " (expected 6)\n";
    return 0;
}
