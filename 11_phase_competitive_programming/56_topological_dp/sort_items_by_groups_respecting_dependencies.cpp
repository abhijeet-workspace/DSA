// Sort Items by Groups Respecting Dependencies — LeetCode 1203
#include <iostream>
#include <queue>
#include <vector>

std::vector<int> topo(int n, const std::vector<std::vector<int>>& g, std::vector<int> indeg) {
    std::queue<int> q;
    for (int i = 0; i < n; ++i)
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
    return order.size() == static_cast<size_t>(n) ? order : std::vector<int>{};
}

std::vector<int> sortItems(int n, int m, std::vector<int> group,
                           const std::vector<std::vector<int>>& beforeItems) {
    for (int i = 0; i < n; ++i)
        if (group[static_cast<size_t>(i)] == -1)
            group[static_cast<size_t>(i)] = m++;
    std::vector<std::vector<int>> itemG(static_cast<size_t>(n)), groupG(static_cast<size_t>(m));
    std::vector<int> itemInd(static_cast<size_t>(n), 0), groupInd(static_cast<size_t>(m), 0);
    for (int v = 0; v < n; ++v) {
        for (int u : beforeItems[static_cast<size_t>(v)]) {
            itemG[static_cast<size_t>(u)].push_back(v);
            ++itemInd[static_cast<size_t>(v)];
            if (group[static_cast<size_t>(u)] != group[static_cast<size_t>(v)]) {
                groupG[static_cast<size_t>(group[static_cast<size_t>(u)])].push_back(
                    group[static_cast<size_t>(v)]);
                ++groupInd[static_cast<size_t>(group[static_cast<size_t>(v)])];
            }
        }
    }
    auto itemOrder = topo(n, itemG, itemInd);
    auto groupOrder = topo(m, groupG, groupInd);
    if (itemOrder.empty() || groupOrder.empty())
        return {};
    std::vector<std::vector<int>> buckets(static_cast<size_t>(m));
    for (int x : itemOrder)
        buckets[static_cast<size_t>(group[static_cast<size_t>(x)])].push_back(x);
    std::vector<int> ans;
    for (int gid : groupOrder)
        for (int x : buckets[static_cast<size_t>(gid)])
            ans.push_back(x);
    return ans;
}

int main() {
    auto a = sortItems(8, 2, {-1, -1, 1, 0, 0, 1, 0, -1}, {{}, {6}, {5}, {6}, {3, 6}, {}, {}, {}});
    std::cout << "size=" << a.size() << " (expected 8)\n";
    return 0;
}
