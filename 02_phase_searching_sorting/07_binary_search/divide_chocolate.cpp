// Divide Chocolate — https://leetcode.com/problems/divide-chocolate/
// sweetness of chunks in order; cut into k+1 contiguous parts; maximize the minimum part sum.
#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

bool canCut(const std::vector<int>& sweetness, int k, int minSum) {
    int parts = 0;
    int cur = 0;
    for (int s : sweetness) {
        cur += s;
        if (cur >= minSum) {
            ++parts;
            cur = 0;
        }
    }
    return parts >= k + 1; // you + k friends
}

int maximizeSweetness(const std::vector<int>& sweetness, int k) {
    int lo = *std::min_element(sweetness.begin(), sweetness.end());
    int hi = std::accumulate(sweetness.begin(), sweetness.end(), 0);
    int ans = lo;
    while (lo <= hi) {
        const int mid = lo + (hi - lo) / 2;
        if (canCut(sweetness, k, mid)) {
            ans = mid;
            lo = mid + 1; // maximize the minimum
        } else {
            hi = mid - 1;
        }
    }
    return ans;
}

int main() {
    std::cout << maximizeSweetness({1, 2, 3, 4, 5, 6, 7, 8, 9}, 5) << " (expected 6)\n"
              << maximizeSweetness({5, 6, 7, 8, 9, 1, 2, 3, 4}, 8) << " (expected 1)\n";
    return 0;
}
