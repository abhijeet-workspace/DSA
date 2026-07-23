// Group Anagrams — LC 49
// Canonical key = sorted string; map key → list of anagrams.
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string> strs) {
    std::unordered_map<std::string, std::vector<std::string>> groups;
    for (const std::string& s : strs) {
        std::string key = s;
        std::sort(key.begin(), key.end()); // same multiset → same key
        groups[key].push_back(s);
    }
    std::vector<std::vector<std::string>> result;
    result.reserve(groups.size());
    for (auto& [_, list] : groups) result.push_back(std::move(list));
    return result;
}

int main() {
    auto groups = groupAnagrams({"eat", "tea", "tan", "ate", "nat", "bat"});
    std::cout << "groups=" << groups.size() << " (expected 3)\n";
    for (const auto& g : groups) {
        std::cout << "  [";
        for (size_t i = 0; i < g.size(); ++i)
            std::cout << g[i] << (i + 1 < g.size() ? "," : "");
        std::cout << "]\n";
    }
    return 0;
}
