// Bidirectional BFS — shortest path in an unweighted graph
// Expand from source and target until the frontiers meet.
#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

int bidirectionalBfs(const std::vector<std::vector<int>>& adj, int src, int dst) {
    if (src == dst) return 0;

    std::queue<int> qSrc, qDst;
    std::unordered_map<int, int> distSrc, distDst;
    qSrc.push(src);
    qDst.push(dst);
    distSrc[src] = 0;
    distDst[dst] = 0;

    auto expand = [&](std::queue<int>& q, std::unordered_map<int, int>& distMine,
                      const std::unordered_map<int, int>& distOther) -> int {
        int sz = static_cast<int>(q.size());
        while (sz--) {
            int u = q.front();
            q.pop();
            for (int v : adj[u]) {
                if (distMine.count(v)) continue;
                distMine[v] = distMine[u] + 1;
                if (distOther.count(v)) {
                    return distMine[v] + distOther.at(v);
                }
                q.push(v);
            }
        }
        return -1;
    };

    while (!qSrc.empty() && !qDst.empty()) {
        // Expand the smaller frontier first (optional heuristic).
        int hit = (qSrc.size() <= qDst.size()) ? expand(qSrc, distSrc, distDst)
                                               : expand(qDst, distDst, distSrc);
        if (hit != -1) return hit;
    }
    return -1; // unreachable
}

int main() {
    int V = 6;
    std::vector<std::vector<int>> adj(V);
    auto add = [&](int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    };
    add(0, 1);
    add(0, 2);
    add(1, 3);
    add(2, 3);
    add(3, 4);
    add(4, 5);

    int src = 0, dst = 5;
    int d = bidirectionalBfs(adj, src, dst);
    std::cout << "Shortest " << src << "->" << dst << ": " << d << "\n"; // expected 4
    return 0;
}
