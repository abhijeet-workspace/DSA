// Cuckoo filter lab — simplified fingerprints + kicks
#include <cstdint>
#include <iostream>
#include <string>
#include <vector>

struct CuckooFilter {
    static constexpr int BUCKET = 4;
    std::vector<std::vector<uint8_t>> tab;
    explicit CuckooFilter(int buckets) : tab(buckets, std::vector<uint8_t>(BUCKET, 0)) {}
    uint8_t fp(const std::string& s) const {
        auto h = std::hash<std::string>{}(s);
        uint8_t f = uint8_t(h & 0xff);
        return f ? f : 1;
    }
    size_t i1(const std::string& s) const { return std::hash<std::string>{}(s) % tab.size(); }
    size_t alt(size_t i, uint8_t f) const { return (i ^ (std::hash<uint8_t>{}(f))) % tab.size(); }

    bool add_to(size_t i, uint8_t f) {
        for (auto& x : tab[i])
            if (!x) {
                x = f;
                return true;
            }
        return false;
    }
    bool insert(const std::string& s) {
        uint8_t f = fp(s);
        size_t a = i1(s), b = alt(a, f);
        if (add_to(a, f) || add_to(b, f))
            return true;
        size_t i = a;
        for (int kick = 0; kick < 20; ++kick) {
            int slot = kick % BUCKET;
            std::swap(f, tab[i][slot]);
            i = alt(i, f);
            if (add_to(i, f))
                return true;
        }
        return false;
    }
    bool maybe(const std::string& s) const {
        uint8_t f = fp(s);
        size_t a = i1(s), b = alt(a, f);
        for (uint8_t x : tab[a])
            if (x == f)
                return true;
        for (uint8_t x : tab[b])
            if (x == f)
                return true;
        return false;
    }
    bool erase(const std::string& s) {
        uint8_t f = fp(s);
        size_t a = i1(s), b = alt(a, f);
        for (auto& x : tab[a])
            if (x == f) {
                x = 0;
                return true;
            }
        for (auto& x : tab[b])
            if (x == f) {
                x = 0;
                return true;
            }
        return false;
    }
};

int main() {
    CuckooFilter cf(32);
    cf.insert("cat");
    cf.insert("dog");
    std::cout << std::boolalpha << cf.maybe("cat") << " (expected true)\n";
    cf.erase("cat");
    std::cout << cf.maybe("cat") << " (expected false usually)\n";
    return 0;
}
