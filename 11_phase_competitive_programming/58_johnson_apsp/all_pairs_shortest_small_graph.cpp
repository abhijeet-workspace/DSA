// All-Pairs Shortest Paths — small graph lab
#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    const int INF = 1e9;
    int n = 4;
    std::vector<std::vector<int>> d(n, std::vector<int>(n, INF));
    for (int i = 0; i < n; ++i)
        d[i][i] = 0;
    auto add = [&](int u, int v, int w) { d[u][v] = std::min(d[u][v], w); };
    add(0, 1, 3);
    add(0, 2, 10);
    add(1, 2, 1);
    add(2, 3, 2);
    add(1, 3, 7);
    for (int k = 0; k < n; ++k)
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (d[i][k] < INF && d[k][j] < INF)
                    d[i][j] = std::min(d[i][j], d[i][k] + d[k][j]);
    std::cout << d[0][3] << " (expected 6)\n";
    return 0;
}
