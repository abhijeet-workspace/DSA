// Compare Version Numbers — LC 165
// Compare dot-separated revisions as integers (ignore leading zeros).
#include <iostream>
#include <string>

int compareVersion(const std::string& version1, const std::string& version2) {
    const int n = static_cast<int>(version1.size());
    const int m = static_cast<int>(version2.size());
    int i = 0, j = 0;
    while (i < n || j < m) {
        long a = 0, b = 0;
        while (i < n && version1[static_cast<size_t>(i)] != '.') {
            a = a * 10 + (version1[static_cast<size_t>(i)] - '0');
            ++i;
        }
        while (j < m && version2[static_cast<size_t>(j)] != '.') {
            b = b * 10 + (version2[static_cast<size_t>(j)] - '0');
            ++j;
        }
        if (a < b) return -1;
        if (a > b) return 1;
        if (i < n && version1[static_cast<size_t>(i)] == '.') ++i;
        if (j < m && version2[static_cast<size_t>(j)] == '.') ++j;
    }
    return 0;
}

int main() {
    std::cout << compareVersion("1.01", "1.001") << " (expected 0)\n";
    std::cout << compareVersion("1.0", "1.0.0") << " (expected 0)\n";
    std::cout << compareVersion("0.1", "1.1") << " (expected -1)\n";
    return 0;
}
