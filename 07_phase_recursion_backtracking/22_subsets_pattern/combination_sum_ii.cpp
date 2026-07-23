// Combination Sum II — https://leetcode.com/problems/combination-sum-ii/
// Candidates may duplicate; each index used once; unique combos summing to target.
#include <algorithm>
#include <iostream>
#include <vector>

void backtrack(const std::vector<int>& candidates, int target, int start,
               std::vector<int>& current, std::vector<std::vector<int>>& result) {
    if (target == 0) {
        result.push_back(current); // valid combo
        return;
    }
    for (int i = start; i < static_cast<int>(candidates.size()); ++i) {
        if (candidates[static_cast<size_t>(i)] > target) {
            break; // sorted: rest too large
        }
        if (i > start && candidates[static_cast<size_t>(i)] ==
                             candidates[static_cast<size_t>(i - 1)]) {
            continue; // skip duplicate at same depth
        }
        current.push_back(candidates[static_cast<size_t>(i)]);
        backtrack(candidates, target - candidates[static_cast<size_t>(i)], i + 1,
                  current, result); // each index once
        current.pop_back();
    }
}

std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates, int target) {
    std::sort(candidates.begin(), candidates.end()); // enable skip + prune
    std::vector<std::vector<int>> result;
    std::vector<int> current;
    backtrack(candidates, target, 0, current, result);
    return result;
}

int main() {
    std::vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
    const auto result = combinationSum2(candidates, 8);
    std::cout << "combos=" << result.size() << " (expected 4)\n";
    for (const auto& comb : result) {
        std::cout << "[";
        for (size_t i = 0; i < comb.size(); ++i) {
            std::cout << comb[i] << (i + 1 < comb.size() ? " " : "");
        }
        std::cout << "]\n";
    }
    return 0;
}
