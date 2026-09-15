// Find All Centroids — O(N^2) verification oracle
#include <iostream>
#include <vector>

std::vector<int> findAllCentroids(int n, const std::vector<std::vector<int>>& g) {
    std::vector<int> cents;
    for (int v = 1; v <= n; ++v) {
        bool ok = true;
        for (int to : g[static_cast<size_t>(v)]) {
            std::vector<char> seen(static_cast<size_t>(n) + 1, 0);
            seen[static_cast<size_t>(v)] = 1;
            seen[static_cast<size_t>(to)] = 1;
            int cnt = 0;
            std::vector<int> st = {to};
            while (!st.empty()) {
                int u = st.back();
                st.pop_back();
                ++cnt;
                for (int w : g[static_cast<size_t>(u)])
                    if (!seen[static_cast<size_t>(w)]) {
                        seen[static_cast<size_t>(w)] = 1;
                        st.push_back(w);
                    }
            }
            if (cnt > n / 2) {
                ok = false;
                break;
            }
        }
        if (ok)
            cents.push_back(v);
    }
    return cents;
}

int main() {
    int n = 4;
    std::vector<std::vector<int>> g(static_cast<size_t>(n) + 1);
    auto add = [&](int u, int v) {
        g[static_cast<size_t>(u)].push_back(v);
        g[static_cast<size_t>(v)].push_back(u);
    };
    add(1, 2);
    add(2, 3);
    add(3, 4);
    auto c = findAllCentroids(n, g);
    std::cout << "centroids:";
    for (int x : c)
        std::cout << " " << x;
    std::cout << " (expected 2 3)\n";
    return 0;
}
