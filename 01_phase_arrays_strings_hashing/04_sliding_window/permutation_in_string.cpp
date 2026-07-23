// Permutation in String — LC 567
// Fixed window of |s1|; match 26-count arrays while sliding.
#include <iostream>
#include <vector>
#include <string>

bool checkInclusion(const std::string& s1, const std::string& s2) {
    const int n1 = static_cast<int>(s1.size());
    const int n2 = static_cast<int>(s2.size());
    if (n1 > n2) return false;
    std::vector<int> counts1(26, 0), counts2(26, 0);
    for (int i = 0; i < n1; ++i) {
        ++counts1[static_cast<size_t>(s1[static_cast<size_t>(i)] - 'a')];
        ++counts2[static_cast<size_t>(s2[static_cast<size_t>(i)] - 'a')];
    }
    if (counts1 == counts2) return true;
    for (int i = n1; i < n2; ++i) {
        ++counts2[static_cast<size_t>(s2[static_cast<size_t>(i)] - 'a')];
        --counts2[static_cast<size_t>(s2[static_cast<size_t>(i - n1)] - 'a')];
        if (counts1 == counts2) return true;
    }
    return false;
}

int main() {
    std::cout << std::boolalpha
              << checkInclusion("ab", "eidbaooo") << " (expected true)\n"
              << checkInclusion("ab", "eidboaoo") << " (expected false)\n";
    return 0;
}
