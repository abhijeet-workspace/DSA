// Minimum Number of Operations to Reinitialize a Permutation —
// https://leetcode.com/problems/minimum-number-of-operations-to-reinitialize-a-permutation/
// Operation permutes indices; answer = cycle length of index 1 under i -> 2i mod (n-1).
#include <iostream>

int reinitializePermutation(int n) {
    if (n == 2)
        return 1;
    int ans = 0;
    int i = 1;
    do {
        i = (2 * i) % (n - 1);
        ++ans;
    } while (i != 1);
    return ans;
}

int main() {
    std::cout << reinitializePermutation(2) << " (expected 1)\n"
              << reinitializePermutation(4) << " (expected 2)\n"
              << reinitializePermutation(6) << " (expected 4)\n";
    return 0;
}
