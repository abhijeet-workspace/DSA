// Sliding Window Median — https://leetcode.com/problems/sliding-window-median/
// Median of each size-k window; two multisets as balanced halves.
#include <iostream>
#include <set>
#include <vector>

class SlidingWindowMedian {
    std::multiset<int> low;  // lower half; max at rbegin
    std::multiset<int> high; // upper half; min at begin

    void balance() {
        if (low.size() > high.size() + 1) {
            high.insert(*low.rbegin());
            low.erase(std::prev(low.end()));
        } else if (low.size() < high.size()) {
            low.insert(*high.begin());
            high.erase(high.begin());
        }
    }

public:
    void add(int num) {
        if (low.empty() || num <= *low.rbegin()) {
            low.insert(num);
        } else {
            high.insert(num);
        }
        balance();
    }

    void remove(int num) {
        auto it = low.find(num);
        if (it != low.end()) {
            low.erase(it); // erase one occurrence
        } else {
            it = high.find(num);
            if (it != high.end()) {
                high.erase(it);
            }
        }
        balance();
    }

    double getMedian() const {
        if (low.size() > high.size()) {
            return static_cast<double>(*low.rbegin());
        }
        return (*low.rbegin() + *high.begin()) / 2.0;
    }
};

std::vector<double> medianSlidingWindow(const std::vector<int>& nums, int k) {
    SlidingWindowMedian swm;
    std::vector<double> result;
    result.reserve(nums.size() - static_cast<size_t>(k) + 1);
    for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
        swm.add(nums[static_cast<size_t>(i)]);
        if (i >= k - 1) {
            result.push_back(swm.getMedian());
            swm.remove(nums[static_cast<size_t>(i - k + 1)]); // slide out
        }
    }
    return result;
}

int main() {
    const std::vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    const int k = 3;
    const auto medians = medianSlidingWindow(nums, k);
    std::cout << "Medians:";
    for (double d : medians) {
        std::cout << " " << d;
    }
    std::cout << " (expected 1 -1 -1 3 5 6)\n";
    return 0;
}
