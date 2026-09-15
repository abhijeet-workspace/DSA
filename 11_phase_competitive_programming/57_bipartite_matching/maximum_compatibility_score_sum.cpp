// Maximum Compatibility Score Sum — LeetCode 1947
#include <algorithm>
#include <iostream>
#include <vector>

int maxCompatibilitySum(const std::vector<std::vector<int>>& students,
                        const std::vector<std::vector<int>>& mentors) {
    int m = static_cast<int>(students.size());
    int q = static_cast<int>(students[0].size());
    std::vector<std::vector<int>> score(static_cast<size_t>(m),
                                        std::vector<int>(static_cast<size_t>(m), 0));
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < m; ++j)
            for (int k = 0; k < q; ++k)
                score[static_cast<size_t>(i)][static_cast<size_t>(j)] +=
                    students[static_cast<size_t>(i)][static_cast<size_t>(k)] ==
                    mentors[static_cast<size_t>(j)][static_cast<size_t>(k)];
    int best = 0;
    std::vector<int> perm(static_cast<size_t>(m));
    for (int i = 0; i < m; ++i)
        perm[static_cast<size_t>(i)] = i;
    do {
        int s = 0;
        for (int i = 0; i < m; ++i)
            s += score[static_cast<size_t>(i)][static_cast<size_t>(perm[static_cast<size_t>(i)])];
        best = std::max(best, s);
    } while (std::next_permutation(perm.begin(), perm.end()));
    return best;
}

int main() {
    std::cout << maxCompatibilitySum({{1, 1, 0}, {1, 0, 1}, {0, 0, 1}},
                                     {{1, 0, 0}, {0, 0, 1}, {1, 1, 0}})
              << " (expected 8)\n";
    return 0;
}
