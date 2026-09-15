// Encode and Decode Strings — https://leetcode.com/problems/encode-and-decode-strings/
// Length-prefix framing: len#payload per string.
#include <iostream>
#include <string>
#include <vector>

std::string encode(const std::vector<std::string>& strs) {
    std::string out;
    for (const auto& s : strs) {
        out += std::to_string(s.size());
        out.push_back('#');
        out += s;
    }
    return out;
}

std::vector<std::string> decode(const std::string& s) {
    std::vector<std::string> out;
    size_t i = 0;
    while (i < s.size()) {
        size_t j = i;
        while (j < s.size() && s[j] != '#') ++j;
        int len = std::stoi(s.substr(i, j - i));
        out.push_back(s.substr(j + 1, len));
        i = j + 1 + len;
    }
    return out;
}

int main() {
    auto enc = encode({"Hello", "World", "", "a#b"});
    auto dec = decode(enc);
    for (auto& x : dec) std::cout << "[" << x << "] ";
    std::cout << "(expected [Hello] [World] [] [a#b])\n";
    return 0;
}
