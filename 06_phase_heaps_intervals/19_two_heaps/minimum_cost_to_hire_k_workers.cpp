// Minimum Cost to Hire K Workers — https://leetcode.com/problems/minimum-cost-to-hire-k-workers/
// Sort by wage/quality ratio; maintain max-heap of qualities in window of size k.
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

double mincostToHireWorkers(const std::vector<int>& quality, const std::vector<int>& wage, int k) {
    const int n = static_cast<int>(quality.size());
    std::vector<std::pair<double, int>> workers; // ratio, quality
    workers.reserve(static_cast<size_t>(n));
    for (int i = 0; i < n; ++i) {
        workers.push_back({static_cast<double>(wage[static_cast<size_t>(i)]) /
                               static_cast<double>(quality[static_cast<size_t>(i)]),
                           quality[static_cast<size_t>(i)]});
    }
    std::sort(workers.begin(), workers.end()); // ascending ratio
    std::priority_queue<int> maxQual;          // drop highest quality when > k
    long long sumQual = 0;
    double best = 1e18;
    for (const auto& [ratio, q] : workers) {
        maxQual.push(q);
        sumQual += q;
        if (static_cast<int>(maxQual.size()) > k) {
            sumQual -= maxQual.top();
            maxQual.pop();
        }
        if (static_cast<int>(maxQual.size()) == k) {
            best = std::min(best, ratio * static_cast<double>(sumQual));
        }
    }
    return best;
}

int main() {
    std::cout.setf(std::ios::fixed);
    std::cout.precision(5);
    std::cout << mincostToHireWorkers({10, 20, 5}, {70, 50, 30}, 2) << " (expected 105.00000)\n"
              << mincostToHireWorkers({3, 1, 10, 10, 1}, {4, 8, 2, 2, 7}, 3)
              << " (expected 30.66667)\n";
    return 0;
}
