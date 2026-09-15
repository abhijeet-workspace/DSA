// Top K Frequent Words — https://leetcode.com/problems/top-k-frequent-words/
// Count words; min-heap of size k with freq asc, word desc for tie-break.
#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

struct WordCmp {
    bool operator()(const std::pair<int, std::string>& a,
                    const std::pair<int, std::string>& b) const {
        if (a.first != b.first) {
            return a.first > b.first; // higher freq = lower priority in min-heap
        }
        return a.second < b.second; // lexicographically smaller = worse for min-heap
    }
};

std::vector<std::string> topKFrequent(const std::vector<std::string>& words, int k) {
    std::unordered_map<std::string, int> freq;
    for (const auto& w : words) {
        ++freq[w];
    }
    std::priority_queue<std::pair<int, std::string>,
                        std::vector<std::pair<int, std::string>>, WordCmp>
        min_heap;
    for (const auto& [word, count] : freq) {
        min_heap.push({count, word});
        if (static_cast<int>(min_heap.size()) > k) {
            min_heap.pop();
        }
    }
    std::vector<std::string> result(static_cast<size_t>(k));
    for (int i = k - 1; i >= 0; --i) {
        result[static_cast<size_t>(i)] = min_heap.top().second;
        min_heap.pop(); // pop worst-first → fill from the end
    }
    return result;
}

int main() {
    const auto r1 = topKFrequent(
        {"i", "love", "leetcode", "i", "love", "coding"}, 2);
    std::cout << "top:";
    for (const auto& w : r1) {
        std::cout << " " << w;
    }
    std::cout << " (expected i love)\n";

    const auto r2 = topKFrequent(
        {"the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"},
        4);
    std::cout << "top:";
    for (const auto& w : r2) {
        std::cout << " " << w;
    }
    std::cout << " (expected the is sunny day)\n";
    return 0;
}
