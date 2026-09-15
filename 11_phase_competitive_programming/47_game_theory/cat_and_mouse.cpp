#include <functional>
#include <iostream>
#include <vector>

int catMouseGame(std::vector<std::vector<int>> g) {
    int n = g.size();
    std::vector<std::vector<std::vector<int>>> memo(
        n, std::vector<std::vector<int>>(n, std::vector<int>(2 * n + 5, -1)));
    std::function<int(int, int, int)> dfs = [&](int m, int c, int t) -> int {
        if (t > 2 * n)
            return 0;
        if (m == 0)
            return 1;
        if (m == c)
            return 2;
        int& res = memo[m][c][t];
        if (res != -1)
            return res;
        if (t % 2 == 0) {
            bool draw = false;
            for (int nxt : g[m]) {
                int r = dfs(nxt, c, t + 1);
                if (r == 1)
                    return res = 1;
                if (r == 0)
                    draw = true;
            }
            return res = draw ? 0 : 2;
        }
        bool draw = false;
        for (int nxt : g[c]) {
            if (nxt == 0)
                continue;
            int r = dfs(m, nxt, t + 1);
            if (r == 2)
                return res = 2;
            if (r == 0)
                draw = true;
        }
        return res = draw ? 0 : 1;
    };
    return dfs(1, 2, 0);
}

int main() {
    std::vector<std::vector<int>> g = {{2, 5}, {3}, {0, 4, 5}, {1, 4, 5}, {2, 3}, {0, 2, 3}};
    std::cout << "catMouse=" << catMouseGame(g) << " (expected 0)\n";
    return 0;
}
