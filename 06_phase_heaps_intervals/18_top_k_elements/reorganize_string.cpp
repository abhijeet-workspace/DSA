// Reorganize String — https://leetcode.com/problems/reorganize-string/
// Max-heap by frequency; always place next most frequent that ≠ last char.
#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <vector>

std::string reorganizeString(const std::string& s) {
    std::vector<int> freq(26, 0);
    for (char c : s) {
        ++freq[static_cast<size_t>(c - 'a')];
    }
    using P = std::pair<int, char>; // count, char
    std::priority_queue<P> max_heap;
    for (int i = 0; i < 26; ++i) {
        if (freq[static_cast<size_t>(i)] > 0) {
            max_heap.push({freq[static_cast<size_t>(i)], static_cast<char>('a' + i)});
        }
    }
    std::string result;
    result.reserve(s.size());
    P prev = {0, '#'}; // last placed (held out one turn)
    while (!max_heap.empty()) {
        auto [count, ch] = max_heap.top();
        max_heap.pop();
        result.push_back(ch);
        --count;
        if (prev.first > 0) {
            max_heap.push(prev); // reinsert previous after a gap
        }
        prev = {count, ch};
    }
    if (static_cast<int>(result.size()) != static_cast<int>(s.size())) {
        return ""; // leftover prev with count > 0 means impossible
    }
    return result;
}

int main() {
    std::cout << reorganizeString("aab") << " (expected aba)\n";
    std::cout << reorganizeString("aaab") << " (expected empty)\n";
    std::cout << reorganizeString("vvvlo") << " (expected one of: vlvov, ...)\n";
    return 0;
}
