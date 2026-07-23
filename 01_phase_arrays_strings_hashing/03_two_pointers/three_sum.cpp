// 3Sum — LC 15
// Sort, fix i, two-pointer search for pair summing to -nums[i]; skip dups.
#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::vector<int>> threeSum(std::vector<int> nums) {
    std::sort(nums.begin(), nums.end());
    std::vector<std::vector<int>> ans;
    int n = static_cast<int>(nums.size());
    for (int i = 0; i < n; ++i) {
        if (i > 0 && nums[static_cast<size_t>(i)] == nums[static_cast<size_t>(i - 1)]) continue;
        int L = i + 1, R = n - 1;
        while (L < R) {
            long long sum = static_cast<long long>(nums[static_cast<size_t>(i)])
                + nums[static_cast<size_t>(L)] + nums[static_cast<size_t>(R)];
            if (sum == 0) {
                ans.push_back({nums[static_cast<size_t>(i)], nums[static_cast<size_t>(L)],
                               nums[static_cast<size_t>(R)]});
                ++L; --R;
                while (L < R && nums[static_cast<size_t>(L)] == nums[static_cast<size_t>(L - 1)]) ++L;
                while (L < R && nums[static_cast<size_t>(R)] == nums[static_cast<size_t>(R + 1)]) --R;
            } else if (sum < 0) ++L;
            else --R;
        }
    }
    return ans;
}

int main() {
    auto ans = threeSum({-1, 0, 1, 2, -1, -4});
    std::cout << "triplets=" << ans.size() << " (expected 2)\n";
    for (const auto& t : ans) {
        std::cout << "  [" << t[0] << "," << t[1] << "," << t[2] << "]\n";
    }
    return 0;
}
