// Total Cost to Hire K Workers — https://leetcode.com/problems/total-cost-to-hire-k-workers/
// Two min-heaps for left/right candidate windows of size candidates.
#include <iostream>
#include <queue>
#include <vector>

long long totalCost(std::vector<int>& costs, int k, int candidates) {
    const int n = static_cast<int>(costs.size());
    using P = std::pair<int, int>; // cost, index
    std::priority_queue<P, std::vector<P>, std::greater<P>> left, right;
    int l = 0;
    int r = n - 1;
    for (int i = 0; i < candidates && l <= r; ++i) {
        left.push({costs[static_cast<size_t>(l)], l});
        ++l;
    }
    for (int i = 0; i < candidates && l <= r; ++i) {
        right.push({costs[static_cast<size_t>(r)], r});
        --r;
    }
    long long ans = 0;
    for (int hired = 0; hired < k; ++hired) {
        if (right.empty() || (!left.empty() && left.top() <= right.top())) {
            ans += left.top().first;
            left.pop();
            if (l <= r) {
                left.push({costs[static_cast<size_t>(l)], l});
                ++l;
            }
        } else {
            ans += right.top().first;
            right.pop();
            if (l <= r) {
                right.push({costs[static_cast<size_t>(r)], r});
                --r;
            }
        }
    }
    return ans;
}

int main() {
    std::vector<int> a = {17, 12, 10, 2, 7, 2, 11, 20, 8};
    std::cout << totalCost(a, 3, 4) << " (expected 11)\n";
    std::vector<int> b = {1, 2, 4, 1};
    std::cout << totalCost(b, 3, 3) << " (expected 4)\n";
    return 0;
}
