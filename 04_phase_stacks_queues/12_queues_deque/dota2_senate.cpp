// Dota2 Senate — https://leetcode.com/problems/dota2-senate/
// Radiant/Dire ban next opposing senator; queue indices by party.
#include <iostream>
#include <queue>
#include <string>

std::string predictPartyVictory(const std::string& senate) {
    const int n = static_cast<int>(senate.size());
    std::queue<int> radiant;
    std::queue<int> dire;
    for (int i = 0; i < n; ++i) {
        if (senate[static_cast<size_t>(i)] == 'R') {
            radiant.push(i);
        } else {
            dire.push(i);
        }
    }
    while (!radiant.empty() && !dire.empty()) {
        const int r = radiant.front();
        radiant.pop();
        const int d = dire.front();
        dire.pop();
        if (r < d) {
            radiant.push(r + n); // survives to next round
        } else {
            dire.push(d + n);
        }
    }
    return radiant.empty() ? "Dire" : "Radiant";
}

int main() {
    std::cout << predictPartyVictory("RD") << " (expected Radiant)\n";
    std::cout << predictPartyVictory("RDD") << " (expected Dire)\n";
    return 0;
}
