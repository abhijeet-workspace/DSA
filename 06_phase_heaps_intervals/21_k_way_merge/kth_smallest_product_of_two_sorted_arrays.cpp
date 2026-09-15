// Kth Smallest Product of Two Sorted Arrays —
// https://leetcode.com/problems/kth-smallest-product-of-two-sorted-arrays/ Binary search on product
// value; count pairs with nums1[i]*nums2[j] <= mid.
#include <iostream>
#include <vector>

long long kthSmallestProduct(std::vector<int>& nums1, std::vector<int>& nums2, long long k) {
    auto countLE = [&](long long x) -> long long {
        long long cnt = 0;
        for (int a : nums1) {
            if (a == 0) {
                if (x >= 0) {
                    cnt += static_cast<long long>(nums2.size());
                }
                continue;
            }
            if (a > 0) {
                int lo = 0;
                int hi = static_cast<int>(nums2.size());
                while (lo < hi) {
                    const int mid = (lo + hi) / 2;
                    if (1LL * a * nums2[static_cast<size_t>(mid)] <= x) {
                        lo = mid + 1;
                    } else {
                        hi = mid;
                    }
                }
                cnt += lo;
            } else {
                int lo = 0;
                int hi = static_cast<int>(nums2.size());
                while (lo < hi) {
                    const int mid = (lo + hi) / 2;
                    if (1LL * a * nums2[static_cast<size_t>(mid)] <= x) {
                        hi = mid;
                    } else {
                        lo = mid + 1;
                    }
                }
                cnt += static_cast<long long>(nums2.size()) - lo;
            }
        }
        return cnt;
    };

    long long lo = -100000000000LL; // -1e11
    long long hi = 100000000000LL;  // 1e11
    while (lo < hi) {
        const long long mid = lo + (hi - lo) / 2;
        if (countLE(mid) >= k) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    return lo;
}

int main() {
    std::vector<int> a = {2, 5};
    std::vector<int> b = {3, 4};
    std::cout << kthSmallestProduct(a, b, 2) << " (expected 8)\n";
    std::vector<int> c = {-4, -2, 0, 3};
    std::vector<int> d = {2, 4};
    std::cout << kthSmallestProduct(c, d, 6) << " (expected 0)\n";
    return 0;
}
