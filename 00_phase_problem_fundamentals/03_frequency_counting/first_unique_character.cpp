// First Unique Character in a String — LC 387
#include <iostream>
#include <string>

int firstUniqChar(const std::string& s) {
    int freq[26] = {};
    for (char c : s)
        ++freq[c - 'a'];
    for (int i = 0; i < static_cast<int>(s.size()); ++i) {
        if (freq[s[static_cast<size_t>(i)] - 'a'] == 1)
            return i;
    }
    return -1;
}

int main() {
    std::cout << firstUniqChar("leetcode") << " (expected 0)\n";
    std::cout << firstUniqChar("loveleetcode") << " (expected 2)\n";
    std::cout << firstUniqChar("aabb") << " (expected -1)\n";
    return 0;
}
