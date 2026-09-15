#include <iostream>
#include <unordered_set>
#include <vector>

bool nimFirst(const std::vector<int>& p) {
    int x = 0;
    for (int v : p)
        x ^= v;
    return x != 0;
}

int mex(const std::unordered_set<int>& s) {
    int m = 0;
    while (s.count(m))
        ++m;
    return m;
}

int main() {
    std::cout << std::boolalpha << "first=" << nimFirst({1, 2, 3}) << " (expected false)\n"
              << "mex=" << mex({0, 1, 3}) << " (expected 2)\n";
    return 0;
}
