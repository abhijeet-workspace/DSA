// Digit DP — count integers in [0, R] whose digit sum equals target.
// State (pos, sum, tight); memoized over decimal places.
#include <cstring>
#include <iostream>
#include <string>

long long memo[20][200][2];
std::string S;
int targetSum;

long long go(int pos, int sum, int tight) {
    if (pos == static_cast<int>(S.size())) {
        return sum == targetSum ? 1 : 0;
    }
    long long& res = memo[pos][sum][tight];
    if (res != -1) {
        return res;
    }
    res = 0;
    const int up = tight ? (S[static_cast<size_t>(pos)] - '0') : 9;
    for (int d = 0; d <= up; ++d) {
        if (sum + d > targetSum) {
            continue;
        }
        res += go(pos + 1, sum + d, tight && (d == up));
    }
    return res;
}

long long countUpTo(long long R, int tgt) {
    S = std::to_string(R);
    targetSum = tgt;
    std::memset(memo, -1, sizeof memo);
    return go(0, 0, 1);
}

int main() {
    // <= 20 with digit sum 2: 2, 11, 20 → 3
    std::cout << countUpTo(20, 2) << " (expected 3)\n";
    return 0;
}
