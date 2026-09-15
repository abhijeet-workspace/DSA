// LC914 X of a Kind in a Deck — gcd of frequencies
#include <iostream>
#include <numeric>
#include <unordered_map>
#include <vector>

bool hasGroupsSizeX(const std::vector<int>& deck) {
    std::unordered_map<int, int> freq;
    for (int x : deck)
        ++freq[x];
    int g = 0;
    for (auto& [_, f] : freq)
        g = std::gcd(g, f);
    return g >= 2;
}

int main() {
    std::cout << std::boolalpha;
    std::cout << "hasGroups({1,2,3,4,4,3,2,1})=" << hasGroupsSizeX({1, 2, 3, 4, 4, 3, 2, 1})
              << " (expected true)\n";
    std::cout << "hasGroups({1,1,1,2,2,2,3,3})=" << hasGroupsSizeX({1, 1, 1, 2, 2, 2, 3, 3})
              << " (expected false)\n";
    return 0;
}
