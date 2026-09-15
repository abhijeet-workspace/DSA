// Shortest Path to Get All Keys — https://leetcode.com/problems/shortest-path-to-get-all-keys/
#include <iostream>
#include <queue>
#include <string>
#include <tuple>
#include <vector>

int shortestPathAllKeys(std::vector<std::string>& grid) {
    const int R = static_cast<int>(grid.size());
    const int C = static_cast<int>(grid[0].size());
    int sr = 0, sc = 0, keys = 0;
    for (int i = 0; i < R; ++i)
        for (int j = 0; j < C; ++j) {
            const char ch = grid[static_cast<size_t>(i)][static_cast<size_t>(j)];
            if (ch == '@') { sr = i; sc = j; }
            if (ch >= 'a' && ch <= 'f') keys = std::max(keys, ch - 'a' + 1);
        }
    const int full = (1 << keys) - 1;
    std::vector<std::vector<std::vector<char>>> seen(
        R, std::vector<std::vector<char>>(C, std::vector<char>(1 << keys, 0)));
    std::queue<std::tuple<int, int, int, int>> q;
    q.emplace(sr, sc, 0, 0);
    seen[static_cast<size_t>(sr)][static_cast<size_t>(sc)][0] = 1;
    const int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    while (!q.empty()) {
        auto [r, c, mask, d] = q.front();
        q.pop();
        if (mask == full) return d;
        for (auto& dir : dirs) {
            int nr = r + dir[0], nc = c + dir[1];
            if (nr < 0 || nc < 0 || nr >= R || nc >= C) continue;
            char ch = grid[static_cast<size_t>(nr)][static_cast<size_t>(nc)];
            if (ch == '#') continue;
            int nmask = mask;
            if (ch >= 'A' && ch <= 'F' && !(mask & (1 << (ch - 'A')))) continue;
            if (ch >= 'a' && ch <= 'f') nmask |= 1 << (ch - 'a');
            if (!seen[static_cast<size_t>(nr)][static_cast<size_t>(nc)][static_cast<size_t>(nmask)]) {
                seen[static_cast<size_t>(nr)][static_cast<size_t>(nc)][static_cast<size_t>(nmask)] = 1;
                q.emplace(nr, nc, nmask, d + 1);
            }
        }
    }
    return -1;
}

int main() {
    std::vector<std::string> grid{"@.a.#", "###.#", "b.A.B"};
    std::cout << shortestPathAllKeys(grid) << " (expected 8)\n";
    return 0;
}
