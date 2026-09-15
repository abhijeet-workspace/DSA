// Shuffle String — LC 1528
// Place s[i] at index indices[i].
#include <iostream>
#include <string>
#include <vector>

std::string restoreString(const std::string& s, const std::vector<int>& indices) {
    std::string ans(s.size(), ' ');
    for (size_t i = 0; i < s.size(); ++i) {
        ans[static_cast<size_t>(indices[i])] = s[i];
    }
    return ans;
}

int main() {
    std::cout << restoreString("codeleet", {4, 5, 6, 7, 0, 2, 1, 3}) << " (expected leetcode)\n";
    return 0;
}
