// Combination Sum III — https://leetcode.com/problems/combination-sum-iii/
// Find all combinations of k distinct numbers in [1,9] that sum to n.
#include <iostream>
#include <vector>

void dfs(int start, int k, int remain, std::vector<int>& path,
         std::vector<std::vector<int>>& result) {
    if (k == 0 && remain == 0) {
        result.push_back(path);
        return;
    }
    if (k == 0 || remain <= 0) return;
    for (int x = start; x <= 9; ++x) {
        if (x > remain) break;
        path.push_back(x);
        dfs(x + 1, k - 1, remain - x, path, result);
        path.pop_back();
    }
}

std::vector<std::vector<int>> combinationSum3(int k, int n) {
    std::vector<std::vector<int>> result;
    std::vector<int> path;
    dfs(1, k, n, path, result);
    return result;
}

int main() {
    const auto r = combinationSum3(3, 7);
    std::cout << "count=" << r.size() << " (expected 1)\n";
    for (const auto& c : r) {
        for (size_t i = 0; i < c.size(); ++i) std::cout << c[i] << (i + 1 < c.size() ? " " : "");
        std::cout << "\n";
    }
    return 0;
}
