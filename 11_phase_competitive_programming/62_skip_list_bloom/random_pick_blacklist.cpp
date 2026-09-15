// Random Pick with Blacklist — LC 710
#include <cstdlib>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

struct Solution {
    int M;
    std::unordered_map<int, int> remap;
    Solution(int n, std::vector<int> blacklist) {
        std::unordered_set<int> black(blacklist.begin(), blacklist.end());
        M = n - (int)black.size();
        std::vector<int> whites;
        for (int x = M; x < n; ++x)
            if (!black.count(x))
                whites.push_back(x);
        int j = 0;
        for (int b : black)
            if (b < M)
                remap[b] = whites[j++];
    }
    int pick() {
        int x = std::rand() % M;
        return remap.count(x) ? remap[x] : x;
    }
};

int main() {
    std::srand(2);
    Solution s(4, {1, 2});
    for (int i = 0; i < 5; ++i)
        std::cout << s.pick() << " ";
    std::cout << "(expected only 0/3)\n";
    return 0;
}
