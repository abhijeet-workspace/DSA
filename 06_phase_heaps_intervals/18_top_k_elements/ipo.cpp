// IPO — https://leetcode.com/problems/ipo/
// Do at most k projects: min-heap by capital unlock, max-heap by profit pick.
#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

int findMaximizedCapital(int k, int w, const std::vector<int>& profits,
                         const std::vector<int>& capital) {
    const int n = static_cast<int>(profits.size());
    std::vector<std::pair<int, int>> projects; // capital, profit
    projects.reserve(static_cast<size_t>(n));
    for (int i = 0; i < n; ++i) {
        projects.push_back({capital[static_cast<size_t>(i)],
                            profits[static_cast<size_t>(i)]});
    }
    std::sort(projects.begin(), projects.end()); // unlock order by capital
    std::priority_queue<int> max_profit; // affordable profits
    int i = 0;
    for (int done = 0; done < k; ++done) {
        while (i < n && projects[static_cast<size_t>(i)].first <= w) {
            max_profit.push(projects[static_cast<size_t>(i)].second);
            ++i;
        }
        if (max_profit.empty()) {
            break; // nothing affordable
        }
        w += max_profit.top();
        max_profit.pop();
    }
    return w;
}

int main() {
    std::cout << findMaximizedCapital(2, 0, {1, 2, 3}, {0, 1, 1})
              << " (expected 4)\n";
    std::cout << findMaximizedCapital(3, 0, {1, 2, 3}, {0, 1, 2})
              << " (expected 6)\n";
    return 0;
}
