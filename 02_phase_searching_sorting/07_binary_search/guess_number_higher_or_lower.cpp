// Guess Number Higher or Lower — https://leetcode.com/problems/guess-number-higher-or-lower/
// Hidden pick in [1, n]; guess API returns -1 / 1 / 0. Binary search the pick.
#include <iostream>

static int g_pick = 0;

int guess(int num) {
    if (num > g_pick) {
        return -1;
    }
    if (num < g_pick) {
        return 1;
    }
    return 0;
}

int guessNumber(int n) {
    int lo = 1;
    int hi = n;
    while (lo <= hi) {
        const int mid = lo + (hi - lo) / 2;
        const int res = guess(mid);
        if (res == 0) {
            return mid;
        }
        if (res < 0) {
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    return -1;
}

int main() {
    g_pick = 6;
    std::cout << guessNumber(10) << " (expected 6)\n";
    g_pick = 1;
    std::cout << guessNumber(1) << " (expected 1)\n";
    return 0;
}
