// Keyboard Autopilot — teaching lab
// DAG of typed prefixes: from state (i) with last key, count ways to type string with optional
// "same-key hold". Precise I/O: given s of digits on a phone keypad graph, count walks that produce
// s.
#include <iostream>
#include <string>
#include <vector>

// Keys 1..9 grid adjacency (4-dir), count sequences of moves+stays producing string s (digits
// '1'..'9').
long long countWays(const std::string& s) {
    static const std::vector<std::vector<int>> adj = {
        {}, // 0 unused
        {1, 2, 4},    {2, 1, 3, 5}, {3, 2, 6},    {4, 1, 5, 7}, {5, 2, 4, 6, 8},
        {6, 3, 5, 9}, {7, 4, 8},    {8, 5, 7, 9}, {9, 6, 8},
    };
    int n = static_cast<int>(s.size());
    std::vector<std::vector<long long>> dp(static_cast<size_t>(n), std::vector<long long>(10, 0));
    int start = s[0] - '0';
    dp[0][static_cast<size_t>(start)] = 1;
    for (int i = 0; i + 1 < n; ++i) {
        int need = s[static_cast<size_t>(i + 1)] - '0';
        for (int u = 1; u <= 9; ++u) {
            if (!dp[static_cast<size_t>(i)][static_cast<size_t>(u)])
                continue;
            for (int v : adj[static_cast<size_t>(u)])
                if (v == need)
                    dp[static_cast<size_t>(i + 1)][static_cast<size_t>(v)] +=
                        dp[static_cast<size_t>(i)][static_cast<size_t>(u)];
        }
    }
    long long ans = 0;
    for (int u = 1; u <= 9; ++u)
        ans += dp[static_cast<size_t>(n - 1)][static_cast<size_t>(u)];
    return ans;
}

int main() {
    // "12": from 1 can go to 2 → 1 way
    std::cout << countWays("12") << " (expected 1)\n";
    // "11": 1 only stays via self-loop listed → 1 way
    std::cout << countWays("11") << " (expected 1)\n";
    // "13": 1 not adjacent to 3 → 0
    std::cout << countWays("13") << " (expected 0)\n";
    return 0;
}
