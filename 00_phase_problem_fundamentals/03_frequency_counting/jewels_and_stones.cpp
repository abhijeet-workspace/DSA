// Jewels and Stones — LC 771
#include <iostream>
#include <string>

int numJewelsInStones(const std::string& jewels, const std::string& stones) {
    bool isJewel[128] = {};
    for (char c : jewels) isJewel[static_cast<unsigned char>(c)] = true;
    int ans = 0;
    for (char c : stones) if (isJewel[static_cast<unsigned char>(c)]) ++ans;
    return ans;
}

int main() {
    std::cout << numJewelsInStones("aA", "aAAbbbb") << " (expected 3)\n";
    std::cout << numJewelsInStones("z", "ZZ") << " (expected 0)\n";
    return 0;
}
