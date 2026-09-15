// Bloom false-positive rate lab
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

struct Bloom {
    std::vector<bool> bits;
    int k;
    explicit Bloom(int m, int k_) : bits(m), k(k_) {}
    size_t hash(const std::string& s, int i) const {
        return (std::hash<std::string>{}(s + "#" + std::to_string(i))) % bits.size();
    }
    void add(const std::string& s) {
        for (int i = 0; i < k; ++i)
            bits[hash(s, i)] = true;
    }
    bool maybe(const std::string& s) const {
        for (int i = 0; i < k; ++i)
            if (!bits[hash(s, i)])
                return false;
        return true;
    }
};

int main() {
    const int m = 1000, k = 3, n = 100, t = 1000;
    Bloom b(m, k);
    for (int i = 0; i < n; ++i)
        b.add("in" + std::to_string(i));
    int fp = 0;
    for (int i = 0; i < t; ++i)
        if (b.maybe("out" + std::to_string(i)))
            ++fp;
    double emp = double(fp) / t;
    double th = std::pow(1.0 - std::exp(-double(k) * n / m), k);
    std::cout << "empiricalFP=" << emp << " theory~=" << th << "\n";
    return 0;
}
