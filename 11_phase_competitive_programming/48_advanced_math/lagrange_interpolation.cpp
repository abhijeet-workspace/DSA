#include <iostream>
#include <vector>
long long lagrangeEval(const std::vector<long long>& y, long long x) {
    int k = y.size();
    long long ans = 0;
    for (int i = 0; i < k; ++i) {
        long long num = 1, den = 1;
        for (int j = 0; j < k; ++j)
            if (j != i) {
                num *= (x - j);
                den *= (i - j);
            }
        ans += y[i] * num / den;
    }
    return ans;
}
int main() {
    std::cout << "P3=" << lagrangeEval({1, 2, 4}, 3) << " (expected 7)\n";
    return 0;
}
