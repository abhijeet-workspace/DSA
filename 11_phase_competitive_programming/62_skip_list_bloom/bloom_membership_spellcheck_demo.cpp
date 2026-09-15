// Bloom membership spellcheck demo
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

int main() {
    Bloom b(64, 3);
    std::unordered_set<std::string> dict = {"cat", "dog", "bird"};
    for (auto& w : dict)
        b.add(w);
    for (auto q : {"cat", "cot", "dog", "fish"}) {
        if (!b.maybe(q))
            std::cout << q << ": miss\n";
        else if (dict.count(q))
            std::cout << q << ": hit\n";
        else
            std::cout << q << ": bloom-FP-rejected\n";
    }
    return 0;
}
