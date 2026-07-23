// Sliding Window Maximum — https://leetcode.com/problems/sliding-window-maximum/
// Return max of each contiguous window of size k.
#include <iostream>
#include <vector>
#include <deque>

std::vector<int> maxSlidingWindow(const std::vector<int>& nums, int k) {
    std::deque<int> dq; // indices, nums decreasing front→back
    std::vector<int> result;
    for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
        if (!dq.empty() && dq.front() == i - k) {
            dq.pop_front(); // leave window
        }
        while (!dq.empty() && nums[static_cast<size_t>(dq.back())] < nums[static_cast<size_t>(i)]) {
            dq.pop_back(); // smaller than nums[i] cannot be max
        }
        dq.push_back(i);
        if (i >= k - 1) {
            result.push_back(nums[static_cast<size_t>(dq.front())]);
        }
    }
    return result;
}

int main() {
    const std::vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    const auto res = maxSlidingWindow(nums, 3);
    std::cout << "Max sliding windows:";
    for (int x : res) {
        std::cout << ' ' << x;
    }
    std::cout << " (expected 3 3 5 5 6 7)\n";
    return 0;
}
