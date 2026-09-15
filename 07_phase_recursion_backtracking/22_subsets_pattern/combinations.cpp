// Combinations — https://leetcode.com/problems/combinations/
// Return all combinations of k numbers chosen from 1..n.
#include <iostream>
#include <vector>

void dfs(int start, int n, int k, std::vector<int>& path,
         std::vector<std::vector<int>>& result) {
    if (static_cast<int>(path.size()) == k) {
        result.push_back(path);
        return;
    }
    for (int x = start; x <= n; ++x) {
        // prune: not enough numbers left
        if (n - x + 1 < k - static_cast<int>(path.size())) break;
        path.push_back(x);
        dfs(x + 1, n, k, path, result);
        path.pop_back();
    }
}

std::vector<std::vector<int>> combine(int n, int k) {
    std::vector<std::vector<int>> result;
    std::vector<int> path;
    dfs(1, n, k, path, result);
    return result;
}

int main() {
    const auto r = combine(4, 2);
    std::cout << "count=" << r.size() << " (expected 6)\n";
    return 0;
}
