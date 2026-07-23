// Koko Eating Bananas — https://leetcode.com/problems/koko-eating-bananas/
// Binary search minimum speed k such that all piles finish within h hours.
#include <iostream>
#include <vector>
#include <algorithm>

bool canEatAll(const std::vector<int>& piles, int h, int k) {
    long long hours = 0;
    for (int pile : piles) {
        hours += (pile + k - 1LL) / k; // ceil(pile / k)
    }
    return hours <= h;
}

int minEatingSpeed(const std::vector<int>& piles, int h) {
    int low = 1;
    int high = *std::max_element(piles.begin(), piles.end());
    int ans = high;
    while (low <= high) {
        const int mid = low + (high - low) / 2;
        if (canEatAll(piles, h, mid)) {
            ans = mid;
            high = mid - 1; // try slower
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int main() {
    const std::vector<int> piles = {3, 6, 7, 11};
    std::cout << "Min Speed: " << minEatingSpeed(piles, 8) << " (expected 4)\n";
    return 0;
}
