// Shortest Path in Binary Matrix — https://leetcode.com/problems/shortest-path-in-binary-matrix/
// Shortest clear path from (0,0) to (n-1,n-1) with 8-directional moves on 0-cells.
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

int shortestPathBinaryMatrix(std::vector<std::vector<int>>& grid) {
    const int n = static_cast<int>(grid.size());
    if (grid[0][0] != 0 || grid[n - 1][n - 1] != 0) {
        return -1;
    }
    if (n == 1) {
        return 1;
    }
    const int dr[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    const int dc[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
    std::queue<std::pair<int, int>> q;
    q.push({0, 0});
    grid[0][0] = 1; // mark visited; store distance in cell
    while (!q.empty()) {
        const auto [r, c] = q.front();
        q.pop();
        const int dist = grid[r][c];
        for (int k = 0; k < 8; ++k) {
            const int nr = r + dr[k];
            const int nc = c + dc[k];
            if (nr < 0 || nc < 0 || nr >= n || nc >= n || grid[nr][nc] != 0) {
                continue;
            }
            if (nr == n - 1 && nc == n - 1) {
                return dist + 1;
            }
            grid[nr][nc] = dist + 1;
            q.push({nr, nc});
        }
    }
    return -1;
}

int main() {
    std::vector<std::vector<int>> g1 = {{0, 1}, {1, 0}};
    std::vector<std::vector<int>> g2 = {{0, 0, 0}, {1, 1, 0}, {1, 1, 0}};
    std::cout << shortestPathBinaryMatrix(g1) << " (expected 2)\n";
    std::cout << shortestPathBinaryMatrix(g2) << " (expected 4)\n";
    return 0;
}
