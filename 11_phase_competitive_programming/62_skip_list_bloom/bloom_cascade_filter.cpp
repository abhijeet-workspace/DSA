// Bloom cascade filter — Bloom then exact set
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

struct Bloom {
    std::vector<bool> bits;
    int k;
    Bloom(int m, int k_) : bits(m), k(k_) {}
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

struct Cascade {
    Bloom bloom;
    std::unordered_set<std::string> exact;
    Cascade() : bloom(128, 3) {}
    void add(const std::string& s) {
        bloom.add(s);
        exact.insert(s);
    }
    bool contains(const std::string& s) const {
        if (!bloom.maybe(s))
            return false;
        return exact.count(s) > 0;
    }
};

int main() {
    Cascade c;
    c.add("apple");
    c.add("pear");
    std::cout << std::boolalpha;
    std::cout << c.contains("apple") << " (expected true)\n";
    std::cout << c.contains("banana") << " (expected false)\n";
    return 0;
}
