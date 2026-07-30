// A* — heuristic shortest path on a small grid (4-directional)
// f(n) = g(n) + h(n); Manhattan heuristic is admissible for 4-dir grids.
#include <cmath>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

struct Node {
    int f, g, r, c;
    bool operator>(const Node& o) const { return f > o.f; }
};

int manhattan(int r, int c, int tr, int tc) {
    return std::abs(r - tr) + std::abs(c - tc);
}

int aStar(const std::vector<std::vector<int>>& grid, std::pair<int, int> start,
          std::pair<int, int> goal) {
    const int m = static_cast<int>(grid.size());
    const int n = static_cast<int>(grid[0].size());
    const int sr = start.first, sc = start.second;
    const int gr = goal.first, gc = goal.second;
    if (grid[sr][sc] || grid[gr][gc]) return -1;

    const int INF = 1e9;
    std::vector<std::vector<int>> gScore(m, std::vector<int>(n, INF));
    std::priority_queue<Node, std::vector<Node>, std::greater<Node>> pq;

    gScore[sr][sc] = 0;
    pq.push({manhattan(sr, sc, gr, gc), 0, sr, sc});

    const int dr[] = {0, 1, 0, -1};
    const int dc[] = {1, 0, -1, 0};

    while (!pq.empty()) {
        Node cur = pq.top();
        pq.pop();
        if (cur.r == gr && cur.c == gc) return cur.g;
        if (cur.g > gScore[cur.r][cur.c]) continue; // stale

        for (int k = 0; k < 4; ++k) {
            int nr = cur.r + dr[k];
            int nc = cur.c + dc[k];
            if (nr < 0 || nr >= m || nc < 0 || nc >= n || grid[nr][nc]) continue;
            int ng = cur.g + 1;
            if (ng < gScore[nr][nc]) {
                gScore[nr][nc] = ng;
                int f = ng + manhattan(nr, nc, gr, gc);
                pq.push({f, ng, nr, nc});
            }
        }
    }
    return -1;
}

int main() {
    // 0 = free, 1 = wall
    std::vector<std::vector<int>> grid = {
        {0, 0, 0, 0},
        {1, 1, 0, 1},
        {0, 0, 0, 0},
        {0, 1, 1, 0},
    };
    int dist = aStar(grid, {0, 0}, {3, 3});
    std::cout << "A* path length: " << dist << "\n"; // expected 6
    return 0;
}
