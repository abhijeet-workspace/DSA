// Minimum Genetic Mutation — https://leetcode.com/problems/minimum-genetic-mutation/
#include <iostream>
#include <queue>
#include <string>
#include <unordered_set>
#include <vector>

int minMutation(const std::string& startGene, const std::string& endGene,
                const std::vector<std::string>& bank) {
    std::unordered_set<std::string> valid(bank.begin(), bank.end());
    if (!valid.count(endGene))
        return -1;
    const std::string genes = "ACGT";
    std::unordered_set<std::string> vis{{startGene}};
    std::queue<std::pair<std::string, int>> q;
    q.push({startGene, 0});
    while (!q.empty()) {
        auto [cur, dist] = q.front();
        q.pop();
        if (cur == endGene)
            return dist;
        for (size_t i = 0; i < cur.size(); ++i) {
            char old = cur[i];
            for (char g : genes) {
                if (g == old)
                    continue;
                cur[i] = g;
                if (valid.count(cur) && !vis.count(cur)) {
                    vis.insert(cur);
                    q.push({cur, dist + 1});
                }
            }
            cur[i] = old;
        }
    }
    return -1;
}

int main() {
    std::cout << minMutation("AACCGGTT", "AACCGGTA", {"AACCGGTA"}) << " (expected 1)\n";
    return 0;
}
