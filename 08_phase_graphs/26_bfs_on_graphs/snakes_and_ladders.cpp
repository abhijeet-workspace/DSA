// Snakes and Ladders — https://leetcode.com/problems/snakes-and-ladders/
#include <iostream>
#include <queue>
#include <vector>

int snakesAndLadders(const std::vector<std::vector<int>>& board) {
    const int n = static_cast<int>(board.size());
    auto idToRC = [&](int id) {
        int r = (id - 1) / n;
        int c = (id - 1) % n;
        if (r % 2 == 1)
            c = n - 1 - c;
        r = n - 1 - r;
        return std::pair<int, int>{r, c};
    };
    std::vector<int> dist(static_cast<size_t>(n * n + 1), -1);
    std::queue<int> q;
    dist[1] = 0;
    q.push(1);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        if (cur == n * n)
            return dist[static_cast<size_t>(cur)];
        for (int step = 1; step <= 6 && cur + step <= n * n; ++step) {
            int next = cur + step;
            auto [r, c] = idToRC(next);
            if (board[static_cast<size_t>(r)][static_cast<size_t>(c)] != -1)
                next = board[static_cast<size_t>(r)][static_cast<size_t>(c)];
            if (dist[static_cast<size_t>(next)] == -1) {
                dist[static_cast<size_t>(next)] = dist[static_cast<size_t>(cur)] + 1;
                q.push(next);
            }
        }
    }
    return -1;
}

int main() {
    std::vector<std::vector<int>> board = {{-1, -1, -1, -1, -1, -1}, {-1, -1, -1, -1, -1, -1},
                                           {-1, -1, -1, -1, -1, -1}, {-1, 35, -1, -1, 13, -1},
                                           {-1, -1, -1, -1, -1, -1}, {-1, 15, -1, -1, -1, -1}};
    std::cout << snakesAndLadders(board) << " (expected 4)\n";
    return 0;
}
