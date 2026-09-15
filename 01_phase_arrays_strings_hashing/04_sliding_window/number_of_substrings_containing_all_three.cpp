// Number of Substrings Containing All Three Characters — LC 1358
// For each right, track last index of a/b/c; add 1+min(lastA,lastB,lastC).
#include <algorithm>
#include <iostream>
#include <string>

int numberOfSubstrings(const std::string& s) {
    int lastA = -1, lastB = -1, lastC = -1;
    int count = 0;
    for (int i = 0; i < static_cast<int>(s.size()); ++i) {
        if (s[static_cast<size_t>(i)] == 'a')
            lastA = i;
        else if (s[static_cast<size_t>(i)] == 'b')
            lastB = i;
        else
            lastC = i;
        const int m = std::min({lastA, lastB, lastC});
        if (m >= 0)
            count += m + 1;
    }
    return count;
}

int main() {
    std::cout << numberOfSubstrings("abcabc") << " (expected 10)\n"
              << numberOfSubstrings("aaacb") << " (expected 3)\n"
              << numberOfSubstrings("abc") << " (expected 1)\n";
    return 0;
}
