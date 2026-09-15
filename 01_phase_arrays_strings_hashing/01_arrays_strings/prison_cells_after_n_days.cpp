// Prison Cells After N Days — https://leetcode.com/problems/prison-cells-after-n-days/
// 8 cells; next day cell is 1 iff neighbors equal. Find state after N days (cycle detection).
#include <iostream>
#include <unordered_map>
#include <vector>

std::vector<int> prisonAfterNDays(std::vector<int> cells, int n) {
    std::unordered_map<int, int> seen; // bitmask -> day
    auto toMask = [](const std::vector<int>& c) {
        int m = 0;
        for (int i = 0; i < 8; ++i) {
            m |= c[static_cast<size_t>(i)] << i;
        }
        return m;
    };
    auto nextDay = [](const std::vector<int>& c) {
        std::vector<int> nxt(8, 0);
        for (int i = 1; i <= 6; ++i) {
            nxt[static_cast<size_t>(i)] =
                c[static_cast<size_t>(i - 1)] == c[static_cast<size_t>(i + 1)] ? 1 : 0;
        }
        return nxt;
    };

    for (int day = 0; day < n; ++day) {
        const int mask = toMask(cells);
        if (seen.count(mask)) {
            const int cycle = day - seen[mask];
            const int remain = (n - day) % cycle;
            return prisonAfterNDays(cells, remain);
        }
        seen[mask] = day;
        cells = nextDay(cells);
    }
    return cells;
}

int main() {
    // n=7 returns to the start of a 7-day cycle (LC example text is inconsistent with the rule).
    const auto a = prisonAfterNDays({0, 1, 0, 1, 1, 0, 1, 0}, 7);
    for (size_t i = 0; i < a.size(); ++i) {
        if (i)
            std::cout << ' ';
        std::cout << a[i];
    }
    std::cout << " (expected 0 1 0 1 1 0 1 0)\n";
    const auto b = prisonAfterNDays({0, 1, 0, 1, 1, 0, 1, 0}, 1);
    for (size_t i = 0; i < b.size(); ++i) {
        if (i)
            std::cout << ' ';
        std::cout << b[i];
    }
    std::cout << " (expected 0 1 1 0 0 1 1 0)\n";
    const auto c = prisonAfterNDays({1, 0, 0, 1, 0, 0, 1, 0}, 1000000000);
    for (size_t i = 0; i < c.size(); ++i) {
        if (i)
            std::cout << ' ';
        std::cout << c[i];
    }
    std::cout << " (expected 0 0 1 1 1 1 1 0)\n";
    return 0;
}
