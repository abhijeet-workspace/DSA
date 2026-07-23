// Combination Sum — https://leetcode.com/problems/combination-sum/
// Distinct candidates; unlimited reuse; all unique combos summing to target.
#include <iostream>
#include <vector>

void backtrack(const std::vector<int>& candidates, int remain, int index,
               std::vector<int>& cur, std::vector<std::vector<int>>& result) {
    if (remain == 0) {
        result.push_back(cur); // found a valid combo
        return;
    }
    if (remain < 0 || index >= static_cast<int>(candidates.size())) {
        return; // overshot or exhausted
    }
    cur.push_back(candidates[static_cast<size_t>(index)]);
    backtrack(candidates, remain - candidates[static_cast<size_t>(index)], index, cur,
              result); // reuse same index
    cur.pop_back();
    backtrack(candidates, remain, index + 1, cur, result); // skip to next
}

std::vector<std::vector<int>> combinationSum(const std::vector<int>& candidates,
                                             int target) {
    std::vector<std::vector<int>> result;
    std::vector<int> cur;
    backtrack(candidates, target, 0, cur, result);
    return result;
}

int main() {
    const auto res = combinationSum({2, 3, 6, 7}, 7);
    std::cout << "combos=" << res.size() << " (expected 2)\n";
    for (const auto& comb : res) {
        std::cout << "[";
        for (size_t i = 0; i < comb.size(); ++i) {
            std::cout << comb[i] << (i + 1 < comb.size() ? " " : "");
        }
        std::cout << "]\n";
    }
    return 0;
}
