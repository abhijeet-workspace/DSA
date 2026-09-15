// Maximum Performance of a Team — https://leetcode.com/problems/maximum-performance-of-a-team/
// Sort by efficiency desc; min-heap of speeds for top-k; track speed sum * min efficiency.
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

int maxPerformance(int n, std::vector<int>& speed, std::vector<int>& efficiency, int k) {
    std::vector<std::pair<int, int>> eng; // efficiency, speed
    for (int i = 0; i < n; ++i) {
        eng.push_back({efficiency[static_cast<size_t>(i)], speed[static_cast<size_t>(i)]});
    }
    std::sort(eng.rbegin(), eng.rend()); // high efficiency first
    std::priority_queue<int, std::vector<int>, std::greater<int>> minSpeed;
    long long sum = 0, best = 0;
    const int MOD = 1'000'000'007;
    for (auto [eff, sp] : eng) {
        minSpeed.push(sp);
        sum += sp;
        if (static_cast<int>(minSpeed.size()) > k) {
            sum -= minSpeed.top();
            minSpeed.pop();
        }
        best = std::max(best, sum * eff);
    }
    return static_cast<int>(best % MOD);
}

int main() {
    std::vector<int> speed = {2, 10, 3, 1, 5, 8};
    std::vector<int> efficiency = {5, 4, 3, 9, 7, 2};
    std::cout << maxPerformance(6, speed, efficiency, 2) << " (expected 60)\n";
    return 0;
}
