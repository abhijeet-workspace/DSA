// Single-Threaded CPU — https://leetcode.com/problems/single-threaded-cpu/
// Sort by enqueue; min-heap of available tasks by (processingTime, index).
#include <algorithm>
#include <array>
#include <iostream>
#include <queue>
#include <vector>

std::vector<int> getOrder(std::vector<std::vector<int>>& tasks) {
    const int n = static_cast<int>(tasks.size());
    std::vector<std::array<long long, 3>> arr(static_cast<size_t>(n)); // enqueue, proc, idx
    for (int i = 0; i < n; ++i) {
        arr[static_cast<size_t>(i)] = {tasks[static_cast<size_t>(i)][0],
                                       tasks[static_cast<size_t>(i)][1], i};
    }
    std::sort(arr.begin(), arr.end());
    using P = std::pair<long long, int>; // proc, idx
    std::priority_queue<P, std::vector<P>, std::greater<P>> avail;
    std::vector<int> order;
    long long time = 0;
    int i = 0;
    while (static_cast<int>(order.size()) < n) {
        while (i < n && arr[static_cast<size_t>(i)][0] <= time) {
            avail.push(
                {arr[static_cast<size_t>(i)][1], static_cast<int>(arr[static_cast<size_t>(i)][2])});
            ++i;
        }
        if (avail.empty()) {
            time = arr[static_cast<size_t>(i)][0];
            continue;
        }
        auto [proc, idx] = avail.top();
        avail.pop();
        time += proc;
        order.push_back(idx);
    }
    return order;
}

int main() {
    std::vector<std::vector<int>> tasks = {{1, 2}, {2, 4}, {3, 2}, {4, 1}};
    auto o = getOrder(tasks);
    for (int x : o)
        std::cout << x << " ";
    std::cout << "(expected 0 2 3 1)\n";
    return 0;
}
