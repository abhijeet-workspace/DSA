// First Negative Integer in Every Window of Size K
// For each window of size k, return the first negative (0 if none).
#include <iostream>
#include <vector>
#include <deque>

std::vector<int> firstNegative(const std::vector<int>& arr, int k) {
    std::deque<int> dq; // indices of negatives in window order
    std::vector<int> res;
    for (int i = 0; i < static_cast<int>(arr.size()); ++i) {
        if (!dq.empty() && dq.front() == i - k) {
            dq.pop_front(); // leave window
        }
        if (arr[static_cast<size_t>(i)] < 0) {
            dq.push_back(i);
        }
        if (i >= k - 1) {
            res.push_back(dq.empty() ? 0 : arr[static_cast<size_t>(dq.front())]);
        }
    }
    return res;
}

int main() {
    const std::vector<int> arr = {12, -1, -7, 8, -15, 30, 16, 28};
    const auto res = firstNegative(arr, 3);
    std::cout << "First negatives:";
    for (int x : res) {
        std::cout << ' ' << x;
    }
    std::cout << " (expected -1 -1 -7 -15 -15 0)\n";
    return 0;
}
