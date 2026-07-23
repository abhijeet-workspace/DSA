// Min Vertex Cover (Bipartite) — König's theorem
// Min vertex cover size equals max matching; construct cover via Z-set.
#include <iostream>
#include <queue>
#include <string>
#include <vector>

struct BipartiteKonig {
    int nL, nR;
    std::vector<std::vector<int>> adj;
    std::vector<int> pairU, pairV;

    BipartiteKonig(int nL_, int nR_)
        : nL(nL_), nR(nR_), adj(nL_), pairU(nL_, -1), pairV(nR_, -1) {}

    void addEdge(int u, int v) { adj[static_cast<size_t>(u)].push_back(v); }

    bool dfs(int u, std::vector<char>& used) {
        if (used[static_cast<size_t>(u)]) return false;
        used[static_cast<size_t>(u)] = 1;
        for (int v : adj[static_cast<size_t>(u)]) {
            if (pairV[static_cast<size_t>(v)] == -1
                || dfs(pairV[static_cast<size_t>(v)], used)) {
                pairU[static_cast<size_t>(u)] = v;
                pairV[static_cast<size_t>(v)] = u;
                return true;
            }
        }
        return false;
    }

    int maxMatching() {
        int m = 0;
        for (int u = 0; u < nL; ++u) {
            std::vector<char> used(nL, 0);
            if (dfs(u, used)) ++m;
        }
        return m;
    }

    std::pair<int, std::vector<std::string>> minVertexCover() {
        int match = maxMatching();

        std::vector<char> inZ_L(nL, 0), inZ_R(nR, 0);
        std::queue<int> q;
        for (int u = 0; u < nL; ++u) {
            if (pairU[static_cast<size_t>(u)] == -1) {
                inZ_L[static_cast<size_t>(u)] = 1;
                q.push(u);
            }
        }
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : adj[static_cast<size_t>(u)]) {
                if (pairU[static_cast<size_t>(u)] == v) continue; // skip matching L→R
                if (inZ_R[static_cast<size_t>(v)]) continue;
                inZ_R[static_cast<size_t>(v)] = 1;
                int u2 = pairV[static_cast<size_t>(v)]; // matching R→L
                if (u2 != -1 && !inZ_L[static_cast<size_t>(u2)]) {
                    inZ_L[static_cast<size_t>(u2)] = 1;
                    q.push(u2);
                }
            }
        }

        std::vector<std::string> cover;
        for (int u = 0; u < nL; ++u)
            if (!inZ_L[static_cast<size_t>(u)]) cover.push_back("L" + std::to_string(u));
        for (int v = 0; v < nR; ++v)
            if (inZ_R[static_cast<size_t>(v)]) cover.push_back("R" + std::to_string(v));

        if (static_cast<int>(cover.size()) != match) {
            std::cout << "warning: cover " << cover.size() << " != match " << match
                      << "\n";
        }
        return {static_cast<int>(cover.size()), cover};
    }
};

int main() {
    BipartiteKonig g(3, 2);
    g.addEdge(0, 0);
    g.addEdge(1, 0);
    g.addEdge(1, 1);
    g.addEdge(2, 1);
    auto result = g.minVertexCover();
    std::cout << "min_vertex_cover=" << result.first << " (expected 2)\n";
    std::cout << "cover:";
    for (const auto& x : result.second) std::cout << " " << x;
    std::cout << "\n";
    return 0;
}
