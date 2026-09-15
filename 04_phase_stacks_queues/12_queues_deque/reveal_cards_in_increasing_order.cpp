// Reveal Cards In Increasing Order — https://leetcode.com/problems/reveal-cards-in-increasing-order/
// Reverse the reveal process with a deque of indices.
#include <algorithm>
#include <deque>
#include <iostream>
#include <vector>

std::vector<int> deckRevealedIncreasing(std::vector<int> deck) {
    std::sort(deck.begin(), deck.end());
    const int n = static_cast<int>(deck.size());
    std::deque<int> idx;
    for (int i = 0; i < n; ++i) {
        idx.push_back(i);
    }
    std::vector<int> res(static_cast<size_t>(n));
    for (int card : deck) {
        res[static_cast<size_t>(idx.front())] = card;
        idx.pop_front();
        if (!idx.empty()) {
            idx.push_back(idx.front());
            idx.pop_front();
        }
    }
    return res;
}

int main() {
    const auto res = deckRevealedIncreasing({17, 13, 11, 2, 3, 5, 7});
    std::cout << "Deck:";
    for (int x : res) {
        std::cout << ' ' << x;
    }
    std::cout << " (expected 2 13 3 11 5 17 7)\n";
    return 0;
}
