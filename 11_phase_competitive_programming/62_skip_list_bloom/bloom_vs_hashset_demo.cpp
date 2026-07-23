// Bloom vs hash set membership demo
// Same workload; Bloom may false-positive, set is exact.
#include <functional>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

struct Bloom {
    std::vector<bool> bits;
    int k;

    Bloom(size_t m, int k_) : bits(m), k(k_) {}

    size_t H(const std::string& s, int i) const {
        return std::hash<std::string>{}(s + std::to_string(i)) % bits.size();
    }

    void insert(const std::string& s) {
        for (int i = 0; i < k; ++i) {
            bits[H(s, i)] = true;
        }
    }

    bool maybe(const std::string& s) const {
        for (int i = 0; i < k; ++i) {
            if (!bits[H(s, i)]) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Bloom b(1024, 4);
    std::unordered_set<std::string> set;
    for (int i = 0; i < 100; ++i) {
        const std::string s = "key" + std::to_string(i);
        b.insert(s);
        set.insert(s);
    }
    int exact = 0, bloomPos = 0, fp = 0;
    for (int i = 0; i < 200; ++i) {
        const std::string s = "key" + std::to_string(i);
        const bool in = set.count(s) != 0;
        const bool mb = b.maybe(s);
        if (in) {
            ++exact;
        }
        if (mb) {
            ++bloomPos;
        }
        if (mb && !in) {
            ++fp;
        }
    }
    std::cout << "exact_hits=" << exact << " bloom_pos=" << bloomPos
              << " false_pos=" << fp << "\n";
    return 0;
}
