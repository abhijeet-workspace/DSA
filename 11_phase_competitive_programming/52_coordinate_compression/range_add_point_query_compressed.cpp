#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>
int main() {
    std::vector<int> points = {10, 50, 100};
    std::vector<std::tuple<int, int, int>> adds = {{10, 50, 3}, {50, 100, 2}, {10, 100, 1}};
    std::vector<int> coords = points;
    for (auto [L, R, v] : adds) {
        coords.push_back(L);
        coords.push_back(R);
    }
    std::sort(coords.begin(), coords.end());
    coords.erase(std::unique(coords.begin(), coords.end()), coords.end());
    auto id = [&](int x) {
        return int(std::lower_bound(coords.begin(), coords.end(), x) - coords.begin());
    };
    std::vector<long long> diff(coords.size() + 1, 0);
    for (auto [L, R, v] : adds) {
        diff[id(L)] += v;
        int r = id(R);
        if (r + 1 < (int)diff.size())
            diff[r + 1] -= v;
    }
    for (int i = 1; i < (int)diff.size(); ++i)
        diff[i] += diff[i - 1];
    auto q = [&](int x) { return diff[id(x)]; };
    bool ok = q(10) == 4 && q(50) == 6 && q(100) == 3;
    std::cout << "q " << q(10) << " " << q(50) << " " << q(100) << "\n" << (ok ? "OK\n" : "FAIL\n");
    return ok ? 0 : 1;
}
