// Bloom filter lab — insert + possiblyContains
// k hashes set bits; negatives are definite, positives may be false.
#include <functional>
#include <iostream>
#include <string>
#include <vector>

struct Bloom {
    std::vector<bool> bits;
    int k;

    explicit Bloom(size_t m, int k_) : bits(m, false), k(k_) {}

    size_t hash(const std::string& s, int i) const {
        return (std::hash<std::string>{}(s + "#" + std::to_string(i))) % bits.size();
    }

    void insert(const std::string& s) {
        for (int i = 0; i < k; ++i) {
            bits[hash(s, i)] = true;
        }
    }

    bool possiblyContains(const std::string& s) const {
        for (int i = 0; i < k; ++i) {
            if (!bits[hash(s, i)]) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Bloom b(256, 3);
    b.insert("cat");
    b.insert("dog");
    std::cout << std::boolalpha << b.possiblyContains("cat") << " (expected true)\n"
              << b.possiblyContains("fish") << " (expected false usually)\n";
    return 0;
}
