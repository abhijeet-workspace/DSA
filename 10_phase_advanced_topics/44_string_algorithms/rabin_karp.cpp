// Rabin–Karp — rolling hash pattern search; verify on hash hit
// hash' = (d*(hash - lead*h) + next) % q; check chars to kill collisions
#include <iostream>
#include <vector>
#include <string>

constexpr int ALPHABET_SIZE = 256;

std::vector<int> rabinKarpSearch(const std::string& txt, const std::string& pat, int q) {
    std::vector<int> matches;
    int n = static_cast<int>(txt.size());
    int m = static_cast<int>(pat.size());
    if (m == 0 || n < m) return matches;

    int patHash = 0, txtHash = 0, h = 1;
    for (int i = 0; i < m - 1; ++i) h = (h * ALPHABET_SIZE) % q;
    for (int i = 0; i < m; ++i) {
        patHash = (ALPHABET_SIZE * patHash + pat[i]) % q;
        txtHash = (ALPHABET_SIZE * txtHash + txt[i]) % q;
    }

    for (int i = 0; i <= n - m; ++i) {
        if (patHash == txtHash) {
            bool ok = true;
            for (int j = 0; j < m; ++j) {
                if (txt[i + j] != pat[j]) {
                    ok = false;
                    break;
                }
            }
            if (ok) matches.push_back(i);
        }
        if (i < n - m) {
            txtHash = (ALPHABET_SIZE * (txtHash - txt[i] * h) + txt[i + m]) % q;
            if (txtHash < 0) txtHash += q;
        }
    }
    return matches;
}

int main() {
    const int primeMod = 101;
    auto printHits = [&](const std::string& txt, const std::string& pat) {
        auto hits = rabinKarpSearch(txt, pat, primeMod);
        std::cout << "\"" << pat << "\" in \"" << txt << "\": ";
        if (hits.empty()) std::cout << "none";
        else
            for (int p : hits) std::cout << p << " ";
        std::cout << "\n";
    };
    printHits("GEEKS FOR GEEKS", "GEEK");
    printHits("ABABCABABABABACD", "ABABACD");
    printHits("AABAACAADAABAAABAA", "AABA");
    printHits("SUCCESS", "FAIL");
    return 0;
}
