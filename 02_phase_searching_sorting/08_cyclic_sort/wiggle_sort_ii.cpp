// Wiggle Sort II — https://leetcode.com/problems/wiggle-sort-ii/
// Median + virtual index map A(i)=(1+2i)%(n|1) + Dutch partition into wiggle slots.
#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

void wiggleSort(std::vector<int>& nums) {
    const int n = static_cast<int>(nums.size());
    if (n <= 1)
        return;
    auto midIt = nums.begin() + n / 2;
    std::nth_element(nums.begin(), midIt, nums.end());
    const int mid = *midIt;

    auto A = [n](int i) { return (1 + 2 * i) % (n | 1); };

    int i = 0, j = 0, k = n - 1;
    while (j <= k) {
        if (nums[static_cast<size_t>(A(j))] > mid) {
            std::swap(nums[static_cast<size_t>(A(i))], nums[static_cast<size_t>(A(j))]);
            ++i;
            ++j;
        } else if (nums[static_cast<size_t>(A(j))] < mid) {
            std::swap(nums[static_cast<size_t>(A(j))], nums[static_cast<size_t>(A(k))]);
            --k;
        } else {
            ++j;
        }
    }
}

bool isWiggle(const std::vector<int>& a) {
    for (size_t i = 0; i + 1 < a.size(); ++i) {
        if (i % 2 == 0) {
            if (!(a[i] < a[i + 1]))
                return false;
        } else {
            if (!(a[i] > a[i + 1]))
                return false;
        }
    }
    return true;
}

int main() {
    std::vector<int> nums = {1, 5, 1, 1, 6, 4};
    wiggleSort(nums);
    for (int x : nums)
        std::cout << x << ' ';
    std::cout << (isWiggle(nums) ? "(wiggle ok)\n" : "(wiggle FAILED)\n");
    return 0;
}
