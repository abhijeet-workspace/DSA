// Counting Bloom filter lab
#include <cstdint>
#include <iostream>
#include <string>
#include <vector>

struct CountingBloom {
    std::vector<uint8_t> cnt;
    int k;
    CountingBloom(int m, int k_) : cnt(m), k(k_) {}
    size_t hash(const std::string& s, int i) const {
        return (std::hash<std::string>{}(s + "#" + std::to_string(i))) % cnt.size();
    }
    void add(const std::string& s) {
        for (int i = 0; i < k; ++i) {
            auto& c = cnt[hash(s, i)];
            if (c < 255)
                ++c;
        }
    }
    void remove(const std::string& s) {
        for (int i = 0; i < k; ++i) {
            auto& c = cnt[hash(s, i)];
            if (c)
                --c;
        }
    }
    bool maybe(const std::string& s) const {
        for (int i = 0; i < k; ++i)
            if (!cnt[hash(s, i)])
                return false;
        return true;
    }
};

int main() {
    CountingBloom b(256, 3);
    b.add("cat");
    std::cout << std::boolalpha << b.maybe("cat") << " (expected true)\n";
    b.remove("cat");
    std::cout << b.maybe("cat") << " (expected false usually)\n";
    return 0;
}
