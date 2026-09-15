// Assign Cookies — https://leetcode.com/problems/assign-cookies/
// Greedily give smallest cookie that satisfies each child (sorted).
#include <algorithm>
#include <iostream>
#include <vector>

int findContentChildren(std::vector<int>& g, std::vector<int>& s) {
    std::sort(g.begin(), g.end());
    std::sort(s.begin(), s.end());
    int i = 0; // next child
    int j = 0; // next cookie
    const int n = static_cast<int>(g.size());
    const int m = static_cast<int>(s.size());
    while (i < n && j < m) {
        if (s[static_cast<size_t>(j)] >= g[static_cast<size_t>(i)]) {
            ++i; // child content
        }
        ++j; // cookie used (or too small)
    }
    return i;
}

int main() {
    std::vector<int> g1 = {1, 2, 3};
    std::vector<int> s1 = {1, 1};
    std::vector<int> g2 = {1, 2};
    std::vector<int> s2 = {1, 2, 3};
    std::cout << findContentChildren(g1, s1) << " (expected 1)\n"
              << findContentChildren(g2, s2) << " (expected 2)\n";
    return 0;
}
