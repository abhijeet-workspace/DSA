// Subtree add via Euler in/out + Fenwick difference
#include <iostream>
#include <vector>

struct Fenwick {
    int n;
    std::vector<long long> bit;
    Fenwick(int n) : n(n), bit(n + 1, 0) {}
    void add(int i, long long v) {
        for (; i <= n; i += i & -i)
            bit[i] += v;
    }
    long long sum(int i) {
        long long s = 0;
        for (; i > 0; i -= i & -i)
            s += bit[i];
        return s;
    }
    void rangeAdd(int l, int r, long long v) {
        add(l, v);
        add(r + 1, -v);
    } // point query via sum
};

int main() {
    // tree 0-1-3, 0-2
    std::vector<std::vector<int>> adj(4);
    auto ae = [&](int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    };
    ae(0, 1);
    ae(1, 3);
    ae(0, 2);
    std::vector<int> inT(4), outT(4);
    int timer = 1; // 1-based fenwick
    auto dfs = [&](auto&& self, int u, int p) -> void {
        inT[u] = timer++;
        for (int v : adj[u])
            if (v != p)
                self(self, v, u);
        outT[u] = timer - 1;
    };
    dfs(dfs, 0, -1);
    Fenwick fw(4);
    // add +5 to subtree of 1 (nodes 1,3)
    fw.rangeAdd(inT[1], outT[1], 5);
    long long v1 = fw.sum(inT[1]);
    long long v3 = fw.sum(inT[3]);
    long long v2 = fw.sum(inT[2]);
    bool ok = (v1 == 5 && v3 == 5 && v2 == 0);
    std::cout << "v1=" << v1 << " v3=" << v3 << " v2=" << v2 << "\n";
    std::cout << (ok ? "OK\n" : "FAIL\n");
    return ok ? 0 : 1;
}
