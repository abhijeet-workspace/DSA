// Random Pick with Weight — LC 528
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>

struct Solution {
    std::vector<int> pref;
    explicit Solution(std::vector<int> w) {
        pref = w;
        for (int i = 1; i < (int)pref.size(); ++i)
            pref[i] += pref[i - 1];
    }
    int pickIndex() {
        int r = std::rand() % pref.back() + 1;
        return (int)(std::lower_bound(pref.begin(), pref.end(), r) - pref.begin());
    }
};

int main() {
    std::srand(9);
    Solution s({1, 3});
    int c0 = 0, c1 = 0;
    for (int i = 0; i < 4000; ++i)
        (s.pickIndex() == 0 ? ++c0 : ++c1);
    std::cout << "c0=" << c0 << " c1=" << c1 << " (c1 should dominate)\n";
    return 0;
}
