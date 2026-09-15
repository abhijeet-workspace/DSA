// Circular Array Loop — https://leetcode.com/problems/circular-array-loop/
// Jump graph on indices; Floyd detect same-direction cycle of length > 1.
#include <iostream>
#include <vector>

int nextIndex(const std::vector<int>& nums, int i) {
    const int n = static_cast<int>(nums.size());
    long long j = static_cast<long long>(i) + nums[static_cast<size_t>(i)];
    j %= n;
    if (j < 0)
        j += n;
    return static_cast<int>(j);
}

bool circularArrayLoop(std::vector<int>& nums) {
    const int n = static_cast<int>(nums.size());
    for (int start = 0; start < n; ++start) {
        if (nums[static_cast<size_t>(start)] == 0)
            continue;

        int slow = start;
        int fast = start;
        const bool forward = nums[static_cast<size_t>(start)] > 0;

        auto ok = [&](int idx) {
            return nums[static_cast<size_t>(idx)] != 0 &&
                   ((nums[static_cast<size_t>(idx)] > 0) == forward);
        };

        while (true) {
            if (!ok(slow))
                break;
            slow = nextIndex(nums, slow);
            if (!ok(slow))
                break;

            if (!ok(fast))
                break;
            fast = nextIndex(nums, fast);
            if (!ok(fast))
                break;
            fast = nextIndex(nums, fast);
            if (!ok(fast))
                break;

            if (slow == fast) {
                if (nextIndex(nums, slow) != slow)
                    return true; // length > 1
                break;
            }
        }

        int j = start;
        while (ok(j)) {
            const int nxt = nextIndex(nums, j);
            nums[static_cast<size_t>(j)] = 0;
            j = nxt;
        }
    }
    return false;
}

int main() {
    std::vector<int> a = {2, -1, 1, 2, 2};
    std::vector<int> b = {-1, 2};
    std::vector<int> c = {-2, 1, -1, -2, -2};
    std::cout << std::boolalpha << circularArrayLoop(a) << " (expected true)\n"
              << circularArrayLoop(b) << " (expected false)\n"
              << circularArrayLoop(c) << " (expected false)\n";
    return 0;
}
