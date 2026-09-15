// Maximum Length of a Concatenated String with Unique Characters
// https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/
#include <iostream>
#include <string>
#include <vector>

int bitMask(const std::string& s) {
    int mask = 0;
    for (char c : s) {
        const int b = 1 << (c - 'a');
        if (mask & b)
            return -1; // duplicate inside word
        mask |= b;
    }
    return mask;
}

void dfs(const std::vector<int>& masks, const std::vector<int>& lens, int i, int used, int curLen,
         int& best) {
    best = std::max(best, curLen);
    for (int j = i; j < static_cast<int>(masks.size()); ++j) {
        if (masks[static_cast<size_t>(j)] < 0)
            continue;
        if (used & masks[static_cast<size_t>(j)])
            continue;
        dfs(masks, lens, j + 1, used | masks[static_cast<size_t>(j)],
            curLen + lens[static_cast<size_t>(j)], best);
    }
}

int maxLength(const std::vector<std::string>& arr) {
    std::vector<int> masks, lens;
    for (const auto& s : arr) {
        masks.push_back(bitMask(s));
        lens.push_back(static_cast<int>(s.size()));
    }
    int best = 0;
    dfs(masks, lens, 0, 0, 0, best);
    return best;
}

int main() {
    std::cout << maxLength({"un", "iq", "ue"}) << " (expected 4)\n";
    std::cout << maxLength({"cha", "r", "act", "ers"}) << " (expected 6)\n";
    return 0;
}
