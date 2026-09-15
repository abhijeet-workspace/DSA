// Maximum Students Taking Exam — https://leetcode.com/problems/maximum-students-taking-exam/
#include <algorithm>
#include <iostream>
#include <vector>

int maxStudents(std::vector<std::vector<char>>& seats) {
    const int R = static_cast<int>(seats.size());
    const int C = static_cast<int>(seats[0].size());
    std::vector<int> rowMask(R, 0);
    for (int r = 0; r < R; ++r)
        for (int c = 0; c < C; ++c)
            if (seats[static_cast<size_t>(r)][static_cast<size_t>(c)] == '.')
                rowMask[static_cast<size_t>(r)] |= 1 << c;
    const int N = 1 << C;
    std::vector<int> dp(N, -1e9);
    dp[0] = 0;
    for (int r = 0; r < R; ++r) {
        std::vector<int> ndp(N, -1e9);
        for (int mask = 0; mask < N; ++mask) {
            if ((mask & rowMask[static_cast<size_t>(r)]) != mask)
                continue;
            if (mask & (mask << 1))
                continue; // adjacent
            const int bits = __builtin_popcount(static_cast<unsigned>(mask));
            for (int prev = 0; prev < N; ++prev) {
                if (dp[static_cast<size_t>(prev)] < -1e8)
                    continue;
                if ((mask & (prev << 1)) || (mask & (prev >> 1)))
                    continue; // diagonals
                ndp[static_cast<size_t>(mask)] =
                    std::max(ndp[static_cast<size_t>(mask)], dp[static_cast<size_t>(prev)] + bits);
            }
        }
        dp.swap(ndp);
    }
    return *std::max_element(dp.begin(), dp.end());
}

int main() {
    std::vector<std::vector<char>> seats{{'#', '.', '#', '#', '.', '#'},
                                         {'.', '#', '#', '#', '#', '.'},
                                         {'#', '.', '#', '#', '.', '#'}};
    std::cout << maxStudents(seats) << " (expected 4)\n";
    return 0;
}
