// LC372 Super Pow — a^b mod 1337, b as digit array
#include <iostream>
#include <vector>

int modPow(int x, int k, int mod = 1337) {
    long long base = x % mod, ans = 1;
    while (k > 0) {
        if (k & 1)
            ans = ans * base % mod;
        base = base * base % mod;
        k >>= 1;
    }
    return static_cast<int>(ans);
}

int superPow(int a, const std::vector<int>& b) {
    int ans = 1;
    for (int d : b) {
        ans = modPow(ans, 10) * 1LL * modPow(a, d) % 1337;
    }
    return ans;
}

int main() {
    std::cout << "superPow(2,[3])=" << superPow(2, {3}) << " (expected 8)\n";
    std::cout << "superPow(2,[1,0])=" << superPow(2, {1, 0}) << " (expected 1024)\n";
    return 0;
}
