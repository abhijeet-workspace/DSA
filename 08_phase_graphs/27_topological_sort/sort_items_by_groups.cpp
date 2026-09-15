// Sort Items by Groups Respecting Dependencies — LeetCode 1203
// Topo-sort groups, then items within each group order.
#include <iostream>
#include <queue>
#include <vector>

std::vector<int> topoSort(const std::vector<std::vector<int>>& g, std::vector<int>& indeg) {
    std::queue<int> q;
    for (int i = 0; i < static_cast<int>(indeg.size()); ++i) {
        if (indeg[static_cast<size_t>(i)] == 0) {
            q.push(i);
        }
    }
    std::vector<int> order;
    while (!q.empty()) {
        const int u = q.front();
        q.pop();
        order.push_back(u);
        for (int v : g[static_cast<size_t>(u)]) {
            if (--indeg[static_cast<size_t>(v)] == 0) {
                q.push(v);
            }
        }
    }
    return order.size() == indeg.size() ? order : std::vector<int>{};
}

std::vector<int> sortItems(int n, int m, std::vector<int> group,
                           const std::vector<std::vector<int>>& beforeItems) {
    // assign unique group id for items with group == -1
    for (int i = 0; i < n; ++i) {
        if (group[static_cast<size_t>(i)] == -1) {
            group[static_cast<size_t>(i)] = m++;
        }
    }
    std::vector<std::vector<int>> itemGraph(static_cast<size_t>(n));
    std::vector<int> itemIndeg(static_cast<size_t>(n), 0);
    std::vector<std::vector<int>> groupGraph(static_cast<size_t>(m));
    std::vector<int> groupIndeg(static_cast<size_t>(m), 0);

    for (int v = 0; v < n; ++v) {
        for (int u : beforeItems[static_cast<size_t>(v)]) {
            itemGraph[static_cast<size_t>(u)].push_back(v);
            ++itemIndeg[static_cast<size_t>(v)];
            const int gu = group[static_cast<size_t>(u)];
            const int gv = group[static_cast<size_t>(v)];
            if (gu != gv) {
                groupGraph[static_cast<size_t>(gu)].push_back(gv);
                ++groupIndeg[static_cast<size_t>(gv)];
            }
        }
    }

    const auto groupOrder = topoSort(groupGraph, groupIndeg);
    const auto itemOrder = topoSort(itemGraph, itemIndeg);
    if (groupOrder.empty() || itemOrder.empty()) {
        return {};
    }

    std::vector<std::vector<int>> itemsInGroup(static_cast<size_t>(m));
    for (int item : itemOrder) {
        itemsInGroup[static_cast<size_t>(group[static_cast<size_t>(item)])].push_back(item);
    }
    std::vector<int> ans;
    ans.reserve(static_cast<size_t>(n));
    for (int g : groupOrder) {
        for (int item : itemsInGroup[static_cast<size_t>(g)]) {
            ans.push_back(item);
        }
    }
    return ans;
}

int main() {
    const int n = 8;
    const int m = 2;
    std::vector<int> group = {-1, -1, 1, 0, 0, 1, 0, -1};
    const std::vector<std::vector<int>> beforeItems = {{}, {6}, {5}, {6}, {3, 6}, {}, {}, {}};
    const auto ans = sortItems(n, m, group, beforeItems);
    std::cout << "order size " << ans.size() << " (expected 8): ";
    for (int x : ans) {
        std::cout << x << " ";
    }
    std::cout << "\n";
    return 0;
}
