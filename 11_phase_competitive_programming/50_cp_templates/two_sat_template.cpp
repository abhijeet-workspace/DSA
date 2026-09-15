// 2-SAT template — implication graph + SCC (Kosaraju)
#include <algorithm>
#include <iostream>
#include <vector>

struct TwoSat {
    int n;
    std::vector<std::vector<int>> g, gr;
    std::vector<int> order, comp;
    std::vector<char> used;
    explicit TwoSat(int n) : n(n), g(2 * n), gr(2 * n) {}
    void addImp(int a, int b) {
        g[a].push_back(b);
        gr[b].push_back(a);
    }
    void addOr(int x, bool xv, int y, bool yv) {
        // (x=xv) or (y=yv)
        int a = 2 * x + (xv ? 0 : 1);
        int b = 2 * y + (yv ? 0 : 1);
        addImp(a ^ 1, b);
        addImp(b ^ 1, a);
    }
    void dfs1(int v) {
        used[v] = 1;
        for (int to : g[v])
            if (!used[to])
                dfs1(to);
        order.push_back(v);
    }
    void dfs2(int v, int c) {
        comp[v] = c;
        for (int to : gr[v])
            if (comp[to] == -1)
                dfs2(to, c);
    }
    bool satisfiable(std::vector<int>& assign) {
        int N = 2 * n;
        used.assign(N, 0);
        order.clear();
        for (int i = 0; i < N; ++i)
            if (!used[i])
                dfs1(i);
        comp.assign(N, -1);
        int cid = 0;
        for (int i = N - 1; i >= 0; --i) {
            int v = order[i];
            if (comp[v] == -1)
                dfs2(v, cid++);
        }
        assign.assign(n, 0);
        for (int i = 0; i < n; ++i) {
            if (comp[2 * i] == comp[2 * i + 1])
                return false;
            assign[i] = comp[2 * i] > comp[2 * i + 1];
        }
        return true;
    }
};

int main() {
    // vars 0,1: force (x0 or x1) and (!x0 or !x1) => one true one false OK
    // and (x0 or !x1) ... keep simple: x0 true required via (x0 or x0)
    TwoSat ts(2);
    ts.addOr(0, true, 0, true);   // x0
    ts.addOr(1, false, 1, false); // !x1
    std::vector<int> asg;
    const bool okSat = ts.satisfiable(asg);
    const bool okVal = okSat && asg[0] == 1 && asg[1] == 0;
    std::cout << "sat=" << okSat << " assign=" << asg[0] << asg[1] << "\n";
    std::cout << (okVal ? "OK\n" : "FAIL\n");
    return okVal ? 0 : 1;
}
