// Decode String — LC 394 (recursive descent)
#include <cctype>
#include <functional>
#include <iostream>
#include <string>

std::string decodeString(const std::string& s) {
    size_t i = 0;
    std::function<std::string()> parse = [&]() -> std::string {
        std::string cur;
        while (i < s.size() && s[i] != ']') {
            if (std::isdigit(static_cast<unsigned char>(s[i]))) {
                int k = 0;
                while (i < s.size() && std::isdigit(static_cast<unsigned char>(s[i]))) {
                    k = k * 10 + (s[i] - '0');
                    ++i;
                }
                ++i; // skip '['
                std::string inner = parse();
                ++i; // skip ']'
                while (k--)
                    cur += inner;
            } else {
                cur += s[i++];
            }
        }
        return cur;
    };
    return parse();
}

int main() {
    std::cout << decodeString("3[a]2[bc]") << " (expected aaabcbc)\n";
    std::cout << decodeString("3[a2[c]]") << " (expected accaccacc)\n";
    std::cout << decodeString("2[abc]3[cd]ef") << " (expected abcabccdcdcdef)\n";
    return 0;
}
