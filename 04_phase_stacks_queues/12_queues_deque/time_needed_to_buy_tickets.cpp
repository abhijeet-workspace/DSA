// Time Needed to Buy Tickets — https://leetcode.com/problems/time-needed-to-buy-tickets/
// O(N) count: people before k buy min(t[i], t[k]); after buy min(t[i], t[k]-1).
#include <algorithm>
#include <iostream>
#include <vector>

int timeRequiredToBuy(const std::vector<int>& tickets, int k) {
    const int need = tickets[static_cast<size_t>(k)];
    int seconds = 0;
    for (int i = 0; i < static_cast<int>(tickets.size()); ++i) {
        if (i <= k) {
            seconds += std::min(tickets[static_cast<size_t>(i)], need);
        } else {
            seconds += std::min(tickets[static_cast<size_t>(i)], need - 1);
        }
    }
    return seconds;
}

int main() {
    std::cout << timeRequiredToBuy({2, 3, 2}, 2) << " (expected 6)\n";
    std::cout << timeRequiredToBuy({5, 1, 1, 1}, 0) << " (expected 8)\n";
    return 0;
}
