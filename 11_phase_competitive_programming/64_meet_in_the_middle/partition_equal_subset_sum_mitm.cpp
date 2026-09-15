// Partition Equal Subset Sum — MITM angle (LC 416 usually DP)
#include <algorithm>
#include <iostream>
#include <vector>

bool canPartitionMITM(std::vector<int> nums) {
    long long S = 0;
    for (int x : nums)
        S += x;
    if (S % 2)
        return false;
    long long T = S / 2;
    int n = (int)nums.size();
    std::vector<int> L(nums.begin(), nums.begin() + n / 2);
    std::vector<int> R(nums.begin() + n / 2, nums.end());
    auto enumS = [](const std::vector<int>& a) {
        std::vector<long long> out(1 << a.size());
        for (int m = 0; m < (1 << (int)a.size()); ++m) {
            long long s = 0;
            for (int i = 0; i < (int)a.size(); ++i)
                if (m & (1 << i))
                    s += a[i];
            out[m] = s;
        }
        return out;
    };
    auto sumsL = enumS(L), sumsR = enumS(R);
    std::sort(sumsR.begin(), sumsR.end());
    for (long long s : sumsL)
        if (std::binary_search(sumsR.begin(), sumsR.end(), T - s))
            return true;
    return false;
}

int main() {
    std::cout << std::boolalpha << canPartitionMITM({1, 5, 11, 5}) << " (expected true)\n";
    std::cout << canPartitionMITM({1, 2, 3, 5}) << " (expected false)\n";
    return 0;
}
