// Build a Matrix With Conditions — https://leetcode.com/problems/build-a-matrix-with-conditions/
#include <iostream>
#include <queue>
#include <vector>

std::vector<int> topo(int k, const std::vector<std::vector<int>>& cond) {
    std::vector<std::vector<int>> g(static_cast<size_t>(k + 1));
    std::vector<int> indeg(static_cast<size_t>(k + 1), 0);
    for (const auto& c : cond) {
        g[static_cast<size_t>(c[0])].push_back(c[1]);
        ++indeg[static_cast<size_t>(c[1])];
    }
    std::queue<int> q;
    for (int i = 1; i <= k; ++i)
        if (indeg[static_cast<size_t>(i)] == 0)
            q.push(i);
    std::vector<int> order;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        order.push_back(u);
        for (int v : g[static_cast<size_t>(u)])
            if (--indeg[static_cast<size_t>(v)] == 0)
                q.push(v);
    }
    if (static_cast<int>(order.size()) != k)
        return {};
    return order;
}

std::vector<std::vector<int>> buildMatrix(int k, const std::vector<std::vector<int>>& rowConditions,
                                          const std::vector<std::vector<int>>& colConditions) {
    auto rowOrder = topo(k, rowConditions);
    auto colOrder = topo(k, colConditions);
    if (rowOrder.empty() || colOrder.empty())
        return {};
    std::vector<int> rowPos(static_cast<size_t>(k + 1)), colPos(static_cast<size_t>(k + 1));
    for (int i = 0; i < k; ++i) {
        rowPos[static_cast<size_t>(rowOrder[static_cast<size_t>(i)])] = i;
        colPos[static_cast<size_t>(colOrder[static_cast<size_t>(i)])] = i;
    }
    std::vector<std::vector<int>> mat(static_cast<size_t>(k),
                                      std::vector<int>(static_cast<size_t>(k), 0));
    for (int num = 1; num <= k; ++num)
        mat[static_cast<size_t>(rowPos[static_cast<size_t>(num)])]
           [static_cast<size_t>(colPos[static_cast<size_t>(num)])] = num;
    return mat;
}

int main() {
    const auto m = buildMatrix(3, {{1, 2}, {3, 2}}, {{2, 1}, {3, 2}});
    std::cout << "rows=" << m.size() << " (expected 3)\n";
    for (const auto& row : m) {
        for (int x : row)
            std::cout << x << " ";
        std::cout << "\n";
    }
    return 0;
}
