// Heavy-Light Decomposition — path sums via chains + Fenwick
// Heavy child = largest subtree; light edges jump O(log N) times.
#include <algorithm>
#include <iostream>
#include <vector>

struct HLD {
    int n = 0;
    int timer = 0;
    std::vector<std::vector<int>> g;
    std::vector<int> parent, depth, heavy, head, pos, sz, val;
    std::vector<long long> bit;

    explicit HLD(int n_)
        : n(n_),
          g(n_),
          parent(n_),
          depth(n_),
          heavy(n_, -1),
          head(n_),
          pos(n_),
          sz(n_),
          val(n_),
          bit(n_ + 1, 0) {}

    void addEdge(int u, int v) {
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int dfs(int v, int p) {
        parent[v] = p;
        sz[v] = 1;
        int maxSz = 0;
        for (int to : g[v]) {
            if (to == p) {
                continue;
            }
            depth[to] = depth[v] + 1;
            int s = dfs(to, v);
            sz[v] += s;
            if (s > maxSz) {
                maxSz = s;
                heavy[v] = to;
            }
        }
        return sz[v];
    }

    void decompose(int v, int h) {
        head[v] = h;
        pos[v] = timer++;
        if (heavy[v] != -1) {
            decompose(heavy[v], h);
        }
        for (int to : g[v]) {
            if (to != parent[v] && to != heavy[v]) {
                decompose(to, to);
            }
        }
    }

    void bitAdd(int i, long long x) {
        for (++i; i <= n; i += i & -i) {
            bit[i] += x;
        }
    }

    long long bitSum(int i) {
        long long s = 0;
        for (++i; i > 0; i -= i & -i) {
            s += bit[i];
        }
        return s;
    }

    long long bitRange(int l, int r) {
        return bitSum(r) - (l ? bitSum(l - 1) : 0);
    }

    void init(const std::vector<int>& values, int root = 0) {
        val = values;
        dfs(root, -1);
        decompose(root, root);
        for (int v = 0; v < n; ++v) {
            bitAdd(pos[v], val[v]);
        }
    }

    long long pathQuery(int a, int b) {
        long long res = 0;
        while (head[a] != head[b]) {
            if (depth[head[a]] < depth[head[b]]) {
                std::swap(a, b);
            }
            res += bitRange(pos[head[a]], pos[a]);
            a = parent[head[a]];
        }
        if (depth[a] > depth[b]) {
            std::swap(a, b);
        }
        res += bitRange(pos[a], pos[b]);
        return res;
    }
};

int main() {
    HLD h(4);
    h.addEdge(0, 1);
    h.addEdge(0, 2);
    h.addEdge(1, 3);
    h.init({1, 2, 3, 4}, 0);
    std::cout << "pathSum(3,2)=" << h.pathQuery(3, 2) << " (expected 10)\n";
    std::cout << "pathSum(3,1)=" << h.pathQuery(3, 1) << " (expected 6)\n";
    return 0;
}
