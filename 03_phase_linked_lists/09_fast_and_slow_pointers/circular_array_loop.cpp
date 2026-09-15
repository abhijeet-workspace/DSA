// Circular Array Loop — https://leetcode.com/problems/circular-array-loop/
// True if a same-direction cycle of length > 1 exists in the circular jump array.
#include <iostream>
#include <vector>

int nextIndex(const std::vector<int>& nums, int i) {
    const int n = static_cast<int>(nums.size());
    long long j = static_cast<long long>(i) + nums[i];
    j %= n;
    if (j < 0) {
        j += n;
    }
    return static_cast<int>(j);
}

bool circularArrayLoop(std::vector<int>& nums) {
    const int n = static_cast<int>(nums.size());
    for (int i = 0; i < n; ++i) {
        if (nums[i] == 0) {
            continue;
        }
        int slow = i;
        int fast = i;
        const bool forward = nums[i] > 0;
        while (true) {
            slow = nextIndex(nums, slow);
            if ((nums[slow] > 0) != forward || nextIndex(nums, slow) == slow) {
                break;
            }
            fast = nextIndex(nums, fast);
            if ((nums[fast] > 0) != forward || nextIndex(nums, fast) == fast) {
                break;
            }
            fast = nextIndex(nums, fast);
            if ((nums[fast] > 0) != forward || nextIndex(nums, fast) == fast) {
                break;
            }
            if (slow == fast) {
                return true;
            }
        }
        int j = i;
        const int dir = nums[i] > 0 ? 1 : -1;
        while ((nums[j] > 0 ? 1 : -1) == dir && nums[j] != 0) {
            const int nxt = nextIndex(nums, j);
            nums[j] = 0; // mark visited
            j = nxt;
        }
    }
    return false;
}

int main() {
    std::vector<int> a{2, -1, 1, 2, 2};
    std::cout << std::boolalpha << circularArrayLoop(a) << " (expected true)\n";
    std::vector<int> b{-1, 2};
    std::cout << circularArrayLoop(b) << " (expected false)\n";
    return 0;
}
