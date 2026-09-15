// HyperLogLog sketch lab — simplified
#include <cmath>
#include <cstdint>
#include <iostream>
#include <string>
#include <vector>

struct HLL {
    static constexpr int P = 4; // 16 registers
    static constexpr int M = 1 << P;
    std::vector<int> reg;
    HLL() : reg(M, 0) {}
    void add(const std::string& s) {
        uint32_t h = (uint32_t)std::hash<std::string>{}(s);
        int idx = h >> (32 - P);
        uint32_t w = h << P;
        int rho = 1;
        while (rho <= 32 - P && ((w >> (32 - rho)) & 1) == 0)
            ++rho;
        if (w == 0)
            rho = 32 - P + 1;
        reg[idx] = std::max(reg[idx], rho);
    }
    double estimate() const {
        double sum = 0;
        for (int r : reg)
            sum += std::pow(2.0, -r);
        double am = 0.7213 / (1 + 1.079 / M); // rough alpha
        return am * M * M / sum;
    }
};

int main() {
    HLL h;
    for (int i = 0; i < 100; ++i)
        h.add("id" + std::to_string(i));
    for (int i = 0; i < 50; ++i)
        h.add("id" + std::to_string(i)); // dupes
    std::cout << "estimate~=" << h.estimate() << " (true 100; rough)\n";
    return 0;
}
