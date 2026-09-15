// Z-Algorithm vs Suffix Array — teaching
#include <iostream>
#include <string>
#include <vector>

std::vector<int> zFunction(const std::string& s) {
    int n = static_cast<int>(s.size());
    std::vector<int> z(n);
    int l = 0, r = 0;
    for (int i = 1; i < n; ++i) {
        if (i <= r)
            z[i] = std::min(r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
    return z;
}

int main() {
    std::string s = "aabcaabxaaaz";
    auto z = zFunction(s);
    std::cout << "z[3]=" << z[3] << " (expected 0)\n";
    std::cout << "z[4]=" << z[4] << " (expected 3)\n"; // aab matches prefix
    // Pedagogy: Z gives LCP of each suffix with the whole string in O(N).
    // SA+LCP gives LCP between lexicographically adjacent suffixes — different query shape.
    std::cout << "note_z_vs_sa=ok\n";
    return 0;
}
