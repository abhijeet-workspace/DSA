// Random Flip Matrix — LC 519
#include <cstdlib>
#include <iostream>
#include <unordered_map>
#include <vector>

struct Solution {
    int m, n, rem;
    std::unordered_map<int, int> mp;
    Solution(int m_, int n_) : m(m_), n(n_), rem(m_ * n_) {}
    std::vector<int> flip() {
        int r = std::rand() % rem;
        --rem;
        int x = mp.count(r) ? mp[r] : r;
        mp[r] = mp.count(rem) ? mp[rem] : rem;
        return {x / n, x % n};
    }
    void reset() {
        rem = m * n;
        mp.clear();
    }
};

int main() {
    std::srand(8);
    Solution s(2, 2);
    for (int i = 0; i < 4; ++i) {
        auto p = s.flip();
        std::cout << "(" << p[0] << "," << p[1] << ") ";
    }
    std::cout << "\n";
    return 0;
}
