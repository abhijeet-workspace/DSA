// Sort Characters By Frequency — LC 451
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

std::string frequencySort(const std::string& s) {
    int freq[128] = {};
    for (unsigned char c : s)
        ++freq[c];
    std::vector<std::pair<int, char>> items;
    for (int c = 0; c < 128; ++c)
        if (freq[c])
            items.push_back({freq[c], static_cast<char>(c)});
    std::sort(items.begin(), items.end(), [](const auto& a, const auto& b) {
        if (a.first != b.first)
            return a.first > b.first;
        return a.second < b.second;
    });
    std::string ans;
    ans.reserve(s.size());
    for (auto [f, ch] : items)
        ans.append(static_cast<size_t>(f), ch);
    return ans;
}

int main() {
    std::cout << frequencySort("tree") << " (expected eert or eetr)\n";
    std::cout << frequencySort("cccaaa") << " (expected cccaaa or aaaccc)\n";
    return 0;
}
