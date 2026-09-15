#include <iostream>
int countVowelPermutation(int n) {
    constexpr int MOD = 1'000'000'007;
    long long a = 1, e = 1, i = 1, o = 1, u = 1;
    for (int len = 1; len < n; ++len) {
        long long na = (e + i + u) % MOD, ne = (a + i) % MOD, ni = (e + o) % MOD, no = i,
                  nu = (i + o) % MOD;
        a = na;
        e = ne;
        i = ni;
        o = no;
        u = nu;
    }
    return (int)((a + e + i + o + u) % MOD);
}
int main() {
    std::cout << "v(1)=" << countVowelPermutation(1)
              << " (expected 5)\nv(2)=" << countVowelPermutation(2) << " (expected 10)\n";
    return 0;
}
