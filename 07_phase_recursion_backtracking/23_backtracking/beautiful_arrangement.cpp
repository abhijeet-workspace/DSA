// Beautiful Arrangement — https://leetcode.com/problems/beautiful-arrangement/
// Count permutations of 1..n where for each i, perm[i] % i == 0 or i % perm[i] == 0 (1-indexed).
#include <iostream>
#include <vector>

void dfs(int pos, int n, std::vector<bool>& used, int& count) {
    if (pos > n) {
        ++count;
        return;
    }
    for (int x = 1; x <= n; ++x) {
        if (used[static_cast<size_t>(x)]) continue;
        if (x % pos == 0 || pos % x == 0) {
            used[static_cast<size_t>(x)] = true;
            dfs(pos + 1, n, used, count);
            used[static_cast<size_t>(x)] = false;
        }
    }
}

int countArrangement(int n) {
    std::vector<bool> used(static_cast<size_t>(n + 1), false);
    int count = 0;
    dfs(1, n, used, count);
    return count;
}

int main() {
    std::cout << countArrangement(2) << " (expected 2)\n";
    std::cout << countArrangement(1) << " (expected 1)\n";
    return 0;
}
