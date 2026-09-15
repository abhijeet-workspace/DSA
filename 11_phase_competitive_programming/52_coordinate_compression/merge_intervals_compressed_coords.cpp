#include <algorithm>
#include <iostream>
#include <vector>
int main() {
    std::vector<std::pair<int, int>> iv = {{1, 3}, {100, 105}, {2, 6}, {104, 110}};
    std::vector<int> c;
    for (auto [L, R] : iv) {
        c.push_back(L);
        c.push_back(R);
    }
    std::sort(c.begin(), c.end());
    c.erase(std::unique(c.begin(), c.end()), c.end());
    auto id = [&](int x) { return int(std::lower_bound(c.begin(), c.end(), x) - c.begin()); };
    std::vector<std::pair<int, int>> mapped;
    for (auto [L, R] : iv)
        mapped.push_back({id(L), id(R)});
    std::sort(mapped.begin(), mapped.end());
    std::vector<std::pair<int, int>> merged;
    for (auto p : mapped) {
        if (merged.empty() || merged.back().second < p.first)
            merged.push_back(p);
        else
            merged.back().second = std::max(merged.back().second, p.second);
    }
    std::vector<std::pair<int, int>> out;
    for (auto [L, R] : merged)
        out.push_back({c[L], c[R]});
    const std::vector<std::pair<int, int>> exp = {{1, 6}, {100, 110}};
    bool ok = out == exp;
    std::cout << (ok ? "OK\n" : "FAIL\n");
    return ok ? 0 : 1;
}
