#include <iostream>
#include <unordered_set>
#include <vector>

std::vector<int> grundy(int n, const std::vector<int>& S) {
    std::vector<int> G(n + 1);
    for (int x = 1; x <= n; ++x) {
        std::unordered_set<int> r;
        for (int s : S)
            if (s <= x)
                r.insert(G[x - s]);
        int m = 0;
        while (r.count(m))
            ++m;
        G[x] = m;
    }
    return G;
}

int main() {
    auto G = grundy(10, {1, 3, 4});
    std::cout << "G:";
    for (int i = 0; i <= 10; ++i)
        std::cout << " " << G[i];
    std::cout << "\n";
    int x = G[3] ^ G[5] ^ G[7];
    std::cout << "XOR=" << x << " first=" << (x != 0) << "\n";
    return 0;
}
