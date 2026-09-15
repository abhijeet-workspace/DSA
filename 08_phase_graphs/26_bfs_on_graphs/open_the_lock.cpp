// Open the Lock — https://leetcode.com/problems/open-the-lock/
// 4-wheel lock '0000'..; BFS minimum turns to target avoiding deadends.
#include <iostream>
#include <queue>
#include <string>
#include <unordered_set>
#include <vector>

int openLock(const std::vector<std::string>& deadends, const std::string& target) {
    std::unordered_set<std::string> dead(deadends.begin(), deadends.end());
    if (dead.count("0000"))
        return -1;
    std::unordered_set<std::string> vis{{"0000"}};
    std::queue<std::pair<std::string, int>> q;
    q.push({"0000", 0});
    while (!q.empty()) {
        auto [cur, dist] = q.front();
        q.pop();
        if (cur == target)
            return dist;
        for (int i = 0; i < 4; ++i) {
            for (int d : {-1, 1}) {
                std::string next = cur;
                next[static_cast<size_t>(i)] =
                    static_cast<char>('0' + (next[static_cast<size_t>(i)] - '0' + d + 10) % 10);
                if (!dead.count(next) && !vis.count(next)) {
                    vis.insert(next);
                    q.push({next, dist + 1});
                }
            }
        }
    }
    return -1;
}

int main() {
    std::cout << openLock({"0201", "0101", "0102", "1212", "2002"}, "0202") << " (expected 6)\n";
    return 0;
}
