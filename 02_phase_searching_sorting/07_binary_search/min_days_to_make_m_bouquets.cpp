// Minimum Number of Days to Make m Bouquets —
// https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/ Adjacent flowers;
// bloomDay[i] is the day flower i blooms. Min day to make m bouquets of k adjacent.
#include <algorithm>
#include <iostream>
#include <vector>

bool canMake(const std::vector<int>& bloomDay, int m, int k, int day) {
    int bouquets = 0;
    int streak = 0;
    for (int d : bloomDay) {
        if (d <= day) {
            ++streak;
            if (streak == k) {
                ++bouquets;
                streak = 0;
            }
        } else {
            streak = 0;
        }
    }
    return bouquets >= m;
}

int minDays(const std::vector<int>& bloomDay, int m, int k) {
    const long long need = 1LL * m * k;
    if (need > static_cast<long long>(bloomDay.size())) {
        return -1;
    }
    int lo = *std::min_element(bloomDay.begin(), bloomDay.end());
    int hi = *std::max_element(bloomDay.begin(), bloomDay.end());
    int ans = -1;
    while (lo <= hi) {
        const int mid = lo + (hi - lo) / 2;
        if (canMake(bloomDay, m, k, mid)) {
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    return ans;
}

int main() {
    std::cout << minDays({1, 10, 3, 10, 2}, 3, 1) << " (expected 3)\n"
              << minDays({1, 10, 3, 10, 2}, 3, 2) << " (expected -1)\n";
    return 0;
}
