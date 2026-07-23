// Aggressive Cows — maximize minimum distance between k cows in stalls.
// Binary search on answer over [1, maxStall - minStall] after sorting.
#include <iostream>
#include <vector>
#include <algorithm>

bool isPossible(const std::vector<int>& stalls, int k, int minDist) {
    int cowsPlaced = 1;
    int lastPos = stalls[0];
    for (size_t i = 1; i < stalls.size(); ++i) {
        if (stalls[i] - lastPos >= minDist) {
            ++cowsPlaced;
            lastPos = stalls[i];
            if (cowsPlaced == k) {
                return true;
            }
        }
    }
    return false;
}

int solveAggressiveCows(std::vector<int> stalls, int k) {
    std::sort(stalls.begin(), stalls.end());
    int low = 1;
    int high = stalls.back() - stalls.front();
    int ans = 0;
    while (low <= high) {
        const int mid = low + (high - low) / 2;
        if (isPossible(stalls, k, mid)) {
            ans = mid;
            low = mid + 1; // maximize min distance
        } else {
            high = mid - 1;
        }
    }
    return ans;
}

int main() {
    std::vector<int> stalls = {1, 2, 8, 4, 9};
    std::cout << "Max Min Distance: " << solveAggressiveCows(stalls, 3)
              << " (expected 3)\n";
    return 0;
}
