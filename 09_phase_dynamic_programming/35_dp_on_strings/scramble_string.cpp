// Scramble String — https://leetcode.com/problems/scramble-string/
#include <array>
#include <functional>
#include <iostream>
#include <string>
#include <unordered_map>

bool isScramble(std::string s1, std::string s2) {
    if (s1.size() != s2.size())
        return false;
    std::unordered_map<std::string, bool> memo;
    std::function<bool(const std::string&, const std::string&)> dfs =
        [&](const std::string& a, const std::string& b) -> bool {
        const std::string key = a + "#" + b;
        if (memo.count(key))
            return memo[key];
        if (a == b)
            return memo[key] = true;
        std::array<int, 26> cnt{};
        for (size_t i = 0; i < a.size(); ++i) {
            cnt[static_cast<size_t>(a[i] - 'a')]++;
            cnt[static_cast<size_t>(b[i] - 'a')]--;
        }
        for (int c : cnt)
            if (c)
                return memo[key] = false;
        const int n = static_cast<int>(a.size());
        for (int i = 1; i < n; ++i) {
            if (dfs(a.substr(0, i), b.substr(0, i)) && dfs(a.substr(i), b.substr(i)))
                return memo[key] = true;
            if (dfs(a.substr(0, i), b.substr(n - i)) && dfs(a.substr(i), b.substr(0, n - i)))
                return memo[key] = true;
        }
        return memo[key] = false;
    };
    return dfs(s1, s2);
}

int main() {
    std::cout << std::boolalpha << isScramble("great", "rgeat") << " (expected true)\n";
    std::cout << isScramble("abcde", "caebd") << " (expected false)\n";
    return 0;
}
