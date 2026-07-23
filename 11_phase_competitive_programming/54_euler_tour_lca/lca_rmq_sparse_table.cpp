// LCA via Euler tour of depths + sparse table RMQ
// Min-depth node between first[u] and first[v] on the tour is the LCA.
#include <algorithm>
#include <iostream>
#include <vector>

struct LCA {
    std::vector<int> euler;
    std::vector<int> depthNode; // depth of euler[i]
    std::vector<int> first;
    std::vector<int> depth;
    std::vector<std::vector<int>> st; // st[k][i] = index of min depth in [i, i+2^k)
    std::vector<int> lg;

    void dfs(int u, int p, int d, const std::vector<std::vector<int>>& adj) {
        depth[static_cast<size_t>(u)] = d;
        first[static_cast<size_t>(u)] = static_cast<int>(euler.size());
        euler.push_back(u);
        depthNode.push_back(d);
        for (int v : adj[static_cast<size_t>(u)]) {
            if (v == p) {
                continue;
            }
            dfs(v, u, d + 1, adj);
            euler.push_back(u);
            depthNode.push_back(d);
        }
    }

    void build(int root, const std::vector<std::vector<int>>& adj) {
        const int n = static_cast<int>(adj.size());
        first.assign(static_cast<size_t>(n), -1);
        depth.assign(static_cast<size_t>(n), 0);
        euler.clear();
        depthNode.clear();
        dfs(root, -1, 0, adj);

        const int m = static_cast<int>(euler.size());
        lg.assign(static_cast<size_t>(m) + 1, 0);
        for (int i = 2; i <= m; ++i) {
            lg[static_cast<size_t>(i)] = lg[static_cast<size_t>(i / 2)] + 1;
        }
        const int K = lg[static_cast<size_t>(m)] + 1;
        st.assign(static_cast<size_t>(K), std::vector<int>(static_cast<size_t>(m)));
        for (int i = 0; i < m; ++i) {
            st[0][static_cast<size_t>(i)] = i;
        }
        for (int k = 1; k < K; ++k) {
            for (int i = 0; i + (1 << k) <= m; ++i) {
                const int left = st[static_cast<size_t>(k - 1)][static_cast<size_t>(i)];
                const int right = st[static_cast<size_t>(k - 1)][static_cast<size_t>(i + (1 << (k - 1)))];
                st[static_cast<size_t>(k)][static_cast<size_t>(i)] =
                    (depthNode[static_cast<size_t>(left)] <= depthNode[static_cast<size_t>(right)])
                        ? left
                        : right;
            }
        }
    }

    int rmqIndex(int l, int r) const {
        const int len = r - l + 1;
        const int k = lg[static_cast<size_t>(len)];
        const int left = st[static_cast<size_t>(k)][static_cast<size_t>(l)];
        const int right = st[static_cast<size_t>(k)][static_cast<size_t>(r - (1 << k) + 1)];
        return (depthNode[static_cast<size_t>(left)] <= depthNode[static_cast<size_t>(right)])
            ? left
            : right;
    }

    int query(int u, int v) const {
        int l = first[static_cast<size_t>(u)];
        int r = first[static_cast<size_t>(v)];
        if (l > r) {
            std::swap(l, r);
        }
        return euler[static_cast<size_t>(rmqIndex(l, r))];
    }
};

int main() {
    const int n = 5;
    std::vector<std::vector<int>> adj(n);
    auto addEdge = [&](int u, int v) {
        adj[static_cast<size_t>(u)].push_back(v);
        adj[static_cast<size_t>(v)].push_back(u);
    };
    // 0-1-3, 0-2-4
    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 3);
    addEdge(2, 4);

    LCA lca;
    lca.build(0, adj);

    const int a = lca.query(3, 4);
    const int b = lca.query(3, 1);
    const int c = lca.query(4, 2);
    const int d = lca.query(1, 2);
    const int e = lca.query(3, 3);

    const bool ok = (a == 0 && b == 1 && c == 2 && d == 0 && e == 3);
    std::cout << "LCA(3,4)=" << a << " (expected 0)\n";
    std::cout << "LCA(3,1)=" << b << " (expected 1)\n";
    std::cout << "LCA(4,2)=" << c << " (expected 2)\n";
    std::cout << "LCA(1,2)=" << d << " (expected 0)\n";
    std::cout << "LCA(3,3)=" << e << " (expected 3)\n";
    std::cout << (ok ? "OK\n" : "FAIL\n");
    return ok ? 0 : 1;
}
