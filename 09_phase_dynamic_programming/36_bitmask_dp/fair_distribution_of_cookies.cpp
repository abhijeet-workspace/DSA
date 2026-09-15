// Fair Distribution of Cookies — https://leetcode.com/problems/fair-distribution-of-cookies/
#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

int distributeCookies(std::vector<int>& cookies, int k) {
    std::sort(cookies.rbegin(), cookies.rend());
    std::vector<int> load(static_cast<size_t>(k), 0);
    int ans = 1e9;
    std::function<void(int)> dfs = [&](int i) {
        if (i == static_cast<int>(cookies.size())) {
            ans = std::min(ans, *std::max_element(load.begin(), load.end()));
            return;
        }
        for (int c = 0; c < k; ++c) {
            if (load[static_cast<size_t>(c)] + cookies[static_cast<size_t>(i)] >= ans)
                continue;
            load[static_cast<size_t>(c)] += cookies[static_cast<size_t>(i)];
            dfs(i + 1);
            load[static_cast<size_t>(c)] -= cookies[static_cast<size_t>(i)];
            if (load[static_cast<size_t>(c)] == 0)
                break;
        }
    };
    dfs(0);
    return ans;
}

int main() {
    std::vector<int> cookies{8, 15, 10, 20, 8};
    std::cout << distributeCookies(cookies, 2) << " (expected 31)\n";
    return 0;
}
