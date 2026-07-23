// Alien Dictionary — https://leetcode.com/problems/alien-dictionary/
// Infer letter order from sorted alien words; "" if invalid/cycle.
#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

std::string alienOrder(const std::vector<std::string>& words) {
    std::unordered_map<char, std::unordered_set<char>> g;
    std::unordered_map<char, int> indeg;
    for (const auto& w : words) {
        for (char c : w) {
            indeg.emplace(c, 0); // every letter appears
        }
    }
    for (size_t i = 0; i + 1 < words.size(); ++i) {
        const std::string& a = words[i];
        const std::string& b = words[i + 1];
        size_t j = 0;
        while (j < a.size() && j < b.size() && a[j] == b[j]) {
            ++j;
        }
        if (j == b.size() && j < a.size()) {
            return ""; // invalid: longer word before its prefix
        }
        if (j < a.size() && j < b.size()) {
            const char u = a[j];
            const char v = b[j];
            if (!g[u].count(v)) {
                g[u].insert(v); // u before v
                ++indeg[v];
            }
        }
    }
    std::queue<char> q;
    for (const auto& [c, d] : indeg) {
        if (d == 0) {
            q.push(c);
        }
    }
    std::string order;
    while (!q.empty()) {
        const char u = q.front();
        q.pop();
        order.push_back(u);
        for (char v : g[u]) {
            if (--indeg[v] == 0) {
                q.push(v);
            }
        }
    }
    return order.size() == indeg.size() ? order : ""; // cycle → ""
}

int main() {
    const std::vector<std::string> w = {"wrt", "wrf", "er", "ett", "rftt"};
    std::cout << "order: " << alienOrder(w) << " (e.g. wertf)\n";
    return 0;
}
