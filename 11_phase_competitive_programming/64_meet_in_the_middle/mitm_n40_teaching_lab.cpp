// MITM n<=40 subset-sum teaching lab (precise statement; no contest ID)
#include <algorithm>
#include <iostream>
#include <vector>

bool subsetSumMITM(const std::vector<long long>& a, long long T) {
    int n = (int)a.size();
    int mid = n / 2;
    std::vector<long long> L, R;
    int nL = mid, nR = n - mid;
    L.resize(1 << nL);
    R.resize(1 << nR);
    for (int m = 0; m < (1 << nL); ++m) {
        long long s = 0;
        for (int i = 0; i < nL; ++i)
            if (m & (1 << i))
                s += a[i];
        L[m] = s;
    }
    for (int m = 0; m < (1 << nR); ++m) {
        long long s = 0;
        for (int i = 0; i < nR; ++i)
            if (m & (1 << i))
                s += a[mid + i];
        R[m] = s;
    }
    std::sort(R.begin(), R.end());
    for (long long s : L)
        if (std::binary_search(R.begin(), R.end(), T - s))
            return true;
    return false;
}

int main() {
    // Statement sample: n=6, T=9
    std::vector<long long> a = {3, 34, 4, 12, 5, 2};
    std::cout << (subsetSumMITM(a, 9) ? "YES" : "NO") << " (expected YES)\n";
    std::cout << (subsetSumMITM(a, 30) ? "YES" : "NO") << " (expected NO)\n";
    return 0;
}
