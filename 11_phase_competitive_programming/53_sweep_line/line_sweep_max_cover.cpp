#include <algorithm>
#include <iostream>
#include <vector>
int maxCoverLengthAtLeastK(std::vector<std::pair<int, int>> iv, int K) {
    std::vector<std::pair<int, int>> ev;
    for (auto [L, R] : iv) {
        ev.push_back({L, +1});
        ev.push_back({R, -1});
    }
    std::sort(ev.begin(), ev.end());
    int cur = 0, ans = 0;
    for (size_t i = 0; i + 1 < ev.size(); ++i) {
        cur += ev[i].second;
        if (cur >= K)
            ans = std::max(ans, ev[i + 1].first - ev[i].first);
    }
    return ans;
}
int main() {
    int a = maxCoverLengthAtLeastK({{1, 5}, {2, 6}, {3, 7}}, 2);
    std::cout << "ans=" << a << " expected=2\n" << (a == 2 ? "OK\n" : "FAIL\n");
    return a == 2 ? 0 : 1;
}
