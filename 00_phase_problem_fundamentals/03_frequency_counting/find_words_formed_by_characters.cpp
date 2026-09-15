// Find Words That Can Be Formed by Characters — LC 1160
#include <iostream>
#include <string>
#include <vector>

int countCharacters(const std::vector<std::string>& words, const std::string& chars) {
    int budget[26] = {};
    for (char c : chars)
        ++budget[c - 'a'];
    int ans = 0;
    for (const std::string& w : words) {
        int need[26] = {};
        bool ok = true;
        for (char c : w) {
            int i = c - 'a';
            if (++need[i] > budget[i]) {
                ok = false;
                break;
            }
        }
        if (ok)
            ans += static_cast<int>(w.size());
    }
    return ans;
}

int main() {
    std::cout << countCharacters({"cat", "bt", "hat", "tree"}, "atach") << " (expected 6)\n";
    return 0;
}
