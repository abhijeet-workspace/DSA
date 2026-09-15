// Stars and bars — teaching
#include <iostream>
long long C(int n, int k) {
    if (k < 0 || k > n)
        return 0;
    long long ans = 1;
    for (int i = 1; i <= k; ++i)
        ans = ans * (n - k + i) / i;
    return ans;
}
long long nonNegSolutions(int n, int k) {
    return C(n + k - 1, k - 1);
}
long long positiveSolutions(int n, int k) {
    return C(n - 1, k - 1);
}
int main() {
    std::cout << nonNegSolutions(5, 3) << " (expected 21)\n";
    std::cout << positiveSolutions(5, 3) << " (expected 6)\n";
    return 0;
}
