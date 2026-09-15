// Nearest Exit from Entrance in Maze —
// https://leetcode.com/problems/nearest-exit-from-entrance-in-maze/
#include <iostream>
#include <queue>
#include <vector>

int nearestExit(std::vector<std::vector<char>> maze, const std::vector<int>& entrance) {
    const int R = static_cast<int>(maze.size());
    const int C = static_cast<int>(maze[0].size());
    std::queue<std::pair<int, int>> q;
    int sr = entrance[0], sc = entrance[1];
    q.push({sr, sc});
    maze[static_cast<size_t>(sr)][static_cast<size_t>(sc)] = '+';
    static const int dr[4] = {1, -1, 0, 0};
    static const int dc[4] = {0, 0, 1, -1};
    int dist = 0;
    while (!q.empty()) {
        int sz = static_cast<int>(q.size());
        while (sz--) {
            auto [r, c] = q.front();
            q.pop();
            for (int k = 0; k < 4; ++k) {
                int nr = r + dr[k], nc = c + dc[k];
                if (nr < 0 || nc < 0 || nr >= R || nc >= C)
                    continue;
                if (maze[static_cast<size_t>(nr)][static_cast<size_t>(nc)] == '+')
                    continue;
                if (nr == 0 || nc == 0 || nr == R - 1 || nc == C - 1)
                    return dist + 1;
                maze[static_cast<size_t>(nr)][static_cast<size_t>(nc)] = '+';
                q.push({nr, nc});
            }
        }
        ++dist;
    }
    return -1;
}

int main() {
    std::cout << nearestExit({{'+', '+', '.', '+'}, {'.', '.', '.', '+'}, {'+', '+', '+', '.'}},
                             {1, 2})
              << " (expected 1)\n";
    return 0;
}
