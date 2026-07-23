// Sliding Window Maximum — LC 239
// Monotonic decreasing deque of indices; front is always the max.
#include <iostream>
#include <vector>
#include <deque>

std::vector<int> maxSlidingWindow(const std::vector<int>& nums, int k) {
    const int n = static_cast<int>(nums.size());
    std::deque<int> dq; // indices, values decreasing
    std::vector<int> result;
    result.reserve(static_cast<size_t>(n - k + 1));
    for (int i = 0; i < n; ++i) {
        if (!dq.empty() && dq.front() == i - k) dq.pop_front(); // out of window
        while (!dq.empty() && nums[static_cast<size_t>(dq.back())] < nums[static_cast<size_t>(i)])
            dq.pop_back();
        dq.push_back(i);
        if (i >= k - 1) result.push_back(nums[static_cast<size_t>(dq.front())]);
    }
    return result;
}

int main() {
    auto result = maxSlidingWindow({1, 3, -1, -3, 5, 3, 6, 7}, 3);
    std::cout << "result:";
    for (int x : result) std::cout << " " << x;
    std::cout << " (expected 3 3 5 5 6 7)\n";
    return 0;
}
