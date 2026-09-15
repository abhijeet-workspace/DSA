// Satisfiability of Equality Equations —
// https://leetcode.com/problems/satisfiability-of-equality-equations/ Union equals first; reject if
// an inequality joins the same component.
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

struct DSU {
    std::vector<int> parent;
    std::vector<int> rank;
    DSU() : parent(26), rank(26, 1) { std::iota(parent.begin(), parent.end(), 0); }
    int find(int i) {
        if (parent[static_cast<size_t>(i)] == i) {
            return i;
        }
        return parent[static_cast<size_t>(i)] = find(parent[static_cast<size_t>(i)]);
    }
    void unite(int i, int j) {
        int ri = find(i);
        int rj = find(j);
        if (ri == rj) {
            return;
        }
        if (rank[static_cast<size_t>(ri)] < rank[static_cast<size_t>(rj)]) {
            parent[static_cast<size_t>(ri)] = rj;
        } else if (rank[static_cast<size_t>(ri)] > rank[static_cast<size_t>(rj)]) {
            parent[static_cast<size_t>(rj)] = ri;
        } else {
            parent[static_cast<size_t>(rj)] = ri;
            ++rank[static_cast<size_t>(ri)];
        }
    }
};

bool equationsPossible(const std::vector<std::string>& equations) {
    DSU dsu;
    for (const auto& eq : equations) {
        if (eq[1] == '=') {
            dsu.unite(eq[0] - 'a', eq[3] - 'a');
        }
    }
    for (const auto& eq : equations) {
        if (eq[1] == '!' && dsu.find(eq[0] - 'a') == dsu.find(eq[3] - 'a')) {
            return false;
        }
    }
    return true;
}

int main() {
    std::cout << std::boolalpha << equationsPossible({"a==b", "b!=a"}) << " (expected false)\n"
              << equationsPossible({"a==b", "b==c", "a==c"}) << " (expected true)\n";
    return 0;
}
