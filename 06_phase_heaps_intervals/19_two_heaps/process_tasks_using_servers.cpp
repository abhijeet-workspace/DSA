// Process Tasks Using Servers — https://leetcode.com/problems/process-tasks-using-servers/
// Free servers min-heap (weight, index); busy min-heap (freeTime, weight, index).
#include <algorithm>
#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

std::vector<int> assignTasks(std::vector<int>& servers, std::vector<int>& tasks) {
    using Free = std::pair<int, int>;             // weight, index
    using Busy = std::tuple<long long, int, int>; // freeTime, weight, index
    std::priority_queue<Free, std::vector<Free>, std::greater<Free>> free;
    std::priority_queue<Busy, std::vector<Busy>, std::greater<Busy>> busy;
    for (int i = 0; i < static_cast<int>(servers.size()); ++i) {
        free.push({servers[static_cast<size_t>(i)], i});
    }
    std::vector<int> ans(tasks.size());
    long long t = 0;
    for (int j = 0; j < static_cast<int>(tasks.size()); ++j) {
        t = std::max(t, static_cast<long long>(j));
        if (free.empty()) {
            t = std::max(t, std::get<0>(busy.top()));
        }
        while (!busy.empty() && std::get<0>(busy.top()) <= t) {
            auto [ft, w, i] = busy.top();
            busy.pop();
            (void)ft;
            free.push({w, i});
        }
        auto [w, i] = free.top();
        free.pop();
        ans[static_cast<size_t>(j)] = i;
        busy.push({t + tasks[static_cast<size_t>(j)], w, i});
    }
    return ans;
}

int main() {
    std::vector<int> servers = {3, 3, 2};
    std::vector<int> tasks = {1, 2, 3, 2, 1, 2};
    auto a = assignTasks(servers, tasks);
    for (int x : a)
        std::cout << x << " ";
    std::cout << "(expected 2 2 0 2 1 2)\n";
    return 0;
}
