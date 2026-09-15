// Count subset sum — meet in the middle
#include <iostream>
#include <unordered_map>
#include <vector>

void enumSums(const std::vector<int>& a, std::vector<long long>& out) {
    int n = (int)a.size();
    out.resize(1 << n);
    for (int m = 0; m < (1 << n); ++m) {
        long long s = 0;
        for (int i = 0; i < n; ++i)
            if (m & (1 << i))
                s += a[i];
        out[m] = s;
    }
}

long long countSubsetSum(const std::vector<int>& arr, long long target) {
    int n = (int)arr.size();
    std::vector<int> L(arr.begin(), arr.begin() + n / 2);
    std::vector<int> R(arr.begin() + n / 2, arr.end());
    std::vector<long long> sumsL, sumsR;
    enumSums(L, sumsL);
    enumSums(R, sumsR);
    std::unordered_map<long long, long long> freq;
    for (auto s : sumsR)
        ++freq[s];
    long long ans = 0;
    for (auto s : sumsL) {
        auto it = freq.find(target - s);
        if (it != freq.end())
            ans += it->second;
    }
    return ans;
}

int main() {
    std::cout << countSubsetSum({1, 1, 1}, 2) << " (expected 3)\n";
    return 0;
}
