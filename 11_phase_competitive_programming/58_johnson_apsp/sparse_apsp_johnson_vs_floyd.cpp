// Sparse APSP: Johnson vs Floyd — demo complexity choice
#include <chrono>
#include <iostream>
#include <vector>

int main() {
    // Conceptual demo: report which algorithm to pick by density heuristic.
    int V = 1000, E = 3000;
    long long floyd_ops = 1LL * V * V * V;
    long long johnson_ops = 1LL * V * E + 1LL * V * E * 20; // BF + V dijkstra-ish
    std::cout << "floyd_ops=" << floyd_ops << " johnsonish_ops=" << johnson_ops << "\n";
    std::cout << (johnson_ops < floyd_ops ? "prefer_johnson" : "prefer_floyd")
              << " (expected prefer_johnson)\n";
    V = 50;
    E = 2500;
    floyd_ops = 1LL * V * V * V;
    johnson_ops = 1LL * V * E + 1LL * V * E * 20;
    std::cout << (johnson_ops < floyd_ops ? "prefer_johnson" : "prefer_floyd")
              << " (expected prefer_floyd)\n";
    return 0;
}
