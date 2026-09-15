// LC633 Sum of Square Numbers
#include <cmath>
#include <iostream>

bool judgeSquareSum(int c) {
    long long lo = 0, hi = static_cast<long long>(std::sqrt(c));
    while (lo <= hi) {
        long long s = lo * lo + hi * hi;
        if (s == c)
            return true;
        if (s < c)
            ++lo;
        else
            --hi;
    }
    return false;
}

int main() {
    std::cout << std::boolalpha;
    std::cout << "judgeSquareSum(5)=" << judgeSquareSum(5) << " (expected true)\n";
    std::cout << "judgeSquareSum(3)=" << judgeSquareSum(3) << " (expected false)\n";
    return 0;
}
