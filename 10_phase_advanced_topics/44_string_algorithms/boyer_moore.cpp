// Boyer-Moore — bad-character heuristic pattern search (teaching demo)
// On mismatch, shift using the rightmost occurrence of the mismatched text char.
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

std::vector<int> buildBadCharTable(const std::string& pat) {
    std::vector<int> bad(256, -1);
    for (int i = 0; i < static_cast<int>(pat.size()); ++i) {
        bad[static_cast<unsigned char>(pat[static_cast<size_t>(i)])] = i;
    }
    return bad;
}

std::vector<int> boyerMooreSearch(const std::string& txt, const std::string& pat) {
    std::vector<int> matches;
    const int n = static_cast<int>(txt.size());
    const int m = static_cast<int>(pat.size());
    if (m == 0 || n < m) return matches;

    std::vector<int> bad = buildBadCharTable(pat);
    int s = 0;
    while (s <= n - m) {
        int j = m - 1;
        while (j >= 0 && pat[static_cast<size_t>(j)] == txt[static_cast<size_t>(s + j)]) {
            --j;
        }
        if (j < 0) {
            matches.push_back(s);
            s += (s + m < n)
                     ? m - bad[static_cast<unsigned char>(txt[static_cast<size_t>(s + m)])]
                     : 1;
        } else {
            const int bc = bad[static_cast<unsigned char>(txt[static_cast<size_t>(s + j)])];
            s += std::max(1, j - bc);
        }
    }
    return matches;
}

int main() {
    auto printHits = [](const std::string& txt, const std::string& pat) {
        auto hits = boyerMooreSearch(txt, pat);
        std::cout << "\"" << pat << "\" in \"" << txt << "\": ";
        if (hits.empty()) std::cout << "none";
        else
            for (int p : hits) std::cout << p << " ";
        std::cout << "\n";
    };
    printHits("ABAAABCD", "ABC");
    printHits("THIS IS A TEST TEXT", "TEST");
    printHits("AAAAAA", "AA");
    printHits("ABCDEFG", "XYZ");
    return 0;
}
