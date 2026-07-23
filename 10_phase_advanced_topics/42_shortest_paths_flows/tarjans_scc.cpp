// Tarjan SCC — one DFS with disc/low-link and node stack
#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

class Graph {
    int V;
    std::vector<std::vector<int>> adj;

    void sccDFS(int u, std::vector<int>& disc, std::vector<int>& low, std::stack<int>& st,
                std::vector<bool>& inStack, int& time, std::vector<std::vector<int>>& sccs) {
        disc[u] = low[u] = ++time;
        st.push(u);
        inStack[u] = true;
        for (int v : adj[u]) {
            if (disc[v] == -1) {
                sccDFS(v, disc, low, st, inStack, time, sccs);
                low[u] = std::min(low[u], low[v]);
            } else if (inStack[v]) {
                low[u] = std::min(low[u], disc[v]); // back-edge into stack
            }
        }
        if (low[u] == disc[u]) {
            std::vector<int> cur;
            while (true) {
                int v = st.top();
                st.pop();
                inStack[v] = false;
                cur.push_back(v);
                if (u == v) {
                    break;
                }
            }
            sccs.push_back(std::move(cur));
        }
    }

public:
    explicit Graph(int V_) : V(V_), adj(V_) {}

    void addEdge(int v, int w) {
        adj[v].push_back(w);
    }

    std::vector<std::vector<int>> findSCCs() {
        std::vector<int> disc(V, -1), low(V, -1);
        std::vector<bool> inStack(V, false);
        std::stack<int> st;
        int time = 0;
        std::vector<std::vector<int>> sccs;
        for (int i = 0; i < V; ++i) {
            if (disc[i] == -1) {
                sccDFS(i, disc, low, st, inStack, time, sccs);
            }
        }
        return sccs;
    }
};

int main() {
    Graph g1(5);
    g1.addEdge(1, 0);
    g1.addEdge(0, 2);
    g1.addEdge(2, 1);
    g1.addEdge(0, 3);
    g1.addEdge(3, 4);
    auto sccs1 = g1.findSCCs();
    std::cout << "g1_sccs=" << sccs1.size() << " (expected 3)\n";

    Graph g2(8);
    g2.addEdge(0, 1);
    g2.addEdge(1, 2);
    g2.addEdge(2, 0);
    g2.addEdge(2, 3);
    g2.addEdge(3, 4);
    g2.addEdge(4, 3);
    g2.addEdge(4, 5);
    g2.addEdge(5, 6);
    g2.addEdge(6, 5);
    g2.addEdge(6, 7);
    g2.addEdge(7, 7);
    auto sccs2 = g2.findSCCs();
    std::cout << "g2_sccs=" << sccs2.size() << " (expected 4)\n";
    return 0;
}
