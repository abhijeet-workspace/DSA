#include <iostream>
#include <vector>
long long kitamasaFib(long long n) {
    if (n == 0)
        return 0;
    auto mul = [](std::vector<long long> a, std::vector<long long> b) {
        std::vector<long long> r(3);
        for (int i = 0; i < 2; ++i)
            for (int j = 0; j < 2; ++j)
                r[i + j] += a[i] * b[j];
        r[1] += r[2];
        r[0] += r[2];
        r.pop_back();
        return r;
    };
    std::vector<long long> res = {1, 0}, base = {0, 1};
    while (n) {
        if (n & 1)
            res = mul(res, base);
        base = mul(base, base);
        n >>= 1;
    }
    return res[1];
}
int main() {
    std::cout << "F10=" << kitamasaFib(10) << " (expected 55)\nF20=" << kitamasaFib(20)
              << " (expected 6765)\n";
    return 0;
}
