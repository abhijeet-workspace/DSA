// LC441 Arranging Coins
#include <iostream>

int arrangeCoins(int n) {
    long long lo = 0, hi = n;
    while (lo <= hi) {
        long long mid = lo + (hi - lo) / 2;
        long long need = mid * (mid + 1) / 2;
        if (need == n)
            return static_cast<int>(mid);
        if (need < n)
            lo = mid + 1;
        else
            hi = mid - 1;
    }
    return static_cast<int>(hi);
}

int main() {
    std::cout << "arrangeCoins(5)=" << arrangeCoins(5) << " (expected 2)\n";
    std::cout << "arrangeCoins(8)=" << arrangeCoins(8) << " (expected 3)\n";
    return 0;
}
