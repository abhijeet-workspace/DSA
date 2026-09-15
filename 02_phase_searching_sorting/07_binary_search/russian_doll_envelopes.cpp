// Russian Doll Envelopes — https://leetcode.com/problems/russian-doll-envelopes/
// Sort by width asc, height desc on ties; LIS on heights (strict) via patience tails.
#include <algorithm>
#include <iostream>
#include <vector>

int maxEnvelopes(std::vector<std::vector<int>>& envelopes) {
    std::sort(envelopes.begin(), envelopes.end(),
              [](const std::vector<int>& a, const std::vector<int>& b) {
                  if (a[0] != b[0]) {
                      return a[0] < b[0];
                  }
                  return a[1] > b[1]; // same width: decreasing height
              });
    std::vector<int> tails;
    for (const auto& e : envelopes) {
        const int h = e[1];
        auto it = std::lower_bound(tails.begin(), tails.end(), h);
        if (it == tails.end()) {
            tails.push_back(h);
        } else {
            *it = h;
        }
    }
    return static_cast<int>(tails.size());
}

int main() {
    std::vector<std::vector<int>> a = {{5, 4}, {6, 4}, {6, 7}, {2, 3}};
    std::vector<std::vector<int>> b = {{1, 1}, {1, 1}, {1, 1}};
    std::cout << maxEnvelopes(a) << " (expected 3)\n" << maxEnvelopes(b) << " (expected 1)\n";
    return 0;
}
