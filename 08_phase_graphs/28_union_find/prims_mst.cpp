// Prim's MST — grow tree by cheapest edge leaving the cut.
// Return total MST weight for an undirected weighted graph.
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using Edge = std::pair<int, int>; // {weight, node}

int primsMST(int V, const std::vector<std::vector<Edge>>& adj) {
    std::priority_queue<Edge, std::vector<Edge>, std::greater<Edge>> pq;
    std::vector<bool> inMST(static_cast<size_t>(V), false);
    int mstWeight = 0;
    pq.push({0, 0}); // start at vertex 0 with zero cost
    while (!pq.empty()) {
        const auto [weight, u] = pq.top();
        pq.pop();
        if (inMST[static_cast<size_t>(u)]) {
            continue; // stale heap entry
        }
        inMST[static_cast<size_t>(u)] = true;
        mstWeight += weight;
        for (const auto& [w, v] : adj[static_cast<size_t>(u)]) {
            if (!inMST[static_cast<size_t>(v)]) {
                pq.push({w, v});
            }
        }
    }
    return mstWeight;
}

int main() {
    const int V = 5;
    std::vector<std::vector<Edge>> adj(static_cast<size_t>(V));
    auto add = [&](int u, int v, int w) {
        adj[static_cast<size_t>(u)].push_back({w, v});
        adj[static_cast<size_t>(v)].push_back({w, u});
    };
    add(0, 1, 2);
    add(0, 3, 3);
    add(1, 2, 8);
    add(1, 4, 5);
    add(1, 3, 6);
    add(2, 4, 7);
    add(3, 4, 9);
    std::cout << "MST weight: " << primsMST(V, adj) << " (expected 16)\n";
    return 0;
}
