// Hand of Straights — https://leetcode.com/problems/hand-of-straights/
// Greedily form consecutive groups of size groupSize from sorted counts.
#include <iostream>
#include <vector>
#include <map>

bool isNStraightHand(const std::vector<int>& hand, int groupSize) {
    if (static_cast<int>(hand.size()) % groupSize != 0) return false;
    std::map<int, int> cnt;
    for (int x : hand) ++cnt[x];
    while (!cnt.empty()) {
        const int start = cnt.begin()->first; // smallest remaining
        for (int i = 0; i < groupSize; ++i) {
            if (!cnt.count(start + i)) return false;
            if (--cnt[start + i] == 0) cnt.erase(start + i);
        }
    }
    return true;
}

int main() {
    const std::vector<int> h = {1, 2, 3, 6, 2, 3, 4, 7, 8};
    std::cout << std::boolalpha << isNStraightHand(h, 3) << " (expected true)\n";
    return 0;
}
