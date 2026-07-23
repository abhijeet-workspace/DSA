// KMP — pattern search via LPS (longest proper prefix that is also suffix)
// On mismatch, jump j = lps[j-1] instead of restarting from pattern[0]
#include <iostream>
#include <vector>
#include <string>

std::vector<int> computeLPSArray(const std::string& pat) {
    int m = static_cast<int>(pat.size());
    std::vector<int> lps(m, 0);
    int len = 0, i = 1;
    while (i < m) {
        if (pat[i] == pat[len]) {
            lps[i++] = ++len;
        } else if (len != 0) {
            len = lps[len - 1]; // fall back
        } else {
            lps[i++] = 0;
        }
    }
    return lps;
}

std::vector<int> KMPSearch(const std::string& txt, const std::string& pat) {
    std::vector<int> matches;
    int n = static_cast<int>(txt.size());
    int m = static_cast<int>(pat.size());
    if (m == 0 || n < m) return matches;

    std::vector<int> lps = computeLPSArray(pat);
    int i = 0, j = 0;
    while (i < n) {
        if (pat[j] == txt[i]) {
            ++i;
            ++j;
        }
        if (j == m) {
            matches.push_back(i - j);
            j = lps[j - 1];
        } else if (i < n && pat[j] != txt[i]) {
            if (j != 0) j = lps[j - 1];
            else ++i;
        }
    }
    return matches;
}

int main() {
    auto printHits = [](const std::string& txt, const std::string& pat) {
        auto hits = KMPSearch(txt, pat);
        std::cout << "\"" << pat << "\" in \"" << txt << "\": ";
        if (hits.empty()) std::cout << "none";
        else
            for (int p : hits) std::cout << p << " ";
        std::cout << "\n";
    };
    printHits("ABABDABACDABABCABAB", "ABABCABAB");
    printHits("AAAAAA", "AA");
    printHits("THIS IS A TEST TEXT", "TEST");
    printHits("ABCDEFG", "XYZ");
    printHits("A", "A");
    return 0;
}
