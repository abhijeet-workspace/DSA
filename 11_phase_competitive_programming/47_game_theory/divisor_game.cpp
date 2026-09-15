#include <iostream>
#include <vector>

bool divisorGame(int n) {
    return n % 2 == 0;
}

bool dp(int n) {
    std::vector<char> w(n + 1);
    for (int i = 2; i <= n; ++i)
        for (int x = 1; x * x <= i; ++x)
            if (i % x == 0) {
                if (!w[i - x]) {
                    w[i] = 1;
                    break;
                }
                int y = i / x;
                if (y < i && !w[i - y]) {
                    w[i] = 1;
                    break;
                }
            }
    return w[n];
}

int main() {
    std::cout << std::boolalpha << "d(2)=" << divisorGame(2) << " dp=" << dp(2)
              << " (expected true)\n"
              << "d(3)=" << divisorGame(3) << " dp=" << dp(3) << " (expected false)\n";
    return 0;
}
