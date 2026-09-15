// Maximum Students Taking Exam — LeetCode 1349
// Bitmask DP on rows; seats form bipartite-ish conflicts — DP version.
#include <algorithm>
#include <iostream>
#include <vector>

int maxStudents(std::vector<std::vector<char>> seats) {
    int R = static_cast<int>(seats.size()), C = static_cast<int>(seats[0].size());
    std::vector<int> valid(static_cast<size_t>(R), 0);
    for (int i = 0; i < R; ++i)
        for (int j = 0; j < C; ++j)
            if (seats[static_cast<size_t>(i)][static_cast<size_t>(j)] == '.')
                valid[static_cast<size_t>(i)] |= 1 << j;
    int M = 1 << C;
    std::vector<int> dp(static_cast<size_t>(M), -1);
    dp[0] = 0;
    for (int r = 0; r < R; ++r) {
        std::vector<int> ndp(static_cast<size_t>(M), -1);
        for (int prev = 0; prev < M; ++prev) {
            if (dp[static_cast<size_t>(prev)] < 0)
                continue;
            for (int cur = 0; cur < M; ++cur) {
                if ((cur & valid[static_cast<size_t>(r)]) != cur)
                    continue;
                if (cur & (cur << 1))
                    continue; // adjacent in row
                if (cur & (prev << 1))
                    continue;
                if (cur & (prev >> 1))
                    continue;
                int bits = __builtin_popcount(static_cast<unsigned>(cur));
                ndp[static_cast<size_t>(cur)] =
                    std::max(ndp[static_cast<size_t>(cur)], dp[static_cast<size_t>(prev)] + bits);
            }
        }
        dp.swap(ndp);
    }
    return *std::max_element(dp.begin(), dp.end());
}

int main() {
    std::cout << maxStudents({{'#', '.', '#', '#', '.', '#'},
                              {'.', '#', '#', '#', '#', '.'},
                              {'#', '.', '#', '#', '.', '#'}})
              << " (expected 4)\n";
    return 0;
}
