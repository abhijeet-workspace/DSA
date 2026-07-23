// Subtree sums — Euler enter times + Fenwick
// Place value at in[u]; subtree(u) = sum on [in[u], out[u]] (enter-only timing).
#include <iostream>
#include <vector>

class Fenwick {
public:
    explicit Fenwick(int n) : bit(static_cast<size_t>(n) + 1, 0) {}

    void add(int i, long long delta) {
        for (; i < static_cast<int>(bit.size()); i += i & -i) {
            bit[static_cast<size_t>(i)] += delta;
        }
    }

    long long sumPrefix(int i) const {
        long long s = 0;
        for (; i > 0; i -= i & -i) {
            s += bit[static_cast<size_t>(i)];
        }
        return s;
    }

    long long sumRange(int l, int r) const {
        return sumPrefix(r) - sumPrefix(l - 1);
    }

private:
    std::vector<long long> bit;
};

void dfsEnter(int u, int p, const std::vector<std::vector<int>>& adj,
              std::vector<int>& inT, std::vector<int>& outT, int& timer) {
    inT[static_cast<size_t>(u)] = timer++;
    for (int v : adj[static_cast<size_t>(u)]) {
        if (v == p) {
            continue;
        }
        dfsEnter(v, u, adj, inT, outT, timer);
    }
    outT[static_cast<size_t>(u)] = timer - 1; // inclusive end of contiguous block
}

int main() {
    const int n = 4;
    std::vector<std::vector<int>> adj(n);
    auto addEdge = [&](int u, int v) {
        adj[static_cast<size_t>(u)].push_back(v);
        adj[static_cast<size_t>(v)].push_back(u);
    };
    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 3);

    const std::vector<long long> val = {5, 1, 2, 3};

    std::vector<int> inT(n), outT(n);
    int timer = 1; // Fenwick is 1-based
    dfsEnter(0, -1, adj, inT, outT, timer);

    Fenwick fw(n);
    for (int u = 0; u < n; ++u) {
        fw.add(inT[static_cast<size_t>(u)], val[static_cast<size_t>(u)]);
    }

    auto subtreeSum = [&](int u) {
        return fw.sumRange(inT[static_cast<size_t>(u)], outT[static_cast<size_t>(u)]);
    };

    const long long s0 = subtreeSum(0);
    const long long s1 = subtreeSum(1);
    const long long s2 = subtreeSum(2);
    const long long s3 = subtreeSum(3);

    fw.add(inT[3], 7); // node 3: 3 → 10
    const long long s1b = subtreeSum(1);

    const bool ok = (s0 == 11 && s1 == 4 && s2 == 2 && s3 == 3 && s1b == 11);
    std::cout << "subtree(0)=" << s0 << " (expected 11)\n";
    std::cout << "subtree(1)=" << s1 << " (expected 4)\n";
    std::cout << "subtree(2)=" << s2 << " (expected 2)\n";
    std::cout << "subtree(3)=" << s3 << " (expected 3)\n";
    std::cout << "after update subtree(1)=" << s1b << " (expected 11)\n";
    std::cout << (ok ? "OK\n" : "FAIL\n");
    return ok ? 0 : 1;
}
