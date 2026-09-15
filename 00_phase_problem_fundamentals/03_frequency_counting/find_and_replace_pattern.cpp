// Find and Replace Pattern — LC 890
#include <iostream>
#include <string>
#include <vector>

static bool matches(const std::string& w, const std::string& p) {
    char w2p[128] = {}, p2w[128] = {};
    for (size_t i = 0; i < w.size(); ++i) {
        const unsigned char a = static_cast<unsigned char>(w[i]);
        const unsigned char b = static_cast<unsigned char>(p[i]);
        if (w2p[a] == 0 && p2w[b] == 0) {
            w2p[a] = static_cast<char>(b);
            p2w[b] = static_cast<char>(a);
        } else if (w2p[a] != static_cast<char>(b) || p2w[b] != static_cast<char>(a)) {
            return false;
        }
    }
    return true;
}

std::vector<std::string> findAndReplacePattern(const std::vector<std::string>& words, const std::string& pattern) {
    std::vector<std::string> ans;
    for (const auto& w : words) if (matches(w, pattern)) ans.push_back(w);
    return ans;
}

int main() {
    for (const auto& w : findAndReplacePattern({"abc", "deq", "mee", "aqq", "dkd", "ccc"}, "abb"))
        std::cout << w << " ";
    std::cout << "(expected mee aqq)\n";
    return 0;
}
