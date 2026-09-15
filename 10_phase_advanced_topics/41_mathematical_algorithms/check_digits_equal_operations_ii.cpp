// Check If Digits Are Equal After Operations II — LC 3463
// Final digits = binomial convolution mod 10; Lucas(2)+Lucas(5)+CRT.
#include <iostream>
#include <string>

static int nCkSmall(int n, int k) {
    if (k < 0 || k > n)
        return 0;
    if (k > n - k)
        k = n - k;
    int res = 1;
    for (int i = 0; i < k; ++i) {
        res *= (n - i);
        res /= (i + 1);
    }
    return res;
}

static int lucas(int n, int k, int p) {
    int res = 1;
    while (n > 0 || k > 0) {
        const int ni = n % p;
        const int ki = k % p;
        if (ki > ni)
            return 0;
        res = (res * nCkSmall(ni, ki)) % p;
        n /= p;
        k /= p;
    }
    return res;
}

static int nCkMod10(int n, int k) {
    const int mod2 = lucas(n, k, 2);
    const int mod5 = lucas(n, k, 5);
    // CRT: unique x in [0,9] with x%2==mod2, x%5==mod5
    static constexpr int lookup[2][5] = {
        {0, 6, 2, 8, 4},
        {5, 1, 7, 3, 9},
    };
    return lookup[mod2][mod5];
}

bool hasSameDigits(const std::string& s) {
    const int n = static_cast<int>(s.size());
    int total = 0;
    for (int i = 0; i + 1 < n; ++i) {
        const int c = nCkMod10(n - 2, i);
        const int diff =
            ((s[static_cast<size_t>(i)] - s[static_cast<size_t>(i + 1)]) % 10 + 10) % 10;
        total = (total + c * diff) % 10;
    }
    return total == 0;
}

int main() {
    std::cout << std::boolalpha << hasSameDigits("3902") << " (expected true)\n"
              << hasSameDigits("34789") << " (expected false)\n";
    return 0;
}
