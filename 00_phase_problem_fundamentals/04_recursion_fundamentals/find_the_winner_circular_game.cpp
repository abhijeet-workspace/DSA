// Find the Winner of the Circular Game — LC 1823
// Josephus recursion (0-based f, map to 1-based).
#include <iostream>
#include <functional>

int findTheWinner(int n, int k) {
    std::function<int(int)> f = [&](int m) -> int {
        if (m == 1) return 0;
        return (f(m - 1) + k) % m;
    };
    return f(n) + 1;
}

int main() {
    std::cout << findTheWinner(5, 2) << " (expected 3)\n";
    std::cout << findTheWinner(6, 5) << " (expected 1)\n";
    return 0;
}
