// Encode / Decode Strings — length-prefixed framing (len#payload)
// Unambiguous for any payload including '#'; round-trip safe.
#include <iostream>
#include <string>
#include <vector>

std::string encode(const std::vector<std::string>& strs) {
    std::string out;
    for (const std::string& s : strs) {
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
        const int len = std::stoi(s.substr(i, j - i));
        i = j + 1;
        out.push_back(s.substr(i, static_cast<size_t>(len)));
        i += static_cast<size_t>(len);
    }
    return out;
}

int main() {
    const std::vector<std::string> original = {"lint", "code", "love", "you"};
    const std::string encoded = encode(original);
    const auto decoded = decode(encoded);
    std::cout << "encoded=" << encoded << "\n";
    std::cout << "roundtrip_ok=" << std::boolalpha << (decoded == original)
              << " (expected true)\n";
    return 0;
}
