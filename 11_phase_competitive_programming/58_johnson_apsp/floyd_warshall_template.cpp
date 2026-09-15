// Floyd–Warshall Template — CP classic
#include <algorithm>
#include <iostream>
#include <vector>

struct Floyd {
    int n;
    std::vector<std::vector<long long>> d;
    static constexpr long long INF = 4e18;
    explicit Floyd(int n_) : n(n_), d(n_, std::vector<long long>(n_, INF)) {
        for (int i = 0; i < n; ++i)
            d[i][i] = 0;
    }
    void addEdge(int u, int v, long long w) { d[u][v] = std::min(d[u][v], w); }
    void run() {
        for (int k = 0; k < n; ++k)
            for (int i = 0; i < n; ++i)
                if (d[i][k] < INF)
                    for (int j = 0; j < n; ++j)
                        if (d[k][j] < INF)
                            d[i][j] = std::min(d[i][j], d[i][k] + d[k][j]);
    }
    bool hasNegCycle() const {
        for (int i = 0; i < n; ++i)
            if (d[i][i] < 0)
                return true;
        return false;
    }
};

int main() {
    Floyd f(3);
    f.addEdge(0, 1, 1);
    f.addEdge(1, 2, -1);
    f.addEdge(0, 2, 3);
    f.run();
    std::cout << f.d[0][2] << " (expected 0)\n";
    std::cout << (f.hasNegCycle() ? "neg" : "ok") << " (expected ok)\n";
    return 0;
}
