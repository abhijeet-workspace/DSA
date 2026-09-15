// Open the Lock — https://leetcode.com/problems/open-the-lock/
// BFS on 4-digit lock states; 8 neighbors per node.
#include <iostream>
#include <queue>
#include <string>
#include <unordered_set>
#include <vector>

int openLock(const std::vector<std::string>& deadends, const std::string& target) {
    std::unordered_set<std::string> dead(deadends.begin(), deadends.end());
    if (dead.count("0000")) {
        return -1;
    }
    if (target == "0000") {
        return 0;
    }
    std::queue<std::string> q;
    std::unordered_set<std::string> seen;
    q.push("0000");
    seen.insert("0000");
    int steps = 0;
    while (!q.empty()) {
        const int sz = static_cast<int>(q.size());
        for (int i = 0; i < sz; ++i) {
            const std::string cur = q.front();
            q.pop();
            for (int w = 0; w < 4; ++w) {
                for (int d : {1, -1}) {
                    std::string nxt = cur;
                    nxt[static_cast<size_t>(w)] =
                        static_cast<char>('0' + (nxt[static_cast<size_t>(w)] - '0' + d + 10) % 10);
                    if (nxt == target) {
                        return steps + 1;
                    }
                    if (!dead.count(nxt) && !seen.count(nxt)) {
                        seen.insert(nxt);
                        q.push(nxt);
                    }
                }
            }
        }
        ++steps;
    }
    return -1;
}

int main() {
    std::cout << openLock({"0201", "0101", "0102", "1212", "2002"}, "0202")
              << " (expected 6)\n";
    std::cout << openLock({"8888"}, "0009") << " (expected 1)\n";
    std::cout << openLock({"8887", "8889", "8878", "8898", "8788", "8988", "7888", "9888"}, "8888")
              << " (expected -1)\n";
    return 0;
}
