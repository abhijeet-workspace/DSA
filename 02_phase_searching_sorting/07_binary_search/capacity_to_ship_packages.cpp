// Capacity To Ship Packages Within D Days —
// https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/ Minimize max daily
// capacity so weights ship in <= days, preserving order.
#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

bool canShip(const std::vector<int>& weights, int days, int cap) {
    int used = 1;
    int load = 0;
    for (int w : weights) {
        if (load + w > cap) {
            ++used;
            load = 0;
        }
        load += w;
        if (used > days) {
            return false;
        }
    }
    return true;
}

int shipWithinDays(const std::vector<int>& weights, int days) {
    int lo = *std::max_element(weights.begin(), weights.end());
    int hi = std::accumulate(weights.begin(), weights.end(), 0);
    int ans = hi;
    while (lo <= hi) {
        const int mid = lo + (hi - lo) / 2;
        if (canShip(weights, days, mid)) {
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    return ans;
}

int main() {
    std::cout << shipWithinDays({1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 5) << " (expected 15)\n"
              << shipWithinDays({3, 2, 2, 4, 1, 4}, 3) << " (expected 6)\n";
    return 0;
}
