// Find the Town Judge — https://leetcode.com/problems/find-the-town-judge/
// Judge is trusted by everyone and trusts nobody; return label or -1.
#include <iostream>
#include <vector>

int findJudge(int n, const std::vector<std::vector<int>>& trust) {
    std::vector<int> score(static_cast<size_t>(n + 1), 0);
    for (const auto& t : trust) {
        --score[static_cast<size_t>(t[0])]; // trusts someone
        ++score[static_cast<size_t>(t[1])]; // is trusted
    }
    for (int i = 1; i <= n; ++i) {
        if (score[static_cast<size_t>(i)] == n - 1)
            return i;
    }
    return -1;
}

int main() {
    std::cout << findJudge(2, {{1, 2}}) << " (expected 2)\n";
    std::cout << findJudge(3, {{1, 3}, {2, 3}}) << " (expected 3)\n";
    return 0;
}
