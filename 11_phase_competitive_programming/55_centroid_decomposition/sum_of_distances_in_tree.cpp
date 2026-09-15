// Sum of Distances in Tree — LeetCode 834
// Rerooting DP (related tree DP; not CD — see md pedagogy).
#include <iostream>
#include <vector>

struct SumDist {
    int n;
    std::vector<std::vector<int>> g;
    std::vector<long long> sz, dp, ans;
    SumDist(int n_) : n(n_), g(n_), sz(n_), dp(n_), ans(n_) {}
    void addEdge(int u, int v) {
        g[static_cast<size_t>(u)].push_back(v);
        g[static_cast<size_t>(v)].push_back(u);
    }
    void dfs1(int v, int p) {
        sz[static_cast<size_t>(v)] = 1;
        dp[static_cast<size_t>(v)] = 0;
        for (int to : g[static_cast<size_t>(v)])
            if (to != p) {
                dfs1(to, v);
                sz[static_cast<size_t>(v)] += sz[static_cast<size_t>(to)];
                dp[static_cast<size_t>(v)] +=
                    dp[static_cast<size_t>(to)] + sz[static_cast<size_t>(to)];
            }
    }
    void dfs2(int v, int p) {
        for (int to : g[static_cast<size_t>(v)])
            if (to != p) {
                ans[static_cast<size_t>(to)] = ans[static_cast<size_t>(v)] -
                                               sz[static_cast<size_t>(to)] +
                                               (n - sz[static_cast<size_t>(to)]);
                dfs2(to, v);
            }
    }
    std::vector<long long> solve() {
        dfs1(0, -1);
        ans[0] = dp[0];
        dfs2(0, -1);
        return ans;
    }
};

int main() {
    SumDist t(6);
    t.addEdge(0, 1);
    t.addEdge(0, 2);
    t.addEdge(2, 3);
    t.addEdge(2, 4);
    t.addEdge(2, 5);
    auto a = t.solve();
    std::cout << "ans:";
    for (long long x : a)
        std::cout << " " << x;
    std::cout << " (expected 8 12 6 10 10 10)\n";
    return 0;
}
