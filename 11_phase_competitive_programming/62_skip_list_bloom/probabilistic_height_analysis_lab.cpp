// Probabilistic height analysis lab — geometric tower heights
#include <iostream>
#include <random>
#include <vector>

int main() {
    const int N = 1024, MAXL = 20;
    std::mt19937 rng{42};
    std::vector<int> hist(MAXL + 1);
    int mx = 1;
    for (int i = 0; i < N; ++i) {
        int h = 1;
        while (h < MAXL && (rng() & 1))
            ++h;
        ++hist[h];
        mx = std::max(mx, h);
    }
    std::cout << "maxHeight=" << mx << "\n";
    for (int h = 1; h <= mx; ++h)
        if (hist[h])
            std::cout << "h=" << h << " count=" << hist[h] << "\n";
    return 0;
}
