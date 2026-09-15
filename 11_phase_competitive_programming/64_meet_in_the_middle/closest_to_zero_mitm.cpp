// Closest nonempty subset sum to zero — MITM
#include <algorithm>
#include <iostream>
#include <vector>

void enumSums(const std::vector<int>& a, std::vector<long long>& out) {
    const int n = static_cast<int>(a.size());
    out.resize(1 << n);
    for (int m = 0; m < (1 << n); ++m) {
        long long s = 0;
        for (int i = 0; i < n; ++i) {
            if (m & (1 << i))
                s += a[static_cast<size_t>(i)];
        }
        out[static_cast<size_t>(m)] = s;
    }
}

long long closestToZero(const std::vector<int>& arr) {
    const int n = static_cast<int>(arr.size());
    std::vector<int> L(arr.begin(), arr.begin() + n / 2);
    std::vector<int> R(arr.begin() + n / 2, arr.end());
    std::vector<long long> sumsL, sumsR;
    enumSums(L, sumsL);
    enumSums(R, sumsR);
    std::sort(sumsR.begin(), sumsR.end());

    long long best = llabs(arr[0]);
    for (int ml = 0; ml < static_cast<int>(sumsL.size()); ++ml) {
        const long long s = sumsL[static_cast<size_t>(ml)];
        // left nonempty, right empty
        if (ml != 0)
            best = std::min(best, llabs(s));

        const long long need = -s;
        auto it = std::lower_bound(sumsR.begin(), sumsR.end(), need);
        auto consider = [&](long long t, int mrHintEmpty) {
            if (ml == 0 && mrHintEmpty)
                return; // skip empty+empty
            best = std::min(best, llabs(s + t));
        };
        if (it != sumsR.end()) {
            consider(*it, *it == 0);
        }
        if (it != sumsR.begin()) {
            --it;
            consider(*it, *it == 0);
        }
    }
    // left empty, right nonempty
    for (size_t mr = 1; mr < sumsR.size(); ++mr) {
        best = std::min(best, llabs(sumsR[mr]));
    }
    // also any single zero
    for (int x : arr) {
        if (x == 0)
            return 0;
    }
    return best;
}

int main() {
    std::cout << closestToZero({1, -1, 2}) << " (expected 0)\n";
    std::cout << closestToZero({2, 3, 5}) << " (expected 2)\n";
    return 0;
}
