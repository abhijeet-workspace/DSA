#include <iostream>
#include <vector>

bool winnerSquareGame(int n) {
    std::vector<char> w(n + 1);
    for (int i = 1; i <= n; ++i)
        for (int k = 1; k * k <= i; ++k)
            if (!w[i - k * k]) {
                w[i] = true;
                break;
            }
    return w[n];
}

int main() {
    std::cout << std::boolalpha << "w(2)=" << winnerSquareGame(2) << " (expected false)\n"
              << "w(7)=" << winnerSquareGame(7) << " (expected true)\n";
    return 0;
}
