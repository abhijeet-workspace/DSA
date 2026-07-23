// Partition Labels — https://leetcode.com/problems/partition-labels/
// Extend each window to the farthest last-occurrence of chars inside it.
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

std::vector<int> partitionLabels(const std::string& s) {
    int last[26]{};
    for (int i = 0; i < static_cast<int>(s.size()); ++i) {
        last[s[static_cast<size_t>(i)] - 'a'] = i;
    }
    std::vector<int> ans;
    int start = 0, end = 0;
    for (int i = 0; i < static_cast<int>(s.size()); ++i) {
        end = std::max(end, last[s[static_cast<size_t>(i)] - 'a']);
        if (i == end) { // closed a partition
            ans.push_back(end - start + 1);
            start = i + 1;
        }
    }
    return ans;
}

int main() {
    for (int x : partitionLabels("ababcbacadefegdehijhklij")) {
        std::cout << x << " ";
    }
    std::cout << "(expected 9 7 8)\n";
    return 0;
}
