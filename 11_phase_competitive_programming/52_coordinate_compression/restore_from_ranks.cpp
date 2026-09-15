#include <iostream>
#include <vector>
int main() {
    std::vector<int> coords = {-5, 10, 40, 1000};
    std::vector<int> ranks = {3, 2, 3, 4, 1};
    std::vector<int> restored;
    for (int r : ranks)
        restored.push_back(coords[r - 1]);
    const std::vector<int> exp = {40, 10, 40, 1000, -5};
    bool ok = restored == exp;
    std::cout << (ok ? "OK\n" : "FAIL\n");
    return ok ? 0 : 1;
}
