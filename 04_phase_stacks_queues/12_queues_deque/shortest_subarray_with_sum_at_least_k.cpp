// Shortest Subarray with Sum at Least K —
// https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/ Prefix sums + increasing
// deque of indices; negatives break plain sliding window.
#include <algorithm>
#include <climits>
#include <deque>
#include <iostream>
#include <vector>

int shortestSubarray(const std::vector<int>& nums, int k) {
    const int n = static_cast<int>(nums.size());
    std::vector<long long> prefix(static_cast<size_t>(n + 1), 0);
    for (int i = 0; i < n; ++i) {
        prefix[static_cast<size_t>(i + 1)] =
            prefix[static_cast<size_t>(i)] + nums[static_cast<size_t>(i)];
    }
    std::deque<int> dq; // indices with increasing prefix
    int best = INT_MAX;
    for (int j = 0; j <= n; ++j) {
        while (!dq.empty() &&
               prefix[static_cast<size_t>(j)] - prefix[static_cast<size_t>(dq.front())] >= k) {
            best = std::min(best, j - dq.front());
            dq.pop_front();
        }
        while (!dq.empty() &&
               prefix[static_cast<size_t>(dq.back())] >= prefix[static_cast<size_t>(j)]) {
            dq.pop_back(); // later j is better start for same/worse prefix
        }
        dq.push_back(j);
    }
    return best == INT_MAX ? -1 : best;
}

int main() {
    std::cout << shortestSubarray({1}, 1) << " (expected 1)\n";
    std::cout << shortestSubarray({1, 2}, 4) << " (expected -1)\n";
    std::cout << shortestSubarray({2, -1, 2}, 3) << " (expected 3)\n";
    return 0;
}
