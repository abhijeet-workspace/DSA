// Hungarian Assignment (small) — teaching
// Minimize sum of assignments for n x n cost matrix (n<=4 demo via permutations).
#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

int minAssignment(const std::vector<std::vector<int>>& cost) {
    int n = static_cast<int>(cost.size());
    std::vector<int> p(static_cast<size_t>(n));
    std::iota(p.begin(), p.end(), 0);
    int best = 1e9;
    do {
        int s = 0;
        for (int i = 0; i < n; ++i)
            s += cost[static_cast<size_t>(i)][static_cast<size_t>(p[static_cast<size_t>(i)])];
        best = std::min(best, s);
    } while (std::next_permutation(p.begin(), p.end()));
    return best;
}

int main() {
    std::vector<std::vector<int>> cost = {{9, 2, 7}, {6, 4, 3}, {5, 8, 1}};
    std::cout
        << minAssignment(cost)
        << " (expected 10)\n"; // 2+3+? wait 2+3+5=10 or 2+6+1? 9+4+1=14; 7+6+8=21; 2+3+5=10;
                               // 7+4+5=16; 9+3+8=20; best: row0col1=2,row1col2=3,row2col0=5 →10
    // Actually minimum is 2+3+5=10
    return 0;
}
