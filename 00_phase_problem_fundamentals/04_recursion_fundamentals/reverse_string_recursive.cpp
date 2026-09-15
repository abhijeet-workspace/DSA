// Reverse String — LC 344 (recursive shrinking bounds)
#include <functional>
#include <iostream>
#include <vector>

void reverseString(std::vector<char>& s) {
    std::function<void(int, int)> dfs = [&](int L, int R) {
        if (L >= R)
            return;
        std::swap(s[static_cast<size_t>(L)], s[static_cast<size_t>(R)]);
        dfs(L + 1, R - 1);
    };
    if (!s.empty())
        dfs(0, static_cast<int>(s.size()) - 1);
}

int main() {
    std::vector<char> s{'h', 'e', 'l', 'l', 'o'};
    reverseString(s);
    for (char c : s)
        std::cout << c;
    std::cout << " (expected olleh)\n";
    return 0;
}
