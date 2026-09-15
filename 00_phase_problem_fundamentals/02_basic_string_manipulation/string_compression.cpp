// String Compression — LC 443
// In-place run-length write; return new length.
#include <iostream>
#include <string>
#include <vector>

int compress(std::vector<char>& chars) {
    const int n = static_cast<int>(chars.size());
    int write = 0;
    int read = 0;
    while (read < n) {
        const char c = chars[static_cast<size_t>(read)];
        int count = 0;
        while (read < n && chars[static_cast<size_t>(read)] == c) {
            ++read;
            ++count;
        }
        chars[static_cast<size_t>(write++)] = c;
        if (count > 1) {
            const std::string num = std::to_string(count);
            for (char d : num)
                chars[static_cast<size_t>(write++)] = d;
        }
    }
    return write;
}

int main() {
    std::vector<char> a{'a', 'a', 'b', 'b', 'c', 'c', 'c'};
    const int len = compress(a);
    for (int i = 0; i < len; ++i)
        std::cout << a[static_cast<size_t>(i)];
    std::cout << " (expected a2b2c3)\n";
    return 0;
}
