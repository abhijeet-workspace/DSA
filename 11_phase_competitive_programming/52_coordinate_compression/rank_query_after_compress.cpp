#include <algorithm>
#include <iostream>
#include <vector>
int main() {
    std::vector<int> a = {40, 10, 40, 1000, -5};
    std::vector<int> vals = a;
    std::sort(vals.begin(), vals.end());
    vals.erase(std::unique(vals.begin(), vals.end()), vals.end());
    auto countLE = [&](int x) {
        return int(std::upper_bound(vals.begin(), vals.end(), x) - vals.begin());
    };
    bool ok = countLE(40) == 3 && countLE(9) == 1 && countLE(1000) == 4;
    std::cout << (ok ? "OK\n" : "FAIL\n");
    return ok ? 0 : 1;
}
