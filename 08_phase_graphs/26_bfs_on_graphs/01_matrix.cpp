// 01 Matrix — https://leetcode.com/problems/01-matrix/
// For each cell, distance to the nearest 0; multi-source BFS from all zeros.
#include <climits>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

std::vector<std::vector<int>> updateMatrix(const std::vector<std::vector<int>>& mat) {
    const int m = static_cast<int>(mat.size());
    const int n = static_cast<int>(mat[0].size());
    std::vector<std::vector<int>> dist(m, std::vector<int>(n, INT_MAX));
    std::queue<std::pair<int, int>> q;

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (mat[i][j] == 0) {
                dist[i][j] = 0;
                q.push({i, j}); // all zeros are sources
            }
        }
    }

    const int dirs[] = {0, 1, 0, -1, 0};
    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();
        for (int d = 0; d < 4; ++d) {
            const int nr = r + dirs[d];
            const int nc = c + dirs[d + 1];
            if (nr >= 0 && nr < m && nc >= 0 && nc < n && dist[nr][nc] > dist[r][c] + 1) {
                dist[nr][nc] = dist[r][c] + 1;
                q.push({nr, nc});
            }
        }
    }
    return dist;
}

int main() {
    const std::vector<std::vector<int>> mat = {
        {0, 0, 0},
        {0, 1, 0},
        {1, 1, 1},
    };
    auto result = updateMatrix(mat);
    for (const auto& row : result) {
        for (int x : row) {
            std::cout << x << " ";
        }
        std::cout << "\n";
    }
    // expected:
    // 0 0 0
    // 0 1 0
    // 1 2 1
    return 0;
}
