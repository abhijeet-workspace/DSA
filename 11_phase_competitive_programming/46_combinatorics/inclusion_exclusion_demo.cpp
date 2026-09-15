// Inclusion-exclusion union count — teaching
#include <iostream>
#include <numeric>
#include <vector>
long long countDivisible(long long N, const std::vector<long long>& mods) {
    const int m = (int)mods.size();
    long long ans = 0;
    for (int mask = 1; mask < (1 << m); ++mask) {
        long long l = 1;
        int bits = 0;
        bool overflow = false;
        for (int i = 0; i < m; ++i)
            if (mask & (1 << i)) {
                ++bits;
                long long g = std::gcd(l, mods[i]);
                if (l / g > N / mods[i]) {
                    overflow = true;
                    break;
                }
                l = (l / g) * mods[i];
            }
        if (overflow)
            continue;
        long long add = N / l;
        ans += (bits % 2 ? add : -add);
    }
    return ans;
}
int main() {
    std::cout << countDivisible(10, {2, 3, 5}) << " (expected 8)\n";
    return 0;
}
