// Coordinate compression snippet — ranks for Fenwick indices
#include <algorithm>
#include <iostream>
#include <vector>

std::vector<int> compress(std::vector<int> a) {
    std::vector<int> v = a;
    std::sort(v.begin(), v.end());
    v.erase(std::unique(v.begin(), v.end()), v.end());
    for (int& x : a)
        x = int(std::lower_bound(v.begin(), v.end(), x) - v.begin()) + 1;
    return a;
}

int main() {
    auto r = compress({100, -5, 100, 7});
    const std::vector<int> exp = {3, 1, 3, 2};
    std::cout << "ranks:";
    for (int x : r)
        std::cout << " " << x;
    std::cout << "\n";
    const bool ok = (r == exp);
    std::cout << (ok ? "OK\n" : "FAIL\n");
    return ok ? 0 : 1;
}
